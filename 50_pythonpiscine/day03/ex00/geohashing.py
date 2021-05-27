#!/usr/bin/env python3
# -*-coding:utf-8 -*
import sys
import antigravity


def geohashing(arg_lst):
    arg_date = arg_lst[3]
    arg_lat = arg_lst[1]
    arg_lon = arg_lst[2]
    return antigravity.geohash(float(arg_lat), float(arg_lon), arg_date.encode())


if __name__ == "__main__":
    if len(sys.argv) == 4:
        geohashing(sys.argv)
    else:
        print("Invalid argument number!!")
        sys.exit(0)
