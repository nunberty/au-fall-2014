import math

with open("sqrt.in") as ifile:
    data = ifile.read()

with open("sqrt.out", "w") as out:
    for x in data.splitlines():
        t = int(x)
        ret = 0
        for i in range(1, t + 1, 2):
            if t < i:
                ret =  i // 2
            t -= i
        out.write("{}\n".format(str(ret)))
