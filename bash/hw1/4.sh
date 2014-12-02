#!/bin/bash

# Создать файл, хранящий в себе список процессов, которые начинаются на r.

ps -e | awk '{print $4}' | grep "^r" > r_processes.txt