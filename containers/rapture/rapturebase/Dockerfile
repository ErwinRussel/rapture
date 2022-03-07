# vkcube sample compiled from https://github.com/KhronosGroup/Vulkan-Tools

# docker build -t vkcube .
# xhost +si:localuser:root

# Docker >= 19.03
# docker run --gpus all -ti --rm -e DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix vkcube

# Docker < 19.03
# docker run --runtime=nvidia -ti --rm -e DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix vkcube

FROM nvidia/vulkan:1.1.121

ENV NVIDIA_DRIVER_CAPABILITIES ${NVIDIA_DRIVER_CAPABILITIES},display

# For now, keep all of these 
RUN apt-get update && apt-get install -y --no-install-recommends \ 
    build-essential \
    cmake \
    clang \
    git \
    python3 \
    python3-pip \
    x11-utils \
    x11-xserver-utils \
    gcc-multilib \
    g++-multilib \
    libx11-dev \
    mesa-common-dev \
    xterm && \
    rm -rf /var/lib/apt/lists/*

RUN ln -s /usr/bin/python3 /usr/bin/python && \
    git clone https://github.com/KhronosGroup/Vulkan-Tools.git /opt/Vulkan-Tools && \
    cd /opt/Vulkan-Tools && \
    mkdir build && cd build && \
    python ../scripts/update_deps.py && \
    cmake -C helper.cmake .. && \
    cmake --build . && \
    make install 

# Install Janus Dependencies
RUN apt-get update && apt-get install -y --no-install-recommends libmicrohttpd-dev libjansson-dev \
	libssl-dev libsrtp-dev libsofia-sip-ua-dev libglib2.0-dev \
	libopus-dev libogg-dev libcurl4-openssl-dev liblua5.3-dev \
	libconfig-dev pkg-config gengetopt libtool automake 

RUN git clone https://gitlab.freedesktop.org/libnice/libnice /opt/libnice && \
    cd /opt/libnice && \
    pip3 install meson ninja && \
    meson --prefix=/usr build && ninja -C build && ninja -C build install 
    # # Install libsrtp
    # # This should be into a folder
RUN apt-get update && \
    apt-get install wget && \
    wget -P /opt/libsrtp https://github.com/cisco/libsrtp/archive/v2.2.0.tar.gz && \ 
    cd /opt/libsrtp && \
    tar xfv v2.2.0.tar.gz && cd libsrtp-2.2.0 && \
    ./configure --prefix=/usr --enable-openssl && \
    make shared_library && make install

# Install Janus
RUN git clone https://github.com/meetecho/janus-gateway.git /opt/janus-gateway && \
    cd /opt/janus-gateway && \
    sh autogen.sh && ./configure --prefix=/opt/janus && make && make install && make configs

# Install GStreamer
RUN apt-get -y --no-install-recommends install libgstreamer1.0-0 \
    gstreamer1.0-plugins-base gstreamer1.0-plugins-good \
    gstreamer1.0-plugins-bad gstreamer1.0-plugins-ugly \
    gstreamer1.0-libav gstreamer1.0-doc gstreamer1.0-tools \
    gstreamer1.0-x gstreamer1.0-alsa gstreamer1.0-gl \
    gstreamer1.0-gtk3 gstreamer1.0-qt5 gstreamer1.0-pulseaudio

# Install InputStreamer and rapture tools
RUN git clone https://github.com/ErwinRussel/rapture.git /opt/rapture && \
    cd /opt/rapture && \
    apt-get install python3-setuptools python-dev python-pip -y --no-install-recommends && \
    pip3 install setuptools flask flask_socketio 
# MISSING EVDEV, NEED OTHER PACKAGES WHICH DO NOT WORK https://python-evdev.readthedocs.io/en/latest/install.html

# Install libstrangle 
RUN git clone https://gitlab.com/torkel104/libstrangle.git /opt/strangle && \
    cd /opt/strangle && \
    make && \
    make install 


