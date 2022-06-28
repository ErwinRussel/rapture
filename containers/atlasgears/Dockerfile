FROM nvidia/vulkan:1.1.121

# we need this ffor some reason?
RUN rm /etc/apt/sources.list.d/cuda.list
RUN rm /etc/apt/sources.list.d/nvidia-ml.list

# GET GL STUFF
RUN apt-get update && apt-get install mesa-utils --no-install-recommends -y 

RUN apt-get install ca-certificates wget libxt6 xauth x11-xkb-utils xkb-data --no-install-recommends -y 

RUN apt-get update && apt-get install -y -qq --no-install-recommends \
    libglvnd0 \
    libgl1 \
    libglx0 \
    libegl1 \
    libxext6 \
    libx11-6 \
    libxtst6 \
    libxv1 \
    libegl1-mesa \
    libglu1-mesa \
    && rm -rf /var/lib/apt/lists/*

# CRIU STUFFß
RUN apt-get update && apt-get install git ca-certificates build-essential \
    python build-essential pkg-config libseccomp-dev libprotobuf-dev libprotobuf-c-dev protobuf-c-compiler \
    protobuf-compiler libprotobuf-dev libprotobuf-c-dev protobuf-c-compiler libbsd-dev \
    iproute2 nftables libcap-dev libnet1-dev libnl-3-dev libaio-dev python3-future \
    asciidoc xmlto vim python3-distutils nftables --no-install-recommends -y 
    
# CRIU packages
RUN apt-get install python3-protobuf python-ipaddr --no-install-recommends -y 

RUN git clone https://github.com/checkpoint-restore/criu.git /opt/criu && \
    cd /opt/criu && \
    make && \
    make install 

# Install libstrangle 
RUN apt-get install -y --no-install-recommends \ 
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
    xterm \
    libx11-xcb-dev \
    libxkbcommon-dev \
    libwayland-dev \
    libxrandr-dev \
    wayland-protocols && \
    rm -rf /var/lib/apt/lists/*

RUN git clone https://github.com/ErwinRussel/libstrangle.git /opt/strangle && \
    cd /opt/strangle && \
    make && \
    make install && \
    pip3 install -r promclient/requirements.txt

# atlas
RUN echo "rebuild17" && \
    git clone https://github.com/ErwinRussel/atlas.git /atlas && \
    cd /atlas/test/Glxgears/dev && \
    make clean && \
    make glxgears && \
    make all 

WORKDIR /atlas

CMD nohup bash -c "python3 /opt/strangle/promclient/promclient.py &" && \
    sh run.sh