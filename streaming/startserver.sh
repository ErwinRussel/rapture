# Start the x server
echo "[RAPTURE] -- Starting X Server on Display :0"
startx -- :0 &

# Can you do this in bash script
export DISPLAY=:0

# Set display to a small size
xrandr -s 400x300

# Janus
echo "[RAPTURE] -- Starting Janus"
# /opt/janus/bin/janus &

# G streamer
echo "[RAPTURE] -- Starting Capturing Stream with GStreamer"
sh opt/rapture/gst.sh &

# Webinput
echo "[RAPTURE] -- Starting controller input server"
# python3 opt/rapture/inputserver.py &
