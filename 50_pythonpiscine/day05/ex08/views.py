from django.shortcuts import render
from django.http import HttpResponse
import psycopg2
import csv


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
        CREATE TABLE ex08_planets (
            id serial PRIMARY KEY,
            name varchar(64) unique not null,
            climate varchar,
            diameter integer,
            orbital_period integer,
            population bigint,
            rotation_period integer,
            surface_water real,
            terrain varchar(128)
            )""")
        cur.execute("""
        CREATE TABLE ex08_people (
            id serial PRIMARY KEY,
            name varchar(64) unique not null,
            birth_year varchar(32),
            gender varchar(32),
            eye_color varchar(32),
            hair_color varchar(32),
            height integer,
            mass real,
            homeworld varchar(64) REFERENCES ex08_planets (name)
            )""")
        conn.commit()
        cur.close()
        conn.close()
        return HttpResponse("OK")
    except Exception as e:
        return HttpResponse(e)


def populate(request):
    string = ''
    try:
        conn = psycopg2.connect(
            database='djangotraining',
            host='localhost',
            user='djangouser',
            password='secret'
            )
        cur = conn.cursor()
        with open('ex08/planets.csv', 'r') as f:
            cur.copy_from(
                file=f,
                table='ex08_planets',
                columns=('name', 'climate', 'diameter', 'orbital_period', 'population', 'rotation_period', 'surface_water', 'terrain'),
                sep='\t',
                null='NULL'
            )
        conn.commit()
        string += ' OK'
        with open('ex08/people.csv', 'r') as f:
            cur.copy_from(
                file=f,
                table='ex08_people',
                columns=('name', 'birth_year', 'gender', 'eye_color', 'hair_color', 'height', 'mass', 'homeworld'),
                sep='\t',
                null='NULL'
            )
        conn.commit()
        string += ' OK'
        cur.close()
        conn.close()
    except Exception as e:
        string += str(e)
    return HttpResponse(string)


def display(request):
    try:
        conn = psycopg2.connect(
            database='djangotraining',
            host='localhost',
            user='djangouser',
            password='secret'
            )
        cur = conn.cursor()
        cur.execute("""
        SELECT *
        FROM ex08_people INNER JOIN ex08_planets
        ON ex08_people.homeworld = ex08_planets.name;
        """)
        response = cur.fetchall()
        data = []
        for row in response:
            data.append([
                row[1], row[8], row[11]
            ])
        conn.commit()
        cur.close()
        conn.close()
        context = {
            'data': data,
        }
        if len(data) == 0:
            raise Exception
        return render(request, 'ex08/display.html', context)
    except Exception:
        return HttpResponse("No data Available")

