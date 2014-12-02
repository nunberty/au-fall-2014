#!/bin/bash

# В файле ip.txt записан IP адрес. Пропинговать 
# компьютер и записать результат в res.txt, а 
# ошибки — в err.txt. 

ping `cat ip.txt` -c 10 1> res.txt 2> err.txt