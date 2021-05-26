#!/usr/bin/env python3
# -*-coding:utf-8 -*

import random
from beverages import *


class CoffeeMachine:
    def __init__(self):
        self.used = 0

    class EmptyCup(HotBeverage):
        price = 0.90
        name = "empty cup"

        def description(self):
            return "An empty cup?! Gimme my money back!"

    class BrokenMachineException(Exception):
        def __init__(self):
            super(CoffeeMachine.BrokenMachineException, self).__init__("This coffee machine has to be repaired.")

    def repair(self):
        self.used = 0

    def serve(self, HotBeverage):
        if self.used == 10:
            raise CoffeeMachine.BrokenMachineException()
        else:
            if random.randrange(1, 10) < 3:
                self.used += 1
                return self.EmptyCup()
            else:
                self.used += 1
                return HotBeverage()


def test():
    try:
        machine = CoffeeMachine()
        print(machine.serve(Coffee))
        print(machine.serve(Tea))
        print(machine.serve(Cappuccino))
        print(machine.serve(Tea))
        print(machine.serve(Coffee))
        print(machine.serve(Cappuccino))
        print(machine.serve(Coffee))
        print(machine.serve(Tea))
        print(machine.serve(Chocolate))
        print(machine.serve(Tea))
        print(machine.serve(Coffee))
        print(machine.serve(Tea))
    except Exception as e:
        print(e)
        machine.repair()
    try:
        print(machine.serve(Coffee))
        print(machine.serve(Tea))
        print(machine.serve(Cappuccino))
        print(machine.serve(Tea))
        print(machine.serve(Coffee))
        print(machine.serve(Cappuccino))
        print(machine.serve(Coffee))
        print(machine.serve(Tea))
        print(machine.serve(Chocolate))
        print(machine.serve(Tea))
        print(machine.serve(Coffee))
        print(machine.serve(Tea))
    except Exception as e:
        print(e)
        machine.repair()


if __name__ == "__main__":
    test()
