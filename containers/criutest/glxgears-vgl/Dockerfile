FROM nvidia/vulkan:1.1.121

RUN apt-get update && apt-get install mesa-utils --no-install-recommends -y 

RUN apt-get install ca-certificates wget libxt6 xauth x11-xkb-utils xkb-data --no-install-recommends -y && \
    wget -P /opt/turbovnc https://sourceforge.net/projects/turbovnc/files/2.2.7/turbovnc_2.2.7_amd64.deb && \
    cd /opt/turbovnc && \
    dpkg -i turbovnc_2.2.7_amd64.deb

RUN apt-get install libxtst6 libxv1 libegl1-mesa libglu1-mesa --no-install-recommends -y && \
    wget -P /opt/virtualgl https://sourceforge.net/projects/virtualgl/files/3.0/virtualgl_3.0_amd64.deb && \
    cd /opt/virtualgl && \
    dpkg -i virtualgl_3.0_amd64.deb

ENV DISPLAY=:1

CMD /opt/TurboVNC/bin/vncserver -securitytypes TLSNone,X509None,None :1 && \
    vglrun /opt/VirtualGL/bin/glxspheres64