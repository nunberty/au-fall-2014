#!/usr/bin/env python3

# Alina Kramar
# Merge Sort (all 4 subtasks)

import random
import itertools

class Randseq:
    def __init__(self, n):
        self.counter = -1
        self.n = n

    def __next__(self):
        self.counter += 1
        if self.counter < self.n:
            return random.randint(-100, 100)
        raise StopIteration()

    def __iter__(self):
        return self

def merge(foo, bar):
    try:
        has_foo = False
        has_bar = False
        while True:
            if not has_bar:
                bar_head = next(bar)
                has_bar = True
            if not has_foo:
                foo_head = next(foo)
                has_foo = True
            if foo_head <= bar_head:
                yield foo_head
                has_foo = False
            else:
                yield bar_head
                has_bar = False
    except StopIteration:
        if has_foo:
            yield foo_head
        if has_bar:
            yield bar_head
        yield from foo
        yield from bar

def merge_sorted(seq):
    seq, copy_seq = itertools.tee(seq)
    length = sum(1 for _ in copy_seq)

    if length <= 1:
        return seq

    mid = length // 2
    left, right = itertools.tee(seq)
    left = itertools.islice(left, mid)
    right = itertools.islice(right, mid, None)

    return merge(
        merge_sorted(left),
        merge_sorted(right)
    )

def sort_rand_numbers(n):
    lst = list(Randseq(n))
    return merge_sorted(lst)

n = int(input("Enter length, please: "))
print(" ".join(str(x) for x in sort_rand_numbers(n)))
