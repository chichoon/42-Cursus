#!/usr/bin/env python3
# -*-coding:utf-8 -*
import sys
import requests
from bs4 import BeautifulSoup


def parse_this_page(link):
    result = requests.get(link)
    if result.status_code == 404:
        print('No page found. exit program.')
        sys.exit(0)
    if result.status_code != 200:
        print('Connection failed. exit program.')
        sys.exit(0)
    elif not result.text:
        print('Getting text failed. exit program.')
        sys.exit(0)
    try:
        soup = BeautifulSoup(result.text, 'html.parser')
        title = soup.title.string.split('-')[0].strip()
        soup = soup.find('div', {'id': 'mw-content-text'}).find_all('p', {'class': None})
        for p in soup:
            lst_a = p.find_all('a')
            for a in lst_a:
                if a is not None:
                    soup = a['href']
                    if '/wiki/' in soup and 'Help:' not in soup and 'Wikipedia:' not in soup:
                        return [title, 'https://en.wikipedia.org/' + soup]
        return [title, 0]
    except Exception:
        print('Error while parsing with Beautifulsoup. exit program.')
        sys.exit(0)


def find_road(article):
    link = 'https://en.wikipedia.org/wiki/' + article.replace(' ', '_')
    list_of_article = []
    str_to_print = ''
    lst = parse_this_page(link)
    page_title = lst[0]
    next_link = lst[1]
    while page_title != 'Philosophy':
        if page_title in list_of_article and len(list_of_article) > 1:
            str_to_print = 'It leads to an infinite loop !'
            break
        if next_link == 0:
            str_to_print = 'It leads to a dead end !'
            break
        print(page_title)
        list_of_article.append(page_title)
        lst = parse_this_page(next_link)
        page_title = lst[0]
        next_link = lst[1]
    print(page_title)
    list_of_article.append(page_title)
    if str_to_print == '':
        str_to_print = str(len(list_of_article)) + ' roads from ' + article + ' to philosophy !'
    print(str_to_print)


def philosophy(lst):
    if len(lst) == 2:
        find_road(lst[1])
        sys.exit(0)
    else:
        print('Too many / small arguments!')
        sys.exit(0)


if __name__ == '__main__':
    philosophy(sys.argv)
