import docker
import random
import shortuuid
import atexit
import json
from strategies import Strategies

DEBUG = True

class StrategyEnum:
    spread = 1
    binpack = 2
    random = 3
    rapture = 4

class Scheduler:

    def __init__(self, strategy) -> None:
        super().__init__()
        self.client = docker.from_env()

        atexit.register(self.cleanup_handler)
        self.strategy = strategy
        self.cleanup_handler()

        # Get strategies
        self.strategies = Strategies(self.client)

        # Set service id list
        self.service_ids = [1,2,3,4]

    def get_game_spec(self, name):
        game_db = []
        with open('game_container_catalog.json', 'r') as j:
            game_db = json.loads(j.read())

        game_spec = next(item for item in game_db if item["name"] == name)
        return game_spec

    def get_serv_id(self):
        if len(self.service_ids) <= 0:
            print("no service ids left")
            return random.randrange(10,80)
        id = self.service_ids[0]
        self.service_ids.remove(id)
        return id

    def add_serv_id(self, id):
        if id in self.service_ids:
            print("id already in list")
            return
        self.service_ids.append(id)

    def cleanup_handler(self):
        services = self.client.services.list(filters=dict(label="GAME"))
        for service in services:
            service.remove()
        print("- all cleaned up!")

    # Add reserves
    def get_node_strategy(self, cpu_req, mem_req):
        if(self.strategy==StrategyEnum.spread):
            print("Executing spread strategy")
            return None

        elif(self.strategy==StrategyEnum.binpack):
            print("Executing binpack strategy")
            return self.strategies.get_schedule_node_binpack(cpu_req,mem_req)

        elif(self.strategy==StrategyEnum.random):
            print("Executing random strategy")
            return self.strategies.get_schedule_node_random(cpu_req,mem_req)

        elif(self.strategy==StrategyEnum.rapture):
            print("Executing rapture strategy")
            return self.strategies.get_schedule_node_rapture(cpu_req,mem_req)

        else:
            print("No strategy chose")
            return None

    # todo: add label to running container
    def schedule_game(self, game_spec):
        name = game_spec['name']
        image = game_spec['image']
        envir = game_spec['env']
        cpu_req = game_spec['requirements']['cpu_req']
        mem_req = game_spec['requirements']['mem_req']
        command = game_spec.get('command', '')
        mounts = game_spec['mounts']

        node = self.get_node_strategy(cpu_req, mem_req)
        networks = ['rapture_monitoring']
        uuid = name + shortuuid.uuid()
        # cur_id = self.get_serv_id()
        # uuid = "rapture_game_" + str(cur_id)
        # dynamic_port = 8000 + cur_id
        # endpoint_spec = docker.types.EndpointSpec(ports={dynamic_port:8000})
        endpoint_spec = docker.types.EndpointSpec()
        gpu_constr_str = "node.labels.gpu-node == 1"
        cont_resources = docker.types.Resources(cpu_reservation=cpu_req, cpu_limit=cpu_req, mem_reservation=mem_req, mem_limit=mem_req)
        if (self.strategy != StrategyEnum.spread):
            if node is None:
                print("No node to schedule")
                return

            print("Scheduling {} on node {}".format(uuid, str(node)))
            self.add_limitations(node)
            node_constr_str = "node.hostname=={}".format(node)
            self.client.services.create(image=image, command=command, name=uuid, env=envir, resources=cont_resources,
                               mounts=mounts, constraints=[gpu_constr_str, node_constr_str], labels={"GAME": "1"}, endpoint_spec=endpoint_spec, networks=networks)
        else:
            print("Scheduling {} spread".format(uuid))
            self.client.services.create(image=image, command=command, name=uuid, env=envir, resources=cont_resources,
                                mounts=mounts, constraints=[gpu_constr_str], labels={"GAME": "1"}, endpoint_spec=endpoint_spec, networks=networks)

        if DEBUG:
            self.print_resources()

    def print_resources(self):
        print("#### CURRENT RESOURCES ####")
        print("NAME     CPU      RAM     VRAM    FTime")
        resources = self.strategies.node_resource_dict
        for node in resources.keys():
            cpu = resources[node]["cpu_available"]
            mem = resources[node]["mem_available"]
            vmem = resources[node]["vmem_available"]
            ftime = resources[node]["ftime_available"]
            print("{}:{},{},{},{}".format(node, cpu, mem, vmem, ftime))

    def deschedule_game(self):
        services = self.client.services.list(filters=dict(label="GAME"))
        i = random.randrange(0, len(services))
        desch_service = services[i]
        print("Removing service: {}".format(desch_service.name))
        # host_name = ""
        # self.remove_limitations(host_name)
        if DEBUG:
            self.print_resources()
        desch_service.remove()
        # id = self.add_serv_id(int(desch_service.name[-1]))

    # toto: change this to get from the game DB
    def add_limitations(self, host_name):
        self.strategies.node_resource_dict[host_name]['cpu_available'] -= 1000000000
        self.strategies.node_resource_dict[host_name]['mem_available'] -= 500000000
        self.strategies.node_resource_dict[host_name]['vmem_available'] -= 200000000
        self.strategies.node_resource_dict[host_name]['ftime_available'] -= 300000000

    # todo: change this to get from the game DB
    def remove_limitations(self, host_name):
        self.strategies.node_resource_dict[host_name]['cpu_available'] += 1000000000
        self.strategies.node_resource_dict[host_name]['mem_available'] += 500000000
        self.strategies.node_resource_dict[host_name]['vmem_available'] += 200000000
        self.strategies.node_resource_dict[host_name]['ftime_available'] += 300000000

    def get_current_instances(self):
        return len(self.client.services.list(filters=dict(label="GAME")))


