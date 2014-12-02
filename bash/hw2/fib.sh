#!/bin/bash

#Написать рекурсивную функцию для вычисления n-го числа 
#Фибоначчи. Вычислить с ее помощью число, номер которого 
#передан параметром.

fib()
{
  ind=$0
if (( ind <= 0 ))
 then echo 1
else
  echo $(( $(fib $((ind - 1)) ) + $(fib $((ind - 2)) ) ))
fi
}
echo $(fib $1)
