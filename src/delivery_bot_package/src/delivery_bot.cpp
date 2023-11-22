#include <memory>
#include <unistd.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <JetsonGPIO.h>
#include <delivery_bot_package/DigiPot.h>

using std::placeholders::_1;

/**
 * Define registers with their corresponding addresses
 * Based on the Adafruit Datasheet:
 * https://cdn-shop.adafruit.com/datasheets/PCA9685.pdf
 */

#define I2C_ADDRESS         0x40
#define PCA9685_MODE1       0x00
#define PCA9685_MODE2       0x01
#define PCA9685_LED0_ON_L   0x06
#define PCA9685_PRESCALE    0xFE

#define STEER_PWM_CHANNEL   1

int servoMax = 70;
int servoMin = 32;
int servoMid = 50;

int speedForward =  20; //0 max speed forwards
int speedBackward = 70; //99 max speed backwards
int speedStop =     45; //stop

// Create DigiPot object
DigiPot pot(33, 31, 37);

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

/**
 * @brief The class for subscriber node
 * to listen to cmd_vel topic and
 * send values to servo and DigiPot
 */
class Delivery_Bot : public rclcpp::Node {
public:
    Delivery_Bot() : Node("delivery_bot_node") {
        init_hardware();
        cmd_vel_sub = this->create_subscription<geometry_msgs::msg::Twist>(
                "/cmd_vel", 10, std::bind(&Delivery_Bot::control_callback, this, _1));
    }

    ~Delivery_Bot() {
        // Close the I2C device
        set_pwm(0, 0, 314);
        close(i2c_fd_);
    }

private:
    void init_hardware() {
        // Set the PWM frequency
        pwm_freq_ = 60.0;
        steeringMap = Angle2ServoMap::create(pwm_freq_, 1.0, 2.0, 4095u);

        // Get the I2C device file descriptor
        i2c_fd_ = open("/dev/i2c-1", O_RDWR);
        while (i2c_fd_ < 0) {
            RCUTILS_LOG_ERROR_NAMED(get_name(), "Failed to open I2C device: %d, trying again in 1 sec.", i2c_fd_);
            usleep(1000000);
            i2c_fd_ = open("/dev/i2c-1", O_RDWR);
        }

        // Set the I2C slave address
        dev_address_ = I2C_ADDRESS;
        if (ioctl(i2c_fd_, I2C_SLAVE, dev_address_) < 0) {
            RCUTILS_LOG_ERROR_NAMED(get_name(), "Failed to set I2C slave address");
            return;
        }

        set_frequency(pwm_freq_);

        // Set the default PWM values
        set_pwm(0, 0, 314); // 314 count == 50 degrees servo

    }

    void set_frequency(uint16_t frequency) {
        /**
         * @brief Set frequency of the PWM (in Hz)
         * based on the formula from the datasheet
         *
         * @param[in] frequency         The frequency for which PWM should be set
         */

        uint8_t prescale = (uint8_t)(std::round(25000000.0 / (4096.0 * frequency)) - 1);
        write_reg(PCA9685_MODE1, 0b00010000);
        usleep(1000);
        write_reg(PCA9685_PRESCALE, prescale);
        write_reg(PCA9685_MODE1, 0b10100000);
        usleep(1000);
        // write_reg(PCA9685_MODE2, 0x00);
        // usleep(1000);
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

        write_reg(reg_offset, on_time_low);
        write_reg(reg_offset + 1, on_time_high);
        write_reg(reg_offset + 2, off_time_low);
        write_reg(reg_offset + 3, off_time_high);
    }

    void write_reg(uint8_t reg, uint8_t data) {
        /**
         * @brief                   Write a byte to the specified I2C register
         *
         * @param[in] reg           The register address to write to
         * @param[in] data          The data byte to be written to the register
         */

        uint8_t buf[2] = {reg, data};
        if (write(i2c_fd_, buf, 2) != 2) {
            RCUTILS_LOG_ERROR_NAMED(get_name(), "Failed to write I2C register value");
        }
    }

    uint8_t read_reg(uint8_t reg) {
        /**
         * @brief                   Read a byte from the specified I2C register
         *
         *
         * @param[in] reg           The register address to read from
         * @return                  The data byte read from the register
         */

        uint8_t buf[] = {reg};
        if (write(i2c_fd_, buf, 1) != 2) {
            RCUTILS_LOG_ERROR_NAMED(get_name(), "Failed to write I2C register value");
        }
        if (read(i2c_fd_, buf, 1) != 2) {
            RCUTILS_LOG_ERROR_NAMED(get_name(), "Failed to read I2C register value");
        }
        return buf[0];
    }

    void control_callback(const geometry_msgs::msg::Twist::SharedPtr msg) {
        /**
         * @brief Function to control callback when message arrives in cmd_vel topic
         *
         * @param[in] msg           Message of type Twist
         * msg->linear.x            Throttle
         * msg->angular.z           Servo
         */

        if (msg->linear.x > 0) {
            throttle(speedForward);
        } else if (msg->linear.x < 0) {
            throttle(speedBackward);
        } else if (msg->linear.x == 0) {
            throttle(speedStop);
        }

        if (msg->angular.z < 0 && angle <= servoMax) {
            angle += 3;
            steer(angle);
        } else if (msg->angular.z > 0 && angle >= servoMin) {
            angle -= 3;
            steer(angle);
        } else if (msg->angular.z == 0) {
            angle = servoMid;
            steer(angle);
        }
    }


    void steer(int angle) {
        /**
         * @brief Set the Steering object
         *
         * @param angle             Angle to move the servo to (0 to 180)
         */

        uint16_t pwm = (uint16_t)(std::round(steeringMap->calPwm(angle))) & 0x0FFF;
        RCLCPP_DEBUG(this->get_logger(), "STEERING %d, RAW %d", pwm, angle);
        set_pwm(STEER_PWM_CHANNEL, 0, pwm);
    }

    void throttle(int velocity) {
        /**
         * @brief Set the Steering object
         *
         * @param velocity          Velocity to move the robot with
         */

        pot.set(velocity);
    }

    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_sub;

    int i2c_fd_;
    uint8_t dev_address_;
    float pwm_freq_;
    int angle;
    Angle2ServoMap::Ptr steeringMap;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Delivery_Bot>());
    rclcpp::shutdown();
    return 0;
}