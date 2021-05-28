#!/bin/sh
#python3 -m venv django_venv
source ./django_venv/bin/activate
#pip3 install --upgrade pip
#pip install -r requirement.txt
#django-admin startproject pypiscine
cd pypiscine
python3 manage.py migrate
python3 manage.py runserver
#python3 manage.py startapp helloworld
