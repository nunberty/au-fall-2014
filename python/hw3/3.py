#!/usr/bin/env python3
"Alina Kramar"

class DeniedKeyException(Exception):
    pass

class Dict(dict):
    def __init__(self, denied=()):
        super().__init__()
        self.__dict__["keys_by_order"] = []
        self.__dict__["denied"] = set(denied)

    def __getattr__(self, name):
        return self[name]

    def __setattr__(self, name, value):
        self[name] = value

    def __getitem__(self, key):

        if isinstance(key, int):
            return super().__getitem__(self.keys_by_order[key])
        elif key in super().keys():
            return super().__getitem__(key)
        else:
            raise KeyError

    def __setitem__(self, key, value):
        key = key.replace(" ", "_")
        if key in self.denied:
            raise DeniedKeyException()
        if not key in self.keys_by_order:
            self.keys_by_order.append(key)
        super().__setitem__(key, value)

    def __delitem__(self, key):
        self.keys_by_order.remove(key)
        super().__delitem__(key)
