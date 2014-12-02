#!/bin/bash
# Alina Kramar

wget "http://mit.spbau.ru/sewiki/index.php/SE_Wiki" -O - -q | pcregrep -Mo "<body.*>(.*\n)*.*<\/body>"  | sed -e :a -e 's/<[^>]*>//g;/</N;//ba'