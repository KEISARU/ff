#include <memory>
#include <unistd.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp/time.hpp"
#include "std_msgs/msg/u_int8.hpp"
#include "std_msgs/msg/float32.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "sensor_msgs/msg/joy.hpp"

#include "digipot/DigiPot.h"
#include "digipot/ads1115.hpp"
#include "digipot_interfaces/msg/digipot.hpp"

using namespace std::chrono_literals;

#define I2C_PCA9685_ADDR    0x40
#define PCA9685_MODE1       0x00
#define PCA9685_MODE2       0x01
#define PCA9685_LED0_ON_L   0x06
#define PCA9685_PRESCALE    0xFE

#define STEER_PWM_CHANNEL   0

/**
 * @brief This class is used to map the angles of the
 * servo to int value for the servo based on
 * PWM frequency.
 *
 */
class Angle2ServoMap {
public:
    using Ptr = std::shared_ptr<Angle2ServoMap>;

    /**
     * @brief builder function
     *
     * @param[in] freq          Desired frequency of the PWM signal
     * @param[in] minMiliSec    Minimum high time of the PWM singal in milliseconds
     * @param[in] maxMiliSec    Maximum hight time of the PWM singnal in milliseconds
     * @param[in] maxPWM        The maximum value for the PWM (defining the resolution for PWM signal generator)
     * @return Angle2ServoMap::Ptr
     */

    static Angle2ServoMap::Ptr create(float freq, float minMiliSec, float maxMiliSec, unsigned int maxPWM) {
        return std::make_shared<Angle2ServoMap>(freq, minMiliSec, maxMiliSec, maxPWM);
    }

    float calPwm(int angle) {
        return m_ * angle + b_;
    }

    Angle2ServoMap(float freq, float minMiliSec, float maxMiliSec, unsigned int maxPWM) :
            m_(0), b_(0) {
        float ms_2_percent = float(freq) / 1000.0 /* ms */;
        float minPWMv = minMiliSec * ms_2_percent * maxPWM;
        float maxPWMv = maxMiliSec * ms_2_percent * maxPWM;
        float Fmin = 0.0;
        float Fmax = 180.0;
        m_ = (maxPWMv - minPWMv) / (Fmax - Fmin);
        b_ = minPWMv - m_ * Fmin;
    }

private:
    float m_, b_;
};

class DigipotNode : public rclcpp::Node
{
public:
  DigipotNode(): Node("digipot_node"), digipot_(21,19,23)
  {
    last_control_ = get_clock()->now();
    pwm_freq_ = 60.0;
    steeringMap_ = Angle2ServoMap::create(pwm_freq_, 1.0, 2.0, 4095u);
    
    declare_parameter("udPin", 0);
    declare_parameter("incPin", 0);
    declare_parameter("csPin", 0);

    // Get parameter values
    udPin_ = get_parameter("udPin").as_int();
    incPin_ = get_parameter("incPin").as_int();
    csPin_ = get_parameter("csPin").as_int();

    // Get the I2C device file descriptor
    i2c_fd_ = open("/dev/i2c-0", O_RDWR);
    while (i2c_fd_ < 0) {
        RCUTILS_LOG_ERROR_NAMED(get_name(), "Failed to open I2C device: %d, trying again in 1 sec.", i2c_fd_);
        usleep(1000000);
        i2c_fd_ = open("/dev/i2c-0", O_RDWR);
    }
    RCUTILS_LOG_DEBUG_NAMED(get_name(), "I2C device opened successfully");

    // Set the I2C slave address
    if (ioctl(i2c_fd_, I2C_SLAVE, ADS1X15_ADDRESS) < 0) {
        RCUTILS_LOG_ERROR_NAMED(get_name(), "Failed to set I2C slave address");
        return;
    }
    RCUTILS_LOG_DEBUG_NAMED(get_name(), "I2C slave address set successfully");

    // Get the I2C device file descriptor
    i2c_pca_fd_ = open("/dev/i2c-1", O_RDWR);
    while (i2c_pca_fd_ < 0) {
        RCUTILS_LOG_ERROR_NAMED(get_name(), "Failed to open I2C device: %d, trying again in 1 sec.", i2c_pca_fd_);
        usleep(1000000);
        i2c_pca_fd_ = open("/dev/i2c-1", O_RDWR);
    }
    RCUTILS_LOG_DEBUG_NAMED(get_name(), "I2C device opened successfully");

    // Set the I2C slave address
    if (ioctl(i2c_pca_fd_, I2C_SLAVE, I2C_PCA9685_ADDR) < 0) {
        RCUTILS_LOG_ERROR_NAMED(get_name(), "Failed to set I2C slave address");
        return;
    }
    RCUTILS_LOG_DEBUG_NAMED(get_name(), "I2C slave address set successfully");

    set_frequency(pwm_freq_);

    // Create a subscription to the "digipot" topic with a callback function
    subscription_ = create_subscription<std_msgs::msg::UInt8>(
      "digipot", 10, std::bind(&DigipotNode::digipotCallback, this, std::placeholders::_1));
    
    teleop_sub_ = create_subscription<geometry_msgs::msg::Twist>(
      "teleop", 10, std::bind(&DigipotNode::teleopCallback, this, std::placeholders::_1));
    
    joy_sub_ = create_subscription<sensor_msgs::msg::Joy>(
      "joy", 10, std::bind(&DigipotNode::joyCallback, this, std::placeholders::_1));
    
    publisher_ = this->create_publisher<digipot_interfaces::msg::Digipot>("digipot_status", 10);
    timer_ = this->create_wall_timer(20ms, std::bind(&DigipotNode::timer_callback, this));
    
    
    RCLCPP_INFO(get_logger(), "Digipot node has been initialized.");
  }

private:
  void digipotCallback(const std_msgs::msg::UInt8::SharedPtr msg)
  {
    uint8_t value = msg->data;
    // Log the received message as Debug
    RCLCPP_DEBUG(get_logger(), "Received digipot value: %u", value);
    if(value == 242) {
	    digipot_.increase(1);
	    return;
    }
    if(value == 243) {
	    digipot_.decrease(1);
	    return;
    }
    digipot_.set(value);
  }

