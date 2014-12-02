#!/usr/bin/env python3
# Alina Kramar

def apply(func, test):
    def wrapped(fn, *args, **kwargs):
        old = fn
        if test(args, kwargs):
            return old
        else:
            return func
    return wrapped

@apply(func, test)
def foo(num):
    print("False")

if __name__=='__main__':
    pass
