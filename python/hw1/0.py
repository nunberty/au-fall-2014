import sys
import string
import pymorphy2


def exclude_punctuation(data):
    exclude = set(string.punctuation)
    return ''.join(c for c in data if c not in exclude)

def noun_counter(data):
    morph = pymorphy2.MorphAnalyzer()
    count = 0

    for word in data.split():
        if sorted(morph.parse(word.lower()), key=lambda x: x[3])[0].tag.POS == 'NOUN':
            count += 1

    return count

file_name = input("Enter a file name. please: ")

with open(file_name) as f:
    in_text = f.read()

data = exclude_punctuation(in_text)
print(noun_counter(data))
