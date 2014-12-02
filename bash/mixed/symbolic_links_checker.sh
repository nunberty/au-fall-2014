#!/bin/bash

files=($( ls -la | awk '{print $9}'))
for line in "${files[@]}"
do
    if [ -L "$line" ]
    then
        echo $line
    fi
done