  void teleopCallback(const geometry_msgs::msg::Twist::SharedPtr msg)
  {
    uint8_t value = digipot_.get() + msg->linear.x;
    last_control_ = get_clock()->now();
    if(msg->linear.x > 0)
    {
      digipot_.set(62);

    }
    else
    {
      digipot_.set(35);
    }
  }

  void joyCallback(const sensor_msgs::msg::Joy::SharedPtr msg)
  {
    float fb_value = msg->axes[1];
    float rl_value = msg->axes[2];
    last_control_ = msg->header.stamp;
    int longitudinal_value = static_cast<int>((fb_value + 1.0)/(2.0) * (-99.0) + 99.0);
    int lateral_value = static_cast<int>((rl_value + 1.0)/(2.0) * (60) - 30);
    RCLCPP_DEBUG(get_logger(), "Longitudinal: joystick = %f, command = %d", fb_value, longitudinal_value);
    RCLCPP_DEBUG(get_logger(), "Lateral: joystick = %f, command = %d", rl_value, lateral_value);
    digipot_.set(longitudinal_value);
    uint16_t pwm = (uint16_t)(std::round(steeringMap_->calPwm(lateral_value))) & 0x0FFF;
    set_pwm(STEER_PWM_CHANNEL, 0, pwm);
  }

  void timer_callback()
  {   
      auto message = digipot_interfaces::msg::Digipot();
      if((get_clock()->now() - last_control_).nanoseconds() > 200000000.0)
      {
        digipot_.set(49);
        uint16_t pwm = (uint16_t)(std::round(steeringMap_->calPwm(0))) & 0x0FFF;
        set_pwm(STEER_PWM_CHANNEL, 0, pwm);
      }
      message.value = digipot_.get();
      message.wiper = read_ADC(0) * (6.144f / 32768);
      message.high = read_ADC(1) * (6.144f / 32768);
      publisher_->publish(message);
  }

  int16_t read_ADC(uint8_t channel)
  {
    if (channel > 3) {
    return 0;
    }

    uint16_t config =
      ADS1X15_REG_CONFIG_CQUE_1CONV |   // Set CQUE to any value other than
                                        // None so we can use it in RDY mode
      ADS1X15_REG_CONFIG_CLAT_NONLAT |  // Non-latching (default val)
      ADS1X15_REG_CONFIG_CPOL_ACTVLOW | // Alert/Rdy active low   (default val)
      ADS1X15_REG_CONFIG_CMODE_TRAD |    // Traditional comparator (default val)
      ADS1X15_REG_CONFIG_MODE_SINGLE |    // Sigle read mode
      GAIN_TWOTHIRDS |
      RATE_ADS1115_128SPS |
      MUX_BY_CHANNEL[channel] |
      ADS1X15_REG_CONFIG_OS_SINGLE;

    write_reg(ADS1X15_REG_POINTER_CONFIG, config);
    write_reg(ADS1X15_REG_POINTER_HITHRESH, 0x8000);
    write_reg(ADS1X15_REG_POINTER_LOWTHRESH, 0x0000);
   

    // Wait for the conversion to complete
    while ((read_reg(ADS1X15_REG_POINTER_CONFIG) & 0x8000) == 0);

    // Read the conversion results
    return read_reg(ADS1X15_REG_POINTER_CONVERT);
  }

