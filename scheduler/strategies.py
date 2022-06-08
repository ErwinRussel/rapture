import docker
import random
# from rap_sched import get_gpu_metrics


class Strategies:
    def __init__(self, client) -> None:
        super().__init__()

        self.client = client

    def dockerNodePs(self, machine_name):
        return [s.attrs['Spec']['Name'] for s in self.client.services.list() for _ in s.tasks({'node': machine_name, 'desired-state': 'Running'})]

    def get_availability_dict(self):
        avail_nodes_dict = {}
        nodes = self.client.nodes.list()
        for node in nodes:
            node_dict ={}
            host_name = node.attrs['Description']['Hostname']
            node_dict['cpu_resource'] = node.attrs['Description']['Resources']['NanoCPUs'] # .get('NanoCPUs')
            node_dict['mem_resource'] = node.attrs['Description']['Resources']['MemoryBytes'] # ('MemoryBytes')
            node_dict['cpu_available'] = node_dict['cpu_resource']
            node_dict['mem_available'] = node_dict['mem_resource']
            avail_nodes_dict[host_name] = node_dict

            services = self.client.services.list()
            for service in services:
                for task in service.tasks({'node': host_name, 'desired-state': 'Running'}):
                    print(task['Spec']['Resources'])
                    cpu_reserved = task['Spec']['Resources']['Reservations'].get("NanoCPUs", 0)
                    mem_reserved = task['Spec']['Resources']['Reservations'].get("MemoryBytes", 0)
                    avail_nodes_dict[host_name]['cpu_available'] -= cpu_reserved
                    avail_nodes_dict[host_name]['cpu_available'] -= mem_reserved

        return avail_nodes_dict

    def get_schedule_node_binpack(self, cpu_reserve, mem_reserve):
        nodes_dict = self.get_availability_dict()
        # todo: is this in correct order
        for node in nodes_dict.keys():
            if(nodes_dict[node]['cpu_available'] < cpu_reserve):
                continue
            if(nodes_dict[node]['mem_available'] < mem_reserve):
                continue
            return node
        return None

    def get_schedule_node_random(self, cpu_reserve, mem_reserve):
        nodes_dict = self.get_availability_dict()
        node_list = []
        for node in nodes_dict.keys():
            if(nodes_dict[node]['cpu_available'] < cpu_reserve):
                continue
            if(nodes_dict[node]['mem_available'] < mem_reserve):
                continue
            node_list.append(node)

        n = len(node_list)
        if n == 0:
            return None
        i = random.randrange(0,n)
        return node_list[i]

    def get_schedule_node_rapture(self, cpu_reserve, mem_reserve, vmem_reserve, frametime_reserve):
        node_dict = self.get_availability_dict()
        node_list = []
        # VRAM_free, avg_adj_st = get_gpu_metrics()
        for node in node_dict.keys():
            if(node_dict[node]['cpu_available'] < cpu_reserve):
                continue
            if(node_dict[node]['mem_available'] < mem_reserve):
                continue
            # if(VRAM_free < vmem_reserve):
            #     continue
            # if(avg_adj_st < frametime_reserve):
            #     continue

            # todo: put this in new dict to sort
            node_list.append(node)


        # todo: sort by cpu
        # todo: sort by mem
        # todo: sort by vmem
        # todo: sort by aast

        return node

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




