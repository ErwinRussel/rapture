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

RUN apt-get update && \
    apt-get install wget && \
    wget -P /opt/controller https://www.dropbox.com/s/l2lbrjqrycqryzf/Controller_Linux.tar.gz && \
    cd /opt/controller && \
    tar -xvf Controller_Linux.tar.gz && \
    cd Controller_Linux && \
    chmod +x controllertest.x86_64

WORKDIR /opt/controller/Controller_Linux

CMD if [ $(xrandr | grep \* | cut -d' ' -f4) = "1920x1080" ]; \ 
    then echo 'Resolution already HD'; \ 
    else xrandr -s ${RESOLUTION}; fi && \
    ./controllertest.x86_64 > /dev/null && \
    cat benchmark.txt