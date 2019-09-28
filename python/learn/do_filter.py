# -*- coding: utf-8 -*-
#!/usr/bin/env python3

def is_palindrome(n):
    strn = str(n)
    hlen = len(strn)//2
    if hlen < 1:
        return False
    #  print(hlen)
    j = -1
    for i in range(hlen):
        #  print(i)
        #  print(j)
        if strn[i] != strn[j]:
            return False
        j -= 1
    return True


if __name__ == '__main__':
    output = filter(is_palindrome, range(1, 1000))
    #  print(is_palindrome(12321))
    #  print(is_palindrome(909))
    print(list(output))
