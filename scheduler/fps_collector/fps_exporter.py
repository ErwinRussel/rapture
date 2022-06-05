from prometheus_client import start_http_server, Summary, Gauge
import random
import time
from os.path import exists
from flask import Flask, request

app = Flask(__name__)

# PROM STUFF

file_exists = False
sleep_time = 0
overhead = 0
target_frame_time = 0
test_time = 0
FILE = "./strangle.prom"

g_sleep_time = Gauge('sleep_time', 'Sleep of the limiter in nanoseconds', ['hostname', 'container_name'])
g_overhead = Gauge('overhead', 'Overhead of the limiter in nanoseconds', ['hostname', 'container_name'])
g_target_frame_time = Gauge('target_frame_time', 'Target frame time of the limiter in nanoseconds', ['hostname', 'container_name'])
g_fps = Gauge('fps', 'Current frames per second of application', ['hostname', 'container_name'])
g_adjusted_sleep_time = Gauge('adjusted_sleep_time', 'Adjusted sleep of the limiter in nanoseconds', ['hostname', 'container_name'])
g_achievable_fps = Gauge('achievable_fps', 'Achievable frames per second of application', ['hostname', 'container_name'])
g_free_fps = Gauge('free_fps', 'Free frames per second of the limiter', ['hostname', 'container_name'])
g_target_fps = Gauge('target_fps', 'Frames per second set by strangle', ['hostname', 'container_name'])

def process(data):
    host_name = data.get('host_name', '')
    container_name = data.get('container_name', '')

    sleep_time = data.get('sleep_time', 0)
    overhead = data.get('overhead', 0)
    target_frame_time = data.get('target_frame_time', 0)
    adjusted_sleep_time = data.get('adjusted_sleep_time', 0)
    target_fps = data.get('target_fps', 0)
    fps = data.get('fps', 0)
    achievable_fps = data.get("achievable_fps", 0)
    free_fps = data.get('free_fps', 0)

    if sleep_time != 0:
        g_sleep_time.labels(host_name, container_name).set(sleep_time)

    if overhead != 0:
        g_overhead.labels(host_name, container_name).set(overhead)

    if target_frame_time != 0:
        g_target_frame_time.labels(host_name, container_name).set(target_frame_time)

    if adjusted_sleep_time != 0:
        g_adjusted_sleep_time.labels(host_name, container_name).set(adjusted_sleep_time)

    if target_fps != 0:
        g_target_fps.labels(host_name, container_name).set(target_fps)

    if fps != 0:
        g_fps.labels(host_name, container_name).set(fps)

    if achievable_fps != 0:
        g_achievable_fps.labels(host_name, container_name).set(achievable_fps)

    if free_fps != 0:
        g_free_fps.labels(host_name, container_name).set(free_fps)

def delete_metric(data):
    host_name = data.get('host_name', '')
    container_name = data.get('container_name', '')
    g_sleep_time.remove(host_name, container_name)
    g_overhead.remove(host_name, container_name)
    g_target_frame_time.remove(host_name, container_name)
    g_adjusted_sleep_time.remove(host_name, container_name)
    g_target_fps.remove(host_name, container_name)
    g_fps.remove(host_name, container_name)
    g_achievable_fps.remove(host_name, container_name)
    g_free_fps.remove(host_name, container_name)

@app.route('/push_metric', methods=['POST'])
def handle_data():
    data = request.json
    process(data)
    return "success"

@app.route('/delete_metric', methods=['POST'])
def delete_data():
    data = request.json
    delete_metric(data)
    return "success"

if __name__ == '__main__':
    # Start up the server to expose the metrics.
    start_http_server(8000)
    app.run(host='0.0.0.0', port=8001)