class CountObjects(type):
    count = {}
    def __call__(cls, *args, **kwargs):
        instance = super().__call__(*args, **kwargs)
        cls.update()
        return instance

    def update(cls):
        cls.count[cls] = cls.count.get(cls, 0) + 1
        for base in cls.__bases__:
            if hasattr(base, 'update'):
                base.update()

    @staticmethod
    def stat():
        sorted_by_name = sorted(CountObjects.count.items(), key=lambda x: x[0].__name__)
        for key, value in sorted_by_name:
            print(repr(key), value)

"""
            1
         1     1
      1     2     1
   1     3     3     1
1     4     6     4     1
"""
class C40(metaclass=CountObjects): pass
class C41(metaclass=CountObjects): pass
class C42(metaclass=CountObjects): pass
class C43(metaclass=CountObjects): pass
class C44(metaclass=CountObjects): pass
class C30(C40, C41): pass
class C31(C41, C42): pass
class C32(C42, C43): pass
class C33(C43, C44): pass
class C20(C30, C31): pass
class C21(C31, C32): pass
class C22(C32, C33): pass
class C10(C20, C21): pass
class C11(C21, C22): pass
class C00(C10, C11): pass

x = C00()
CountObjects.stat()
