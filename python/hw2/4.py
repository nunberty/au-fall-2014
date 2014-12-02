#!/usr/bin/env python3

# Alina Kramar
# Task 04

from urllib import request
import json
import collections

def get_json(query):
    response = request.urlopen(
        "http://ajax.googleapis.com/ajax/services/search/web?v=1.0&q={}&rsz=8".format(query)
    ).read()
    return json.loads(response.decode())

def get_stats(json):
    domains = [res['visibleUrl'].split(".")[-1]
               for res in json['responseData']['results']]
    statistic = collections.Counter(domains)
    summa = sum(v for v in statistic.values())
    return ((x, y / summa) for x, y in statistic.items())

query = input("Enter your query: ")
for domain, percent in get_stats(get_json(query)):
    print("{}: {}".format(domain, percent))
