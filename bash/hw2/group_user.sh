#!/bin/bash

#Посчитать количество учетных записей на компьютере 
#состоящих в группе, название которой передано в качестве 
#параметра скрипта.

members()
{
    pattern="^$1"
    awk -F: " /$pattern/ {print $4;}" /etc/group | sed -r 's/[,]/\n /g' | grep -c ""
}
members $1
