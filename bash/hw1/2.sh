#!/bin/bash

# Команда cal. Используя её, вывести текущее число.

cal --color=always | grep -o `echo -e "\e\[7m.*\[27m"`