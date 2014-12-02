# Alina Kramar
# Multiplication of two matrix

a = [ [1, 2], [3, 4] ]
b = [ [1, 0], [0, 1] ]

def transpose(table):
    return list(zip(*table))

def scalar_multiply(v, w):
    return sum(a * b for (a, b) in zip(v, w))

def mult(first, second):
    rows = first
    columns = transpose(second)

    if len(rows) != len(columns) or len(rows[0]) != len(columns[0]):
        raise Exception("Invalid matrix dimensions!")

    return [[scalar_multiply(rows[j], columns[i]) for i in range(len(columns))]
            for j in range(len(rows))]

print(str(mult(a, b)))
