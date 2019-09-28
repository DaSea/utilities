# -*- coding: utf-8 -*-
#!/bin/python3

from functools import reduce


def f(x):
    return x * x
r = map(f, [1, 2, 3, 4, 5])
print(list(r))


def myadd(a, b):
    return a + b
print(reduce(myadd, [1, 2, 3, 4, 5]))


def fn(x, y):
    return 10 * x + y
print(reduce(fn, [1, 3, 5, 7, 9]))


def char2num(s):
    return {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9}[s]
ret = reduce(fn, map(char2num, "13579"))
print(ret)

# 形成一个函数
def str2int(s):
    def fn(x, y):
        return 10 * x + y

    def char2num(s):
        return {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9}[s]
    return reduce(fn, map(char2num, s))

def normalizeword(name):
    nn = name.lower()
    ss = nn[0].upper() + nn[1:]
    return ss
    # return name.capitalize()
L1 =['adam', 'LISA', 'barT']
L2 = list(map(normalizeword, L1))

print(L1)
print(L2)

def prod(l):
    return reduce(lambda x,y: x*y, l)
print("3*5*7*9=", prod([3, 5, 7, 9]))

def str2float(s):
    l = s.split('.', 2)
    ipart = reduce(fn, map(char2num, l[0]))
    fpart = reduce(fn, map(char2num, l[1]))
    return ipart*1.0+fpart/(10**len(l[1]))
print('str2float(\'123.456\') = ', str2float('123.456'))
