#!/bin/bash

white="\e[7m \e[27m \e[7m \e[27m \e[7m \e[27m \e[7m \e[27m "
black="\e[27m \e[7m \e[27m \e[7m \e[27m \e[7m \e[27m \e[7m "
for i in `seq 1 8`
do
    if [ $((i%2)) -eq 0 ]
    then
        echo -e "$black"
    else
        echo -e "$white"
    fi
done
