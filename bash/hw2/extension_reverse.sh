#!/bin/bash

#Написать Bash-скрипт, который переворачивает расширение 
#файла. Например, a.pdf превращается в a.fdp 

extension_reverse()
{
    full=$(basename "$1")
    ext="${full##*.}"
    rext=$(echo $ext | rev)
    name="${full%.*}"
    newname="$name.$rext"
    if [ ! -f $full ]
    then
        echo "File doesn't exist!"
    else
        mv $full $newname
    fi
}
extension_reverse $1
