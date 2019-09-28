# -*- coding: utf-8 -*-
#!/bin/python

num = int(input("请输入一个数:"))

sum = 0
n = len(str(num))

temp = num
while temp > 0:
    digit = temp%10
    sum += digit**n
    temp //= 10

if sum == num:
    print(num, "是一个阿姆斯特朗数!")
else:
    print(num, "不是一个阿姆斯特朗数!")
