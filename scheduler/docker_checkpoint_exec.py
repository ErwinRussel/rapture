import docker

client = docker.from_env()

services = client.services.list(filters=dict(label="GAME"))

service = services[0]

print(service.tasks)

container = client.containers.get(cont_id)

# command = ['sh checkpoint.sh']
# container.exec_run(command,detach=True)