from django.shortcuts import render
from django.http import HttpResponse
import psycopg2


# Create your views here.
def init(request):
    try:
        conn = psycopg2.connect("dbname=d05_db user=jiychoi")
        cur = conn.cursor()
        cur.execute("""
        CREATE TABLE ex00_movies (
            title varchar(64) unique not null,
            episode_nb integer PRIMARY KEY,
            opening_crawl text,
            director varchar(32) not null,
            producer varchar(128) not null,
            release_date date not null
            )""")
        conn.commit()
        cur.close()
        conn.close()
        return HttpResponse("OK")
    except Exception as e:
        return HttpResponse(e)
