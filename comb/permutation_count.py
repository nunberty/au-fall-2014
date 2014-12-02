# coding: utf-8

иimport sys

n, k = [int(x) for x in sys.stdin.readline().split()]
def C_n_k(n, k):
    if k == 1 or k == n:
        return 1
    return C_n_k(n - 1, k - 1) + C_n_k(n - 1, k)
print(C_n_k(n, k))
