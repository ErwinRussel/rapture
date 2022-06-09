# This code snippet was taken from https://github.com/WybeKoper/PASAF/blob/master/data_processing/b_get_experiment_results.py

from prometheus_api_client import PrometheusConnect, MetricsList, Metric, MetricSnapshotDataFrame, MetricRangeDataFrame
from prometheus_api_client.utils import parse_datetime
from datetime import timedelta

def scrape_data(prometheus_host_ip, test, strategy):
    prom = PrometheusConnect(url = "http://" + prometheus_host_ip + ":9090", disable_ssl=True)

    start_time = parse_datetime("30m")
    end_time = parse_datetime("now")

    metric_query_dict = {
        "FPS_cont": "fps",
        "Num_utilized_nodes": "count(nvidia_smi_utilization_gpu_ratio > 0.1) OR on() vector(0)",
        "Num_game_instances_node": "count by(instance) (container_tasks_state{image=\"erwinrussel/vulkanviking:experiment\", state=\"running\"})",
        "Num_violating_cont_node": "count by(hostname) (fps < 25)",
        "CPU_utl_node": "sum by(instance) (rate(node_cpu_seconds_total{mode!=\"idle\"}[1m]))/4",
        "RAM_utl_node": "sum by(instance) (node_memory_Active_bytes/node_memory_MemTotal_bytes)",
        "VRAM_utl_node": "sum by(instance) (nvidia_smi_memory_used_bytes/nvidia_smi_memory_total_bytes)",
        "GPU_utl_node": "sum by(instance) (nvidia_smi_utilization_gpu_ratio)",
        "Avg_FPS_node": "avg by(hostname) (fps)",
        "Min_FPS_node": "min by(hostname) (fps)"
    }

    for metric in metric_query_dict:
        print("Retrieving data for: ", metric)

        metric_data = prom.custom_query_range(
            query=metric_query_dict[metric],
            start_time=start_time,
            end_time=end_time,
            step="5s",
        )

        # metric_data[0]['metric'] = {'__name__': metric}

        # metric_df = MetricRangeDataFrame(metric_data)

        with open("experiment_data/" + test + "/" + strategy + "/" + metric + ".json", "w") as f:
            f.write(str(metric_data))

        # metric_df.to_csv("experiment_data/" + test + "/" + metric + ".csv")


scrape_data("", "random_1_9", "spread")