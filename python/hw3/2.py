#!/usr/bin/env python3
# Alina Kramar
import time
import sys

preamble = """
starttime = time.time()

def trace(function):
    def execute(*args, **kwargs):
        gran = 1000
        print("{}.3fms {}".format(
            (time.time() - starttime) * gran,
            function.__name__)
        )
        enter = time.time()
        res = function(*args, **kwargs)
        ret = time.time()
        print("\t+{}.3fms".format((ret - enter) * gran))
        return res

    return execute

"""

def modify(text):
    res = preamble
    for l in text.splitlines(keepends=True):
        if l.strip().startswith("def "):
            res+=l[:l.index("def ")] + "@trace\n"
        res += l
    return res

if __name__ == "__main__":
    filename = sys.argv[1]
    with open(filename) as f:
        text = modify(f.read())
    exec(text)
