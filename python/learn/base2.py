# -*- coding: utf-8 -*-
#!/bin/python

# 逻辑运算符
a, b = 10, 20
# 与
if(a and b):
    print("a 与 b is true!")
else:
    print("a 与 b 有一个不为true")

# 或
if(a or b):
    print("a和b都为true, 或有一个为true")
else:
    print("都为false")

# 非
a = 0
if not a:
    print("a is false!")

# 成员运算符
# 除了以上的一些运算符之外，Python还支持成员运算符，测试实例中包含了一系列的成员，包括字符串，列表或元组。
# 运算符	描述	实例
# in	如果在指定的序列中找到值返回 True，否则返回 False。 	x 在 y 序列中 , 如果 x 在 y 序列中返回 True。
# not in	如果在指定的序列中没有找到值返回 True，否则返回 False。 	x 不在 y 序列中 , 如果 x 不在 y 序列中返回 True。

a = 10
b = 20
list = [1, 2, 3, 4, 5 ];
if ( a in list ):
   print ("1 - 变量 a 在给定的列表中 list 中")
else:
   print ("1 - 变量 a 不在给定的列表中 list 中")

if ( b not in list ):
   print ("2 - 变量 b 不在给定的列表中 list 中")
else:
   print ("2 - 变量 b 在给定的列表中 list 中")

# 修改变量 a 的值
a = 2
if ( a in list ):
   print ("3 - 变量 a 在给定的列表中 list 中")
else:
   print ("3 - 变量 a 不在给定的列表中 list 中")

# Python身份运算符
"""
身份运算符用于比较两个对象的存储单元
运算符	描述	实例
is	is是判断两个标识符是不是引用自一个对象	x is y, 如果 id(x) 等于 id(y) , is 返回结果 1
is not	is not是判断两个标识符是不是引用自不同对象	x is not y, 如果 id(x) 不等于 id(y). is not 返回结果 1
以下实例演示了Python所有身份运算符的操作：
"""

a = 20
b = 20
if ( a is b ):
   print ("1 - a 和 b 有相同的标识")
else:
   print ("1 - a 和 b 没有相同的标识")

if ( id(a) == id(b) ):
   print ("2 - a 和 b 有相同的标识")
else:
   print ("2 - a 和 b 没有相同的标识")

# 修改变量 b 的值
b = 30
if ( a is b ):
   print ("3 - a 和 b 有相同的标识")
else:
   print ("3 - a 和 b 没有相同的标识")

if ( a is not b ):
   print ("4 - a 和 b 没有相同的标识")
else:
   print ("4 - a 和 b 有相同的标识"

# Fibonacci series: 斐波纳契数
# 两个元素的总和确定了下一个数
a, b = 0, 1
while b < 1000:
    print(b, end=',')
    a, b = b, a+b

# if 嵌套
# 在嵌套 if 语句中，可以把 if...elif...else 结构放在另外一个 if...elif...else 结构中。
# if 表达式1:
#     语句
#     if 表达式2:
#         语句
#     elif 表达式3:
#         语句
#     else
#         语句
# elif 表达式4:
#     语句
# else:
#     语句

# while 循环使用 else 语句
# 在 while … else 在条件语句为 false 时执行 else 的语句块：
count = 0
while count < 5:
   print (count, " 小于 5")
   count = count + 1
else:
   print (count, " 大于或等于 5")