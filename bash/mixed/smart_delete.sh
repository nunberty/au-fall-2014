#!/bin/bash

help=( "Use smart_delete.sh [OPTIONS] [filename mask]"
      "Options: "
      "   -v         -- for disabling confirmation for each file"
      "   -? [-help] -- for help" )
if [ "-help" = "$1" ]
then
    for l in "${help[@]}"
    do
        echo $l
    done
else
    files=($( find . -name "$1" | sed -r 's/.\///'))
    if [ "$1" = "-v" ]
    then
        for line in "${files[@]}"
        do
            rm "$line"
        done
    fi
fi
