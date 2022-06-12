import shortuuid
import docker


class Migrater:
    def __init__(self, scheduler, alpha) -> None:
        super().__init__()
        self.scheduler = scheduler
        self.alpha = alpha
        self.node_resource_dict = scheduler.strategies.node_resource_dict

    # todo: we always schedule with rapture

    def get_util_score(self):
        node_dict = self.node_resource_dict
        score_list = []
        for node in node_dict.keys():
            score = 0
            score = max(score, node_dict[node]['cpu_available']/node_dict[node]['cpu_total'])
            score = max(score, node_dict[node]['mem_available']/node_dict[node]['mem_total'])
            score = max(score, node_dict[node]['vmem_available']/node_dict[node]['vmem_total'])
            score = max(score, node_dict[node]['ftime_available']/node_dict[node]['ftime_total'])

            # todo: do not append when utilization = 0
            score_list.append(score)

        return sum(score_list) / len(score_list)

    def check_migrate(self):
        if self.get_util_score() < self.alpha:
            self.migrate(evac_node)




    # todo: migrating sequence
    def migrate(self, evac_node):
        # use that dockerNodePs functionn to get these serices
        evac_services = self.scheduler.strategies.dockerNodePs(self, evac_node)

        for service in evac_services:
            self.deschedulecheckpoint(service)
            self.schedulerestore(service)

    def schedulerestore(self, service):
        # todo: add env variables for
        envir = ["RESTORE=TRUE"]
        print("Restoring service: {}".format(service.name))
        name = game_spec['name']
        image = game_spec['image']
        envir.append(game_spec['env'])
        cpu_req = game_spec['requirements']['cpu_req']
        mem_req = game_spec['requirements']['mem_req']
        vmem_req = game_spec['requirements']['vmem_req']
        frametime_req = game_spec['requirements']['frametime_req']
        command = game_spec.get('command', '')
        mounts = game_spec['mounts']

        node = self.get_node_strategy(cpu_req, mem_req, vmem_req, frametime_req)
        networks = ['rapture_monitoring']
        uuid = name + shortuuid.uuid()
        endpoint_spec = docker.types.EndpointSpec()
        gpu_constr_str = "node.labels.gpu-node == 1"
        cont_resources = docker.types.Resources(cpu_reservation=cpu_req, cpu_limit=cpu_req, mem_reservation=mem_req,
                                                mem_limit=mem_req)
        if node is None:
            print("No node to schedule")
            return

        print("Scheduling {} on node {}".format(uuid, str(node)))
        self.add_limitations(node)
        node_constr_str = "node.hostname=={}".format(node)
        self.client.services.create(image=image, command=command, name=uuid, env=envir, resources=cont_resources,
                                    mounts=mounts, constraints=[gpu_constr_str, node_constr_str],
                                    labels={"GAME": "1"}, endpoint_spec=endpoint_spec, networks=networks)



    def deschedulecheckpoint(self, desch_service):
        # todo: add exec command to checkpoint and write to file
        print("Checkpointing service: {}".format(desch_service.name))

        # todo: remove
        print("Evacuating service: {}".format(desch_service.name))
        host_name = self.scheduler.get_hostname_service(desch_service)
        self.scheduler.remove_limitations(host_name)
        # if DEBUG:
        #     self.print_resources()
        desch_service.remove()


