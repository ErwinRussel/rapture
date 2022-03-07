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
    git checkout d15ff77bda1ef895ea5cf23d19472b7442e878cb && \
    mkdir build && cd build && \
    python ../scripts/update_deps.py && \
    cmake -C helper.cmake .. && \
    cmake --build . && \
    make install 

RUN apt-get update && \
    apt-get install wget && \
    wget -P /opt/viking https://www.dropbox.com/s/hk80lbdujzpfp72/Viking_Linux.tar.gz && \
    cd /opt/viking && \
    tar -xvf Viking_Linux.tar.gz && \
    cd Viking_Linux && \
    chmod +x Viking_Village.x86_64

# Install libstrangle 
RUN git clone https://gitlab.com/torkel104/libstrangle.git /opt/strangle && \
    cd /opt/strangle && \
    make && \
    make install 

# Create a directory for dumping benchmark and later to mount to
RUN mkdir /opt/output

WORKDIR /opt/viking/Viking_Linux

CMD if [ $(xrandr | grep \* | cut -d' ' -f4) = "1920x1080" ]; \ 
    then echo 'Resolution already HD'; \ 
    else xrandr -s ${RESOLUTION}; fi && \
    sleep ${SLEEP} && \
    echo 'Benchmark started' && \
    strangle ${FPS} ./Viking_Village.x86_64 > /dev/null && \
    mv ./fps.csv /opt/output/fps.csv && \
    cat benchmark.txt




