import time
import random
import json

# Constants
MIN_INSTANCES = 1
MAX_INSTANCES = 9
TEST_DURATION_SEC = 1200 # 20 mins
MIN_PER = 30
MAX_PER = 60

# We should create a similar profile for all of the tests
if __name__ == '__main__':
    # todo: key, value -> t_sec: num_instances
    tot_time = 0
    test = []
    while(tot_time < TEST_DURATION_SEC):
        entry = {}
        amnt_instances = random.randrange(MIN_INSTANCES,MAX_INSTANCES + 1)
        entry['time'] = tot_time
        entry['desired_instances'] = amnt_instances
        test.append(entry)
        period = random.randrange(MIN_PER, MAX_PER+1)
        tot_time += period

    json_object = json.dumps(test, indent=4)
    with open('test1.json', 'w') as f:
        f.write(json_object)
    print(json_object)
    # todo: Schedule x amount of containers
