#!/bin/bash

ndays=$(date -d "$1 days ago")
files=$(ls -lar | grep -F -n "$(whoami)" | awk '{print $6, $7, $8}')
while read -r line; do
    d=$(date - d "$($line | awk '{print $6, $7, $8}')")
    if (( ndays > d ))
    then
        echo "$line"
    fi
done <<< "$files"
echo "$ndays"
