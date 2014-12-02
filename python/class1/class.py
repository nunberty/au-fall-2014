import sys
import itertools

def get_square(N):
    return [
        [1 if i in range(N//2 - j, N//2 + j + 1) else 0 for i in range(N)]
        for j in itertools.chain(range(N//2), range(N//2, -1, -1))]

ret = get_square(11)

students = [("A", "a"), ("B", "b"), ("C", "a"), ("g", "v"), ("C", "b")]

print("\n".join(" ".join(str(x) for x in ret[i]) for i in range(11)))

def get_students(lst):
    return [sorted(list([n[0] for n in g])) for k, g in itertools.groupby(sorted(lst, key=lambda s:s[1]), key=lambda x:x[1])]

print("\n".join(str(x) for x in get_students(students)))
