#!/bin/bash
# Alina Kramar

while [[ 1 == 1 ]]; do
	clear
	if [[ $1 == "-d" || $1 == "-date" ]]; then
		date +"%c"
	else
		date +"%T"
	fi
	sleep 1
done