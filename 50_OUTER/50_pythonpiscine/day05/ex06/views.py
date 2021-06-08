from re import template
from django.shortcuts import render
from django.http import HttpResponse, response
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
        CREATE TABLE ex06_movies (
            title varchar(64) unique not null,
            episode_nb integer PRIMARY KEY,
            opening_crawl text,
            director varchar(32) not null,
            producer varchar(128) not null,
            release_date date not null,
            created timestamp not null default now(),
            updated timestamp not null default now())
        """)
        cur.execute("""
        CREATE OR REPLACE FUNCTION update_changetimestamp_column()
        RETURNS TRIGGER AS $$
        BEGIN
        NEW.updated = now();
        NEW.created = OLD.created;
        RETURN NEW;
        END;
        $$ language 'plpgsql';
        CREATE TRIGGER update_films_changetimestamp BEFORE UPDATE
        ON ex06_movies FOR EACH ROW EXECUTE PROCEDURE
        update_changetimestamp_column();
        """)
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
            INSERT INTO ex06_movies (episode_nb, title, director, producer, release_date)
            VALUES ('{i}', '{elem[0]}', '{elem[1]}', '{elem[2]}', '{elem[3]}')
            ON CONFLICT (title) DO NOTHING
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
        cur.execute(""" SELECT * FROM ex06_movies """)
        response = cur.fetchall()
        data = []
        for row in response:
            data.append(row)
        cur.close()
        conn.close()
        context = {
            'data': data,
        }
        if len(data) == 0:
            raise Exception
        return render(request, 'ex06/display.html', context)
    except Exception:
        return HttpResponse("No data Available")


def update(request):
    try:
        conn = psycopg2.connect(
            database='djangotraining',
            host='localhost',
            user='djangouser',
            password='secret'
            )
        cur = conn.cursor()
        if request.method == 'POST':
            form = request.POST
            cur.execute(f"""
            UPDATE ex06_movies SET opening_crawl='{form['movie_crawl']}' WHERE title='{form['movie_title']}';
            """)
            print("cur")
            conn.commit()
        data = []
        cur.execute(""" SELECT * FROM ex06_movies """)
        response = cur.fetchall()
        for row in response:
            data.append(row[0])
        conn.commit()
        cur.close()
        conn.close()
        if len(data) == 0:
            raise Exception
        return render(request, 'ex06/update.html', {'movie_lst': data, })
    except Exception:
        return HttpResponse("No data Available")

