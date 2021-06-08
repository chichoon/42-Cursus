#!/usr/bin/env python3
# -*-coding:utf-8 -*
import sys
import os
import re


def get_dict():
    dic = {}
    try:
        with open("settings.py", "r") as setting:
            lines = setting.readlines()
            for line in lines:
                if len(line.split("=")) == 2:
                    element = line.split("=")
                    dic[element[0].strip()] = element[1].strip(' "\n')
        return dic
    except Exception:
        print("settings.py read error!")


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
