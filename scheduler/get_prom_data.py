# This code snippet was taken from https://github.com/WybeKoper/PASAF/blob/master/data_processing/b_get_experiment_results.py

from prometheus_api_client import PrometheusConnect, MetricsList, Metric, MetricSnapshotDataFrame, MetricRangeDataFrame
from prometheus_api_client.utils import parse_datetime
from datetime import timedelta

def scrape_data(prometheus_host_ip, test):
    prom = PrometheusConnect(url = "http://" + prometheus_host_ip + ":9090", disable_ssl=True)

    start_time = parse_datetime("30m")
    end_time = parse_datetime("now")

    metric_query_dict = {
        "Mem_utilization_ratio": "node_memory_Active_bytes/node_memory_MemTotal_bytes",
        "Vram_utilization_ratio": "nvidia_smi_memory_used_bytes/nvidia_smi_memory_total_bytes",
    }

    # "FPS": "fps",
    # "sleepTime": "sleeptime"


    for metric in metric_query_dict:
        print("Retrieving data for: ", metric)

        metric_data = prom.custom_query_range(
            query=metric_query_dict[metric],
            start_time=start_time,
            end_time=end_time,
            step="5s",
        )

        metric_data[0]['metric'] = {'__name__': metric}

        metric_df = MetricRangeDataFrame(metric_data)

        metric_df.to_csv("experiment_data/" + test + "/" + metric + ".csv")