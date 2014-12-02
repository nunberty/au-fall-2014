def transpose(table):
    return list(zip(*table))

def check(table):
    return all(l.count("-") % 2 == 0 for l in table + transpose(table))

with open("plusminus.in") as f:
    table = f.read().strip().splitlines()[1:]

with open("plusminus.out", "w") as f:
    print("Yes" if check(table) else "No", file=f)
