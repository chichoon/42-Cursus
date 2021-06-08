#!/bin/sh
python3 -m venv ~/Documents/42c/50_pythonpiscine/django_venv
source ~/Documents/42c/50_pythonpiscine/django_venv/bin/activate
pip3 install --upgrade pip
pip3 install -r requirement.txt
python3 manage.py migrate
python3 manage.py runserver
