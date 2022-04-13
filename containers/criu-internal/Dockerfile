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


