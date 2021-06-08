#! /bin/sh
curl $1 -s | grep http | cut -d '"' -f2 
