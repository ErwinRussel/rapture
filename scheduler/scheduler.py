import docker
import random
import shortuuid
import atexit
import json
from strategies import Strategies

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
        self.strategies = Strategies(self.client)\

    def get_game_spec(self, name):
        game_db = []
        with open('game_container_catalog.json', 'r') as j:
            game_db = json.loads(j.read())

        game_spec = next(item for item in game_db if item["name"] == name)
        return game_spec

    def cleanup_handler(self):
        services = self.client.services.list(filters=dict(label="TEST"))
        for service in services:
            service.remove()
        print("- all cleaned up!")

    # Add reserves
    def get_node_strategy(self):
        if(self.strategy==StrategyEnum.spread):
            print("Executing spread strategy")
            return None

        elif(self.strategy==StrategyEnum.binpack):
            print("Executing binpack strategy")
            return self.strategies.get_schedule_node_binpack(0,0)

        elif(self.strategy==StrategyEnum.random):
            print("Executing random strategy")
            return self.strategies.get_schedule_node_random(0,0)

        elif(self.strategy==StrategyEnum.rapture):
            print("Executing rapture strategy")
            return self.strategies.get_schedule_node_rapture(0,0)

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

        node = self.get_node_strategy()

        # endpoint_spec = {
        #                     'Ports': [
        #                         {
        #                             'Protocol': 'tcp',
        #                             'PublishedPort': port,
        #                             'TargetPort': 8888
        #                         },
        #                     ]
        #                 },

        cont_resources = docker.types.Resources(cpu_reservation=cpu_req, mem_reservation=mem_req)
        uuid = name + shortuuid.uuid()
        if (self.strategy != StrategyEnum.spread):
            if node is None:
                print("No node to schedule")
                return

            print("Scheduling {} on node {}".format(uuid, str(node)))
            constr_str = "node.hostname=={}".format(node)
            self.client.services.create(image=image, command=command, name=uuid, env=envir, resources=cont_resources,
                               mounts=mounts, constraints=[constr_str], labels={"TEST": "1"})
        else:
            print("Scheduling {} spread".format(uuid))
            self.client.services.create(image=image, command=command, name=uuid, env=envir, resources=cont_resources,
                                        mounts=mounts, labels={"TEST": "1"})

    def deschedule_game(self):
        services = self.client.services.list(filters=dict(label="TEST"))
        i = random.randrange(0, len(services))
        desch_service = services[i]
        print("Removing service: {}".format(desch_service.name))
        desch_service.remove()

    def get_current_instances(self):
        return len(self.client.services.list(filters=dict(label="TEST")))


