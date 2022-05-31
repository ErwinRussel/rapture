from scheduler import Scheduler, StrategyEnum
import time
import json

if __name__ == '__main__':
    # todo: set this with argv
    scheduler = Scheduler(StrategyEnum.spread)

    #todo: load game container db
    game_name = "Viking_Village_-_Linux"
    game_spec = scheduler.get_game_spec(game_name)

    scheduler.schedule_game(game_spec)