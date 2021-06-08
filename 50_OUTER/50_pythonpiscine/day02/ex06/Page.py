#!/usr/bin/env python3
# -*-coding:utf-8 -*
from elem import *
from elements import *

class Page:
    def __init__(self, elem: Elem):
        print(type(elem))

    def is_valid():
        lst_type = ['html', 'head', 'body', 'title', 'meta', 'img',
        'table', 'th', 'tr', 'td', 'ul', 'ol', 'li',
        'h1', 'h2', 'p', 'div', 'span', 'hr', 'br', ]
        if elem.tag not in lst_type:
            return False
        if elem.tag == 'html':
            if type(elem.content) == list and elem.content[0].


if __name__ == '__main__':
    Page("asd")
    print(Page(Html(
            [Head(Title(Text('"Hello ground!"'))), Body([H1(Text('"Oh no, not again!"')), Img({'src': "http://i.imgur.com/pfp3T.jpg"})])])))
