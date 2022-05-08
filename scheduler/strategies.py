import docker
import random


class Strategies:
    def __init__(self, client) -> None:
        super().__init__()

        self.client = client

    def dockerNodePs(self, machine_name):
        return [s.attrs['Spec']['Name'] for s in self.client.services.list() for _ in s.tasks({'node': machine_name, 'desired-state': 'Running'})]

    def get_availability_dict(self):
        nodes_dict = {}
        nodes = self.client.nodes.list()
        for node in nodes:
            node_dict ={}
            host_name = node.attrs['Description']['Hostname']
            node_dict['cpu_resource'] = node.attrs['Description']['Resources']['NanoCPUs'] # .get('NanoCPUs')
            node_dict['mem_resource'] = node.attrs['Description']['Resources']['MemoryBytes'] # ('MemoryBytes')
            node_dict['cpu_available'] = node_dict['cpu_resource']
            node_dict['mem_available'] = node_dict['mem_resource']
            nodes_dict[host_name] = node_dict

            services = self.client.services.list()
            for service in services:
                for task in service.tasks({'node': host_name, 'desired-state': 'Running'}):
                    cpu_reserved = task['Spec']['Resources']['Reservations'].get("NanoCPUs", 0)
                    mem_reserved = task['Spec']['Resources']['Reservations'].get("MemoryBytes", 0)
                    nodes_dict[host_name]['cpu_available'] -= cpu_reserved
                    nodes_dict[host_name]['cpu_available'] -= mem_reserved

        return nodes_dict

    def get_schedule_node_binpack(self, cpu_reserve, mem_reserve):
        node_dict = self.get_availability_dict()
        # todo: is this in correct order
        for node in node_dict.keys():
            if(node_dict[node]['cpu_available'] < cpu_reserve):
                continue
            if(node_dict[node]['mem_available'] < mem_reserve):
                continue
            return node
        return None

    def get_schedule_node_random(self, cpu_reserve, mem_reserve):
        # todo: get the availability of nodes
        node_dict = self.get_availability_dict()
        node_list = []
        for node in node_dict.keys():
            if(node_dict[node]['cpu_available'] < cpu_reserve):
                continue
            if(node_dict[node]['mem_available'] < mem_reserve):
                continue
            node_list.append(node)

        n = len(node_list)
        if n == 0:
            return None
        i = random.randrange(0,n)
        return node_list[i]

    def get_schedule_node_rapture(self, cpu_reserve, mem_reserve):
        # get all nodes
        node_dict = self.get_availability_dict()
        # todo: filter all nodes

        # for every node remove with no CPU left

        # for every node remove with no mem left

        # for every node get NVSMI --> remove with no VRAM left
        # my_label_config = {'cluster': 'my_cluster_id', 'label_2': 'label_2_value'}
        # prom.get_current_metric_value(metric_name='up', label_config=my_label_config)
        #
        # # Here, we are fetching the values of a particular metric name
        # prom.custom_query(query="prometheus_http_requests_total")

        # for every node get framesleep expose --> remove with no framesleep / fps left

        # todo: choose the node that is most occupied
        # to do that we need the node with 1. sort: tightest VRAM 2. sort: the tightest framesleep
        # thus we need {node{VRAM_left= },{FPS_left= }.
        # We can do this with viking village on Vulkan and DXVK.


# Todo: with own algorithm, choose the most full node
# Todo: Binpack: expose nvsmi and framesleep

# if __name__ == '__main__':
#     CPU_RESERVE = 0
#     MEM_RESERVE = 0
#     node = get_schedule_node_binpack(CPU_RESERVE,MEM_RESERVE)
#
#     if node is None:
#         print("No node to schedule")
#         exit(0)
#
#     print("Scheduling on " + str(node))
#     cont_resources = docker.types.Resources(cpu_reservation=50000000, mem_reservation=40000000)
#     command = ["ping", "docker.com"]
#     # todo: We do no not add this constraint when scheduling with spread, only with binpack
#     constr_str = "node.hostname==" + node
#     client.services.create(image='alpine', command=command, name="ping", resources=cont_resources, constraints=[constr_str])




