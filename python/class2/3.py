#!/usr/bin/env python3
# Alina Kramar

import time
start_time = time.time()
calls = {}

def spy(f):
    calls[f] = []
    def wrapped(*args, **kwargs):
        diff = time.time() - start_time
        calls[f].append((args, frozenset(tuple(kwargs)), diff))
        r = f(*args, **kwargs)
        return r
    wr = wrapped
    wr.spied = True
    wr.fn = f
    return wr

def bond(fn):
    if getattr(fn, 'spied', False):
        yield from calls[fn.fn]
    else:
        raise Exception()
@spy
def fn(x):
    print(x)

if __name__=='__main__':
    fn(5)
    fn(6)
    for i in bond(fn):
        print(i)
