#!/bin/bash
# Alina Kramar

c=$(cat "$1" | tr '\n' ' ' | grep -P "(<(.+)>.*<\/\2>)|(<(.)+\/>)" -c)
if [ "$c" -eq 1 ]
then
    echo "yes!!!"
else
    echo "no(("
fi
