#!/bin/bash
# ALina Kramar

cat $1 | grep -Po "[A-Za-z_,\-\.]*[A-Za-z][A-Za-z_,\-\.]*@([a-zA-Z]*\.)+[a-zA-Z]+" | sort | uniq -c | sort -nr