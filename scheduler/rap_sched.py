# This code snippet was taken from https://github.com/WybeKoper/PASAF/blob/master/data_processing/b_get_experiment_results.py

from prometheus_api_client import PrometheusConnect

# todo: set docker url
prom = PrometheusConnect(url = "http://172.0.0.1:9090", disable_ssl=True)

def get_gpu_metrics():
    VRAM_free = prom.custom_query(query="sum by(instance) (nvidia_smi_memory_total_bytes - nvidia_smi_memory_used_bytes)")
    avg_adj_st = prom.custom_query(query="avg by(hostname) (adjusted_sleep_time)")

    return VRAM_free, avg_adj_st