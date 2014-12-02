#!/usr/bin/env python3
# Alina Kramar

class ClassBase(type):
    def __init__(classobject, classname, classbases, attrs):
        super(ClassBase, classobject).__init__(classname, classbases, attrs)
        config = open(classname + '.txt')
        for l in config:
            index = l.index(':')
            name = l[0:index].strip()
            value = l[index+1:l.index('\n')]
            setattr(classobject, name,  value)

class A(metaclass=ClassBase):
    def __init__(self, s):
        self.y = s

if __name__=='__main__':
    a = A(42)
    print(a.y)
    print(a.x)
