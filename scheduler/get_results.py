# todo: get the results from the past test
from prometheus_api_client import PrometheusConnect

prom = PrometheusConnect(url="http://localhost:9090", disable_ssl=True)

# Import the required datetime functions
from prometheus_api_client.utils import parse_datetime
from datetime import timedelta

start_time = parse_datetime("2d")
end_time = parse_datetime("now")
chunk_size = timedelta(days=1)

metric_data = prom.get_metric_range_data(
    "up{cluster='my_cluster_id'}",  # this is the metric name and label config
    start_time=start_time,
    end_time=end_time,
    chunk_size=chunk_size,
)


# One must make a call to prometheus

# TODO: write this down on paper before

#Amount of instances per node

#CPU resources per node

#MEM resources per node

#VRAM resources per node

#GPU mem resources per node

#Ratio of idle machines per containers (compactness)?

#

# avg framerate of instances

# lowest framerate of instances

# highest framerate of instances

# number of instances crashed

# number of framesleep violations on a node. 