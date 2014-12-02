#!/bin/bash
# Alina Kramar

sum=0
for file in *
do
    size=$(stat --format "%s" "$file")
    sum=$(($sum + $size))
done
echo $sum
