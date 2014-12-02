#!/usr/bin/env python3
# Alina Kramar

def final(fn):
    fn.is_final = True
    return fn

class WithFinals(type):
    def __init__(classobject, classname, classbases, attrs):

        def extract_overrides(attr):
            overrides = []
            for cls in classobject.__mro__:
                if hasattr(cls, attr):
                    a = getattr(cls, attr)
                    if not any(x is a for x in overrides):
                        overrides.append(a)
            return overrides

        def check_attr(attr):
            def is_final(attr):
                return getattr(attr, 'is_final', False)

            overrides = extract_overrides(attr)
            no_finals = all(not is_final(attr) for attr in overrides)
            lasts = all(not is_final(attr) for attr in overrides[1:])
            correct_final_attr = is_final(overrides[0]) and lasts
            return no_finals or correct_final_attr

        if not all(check_attr(attr) for attr in dir(classobject)):
            raise TypeError("Overriding final attribute!. Does not compute!")

class A(metaclass=WithFinals):
    def foo(self):
        pass

class B(metaclass=WithFinals):
    @final
    def foo(self):
        pass

class C(A, B):
    pass
