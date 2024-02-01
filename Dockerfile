FROM ros:humble AS rsbase
SHELL ["/bin/bash", "-c"]
RUN apt update && apt install -y i2c-tools \
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
  wget \
  python3-cffi \
  python3-aiohttp \
  libavformat-dev \
  libavcodec-dev \
  libavdevice-dev \
  libavutil-dev \
  libswscale-dev \
  libswresample-dev \
  libavfilter-dev \
  libopus-dev \
  libvpx-dev \
  pkg-config \
  libsrtp2-dev \
  python3-opencv \
  pulseaudio \
  ffmpeg \
  libsm6 \
  libxext6 \
  ros-humble-librealsense2-* \ 
  ros-humble-realsense2-*
RUN pip install numpy rtcbot crc32c aiortc aiohttp opencv-python

FROM rsbase AS rscontrol
SHELL ["/bin/bash", "-c"]

RUN git clone https://github.com/pjueon/JetsonGPIO.git && \
  cd JetsonGPIO && \ 
  git checkout v1.2.5 && \
  mkdir build && cd build && \
  cmake .. -DBUILD_EXAMPLES=OFF -DJETSON_GPIO_POST_INSTALL=OFF && \
  cmake --build . --target install && \
  cd / && rm -rf JetsonGPIO
