# -*- coding: utf-8 -*-
#!/usr/bin/env python3

# 生成器


# 杨辉三角
def trianges():
    L = [1]
    while True:
        yield L
        L.append(0)
        print(len(L))
        L = [L[j-1]+L[j] for j in range(len(L))]

n = 0
for t in trianges():
    print(t)
    n = n+1
    if n == 10:
        break
