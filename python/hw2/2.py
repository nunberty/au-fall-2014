#!/usr/bin/env python3

# Alina Kramar
# Task 02

import itertools
import sys

def str_lsum(first, second):
    a = [int(c) for c in first]
    b = [int(c) for c in second]
    return "".join(str(x) for x in lsum(a, b))

def lsum(first, second):
    def get_sum(lst):

        def get_surplus(x):
            return x % 10, x // 10

        ret = []
        surplus = 0
        for i in range(len(lst)):
            summa = lst[i] + surplus
            summa, surplus = get_surplus(summa)
            ret.insert(0, summa)
        if surplus:
            ret.insert(0, surplus)
        return ret

    pairs = itertools.zip_longest(reversed(first), reversed(second), fillvalue=0)
    sums = list(map(lambda x: x[0] + x[1], pairs))
    return get_sum(sums)

a = input("Enter a: ")
b = input("Enter b: ")

print(str_lsum(a, b))
