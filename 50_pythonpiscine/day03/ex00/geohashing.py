#!/usr/bin/env python3
# -*-coding:utf-8 -*
import sys
import antigravity


def geohashing(arg_lst):
    arg_date = arg_lst[3]
    arg_lat = arg_lst[1]
    arg_lon = arg_lst[2]
    try:
        arg_lat = float(arg_lat)
        arg_lon = float(arg_lon)
        return antigravity.geohash(arg_lat, arg_lon, arg_date.encode())
    except Exception:
        print('Please input a float for longitude and latitude')


if __name__ == "__main__":
    if len(sys.argv) == 4:
        geohashing(sys.argv)
    else:
        print("Invalid argument number!!")
        sys.exit(0)
