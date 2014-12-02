# Alina Kramar
# Find product of two prime numbers

import sys
import itertools

def find_primes_products(n):

    def is_prime(a):
        return all([a % i != 0 for i in range(2, int(a**0.5) + 1)])

    primes = filter(is_prime, range(2, n // 2))
    primes_comb = itertools.combinations_with_replacement(primes, 2)

    return [a * b for (a, b) in primes_comb if a * b < n]

N = int(input("Enter N: "))
print(" ".join(str(p) for p in find_primes_products(N)))
