# vkcube sample compiled from https://github.com/KhronosGroup/Vulkan-Tools

# docker build -t vkcube .
# xhost +si:localuser:root

# Docker >= 19.03
# docker run --gpus all -ti --rm -e DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix vkcube

# Docker < 19.03
# docker run --runtime=nvidia -ti --rm -e DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix vkcube

FROM nvidia/vulkan:1.1.121

ENV NVIDIA_DRIVER_CAPABILITIES ${NVIDIA_DRIVER_CAPABILITIES},display

RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    cmake \
    clang \
    libgtk2.0-dev \
    libgtk-3-dev \
    qt5-default \
    git \
    python3 \
    x11-utils \
    wget \
    xterm && \
    rm -rf /var/lib/apt/lists/*

RUN ln -s /usr/bin/python3 /usr/bin/python && \
    git clone https://github.com/KhronosGroup/Vulkan-Tools.git /opt/Vulkan-Tools && \
    cd /opt/Vulkan-Tools && \
    mkdir build && cd build && \
    ../scripts/update_deps.py && \
    cmake -C helper.cmake .. && \
    cmake --build . && \
    make install 

RUN apt install wget && \
    wget -P /opt/GravityMark https://tellusim.com/download/GravityMark_1.31.run && \
    cd /opt/GravityMark && \
    chmod +x GravityMark_1.31.run && \
    yes | ./GravityMark_1.31.run --confirm --noexec

WORKDIR /opt/GravityMark/GravityMark_1.31_linux/bin

ENV DISPLAY "$DISPLAY"

CMD ./GravityMark.x64 -temporal 1 -fps 1 -width 1920 -height 1080 -info 1 -sensors 1 -benchmark 1 -close 1 -screen $DISPLAY -vk

