import sys

def prufer_decode(code):
    length = len(code) + 2
    degrees = [1] * length
    for c in code:
        degrees[c] += 1

    ptr = 0
    while ptr < length and degrees[ptr] != 1:
        ptr += 1
    leaf = ptr

    ret = []
    for i in range(length - 2):
        v = code[i]
        ret.append([leaf, v])

        degrees[leaf] -= 1
        degrees[v] -= 1
        if degrees[v] == 1 and v < ptr:
            leaf = v
        else:
            ptr += 1
            while ptr < length and degrees[ptr] != 1:
                ptr += ptr
            leaf = ptr

    for v in range(length - 1):
        if degrees[v] == 1:
            ret.append([v, length - 1])

    return ret

data = sys.stdin.read()

lines = data.strip().splitlines()
code = [int(x) for x in lines[1].split()]
n = len(code) + 2
adj = [list() for _ in range(n)]
for [x, y] in prufer_decode(code):
    adj[x].append(y)
    adj[y].append(x)
print(n)
for l in adj:
    print(" ".join(str(s) for s in l))
