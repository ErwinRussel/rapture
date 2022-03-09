#!/bin/bash
apt-get install figlet 
figlet Rapture 
echo "Installing all dependencies for runc, containerd, docker and criu"

# -- apt packages (assumes git is installed)
apt-get update 
apt-get install wget libseccomp-dev -y

# first we must install the latest golang 
echo "____________________________"
echo "___________ GO _____________"
echo "____________________________"
wget -P /opt/go https://go.dev/dl/go1.17.8.linux-amd64.tar.gz
cd /opt/go
tar -C /usr/local -xzf go1.17.8.linux-amd64.tar.gz
export PATH=$PATH:/usr/local/go/bin
echo "-- installed version --" # todo make this an aassert
go version 

# -- docker
echo "________________________________"
echo "___________ DOCKER _____________"
echo "________________________________"
apt-get install ca-certificates curl gnupg lsb-release -y
curl -fsSL https://download.docker.com/linux/debian/gpg | sudo gpg --dearmor -o /usr/share/keyrings/docker-archive-keyring.gpg
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/docker-archive-keyring.gpg] https://download.docker.com/linux/debian \
  $(lsb_release -cs) stable" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
apt-get update 
apt-get install docker-ce docker-ce-cli -y
echo "{\"experimental\": true}" >> /etc/docker/daemon.json
echo "-- installed version --" # todo make this an assert
docker version 

# -- containerd 
echo "____________________________________"
echo "___________ CONTAINERD _____________"
echo "____________________________________"
wget -P /opt/containerd https://github.com/containerd/containerd/releases/download/v1.6.1/cri-containerd-cni-1.6.1-linux-amd64.tar.gz
cd /opt/containerd
sudo tar --no-overwrite-dir -C / -xzf cri-containerd-cni-1.6.1-linux-amd64.tar.gz
sudo systemctl daemon-reload
sudo systemctl enable --now containerd
echo "-- installed version --" # todo make this an assert
containerd --version

# -- runc
echo "______________________________"
echo "___________ RUNC _____________"
echo "______________________________"
git clone https://github.com/opencontainers/runc.git /opt/runc
apt-get install build-essential pkg-config -y # --no-install-recommends
cd /opt/runc 
make && make install 
echo "-- installed version --" 
runc --version 

# -- criu 
echo "______________________________"
echo "___________ CRIU _____________"
echo "______________________________"
apt-get install libprotobuf-dev libprotobuf-c-dev protobuf-c-compiler protobuf-compiler python-protobuf pkg-config python-ipaddress libbsd-dev iproute2 nftables libcap-dev libnet1-dev libnl-3-dev libaio-dev python3-future asciidoc xmlto vim python3-distutils libnftables-dev --no-install-recommends -y 
git clone https://github.com/checkpoint-restore/criu.git /opt/criu
cd /opt/criu 
make clean 
make 
make install 
echo "-- installed version --"
criu version --version
criu check 

echo "______________________________"
echo "___________ DONE _____________"
echo "______________________________"
sudo systemctl restart docker 
echo "Restarting Docker..."
sleep 5
echo "Check versions of Docker, ContainerD and Runc, restart if needed."
docker version 
