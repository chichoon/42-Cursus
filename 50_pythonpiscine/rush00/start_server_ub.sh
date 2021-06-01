#!/bin/bash

#python3 -m venv ~/42s/50_pythonpiscine/django_venv
source ../django_venv/bin/activate
pip3 install --upgrade pip
pip3 install -r requirement.txt
python3 manage.py migrate
python3 manage.py runserver
