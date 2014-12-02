#!/bin/bash

ret=""
for f in `ls *.c`
do
    for h in `grep -E "#[[:space:]]*include[[:space:]]*(<.*>|\".*\")" $f | sed -r "s/^.*<//;s/>//;s/^.*\"(.*)\".*$/\1/"`
    do
        if [ ${h: -2} == ".h" ]
        then
            if [ ! -e "$h" ]
            then
                ret="$ret $h"
                echo "File $h doesn't exist!"
            fi
        fi
    done
done
if [ -z "$ret" ]
then
    echo "All headers are here =)"
fi
