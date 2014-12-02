#!/bin/bash

str=$1
uniq_words=$(echo "$str" | tr " " "\n" | sort | uniq | tr "\n" " ")

for word in $uniq_words 
do
	str=$(echo "$str" | sed "s/\b$word\b/*$word*/2g")
done

echo "$str"