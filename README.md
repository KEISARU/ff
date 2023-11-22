# Delivery Bot

## Installation

1. [Install ROS 2](https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debians.html)
2. Install ROS 2 development tools
    ```
    sudo apt update && sudo apt install -y \
      build-essential \
      cmake \
      git \
      libbullet-dev \
      python3-colcon-common-extensions \
      python3-flake8 \
      python3-pip \
      python3-pytest-cov \
      python3-rosdep \
      python3-setuptools \
      python3-vcstool \
      openssh-server \
      wget
    ```
3. Git clone the repository and install dependencies
   ```
   git clone https://github.com/yerikvaliyev/delivery_ws.git
   cd ~/delivery_ws
   vcs import src < delivery_bot.repos
   source /opt/ros/humble/setup.bash
   rosdep update
   rosdep install --from-paths src --ignore-src -r -y --rosdistro humble
   ```
4. Build Package
   ```
   cd ~/delivery_ws
   source /opt/ros/humble/setup.bash
   colcon build --symlink-install --executor sequential
   source ~/delivery_ws/install/local_setup.bash
   ```