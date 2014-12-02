#!/bin/bash

author=$(head -n 1 $1)
count=$(head -n 2 $1)
echo $author $count
