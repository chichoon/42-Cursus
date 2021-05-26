#!/usr/bin/env python3
# -*-coding:utf-8 -*
import sys
import os
import re
from settings import *


def get_dict():
    dic = {}
    for item in globals().items():
        if (
            type(item[1])
            in [
                str,
                int,
                float,
                bool,
                list,
                tuple,
                set,
                dict,
            ]
            and not item[0].startswith("_")
        ):
            dic[item[0]] = item[1]
    return dic


def get_string(filename, dic):
    try:
        with open(filename, "r") as template:
            string_temp = template.read()
            for item in dic.items():
                item_temp = "{" + item[0] + "}"
                string_temp = re.sub(item_temp, str(item[1]), string_temp)
        return string_temp
    except Exception:
        print("template read error!")


def write_html(filename):
    if os.path.splitext(filename)[1] != ".template":
        print("Invalid file extension!")
    elif not os.path.isfile(filename):
        print("no file available!")
    else:
        try:
            dic = get_dict()
            if dic:
                string_template = get_string(filename, dic)
            with open(os.path.splitext(filename)[0] + ".html", "wb") as html:
                html.write(string_template.encode())
        except Exception:
            print("File read Error!!")


def render(arg):
    if len(arg) > 2:
        print("too many arguments!")
    elif len(arg) < 2:
        print("no arguments!")
    else:
        write_html(arg[1])


if __name__ == "__main__":
    render(sys.argv)
