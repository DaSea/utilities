# -*- coding: utf-8 -*-
#!/usr/bin/env python3

def sort_byname(t):
    return t[0]

def sort_byscore(t):
    return t[1]

if __name__ == '__main__':
    L = [('Bob', 75), ('Adam', 92), ('Bart', 66), ('Lisa', 88)]

    L1 = sorted(L, key=sort_byname)
    print(L1)

    L2 = sorted(L, key=sort_byscore, reverse=True)
    print(L2)
