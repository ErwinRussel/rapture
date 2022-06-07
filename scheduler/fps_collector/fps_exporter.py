from prometheus_client import start_http_server, Summary, Gauge
import random
import time
from os.path import exists
from flask import Flask, request
from multiprocessing import Process
import sys

app = Flask(__name__)
g_sleep_time = Gauge('sleep_time', 'Sleep of the limiter in nanoseconds', ['hostname', 'container_name'])
g_overhead = Gauge('overhead', 'Overhead of the limiter in nanoseconds', ['hostname', 'container_name'])
g_target_frame_time = Gauge('target_frame_time', 'Target frame time of the limiter in nanoseconds',
                            ['hostname', 'container_name'])
g_fps = Gauge('fps', 'Current frames per second of application', ['hostname', 'container_name'])
g_adjusted_sleep_time = Gauge('adjusted_sleep_time', 'Adjusted sleep of the limiter in nanoseconds',
                              ['hostname', 'container_name'])
g_achievable_fps = Gauge('achievable_fps', 'Achievable frames per second of application',
                         ['hostname', 'container_name'])
g_free_fps = Gauge('free_fps', 'Free frames per second of the limiter', ['hostname', 'container_name'])
g_target_fps = Gauge('target_fps', 'Frames per second set by strangle', ['hostname', 'container_name'])
g_frame_overhead = Gauge('frame_overhead', 'Nano time of duration of frame', ['hostname', 'container_name'])

timeout_dict = {}
TIMEOUT_S = 15


def cleanup_metrics():
    delete_list = []
    for container_name in timeout_dict.keys():
        t = timeout_dict[container_name]['last_seen']
        host_name = timeout_dict[container_name]['host_name']
        if t <= (time.time() - TIMEOUT_S):
            print("Deleting metrics")
            delete_metric(host_name, container_name)
            delete_list.append(container_name)

    for container in delete_list:
        timeout_dict.pop(container)


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

    if adjusted_sleep_time and fps != 0:
        frame_overhead = (1000000000 / fps) - adjusted_sleep_time
        g_frame_overhead.labels(host_name, container_name).set(frame_overhead)

    timeout_dict[container_name] = {'host_name': host_name, 'last_seen': time.time()}
    cleanup_metrics()


def delete_metric(host_name, container_name):
    g_sleep_time.remove(host_name, container_name)
    g_overhead.remove(host_name, container_name)
    g_target_frame_time.remove(host_name, container_name)
    g_adjusted_sleep_time.remove(host_name, container_name)
    g_target_fps.remove(host_name, container_name)
    g_fps.remove(host_name, container_name)
    g_achievable_fps.remove(host_name, container_name)
    g_free_fps.remove(host_name, container_name)
    g_frame_overhead.remove(host_name, container_name)


@app.route('/push_metric', methods=['POST'])
def handle_data():
    data = request.json
    data['host_name'] = request.remote_addr
    process(data)
    return "success"


@app.route('/delete_metric', methods=['POST'])
def delete_data():
    # data = request.json
    # data['host_name'] = request.remote_addr
    # delete_metric(data)
    return "success"


if __name__ == '__main__':
    # Start up the server to expose the metrics.
    start_http_server(8000)
    app.run(host='0.0.0.0', port=8001)