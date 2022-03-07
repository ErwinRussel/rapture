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
    git \
    cmake \
    python3 \
    x11-utils \
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

WORKDIR /usr/local/bin

CMD vkcube

