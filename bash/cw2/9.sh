#!/bin/bash
# Alina Kramar

directory=$PWD
ok_flag=1
for file in $directory/*.c
do
    filename=$(basename "$file")
    ext=${filename##*.}
    prefix=${filename%.${ext}}
    if [ ! -f ${prefix}.h ]
    then
        ok_flag=0
    fi
done

if [ "$ok_flag" -eq 0 ]
then
    echo "WRONG"
else
    echo "OK"
fi
