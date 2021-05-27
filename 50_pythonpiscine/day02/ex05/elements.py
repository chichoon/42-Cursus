#!/usr/bin/env python3
# -*-coding:utf-8 -*
from elem import *


class Html(Elem):
    def __init__(self, content=None, attr={}):
        super(Html, self).__init__('html', attr, content, 'double')


class Head(Elem):
    def __init__(self, content=None, attr={}):
        super(Head, self).__init__('head', attr, content, 'double')


class Body(Elem):
    def __init__(self, content=None, attr={}):
        super(Body, self).__init__('body', attr, content, 'double')


class Title(Elem):
    def __init__(self, content=None, attr={}):
        super(Title, self).__init__('title', attr, content, 'double')


class Meta(Elem):
    def __init__(self, content={}):
        super(Meta, self).__init__('meta', content, None, 'simple')


class Img(Elem):
    def __init__(self, content={}):
        super(Img, self).__init__('img', content, None, 'simple')


class Table(Elem):
    def __init__(self, content=None, attr={}):
        super(Table, self).__init__('table', attr, content, 'double')


class Th(Elem):
    def __init__(self, content=None, attr={}):
        super(Th, self).__init__('th', attr, content, 'double')


class Tr(Elem):
    def __init__(self, content=None, attr={}):
        super(Tr, self).__init__('tr', attr, content, 'double')


class Td(Elem):
    def __init__(self, content=None, attr={}):
        super(Td, self).__init__('td', attr, content, 'double')


class Ul(Elem):
    def __init__(self, content=None, attr={}):
        super(Ul, self).__init__('ul', attr, content, 'double')


class Ol(Elem):
    def __init__(self, content=None, attr={}):
        super(Ol, self).__init__('ol', attr, content, 'double')


class Li(Elem):
    def __init__(self, content=None, attr={}):
        super(Li, self).__init__('li', attr, content, 'double')


class H1(Elem):
    def __init__(self, content=None, attr={}):
        super(H1, self).__init__('h1', attr, content, 'double')


class H2(Elem):
    def __init__(self, content=None, attr={}):
        super(H2, self).__init__('h2', attr, content, 'double')


class P(Elem):
    def __init__(self, content=None, attr={}):
        super(P, self).__init__('p', attr, content, 'double')


class Div(Elem):
    def __init__(self, content=None, attr={}):
        super(Div, self).__init__('div', attr, content, 'double')


class Span(Elem):
    def __init__(self, content=None, attr={}):
        super(Span, self).__init__('span', attr, content, 'double')


class Hr(Elem):
    def __init__(self, content={}):
        super(Hr, self).__init__('hr', content, None, 'simple')


class Br(Elem):
    def __init__(self, content={}):
        super(Br, self).__init__('br', content, None, 'simple')


if __name__ == '__main__':
    print(
        Html(
            [Head(Title(Text('"Hello ground!"'))), Body([H1(Text('"Oh no, not again!"')), Img({'src': "http://i.imgur.com/pfp3T.jpg"})])]))
