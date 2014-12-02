#!/usr/bin/env python3

# Alina Kramar
# Task 03

import xml.etree.ElementTree as ET

def nice_tree_print(filename):

    def recoursive_print_tree(node, depth):
        shift = '\t' * depth
        print(shift + "<{}> ".format(node.tag) + node.text)
        for child in node.getchildren():
            recoursive_print_tree(child, depth + 1)
        print(shift + "<{}/>".format(node.tag))

    tree = ET.parse(filename)
    root = tree.getroot()
    recoursive_print_tree(root, 0)

nice_tree_print("rss.xml")
