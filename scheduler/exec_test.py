from scheduler import Scheduler, StrategyEnum
import time
import json

if __name__ == '__main__':
    # todo: set this with argv
    scheduler = Scheduler(StrategyEnum.rapture)

    #todo: load game container db
    game_name = "atlasgears"
    game_spec = scheduler.get_game_spec(game_name)

    print("-- Cleaning up before test --")
    scheduler.cleanup_handler()

    otest = []
    with open('test_random_1_9.json', 'r') as j:
        test = json.loads(j.read())
        otest = sorted(test, key = lambda i: i['time'])

    print("-- Starting test --")
    start_time = time.time()

    # test loop
    n = len(otest)
    k = 0
    while(k < n):
        t_next = otest[k]['time']
        desired_instances = otest[k]['desired_instances']
        while((time.time() - start_time) < t_next):
            time.sleep(1)

        curr_instances = scheduler.get_current_instances()
        instance_change = desired_instances - curr_instances
        print("-- Exec {}/{} --".format(k+1,n))
        if(instance_change > 0):
            print("- Scheduling {} instances".format(instance_change))
            for i in range(instance_change):
                scheduler.schedule_game(game_spec)

        elif(instance_change < 0):
            print("- Unscheduling {} instances".format(-instance_change))
            for i in range(-instance_change):
                scheduler.deschedule_game()

        else:
            print("Node change is 0")

        k += 1

