#!/bin/sh
python3 -m venv django_venv
source ./django_venv/bin/activate
pip3 install --upgrade pip
pip install -r requirement.txt
