# Rapture

A GPU-aware cloud gaming infrastructure platform built as part of a master's thesis (2022). Rapture schedules, streams, and live-migrates containerised game workloads across a Docker Swarm cluster, with the goal of maximising GPU node utilisation while maintaining Quality-of-Service (QoS) guarantees for players.

---

## Table of Contents

- [Background](#background)
- [Architecture](#architecture)
- [Repository Structure](#repository-structure)
- [Components](#components)
  - [Scheduler](#scheduler)
  - [Migrater](#migrater)
  - [FPS Collector](#fps-collector)
  - [Streaming & Input](#streaming--input)
  - [Containers](#containers)
  - [Monitoring Stack](#monitoring-stack)
- [Scheduling Strategies](#scheduling-strategies)
- [Game Container Catalog](#game-container-catalog)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Environment Setup](#environment-setup)
  - [Docker Swarm Configuration](#docker-swarm-configuration)
  - [Deploy the Monitoring Stack](#deploy-the-monitoring-stack)
  - [Running the Scheduler](#running-the-scheduler)
- [Experiments](#experiments)
- [Metrics & Observability](#metrics--observability)

---

## Background

Cloud gaming offloads game rendering to remote servers and streams the resulting video to a thin client (browser, set-top box, phone). Each game session requires a dedicated GPU context, which makes bin-packing and live migration of game containers fundamentally different from ordinary cloud workloads.

Rapture investigates three questions:

1. Which container-placement strategy (spread, binpack, random, or the custom *Rapture* strategy) achieves the best balance between GPU utilisation and per-session FPS QoS?
2. Can CRIU-based live container migration consolidate underutilised nodes without violating QoS?
3. How does a 4D resource model (CPU, RAM, VRAM, frame-time budget) change placement decisions compared to a standard 2D model (CPU, RAM)?

---

## Architecture

```
┌──────────────────────────────────────────────────────────┐
│                     Docker Swarm                         │
│                                                          │
│  ┌─────────────┐    ┌──────────────────────────────┐    │
│  │   Manager   │    │         Worker Nodes          │    │
│  │             │    │  ┌────────┐  ┌────────┐       │    │
│  │  Scheduler  │───▶│  │ Game   │  │ Game   │  ...  │    │
│  │  Migrater   │    │  │  Cont. │  │  Cont. │       │    │
│  │  Prometheus │    │  └───┬────┘  └───┬────┘       │    │
│  │  Grafana    │    │      │            │            │    │
│  └─────────────┘    │  ┌───▼────────────▼──────┐    │    │
│                     │  │  libstrangle (FPS cap) │    │    │
│                     │  │  + Prometheus client   │    │    │
│                     │  └────────────────────────┘    │    │
│                     └──────────────────────────────┘    │
│                                                          │
│  ┌─────────────────────────────────────────────────┐    │
│  │  Monitoring (prometheus, grafana, cadvisor,      │    │
│  │  node-exporter, nvsmi-exporter, fps-collector)   │    │
│  └─────────────────────────────────────────────────┘    │
└──────────────────────────────────────────────────────────┘

           Game video ──▶ GStreamer ──▶ Janus WebRTC ──▶ Browser
           Gamepad input ◀── WebSocket ◀── inputserver.py ◀── Browser
```

Each game container bundles a GPU-rendered game, a custom fork of [libstrangle](https://github.com/ErwinRussel/libstrangle) that caps FPS and pushes per-frame timing metrics, and (optionally) a CRIU installation for live checkpointing.

---

## Repository Structure

```
rapture/
├── containers/
│   ├── rapture/
│   │   ├── rapturebase/        # Base image: Vulkan, Janus, GStreamer, libstrangle
│   │   └── raptureviking/      # Viking Village game on top of rapturebase
│   ├── linux/viking/           # Standalone Vulkan Viking Village image
│   ├── dxvk/dxvkviking/        # Windows Viking Village via Wine + DXVK
│   ├── atlasgears/             # GLX gears benchmark with CRIU + libstrangle
│   ├── criutest/               # Containers for testing CRIU checkpoint/restore
│   ├── nvsmi/                  # nvidia-smi Prometheus exporter
│   ├── promlibstrangle/        # libstrangle Prometheus client image
│   └── vulkan/                 # vkcube / vulkaninfo smoke-test images
├── scheduler/
│   ├── scheduler.py            # Core scheduler: place game containers on nodes
│   ├── strategies.py           # Spread / Binpack / Random / Rapture placement logic
│   ├── migrater.py             # Utilisation-driven live migration
│   ├── rap_sched.py            # Prometheus query helpers for GPU metrics
│   ├── game_container_catalog.json  # Registry of supported games + resource requirements
│   ├── fps_collector/          # Flask + Prometheus push-gateway for FPS metrics
│   ├── prometheus/             # Prometheus scrape config
│   ├── monitor.yaml            # Docker Stack: Prometheus, Grafana, cAdvisor, exporters
│   ├── exec_test.py            # Experiment driver (no migration)
│   ├── exec_test_migrate.py    # Experiment driver (with migration)
│   ├── gen_random_test.py      # Generate random workload trace
│   ├── gen_sine_test.py        # Generate sinusoidal workload trace
│   ├── get_prom_data.py        # Scrape and dump Prometheus data after an experiment
│   └── test_*.json             # Pre-generated workload traces
├── streaming/
│   ├── gst.sh                  # GStreamer VP8/RTP capture pipeline
│   ├── startserver.sh          # Boot X server, GStreamer, Janus, input server
│   ├── inputserver.py          # WebSocket → evdev gamepad virtualisation
│   └── requirements.txt
├── cr_environment_install.sh   # One-shot host setup: Go, Docker, containerd, runc, CRIU
└── docker-compose.yml          # Quick single-node test compose file
```

---

## Components

### Scheduler

`scheduler/scheduler.py`

The `Scheduler` class wraps the Docker SDK and manages the lifecycle of game services in a Docker Swarm. It:

- Reads game specs from `game_container_catalog.json` (image, env vars, CPU/RAM/VRAM/frame-time requirements, mounts).
- Delegates node selection to `Strategies` based on the active strategy enum.
- Creates Docker Swarm services with GPU constraints (`node.labels.gpu-node == 1`) and resource reservations/limits.
- Tracks available resources per node in memory and adjusts them on schedule/deschedule.
- Cleans up all running game services on exit via `atexit`.

```python
from scheduler import Scheduler, StrategyEnum

scheduler = Scheduler(StrategyEnum.rapture)
game_spec = scheduler.get_game_spec("Viking_Village_Linux")
scheduler.schedule_game(game_spec)
scheduler.deschedule_game()
```

### Migrater

`scheduler/migrater.py`

The `Migrater` class implements the node-consolidation loop. It is called periodically during an experiment run:

1. **Utilisation score** — for each node, compute the maximum utilisation ratio across all four resource dimensions (CPU, RAM, VRAM, frame-time). Average across all nodes.
2. **Trigger** — if the average score falls below the configurable threshold `alpha` (e.g. 0.7), the cluster is considered under-utilised.
3. **Evacuation** — identify the least-loaded node (most free resources) and migrate all game services off it by checkpointing (via CRIU) and rescheduling them elsewhere using the Rapture strategy.

```python
from migrater import Migrater

migrater = Migrater(scheduler, alpha=0.7)
migrater.check_migrate()  # call in the experiment loop
```

### FPS Collector

`scheduler/fps_collector/fps_exporter.py`

A dual-port Flask + Prometheus service:

| Port | Purpose |
|------|---------|
| 8000 | Prometheus `/metrics` scrape endpoint |
| 8001 | HTTP POST `/push_metric` — receives JSON payloads from the [libstrangle](https://github.com/ErwinRussel/libstrangle) Prometheus client running inside each game container |

Metrics exposed (labelled by `hostname` and `container_name`):

| Metric | Description |
|--------|-------------|
| `fps` | Current frames per second |
| `target_fps` | FPS cap set by libstrangle |
| `achievable_fps` | Maximum FPS the GPU could sustain without the cap |
| `free_fps` | Headroom above the cap |
| `sleep_time` | Limiter sleep in nanoseconds |
| `adjusted_sleep_time` | Sleep after drift correction |
| `overhead` | Limiter overhead in nanoseconds |
| `target_frame_time` | Target frame duration in nanoseconds |
| `frame_overhead` | Actual frame duration minus adjusted sleep |

Metrics are automatically garbage-collected 15 seconds after a container stops sending data.

### Streaming & Input

`streaming/`

**Video streaming** uses GStreamer to capture the X11 display and encode it as VP8 over RTP/UDP to a local port, which Janus WebRTC then forwards to the browser:

```
ximagesrc → videoscale/videorate/videoconvert → vp8enc → rtpvp8pay → udpsink :5004
```

**Input** is handled by `inputserver.py`, a Flask-SocketIO server that translates WebSocket messages from the browser into Linux kernel input events via `evdev`/`UInput`. Both analogue axes (left/right sticks, triggers) and digital buttons are supported.

```
Browser gamepad API → WebSocket → inputserver.py → UInput → /dev/input → game
```

`startserver.sh` orchestrates the full stack: X server, `xrandr` display sizing, GStreamer pipeline, Janus, and the input server.

### Containers

| Image | Base | Game | Notes |
|-------|------|------|-------|
| `rapturebase` | `nvidia/vulkan:1.1.121` | — | Vulkan tools, Janus WebRTC, GStreamer, [libstrangle](https://github.com/ErwinRussel/libstrangle), evdev input server |
| `raptureviking` | `rapturebase` | Viking Village (Linux/Vulkan) | Full streaming stack |
| `linux/viking` | `nvidia/vulkan:1.1.121` | Viking Village (Linux/Vulkan) | Lightweight, [libstrangle](https://github.com/ErwinRussel/libstrangle) + Prometheus client |
| `dxvk/dxvkviking` | `nvidia/vulkan:1.1.121` | Viking Village (Windows/.exe) | Wine + DXVK (DirectX→Vulkan), [libstrangle](https://github.com/ErwinRussel/libstrangle) |
| `atlasgears` | `nvidia/vulkan:1.1.121` | GLX gears benchmark | CRIU + custom [atlas](https://github.com/ErwinRussel/atlas) benchmark harness |

All game containers accept environment variables:

| Variable | Default | Description |
|----------|---------|-------------|
| `FPS` | — | Target FPS cap passed to libstrangle |
| `RESOLUTION` | — | Display resolution (e.g. `1920x1080`) |
| `SLEEP` | `0` | Seconds to wait before starting the game (stagger start) |
| `DISPLAY` | `:0` | X display to render to |

### Monitoring Stack

`scheduler/monitor.yaml` deploys a Docker Stack with:

| Service | Image | Purpose |
|---------|-------|---------|
| `prometheus` | `prom/prometheus` | Metrics store, manager node only |
| `grafana` | `grafana/grafana` | Dashboards, manager node only |
| `node-exporter` | `prom/node-exporter` | Host CPU/RAM/disk/net metrics, all workers |
| `cadvisor` | `google/cadvisor` | Per-container resource metrics, all workers |
| `nvsmi-exporter` | `erwinrussel/nvsmiprom` | Per-GPU VRAM, utilisation, temperature, all workers |
| `fps-collector` | `erwinrussel/fps_collector` | FPS push gateway + Prometheus exporter, manager |

---

## Scheduling Strategies

All strategies require that a candidate node has `node.labels.gpu-node == 1`.

### Spread

Delegates placement entirely to Docker Swarm's built-in spread scheduler. No resource tracking beyond what Swarm provides. Used as a baseline.

### Binpack

Iterates the in-memory node resource dictionary and returns the **first** node that satisfies both the CPU and RAM reservation. Nodes are checked in insertion order, creating a bin-packing effect where earlier nodes are filled before later ones are considered.

### Random

Builds the list of nodes that satisfy CPU and RAM requirements and selects one **uniformly at random**. Used as a second baseline.

### Rapture (custom)

The thesis contribution. Extends binpack with two additional resource dimensions:

- **VRAM** — GPU video memory reservation
- **Frame-time budget** — a proxy for GPU compute headroom; expressed in nanoseconds

Candidate nodes must satisfy all four constraints. Eligible nodes are then sorted ascending by all four dimensions (frame-time as the primary sort key) and the node with the **least available resources** is chosen — i.e. the node that is most loaded but still has capacity. This minimises fragmentation while respecting QoS constraints.

The frame-time budget (`ftime_available`) is intended to be driven by real-time Prometheus data from the `adjusted_sleep_time` metric exported by [libstrangle](https://github.com/ErwinRussel/libstrangle) (partially implemented in `rap_sched.py`).

---

## Game Container Catalog

`scheduler/game_container_catalog.json` is the registry of playable games. Each entry specifies:

```json
{
  "name": "Viking_Village_Linux",
  "image": "erwinrussel/vulkanviking:experiment",
  "env": ["DISPLAY=:0", "FPS=30", "RESOLUTION=1920x1080", "SLEEP=0"],
  "requirements": {
    "cpu_req":       1000000000,
    "mem_req":        500000000,
    "vmem_req":      1500000000,
    "fps_req":               30,
    "frametime_req":  300000000,
    "resolution_req": "1920x1080"
  },
  "ports": {
    "stream":    5004,
    "input_ws":  5008,
    "fps_metrics": 8000
  },
  "mounts": ["/tmp/.X11-unix:/tmp/.X11-unix:rw"]
}
```

Resource values are in Docker's nanosecond/byte units (1 CPU core = `1_000_000_000` NanoCPUs, 1 GiB = `1_073_741_824` bytes).

---

## Getting Started

### Prerequisites

- Linux host(s) with NVIDIA GPU(s)
- NVIDIA drivers installed
- Docker Swarm cluster (1 manager + N workers)
- Workers labelled with `docker node update --label-add gpu-node=1 <hostname>`
- Python 3.8+

### Environment Setup

Run the provided install script on **every node** (manager and workers) to install a compatible Go, Docker, containerd, runc, and the custom CRIU build with GPU checkpoint support:

```bash
sudo bash cr_environment_install.sh
```

This script:
1. Downloads and installs Go 1.17.8
2. Installs Docker CE with experimental mode enabled (required for `docker checkpoint`)
3. Installs containerd 1.6.1
4. Builds runc from source
5. Builds the custom CRIU fork from `https://github.com/ErwinRussel/criu`

### Docker Swarm Configuration

Apply the required Docker daemon changes on every node (`/etc/docker/daemon.json`):

```json
{
  "metrics-addr": "0.0.0.0:4999",
  "experimental": true
}
```

Expose the Docker API over TCP on workers (replace the `ExecStart` line in `/lib/systemd/system/docker.service`):

```
ExecStart=/usr/bin/dockerd -H fd:// -H tcp://0.0.0.0:2375 --containerd=/run/containerd/containerd.sock
```

Reload and restart:

```bash
sudo systemctl daemon-reload && sudo systemctl restart docker
```

Allow X11 connections from the containers on each worker:

```bash
xhost +si:localuser:root
```

### Deploy the Monitoring Stack

From the manager node:

```bash
cd scheduler
docker stack deploy --compose-file monitor.yaml rapture-monitoring
```

Verify all services are running:

```bash
docker stack ps rapture-monitoring
```

Access dashboards:

| Service | URL |
|---------|-----|
| Prometheus | `http://<manager-ip>:9090` |
| Grafana | `http://<manager-ip>:3000` |

### Running the Scheduler

Install Python dependencies on the manager node:

```bash
cd scheduler
pip3 install -r requirements.txt
```

**Run an experiment without migration** (e.g. using the Rapture strategy with a random workload trace):

```bash
python3 exec_test.py
```

Edit `exec_test.py` to select a different strategy or workload trace (`test_*.json`).

**Run an experiment with migration** (Rapture strategy + consolidation at alpha=0.7):

```bash
python3 exec_test_migrate.py
```

**Generate a new workload trace:**

```bash
python3 gen_random_test.py   # Random arrivals
python3 gen_sine_test.py     # Sinusoidal load pattern
```

**Scrape Prometheus data after an experiment:**

```bash
python3 get_prom_data.py
```

Results are written to `experiment_data/` as JSON files, one per metric.

---

## Experiments

Pre-generated workload traces are included:

| File | Description |
|------|-------------|
| `test_random_1_6.json` | Random arrivals, max 6 concurrent sessions |
| `test_random_1_9.json` | Random arrivals, max 9 concurrent sessions |
| `test_sine_0_6.json` | Sinusoidal load, peak 6 sessions |
| `test_sine_0_9.json` | Sinusoidal load, peak 9 sessions |
| `test_onenode.json` | Single-node sanity check |
| `test_migratefast.json` | Fast migration stress test |

Each trace is a JSON array of `{ "time": <seconds>, "desired_instances": <N> }` events. The experiment drivers replay these events in real time against the live cluster.

---

## Metrics & Observability

Key Prometheus queries used for evaluation:

| Metric | Query |
|--------|-------|
| Per-container FPS | `fps` |
| Nodes with active sessions | `count(sum by(instance) (nvidia_smi_memory_used_bytes/nvidia_smi_memory_total_bytes) > 0.14)` |
| Sessions per node | `count by(instance) (container_tasks_state{image="...", state="running"})` |
| FPS QoS violations | `count by(hostname) (fps < 25)` |
| CPU utilisation | `sum by(instance) (rate(node_cpu_seconds_total{mode!="idle"}[1m])) / <num_cores>` |
| RAM utilisation | `sum by(instance) (node_memory_Active_bytes / node_memory_MemTotal_bytes)` |
| VRAM utilisation | `sum by(instance) (nvidia_smi_memory_used_bytes / nvidia_smi_memory_total_bytes)` |
| GPU compute utilisation | `sum by(instance) (nvidia_smi_utilization_gpu_ratio)` |
| Average FPS per node | `avg by(hostname) (fps)` |
| Minimum FPS per node | `min by(hostname) (fps)` |
