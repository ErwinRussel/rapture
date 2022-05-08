# https://github.com/AICoE/prometheus-api-client-python
from prometheus_api_client import PrometheusConnect

prom = PrometheusConnect(url="http://localhost:9090", disable_ssl=True)

def print_all_metrics():
    # Get the list of all the metrics that the Prometheus host scrapes
    print(prom.all_metrics())

def time_series_data_specific_metric():
    my_label_config = {'cluster': 'my_cluster_id', 'label_2': 'label_2_value'}
    prom.get_current_metric_value(metric_name='up', label_config=my_label_config)

    # Here, we are fetching the values of a particular metric name
    prom.custom_query(query="prometheus_http_requests_total")

    # Now, lets try to fetch the `sum` of the metrics
    prom.custom_query(query="sum(prometheus_http_requests_total)")

def get_prometheus_for_a_time_span():
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

# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    print_all_metrics()