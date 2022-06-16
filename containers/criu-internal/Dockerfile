FROM debian

RUN apt-get update && apt-get install git ca-certificates build-essential \
    python build-essential pkg-config libseccomp-dev libprotobuf-dev libprotobuf-c-dev protobuf-c-compiler \
    protobuf-compiler libprotobuf-dev libprotobuf-c-dev protobuf-c-compiler libbsd-dev \
    iproute2 nftables libcap-dev libnet1-dev libnl-3-dev libaio-dev python3-future \
    asciidoc xmlto vim python3-distutils libnftables-dev --no-install-recommends -y 
    
# CRIU packages
RUN apt-get install python3-protobuf python3-ipaddr --no-install-recommends -y 

RUN git clone https://github.com/checkpoint-restore/criu.git /opt/criu && \
    cd /opt/criu && \
    make && \
    make install 

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

# Install libstrangle 
RUN git clone https://github.com/ErwinRussel/libstrangle.git /opt/strangle && \
    cd /opt/strangle && \
    make && \
    make install && \
    pip3 install -r promclient/requirements.txt

RUN git clone https://github.com/ErwinRussel/atlas.git /atlas && \
    cd /atlas/test/Glxgears/dev && \
    make clean && \
    make glxgears && \
    make all 

WORKDIR /atlas

CMD bash -c "sh run.sh"
