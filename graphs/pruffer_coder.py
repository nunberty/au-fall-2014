import sys

def prufer_code(adj):
    length = len(adj)
    def dfs(node):
        for v in adj[node]:
            if parents[v] is None:
                parents[v] = node
                dfs(v)

    degrees = [len(a) for a in adj]
    parents = [None] * length
    parents[-1] = -1
    killed = [False] * length
    ptr = 0
    while ptr < length and degrees[ptr] != 1:
        ptr += 1

    dfs(length - 1)

    ret = []
    leaf = ptr
    for i in range(length - 2):
        nxt = parents[leaf]
        ret.append(nxt)
        degrees[nxt] -= 1

        if degrees[nxt] == 1 and nxt < ptr:
            leaf = nxt
        else:
            ptr += 1

            while ptr < length and degrees[ptr] != 1:
                ptr += 1
            leaf = ptr
    return ret

with open("coder.in") as f:
    data = f.read()

lines = data.strip().splitlines()
adj = [[int(x) for x in l.split()] for l in lines[1:]]

code = prufer_code(adj)

print(str(len(adj)))
print(" ".join(str(s) for s in code))
