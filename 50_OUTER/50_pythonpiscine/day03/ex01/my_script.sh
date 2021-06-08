#!/bin/sh
python3 -m venv local_lib
source ./local_lib/bin/activate
pip3 install --upgrade pip
pip3 --version
pip install git+https://github.com/jaraco/path.git --upgrade --force-reinstall --log logfile.log
python3 my_program.py
