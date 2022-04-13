FROM debian

RUN apt-get update && apt-get install mesa-utils libxt6 xauth x11-xkb-utils xkb-data --no-install-recommends -y

RUN apt-get install wget -y && \
    wget -P /opt/turbovnc https://sourceforge.net/projects/turbovnc/files/2.2.7/turbovnc_2.2.7_amd64.deb && \
    cd /opt/turbovnc && \
    dpkg -i turbovnc_2.2.7_amd64.deb

CMD /opt/TurboVNC/bin/vncserver -securitytypes TLSNone,X509None,None :1 && \
    export DISPLAY=:1 && \
    glxgears