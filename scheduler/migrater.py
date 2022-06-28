import shortuuid
import docker
import time


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
            score = max(score, (node_dict[node]['cpu_total'] - node_dict[node]['cpu_available']) / node_dict[node]['cpu_total'])
            score = max(score, (node_dict[node]['mem_total'] - node_dict[node]['mem_available']) / node_dict[node]['mem_total'])
            score = max(score, (node_dict[node]['vmem_total'] - node_dict[node]['vmem_available']) / node_dict[node]['vmem_total'])
            score = max(score, (node_dict[node]['ftime_total'] - node_dict[node]['ftime_available']) / node_dict[node]['ftime_total'])
            # If score is 0, all is available, the node is not utilized.
            if score == 0:
                score = 0.91
            # if score > 0.7:
            #     continue

            score_list.append(score)

        # Return 1 if only one node
        if len(score_list) <= 1:
            return 1
        else:
            print(score_list)

        return sum(score_list) / len(score_list)

    def get_evac_node(self):
        node_dict = self.node_resource_dict

        node_dict_list = []
        for node in node_dict.keys():
            if(node_dict[node]['cpu_available'] == node_dict[node]['cpu_total']):
                continue
            if(node_dict[node]['mem_available'] == node_dict[node]['mem_total']):
                continue
            if(node_dict[node]['vmem_available'] == node_dict[node]['vmem_total']):
                continue
            if(node_dict[node]['ftime_available'] == node_dict[node]['ftime_total']):
                continue
            entry = node_dict[node]
            entry['name'] = node
            node_dict_list.append(entry)

        n = len(node_dict_list)
        if n == 0:
            return None

        sort1 = sorted(node_dict_list, key=lambda d: d['mem_available'], reverse=True)
        sort2 = sorted(sort1, key=lambda d: d['vmem_available'], reverse=True)
        sort3 = sorted(sort2, key=lambda d: d['cpu_available'], reverse=True)
        sort4 = sorted(sort3, key=lambda d: d['ftime_available'], reverse=True)

        return sort4[0]['name']

    def check_migrate(self):
        utl_score = self.get_util_score()
        # print("Util score: {}".format(utl_score))
        if utl_score < self.alpha:
            evac_node = self.get_evac_node()
            self.migrate(evac_node)

    # todo: migrating sequence
    def migrate(self, evac_node):
        # use that dockerNodePs functionn to get these serices
        evac_services = self.scheduler.strategies.dockerGamePs(evac_node)

        for service in evac_services:
            self.deschedulecheckpoint(service)
            game_spec = self.scheduler.get_game_spec("Viking_Village_Linux")
            self.scheduler.schedule_game(game_spec)

    def schedulerestore(self, game_spec):
        # print("Restoring service: {}".format(service.name))
        name = game_spec['name']
        print("Restoring service: {}".format(name))
        image = game_spec['image']
        envir = game_spec['env'].append("ATL_RESTORE=1")
        cpu_req = game_spec['requirements']['cpu_req']
        mem_req = game_spec['requirements']['mem_req']
        vmem_req = game_spec['requirements']['vmem_req']
        frametime_req = game_spec['requirements']['frametime_req']
        command = ['bash -c "run.sh"']
        mounts = game_spec['mounts']

        node = self.scheduler.get_node_strategy(cpu_req, mem_req, vmem_req, frametime_req)
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
        self.scheduler.add_limitations(node)
        node_constr_str = "node.hostname=={}".format(node)
        self.scheduler.client.services.create(image=image, command=command, name=uuid, env=envir, resources=cont_resources,
                                    mounts=mounts, constraints=[gpu_constr_str, node_constr_str],
                                    labels={"GAME": "1"}, endpoint_spec=endpoint_spec, networks=networks)



    def deschedulecheckpoint(self, desch_service):
        print("Checkpointing service: {}".format(desch_service.name))
        host_name = self.scheduler.get_hostname_service(desch_service)

        # todo: add container
        container = None
        command = ['sh checkpoint.sh']
        self.exec_command(command, container, host_name)

        # todo: remove
        print("Evacuating service: {}".format(desch_service.name))
        self.scheduler.remove_limitations(host_name)
        # if DEBUG:
        #     self.print_resources()
        desch_service.remove()

    def exec_command(self, command, container, node):
        name = "raptureCC"
        uuid = name + shortuuid.uuid()
        image = "erwinrussel/rapturecc:latest"
        mounts = ['/var/run/docker.sock:/var/run/docker.sock:rw']
        networks = ['rapture_monitoring']

        print("{}: Running {} on container {}".format(node, command, container))

        node_constr_str = "node.hostname=={}".format(node)
        restart_policy = docker.types.RestartPolicy(condition="none")
        ephemeral_service = self.scheduler.client.services.create(image=image, command=command, name=uuid,
                                                   restart_policy=restart_policy, constraints=[node_constr_str],
                                                   mounts=mounts, labels={"CC": "1"}, networks=networks)
        print("Executed")
        time.sleep(1)
        print("Removing Service")
        ephemeral_service.remove()
        print("Service removed")