  void write_reg(uint8_t reg, uint16_t data)
  {
        /**
         * @brief                   Write a byte to the specified I2C register
         *
         * @param[in] reg           The register address to write to
         * @param[in] data          The data byte to be written to the register
         */

        uint8_t buf[3] = {reg, uint8_t(data >> 8), uint8_t(data & 0xFF)};
        if (write(i2c_fd_, buf, 3) != 3) {
            RCUTILS_LOG_ERROR_NAMED(get_name(), "Failed to write I2C register value");
        }
    }

    uint16_t read_reg(uint8_t reg)
    {
        /**
         * @brief                   Read a byte from the specified I2C register
         *
         *
         * @param[in] reg           The register address to read from
         * @return                  The data byte read from the register
         */

        uint8_t buf[2] = {reg, 0};
        if (write(i2c_fd_, buf, 1) != 1) {
            RCUTILS_LOG_ERROR_NAMED(get_name(), "Failed to write I2C register value");
        }
        if (read(i2c_fd_, buf, 2) != 2) {
            RCUTILS_LOG_ERROR_NAMED(get_name(), "Failed to read I2C register value");
        }
        return (buf[0] << 8) | buf[1];
    }
  
  void write_pca_reg(uint8_t reg, uint8_t data) {
        /**
         * @brief                   Write a byte to the specified I2C register
         *
         * @param[in] reg           The register address to write to
         * @param[in] data          The data byte to be written to the register
         */

        uint8_t buf[2] = {reg, data};
        if (write(i2c_pca_fd_, buf, 2) != 2) {
            RCUTILS_LOG_ERROR_NAMED(get_name(), "Failed to write I2C register value");
        }
    }

    uint8_t read_pca_reg(uint8_t reg) {
        /**
         * @brief                   Read a byte from the specified I2C register
         *
         *
         * @param[in] reg           The register address to read from
         * @return                  The data byte read from the register
         */

        uint8_t buf[] = {reg};
        if (write(i2c_pca_fd_, buf, 1) != 2) {
            RCUTILS_LOG_ERROR_NAMED(get_name(), "Failed to write I2C register value");
        }
        if (read(i2c_pca_fd_, buf, 1) != 2) {
            RCUTILS_LOG_ERROR_NAMED(get_name(), "Failed to read I2C register value");
        }
        return buf[0];
    }

   void set_pwm(uint8_t channel, uint16_t on_time, uint16_t off_time) {
        /**
         * @brief                   Set PWM values for a specific channel
         *
         * @param[in] channel       The channel for which PWM values are to be set
         * @param[in] on_time       The ON time for the PWM signal (in ticks)
         * @param[in] off_time      The OFF time for the PWM signal (in ticks)
         */

        uint8_t reg_offset = PCA9685_LED0_ON_L + 4 * channel;
        uint8_t on_time_low = on_time & 0xFF;
        uint8_t on_time_high = (on_time >> 8) & 0x0F;
        uint8_t off_time_low = off_time & 0xFF;
        uint8_t off_time_high = (off_time >> 8) & 0x0F;

        write_pca_reg(reg_offset, on_time_low);
        write_pca_reg(reg_offset + 1, on_time_high);
        write_pca_reg(reg_offset + 2, off_time_low);
        write_pca_reg(reg_offset + 3, off_time_high);
    }
  
  void set_frequency(uint16_t frequency) {
        /**
         * @brief Set frequency of the PWM (in Hz)
         * based on the formula from the datasheet
         *
         * @param[in] frequency         The frequency for which PWM should be set
         */

        uint8_t prescale = (uint8_t)(std::round(25000000.0 / (4096.0 * frequency)) - 1);
        write_pca_reg(PCA9685_MODE1, 0b00010000);
        usleep(1000);
        write_pca_reg(PCA9685_PRESCALE, prescale);
        write_pca_reg(PCA9685_MODE1, 0b10100000);
        usleep(1000);
        // write_reg(PCA9685_MODE2, 0x00);
        // usleep(1000);
    }

  int udPin_;
  int incPin_;
  int csPin_;
  int i2c_fd_;
  int i2c_pca_fd_;
  rclcpp::Subscription<std_msgs::msg::UInt8>::SharedPtr subscription_;
  rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr teleop_sub_;
  rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr joy_sub_;
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<digipot_interfaces::msg::Digipot>::SharedPtr publisher_;
  DigiPot digipot_;
  rclcpp::Time last_control_;
  Angle2ServoMap::Ptr steeringMap_;
  float pwm_freq_;
};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);

  // Create an instance of the DigipotNode class
  auto node = std::make_shared<DigipotNode>();

  // Spin the node
  rclcpp::spin(node);

  rclcpp::shutdown();
  return 0;
}
