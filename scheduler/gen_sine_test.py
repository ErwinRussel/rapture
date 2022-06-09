import time
import random
import json
from itertools import cycle

# Constants
MIN_INSTANCES = 0
MAX_INSTANCES = 9
TEST_DURATION_SEC = 1200 # 20 mins
MIN_PER = 30
MAX_PER = 30
# We should create a similar profile for all of the tests
if __name__ == '__main__':
    # todo: key, value -> t_sec: num_instances
    tot_time = 0
    test = []
    i = 1
    while(tot_time < TEST_DURATION_SEC):
        entry = {}
        amnt_instances = -abs(MAX_INSTANCES - (i % (2*MAX_INSTANCES))) + MAX_INSTANCES
        i += 1
        entry['time'] = tot_time
        entry['desired_instances'] = amnt_instances
        test.append(entry)
        period = random.randrange(MIN_PER, MAX_PER+1)
        tot_time += period

    json_object = json.dumps(test, indent=4)
    with open('test_sine_0_6.json', 'w') as f:
        f.write(json_object)
    print(json_object)
    # todo: Schedule x amount of containers
