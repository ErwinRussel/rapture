from scheduler import Scheduler, StrategyEnum
import time
import json

if __name__ == '__main__':
    # todo: set this with argv
    scheduler = Scheduler(StrategyEnum.rapture)

    #todo: load game container db
    game_name = "atlasgears"
    game_spec = scheduler.get_game_spec(game_name)

    scheduler.schedule_game(game_spec)
    time.sleep(1000)
    scheduler.deschedule_game()

