#!/usr/bin/env python3
#Alina Kramar


def Singleton(cls):

    def __init__():
        if not hasattr(cls, 'instance'):
             cls.instance = cls()
        return cls.instance

    return __init__
