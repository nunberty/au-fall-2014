#!/bin/bash

# Написать команду, которая в текущей 
# директории считает кол-во файлов с 
# расширением .txt. 

ls -la | grep -c ".txt$"