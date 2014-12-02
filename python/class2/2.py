#!/usr/bin/env python3
# Alina Kramar

class Node:
    def __init__(self, val):
        self.l_child = None
        self.r_child = None
        self.data = val

class Tree(object):
    def __init__(self):
        self.root = Node(10)

    def __add__(self, val):
        if val is Tree:
            for i in val:
                self.binary_insert(i)
        else:
            self.binary_insert(Node(val))

    def binary_insert(self, node):
        if self.root is None:
            self.root = node
        else:
            if self.root.data > node.data:
                if self.root.l_child == None:
                    self.root.l_child = node
                else:
                    binary_insert(self.root.l_child, node)
            else:
                if self.root.r_child == None:
                    self.root.r_child = node
                else:
                    binary_insert(self.root.r_child, node)

    def in_order_iter(self):
        if not self.root:
            return
        in_order_iter(self.root.l_child)
        yield self.root.data
        in_order_iter(self.root.r_child)

    def pre_order_iter(self):
        if not self.root:
            return
        yield self.root.data
        pre_order_iter(self.root.l_child)
        pre_order_iter(self.root.r_child)

    def __iter__(self):
        yield from in_order_iter()

if __name__=='__main__':
    pass
