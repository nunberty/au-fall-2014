import sys

a, b = [int(x) for x in sys.stdin.readline().split()]
def combinations(n, k):
    elems = set([str(x) for x in range(1, n + 1)])

    def combinations_gen(l, elements):
        if l == 0:
            return [[]]

        if len(elements) == l:
            return [[x for x in elements]]

        elem = elements.pop()
        with_elem = combinations_gen(l - 1, set(elements))
        without_elem = combinations_gen(l, set(elements))
        return [[elem] + xs for xs in with_elem] + without_elem

    return combinations_gen(k, elems)

for xs in combinations(a, b):
    print(" ".join(x for x in xs))
