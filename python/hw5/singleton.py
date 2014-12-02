#!/usr/bin/env python3
# Alina Kramar

class Singleton(type):
    instances = {}
    def __call__(cls, *args, **kwargs):
        hashable_kwargs = frozenset(tuple(kwargs.items()))
        if (args, hashable_kwargs) not in cls.instances:
            new_instance  = super(Singleton, cls).__call__(*args, **kwargs)
            cls.instances[(args, hashable_kwargs)] = new_instance
        return cls.instances[(args, hashable_kwargs)]

class A(object, metaclass=Singleton):
    def __init__(self, val):
        self.val = val

a = A(2)
b = A(4)
c = A(3)

print(a is b)
print(b is c)
