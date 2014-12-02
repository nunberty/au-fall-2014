#!/usr/bin/env python3
#Alina Kramar

instance_cnt = {}
init_not_implemented = None

def register(cls):
    def increment(clazz):
        bases = set(cls.__bases__)
        while bases:
            base = bases.pop()
            if not base.__name__ == object.__name__:
                if base.__name__ in instance_cnt.keys():
                    instance_cnt[base.__name__] += 1
                bases.update(base.__bases__)
        instance_cnt[cls.__name__] += 1

    def cascade_inits_begin():
        global init_not_implemented
        if not init_not_implemented:
            init_not_implemented = cls
            increment(cls)

    def cascade_inits_end():
        global init_not_implemented
        if init_not_implemented == cls:
            init_not_implemented = None

    def hook(*args, **kwargs):
        cascade_inits_begin()
        oldinit(*args, **kwargs)
        cascade_inits_end()

    instance_cnt[cls.__name__] = 0
    oldinit = cls.__init__
    cls.__init__ = hook
    return cls

@register
class A:
    pass

@register
class B(A):
        pass
@register
class C(A):
    pass

@register
class D(B, C):
    pass

def print_hierarchy():
    level = 0
    for k, v in instance_cnt.items():
        indent = '\t'
        print(indent * level + "{}: {}".format(k, v))

if __name__=='__main__':
    a = D()
    print_hierarchy()
