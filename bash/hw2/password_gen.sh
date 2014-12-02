#!/bin/bash

#Напишите Bash-скрипт, который выдает n штук случайных 
#паролей, каждый длиной m. Числа m и n должны задаваться в 
#параметрах. Если параметры не заданы, то должно выводиться 
#сообщение об ошибке. Пароли могут содержать буквы 
#латиницы в верхнем и нижнем регистре, а также цифры 

password_gen()
{
    if [ "$#" -ne 2 ]
    then
        echo "Sorry, wrong arguments count!"
    else
        for k in $(seq $2)
        do
            echo $(< /dev/urandom tr -dc A-Z-a-z-0-9 | head -c$1)
        done
    fi
}
password_gen $1 $2
