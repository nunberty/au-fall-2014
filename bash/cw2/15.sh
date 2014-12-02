#!/bin/bash
# Alina Kramar

read -n1 sym1 <f1.txt
read -n1 sym2 <f2.txt
sym1=$(LC_CTYPE=C printf '%d' "'$sym1")
sym2=$(LC_CTYPE=C printf '%d' "'$sym2")
echo $(($sym2 - $sym1))