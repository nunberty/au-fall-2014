#!/usr/bin/env python3
"Alina Kramar"

import math

class Vector3(object):
    dim = 3

    def __init__(self, vector):
        self.value = [0] * Vector3.dim
        for i in range(Vector3.dim):
            self.value[i] = vector[i]

class Matrix(object):
    dim = 3

    def __init__(self, matrix=None):
        if not matrix:
            self.value = [[0] * Matrix.dim for _ in range(Matrix.dim)]
        else:
            self.value = matrix

    def __add__(self, rhs):
        ret = Matrix()
        for i in range(Matrix.dim):
            for j in range(Matrix.dim):
                ret.value[i][j] = self.value[i][j] + rhs.value[i][j]
        return ret

    def __mul__(self, rhs):

        if isinstance(rhs, Matrix):
            ret = Matrix()
            for i in range(Matrix.dim):
                for j in range(Matrix.dim):
                    for k in range(Matrix.dim):
                        ret.value[i][j] += self.value[i][k] * rhs.value[k][j]
            return ret

        elif isinstance(rhs, Vector3):
            result = [0]*Matrix.dim
            for i in range(Matrix.dim):
                for j in range(Matrix.dim):
                    result[i] += self.value[i][j]*rhs.value[j]
            return Vector3(result)

        else:
            ret = Matrix()
            for i in range(Matrix.dim):
                for j in range(Matrix.dim):
                    ret.value[i][j] = self.value[i][j] * rhs;
            return ret

    def __invert__(self):
        ret = Matrix()
        m, n = ret.value, self.value

        m[0][0] = n[1][1] * n[2][2] - n[2][1] * n[1][2]
        m[0][1] = n[2][1] * n[0][2] - n[0][1] * n[2][2]
        m[0][2] = n[0][1] * n[1][2] - n[1][1] * n[0][2]

        m[1][0] = n[2][0] * n[1][2] - n[1][0] * n[2][2]
        m[1][1] = n[0][0] * n[2][2] - n[2][0] * n[0][2]
        m[1][2] = n[1][0] * n[0][2] - n[0][0] * n[1][2]

        m[2][0] = n[1][0] * n[2][1] - n[2][0] * n[1][1]
        m[2][1] = n[2][0] * n[0][1] - n[0][0] * n[2][1]
        m[2][2] = n[1][0] * n[0][1] - n[0][0] * n[1][1]
        return ret * (1 / self.det())

    def det(self):
        m = self.value
        return ( m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1])
               - m[0][1] * (m[1][0] * m[2][2] - m[2][0] * m[1][2])
               + m[0][2] * (m[1][0] * m[2][1] - m[2][0] * m[1][1]))


class RotationMatrix(Matrix):
    def __init__(self, angle):
        matrix = [[math.cos(angle), -math.sin(angle), 0],
                  [math.sin(angle),  math.cos(angle), 0],
                  [              0,                0, 1]]
        super().__init__(matrix)
