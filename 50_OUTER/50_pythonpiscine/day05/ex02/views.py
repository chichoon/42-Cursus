from django.shortcuts import render
from django.http import HttpResponse
import psycopg2


# Create your views here.
def init(request):
    try:
        conn = psycopg2.connect(
            database='djangotraining',
            host='localhost',
            user='djangouser',
            password='secret'
            )
        cur = conn.cursor()
        cur.execute("""
        CREATE TABLE ex02_movies (
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


def populate(request):
    lst = [
        ['The Phantom Menace', 'George Lucas', 'Rick McCallum', '1999-05-19'],
        ['Attack of the Clones', 'George Lucas', 'Rick McCallum', '2002-05-16'],
        ['Revenge of the Sith', 'George Lucas', 'Rick McCallum', '2005-05-19'],
        ['A New Hope', 'George Lucas', 'Gary Kurtz, Rick McCallum', '1977-05-25'],
        ['The Empire Strikes Back', ' Irvin Kershner', 'Gary Kurtz, Rick McCallum', '1980-05-17'],
        ['Return of the Jedi', 'Richard Marquand', 'Howard G. Kazanjian, George Lucas, Rick McCallum', '1983-05-25'],
        ['The Force Awakens', 'J. J. Abrams', 'Kathleen Kennedy, J. J. Abrams, Bryan Burk', '2015-12-11'],
    ]
    try:
        conn = psycopg2.connect(
            database='djangotraining',
            host='localhost',
            user='djangouser',
            password='secret'
            )
        cur = conn.cursor()
        i = 1
        for elem in lst:
            cur.execute(f"""
            INSERT INTO ex02_movies (episode_nb, title, director, producer, release_date)
            VALUES ('{i}', '{elem[0]}', '{elem[1]}', '{elem[2]}', '{elem[3]}')
            """)
            i += 1
        conn.commit()
        cur.close()
        conn.close()
        return HttpResponse("OK")
    except Exception as e:
        return HttpResponse(e)


def display(request):
    try:
        conn = psycopg2.connect(
            database='djangotraining',
            host='localhost',
            user='djangouser',
            password='secret'
            )
        cur = conn.cursor()
        cur.execute(""" SELECT * FROM ex02_movies """)
        response = cur.fetchall()
        data = []
        for row in response:
            data.append(row)
        conn.commit()
        cur.close()
        conn.close()
        context = {
            'data': data,
        }
        if len(data) == 0:
            raise Exception
        return render(request, 'ex02/display.html', context)
    except Exception:
        return HttpResponse("No data Available")

