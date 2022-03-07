# vulkaninfo sample compiled from https://github.com/KhronosGroup/Vulkan-Tools

# docker build -t vulkaninfo .

# Docker >= 19.03
# docker run --gpus all --rm vulkaninfo

# Docker < 19.03
# docker run --runtime=nvidia --rm vulkaninfo

# apt-get install libx11-dev
## apt-get install libgl1-mesa-dev
# apt-get install xorg-dev

FROM nvidia/vulkan:1.1.121

RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    git \
    cmake \
    python3 && \
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

CMD vulkaninfo

