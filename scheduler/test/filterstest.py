import docker
import random

client = docker.from_env()

schedule = False

if __name__ == '__main__':
    CPU_RESERVE = 0
    MEM_RESERVE = 0
    if schedule:
        command = ["ping", "docker.com"]
        client.services.create(image='alpine', command=command, name="ping", labels={"TEST": "1"})

    services = client.services.list(filters=dict(label="TEST"))
    for service in services:
        print(service.name)