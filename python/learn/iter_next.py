# -*- coding: utf-8 -*-
#!/bin/python
import sys

list = [1, 2, 3, 4]
it = iter(list)
for i in it:
    print(i, end=', ')

while True:
    try:
        print(next(it))
    except StopIteration:
        break

print("\n")


def fibonacci(n):
    a, b, counter = 0, 1, 0
    while True:
        if counter > n:
            return
        yield a
        a, b = b, a + b

        counter += 1
f = fibonacci(10)
while True:
    try:
        print(next(f), end=', ')
    except StopIteration:
        break
