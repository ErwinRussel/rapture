import docker
import shortuuid
import time

client = docker.from_env()

def exec_command(command, container, node):
    name = "raptureCC"
    uuid = name + shortuuid.uuid()
    image = "erwinrussel/rapturecc:latest"
    mounts = ['/var/run/docker.sock:/var/run/docker.sock:rw']
    networks = ['rapture_monitoring']

    print("{}: Running {} on container {}".format(node, command, container))

    node_constr_str = "node.hostname=={}".format(node)
    restart_policy = docker.types.RestartPolicy(condition="none")
    ephemeral_service = client.services.create(image=image, command=command, name=uuid, restart_policy=restart_policy, constraints=[node_constr_str], mounts=mounts, labels={"CC": "1"}, networks=networks)
    print("Executed")
    time.sleep(1)
    print("Removing Service")
    ephemeral_service.remove()
    print("Service removed")


command = "docker run -d --rm alpine ping -c 5 8.8.8.8"
container = None
# command = "docker exec {} sh checkpoint.sh".format(container)
node = "rapture-gpu-node-1"

exec_command(command, container, node)