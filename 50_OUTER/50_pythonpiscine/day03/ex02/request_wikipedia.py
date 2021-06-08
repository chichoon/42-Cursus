#!/usr/bin/env python3
# -*-coding:utf-8 -*
import requests
import json
from dewiki import parser
import sys


def wiki(arg):
    result = requests.get(f'https://en.wikipedia.org/w/api.php?action=query&titles={arg}&prop=revisions&rvprop=content&format=json')
    if result.status_code != 200:
        print("Connection failed. exit program.")
        sys.exit(0)
    elif not result.text:
        print("Getting text failed. exit program.")
        sys.exit(0)
    try:
        json_data = json.loads(result.text).get('query').get('pages')
        for key in json_data.keys():
            data = json_data.get(key).get('revisions')[0].get('*')
        d_parser = parser.Parser()
        return d_parser.parse_string(data)
    except Exception:
        print('Error while parsing data. exit program.')
        sys.exit(0)


def request_wiki(lst):
    if len(lst) == 2:
        filename = lst[1].replace(' ', '_')
        str = wiki(lst[1]).encode()
        with open(f'{filename}.wiki', 'wb') as file:
            file.write(str)
    else:
        print("Too many / small arguments!")
        sys.exit(0)

if __name__ == '__main__':
    request_wiki(sys.argv)
