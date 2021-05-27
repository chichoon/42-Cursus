#!/usr/bin/env python3
# -*-coding:utf-8 -*
from path import Path


def my_program():
    direction = Path('.')
    direction += '/piscinebox'
    direction.mkdir_p()
    file = direction + '/piscine.txt'
    file.touch()
    file.write_text('hello, this is 42 piscine python django.')
    print(file.read_text('utf-8'))


if __name__ == '__main__':
    my_program()
