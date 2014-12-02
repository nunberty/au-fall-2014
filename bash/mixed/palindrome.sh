#!/bin/bash

str1="$1"
str2=$(echo $str1 | rev)
if [ ! "$str2" = "$str1" ]
then
    echo "String does't a palindrome=("
else
    echo "String is palindrome=)"
fi
