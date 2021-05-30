#!/usr/bin/env python3
# -*-coding:utf-8 -*
import keyboard
import sys
import random
from time import sleep


def mini_map():
    player_pos = [3, 3]
    player_char = 's'

    while True:
        if keyboard.is_pressed('w'):
            player_char = 'n'
            player_pos[1] -= 1
        elif keyboard.is_pressed('a'):
            player_char = 'w'
            player_pos[0] -= 1
        elif keyboard.is_pressed('s'):
            player_char = 's'
            player_pos[1] += 1
        elif keyboard.is_pressed('d'):
            player_char = 'e'
            player_pos[0] += 1
        else:
            sleep(1)
        print('-------------------------')
        if player_pos[0] < 0:
            player_pos[0] = 0
        elif player_pos[0] > 24:
            player_pos[0] = 24
        if player_pos[1] < 0:
            player_pos[1] = 0
        elif player_pos[1] > 24:
            player_pos[1] = 24
        for i in range(0, 5):
            for j in range(0, 5):
                if i == player_pos[0] and j == player_pos[1]:
                    sys.stdout.write(player_char)
                else:
                    sys.stdout.write(' ')
            sys.stdout.write('\n')
        print('-------------------------')
        sys.stdout.flush()



if __name__ == '__main__':
    mini_map()
