import docker
import random
# from rap_sched import get_gpu_metrics


class Strategies:
    def __init__(self, client) -> None:
        super().__init__()

        self.client = client
        self.node_resource_dict = self.get_node_resource_dict()

    def dockerNodePs(self, machine_name):
        return [s for s in self.client.services.list() for _ in s.tasks({'node': machine_name, 'desired-state': 'Running'})]

    def dockerGamePs(self, machine_name):
        return [s for s in self.client.services.list(filters=dict(label="GAME")) for _ in s.tasks({'node': machine_name, 'desired-state': 'Running'})]

    def get_node_resource_dict(self):
        node_dict = {}
        nodes = self.client.nodes.list(filters={'role': 'worker'})
        for node in nodes:
            name = node.attrs['Description']['Hostname']
            node_entry = {}
            if(node.attrs['Status']['State'] != 'ready'):
                print("node {} is down".format(name))
                continue
            node_entry['address'] = node.attrs['Status']['Addr']
            node_entry['cpu_available'] = node.attrs['Description']['Resources']['NanoCPUs']
            node_entry['mem_available'] = node.attrs['Description']['Resources']['MemoryBytes']
            node_entry['vmem_available'] = 8000000000
            node_entry['ftime_available'] = 1000000000 # Change into this
            node_entry['cpu_total'] = node_entry['cpu_available']
            node_entry['mem_total'] = node_entry['mem_available']
            node_entry['vmem_total'] = node_entry['vmem_available']
            node_entry['ftime_total'] = node_entry['ftime_available']

            node_dict[name] = node_entry

        return node_dict

    def get_schedule_node_binpack(self, cpu_reserve, mem_reserve):
        nodes_resources = self.node_resource_dict
        # todo: is this in correct order
        for node in nodes_resources.keys():
            if(nodes_resources[node]['cpu_available'] < cpu_reserve):
                continue
            if(nodes_resources[node]['mem_available'] < mem_reserve):
                continue
            return node
        return None

    def get_schedule_node_random(self, cpu_reserve, mem_reserve):
        nodes_resources = self.node_resource_dict
        node_list = []
        for node in nodes_resources.keys():
            if(nodes_resources[node]['cpu_available'] < cpu_reserve):
                continue
            if(nodes_resources[node]['mem_available'] < mem_reserve):
                continue
            node_list.append(node)

        n = len(node_list)
        if n == 0:
            return None
        i = random.randrange(0,n)
        return node_list[i]

    def get_schedule_node_rapture(self, cpu_reserve, mem_reserve, vmem_reserve, frametime_reserve):
        node_dict = self.node_resource_dict
        node_dict_list = []
        # VRAM_free, avg_adj_st = get_gpu_metrics()
        for node in node_dict.keys():
            if(node_dict[node]['cpu_available'] < cpu_reserve):
                continue
            if(node_dict[node]['mem_available'] < mem_reserve):
                continue
            if(node_dict[node]['vmem_available'] < vmem_reserve):
                continue
            if(node_dict[node]['ftime_available'] < frametime_reserve):
                continue
            entry = node_dict[node]
            entry['name'] = node
            node_dict_list.append(entry)

        n = len(node_dict_list)
        if n == 0:
            return None

        sort1 = sorted(node_dict_list, key=lambda d: d['mem_available'])
        sort2 = sorted(sort1, key=lambda d: d['vmem_available'])
        sort3 = sorted(sort2, key=lambda d: d['cpu_available'])
        sort4 = sorted(sort3, key=lambda d: d['ftime_available'])

        return sort4[0]['name']

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




