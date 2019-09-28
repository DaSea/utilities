# -*- coding: utf-8 -*-
# !/usr/bin/python

import os


print("hello world!")
sqlite.

# Indent
if True:
    print("true!")
else:
    print("false!")

# 这是一个单行注释
'''
这是一个多行注释
这是一个多行注释
'''

"""
这也是一个多行注释
"""

# variable
counter = 100          # 整型变量
miles = 1000.0       # 浮点型变量
name = "runoob"     # 字符串

print(counter)
print(miles)
print(name)

a, b, c = 1, 2, "runoob"

# Python3 中有六个标准的数据类型：
# Number（数字）
# 数据类型是不允许改变的,这就意味着如果改变数字数据类型得值，将重新分配内存空间
# Python3 支持 int、float、bool、complex（复数）

a, b, c, d = 20, 5.5, True, 4 + 3j
# 在Python2中是没有布尔型的，它用数字0表示False，用1表示True。到Python3中，把True和False定义成关键字了，但它们的值还是1和0，它们可以和数字相加

# 可以使用del语句删除一些对象引用

del a, b, c, d
# 数值运算
# 5 + 4 = 9  # 加法
# 4.3 - 2 =2.3 # 减法 2.3
# 3 * 7=21  # 乘法
# 2 / 4=0.5  # 除法，得到一个浮点数
# 2 // 4=0 # 除法，得到一个整数
# 17 % 3=2 # 取余
# 2 ** 5=32 # 乘方2^5


# String（字符串）
# Python中的字符串用单引号(')或双引号(")括起来，同时使用反斜杠(\)转义特殊字符。
# 字符串的截取的语法格式如下： 变量[头下标:尾下标]
# 索引值以 0 为开始值，-1 为从末尾的开始位置。
# 加号 (+) 是字符串的连接符， 星号 (*) 表示复制当前字符串，紧跟的数字为复制的次数。实例如下

str = 'Runoob'
print(str)          # 输出字符串
print(str[0:-1])    # 输出第一个个到倒数第二个的所有字符
print(str[0])       # 输出字符串第一个字符
print(str[2:5])     # 输出从第三个开始到第五个的字符
print(str[2:])      # 输出从第三个开始的后的所有字`符
print(str * 2)      # 输出字符串两次
print(str + "TEST")  # 连接字符串
print("run\noob")
print(r'run\noob')
# 字符串不能改变
str[2] = 'l'  # error

# Python 支持格式化字符串的输出 。尽管这样可能会用到非常复杂的表达式，但最基本的用法是将一个值插入到一个有字符串格式符 %s 的字符串中。
# 在 Python 中，字符串格式化使用与 C 中 sprintf 函数一样的语法。
print ("我叫 %s 今年 %d 岁!" % ('小明', 10))

# List（列表）
# List（列表） 是 Python 中使用最频繁的数据类型。
# 列表可以完成大多数集合类的数据结构实现。列表中元素的类型可以不相同，它支持数字，字符串甚至可以包含列表（所谓嵌套）。
# 列表是写在方括号([])之间、用逗号分隔开的元素列表。
# 和字符串一样，列表同样可以被索引和截取，列表被截取后返回一个包含所需元素的新列表。
# # 列表截取的语法格式如下： 变量[头下标:尾下标]
# 索引值以 0 为开始值，-1 为从末尾的开始位置。
# 加号（+）是列表连接运算符，星号（*）是重复操作。如下实例：
list = ['abcd', 786, 2.23, 'runoob', 70.2]
tinylist = [123, 'runoob']
print(list)            # 输出完整列表
print(list[0])         # 输出列表第一个元素
print(list[1:3])       # 从第二个开始输出到第三个元素
print(list[2:])        # 输出从第三个元素开始的所有元素
print(tinylist * 2)    # 输出两次列表
print(list + tinylist)  # 连接列表
## 列表中的元素可以改变
list[3] = 122
## 内置很多方法

# Tuple（元组）
## 元组（tuple）与列表类似，不同之处在于元组的元素不能修改。元组写在小括号(())里，元素之间用逗号隔开。
# 元组中的元素类型也可以不相同：
# 元组与字符串类似，可以被索引且下标索引从0开始，-1 为从末尾开始的位置。也可以进行截取（看上面，这里不再赘述）。
# 其实，可以把字符串看作一种特殊的元组
tuple = ( 'abcd', 786 , 2.23, 'runoob', 70.2  )
tinytuple = (123, 'runoob')
print(tuple)             # 输出完整元组
print(tuple[0])          # 输出元组的第一个元素
print(tuple[1:3])        # 输出从第二个元素开始到第三个元素
print(tuple[2:])         # 输出从第三个元素开始的所有元素
print(tinytuple * 2)     # 输出两次元组
print(tuple + tinytuple) # 连接元组

# 虽然tuple的元素不可改变，但它可以包含可变的对象，比如list列表。
# 构造包含 0 个或 1 个元素的元组比较特殊，所以有一些额外的语法规则：
tup1 = ()    # 空元组
tup2 = (20,) # 一个元素，需要在元素后添加逗号

# 字符串, list, tuple都属于序列

# Sets（集合）
#  集合（set）是一个无序不重复元素的序列。
# 基本功能是进行成员关系测试和删除重复元素。
# 可以使用大括号({})或者 set()函数创建集合，注意：创建一个空集合必须用 set() 而不是 { }，因为 { } 是用来创建一个空字典。

# 创建空集合
sets1 = set()

student = {'Tom', 'Jim', 'Mary', 'Tom', 'Jack', 'Rose'}
print(student)   # 输出集合，重复的元素被自动去掉
# 成员测试
if('Rose' in student) :
    print('Rose 在集合中')
else :
    print('Rose 不在集合中')


# set可以进行集合运算
a = set('abracadabra')
b = set('alacazam')
print(a)
print(a - b)     # a和b的差集
print(a | b)     # a和b的并集
print(a & b)     # a和b的交集
print(a ^ b)     # a和b中不同时存在的元素

# Dictionary（字典）
#  字典（dictionary）是Python中另一个非常有用的内置数据类型。
# 列表是有序的对象结合，字典是无序的对象集合。两者之间的区别在于：字典当中的元素是通过键来存取的，
# 而不是通过偏移存取。
# 字典是一种映射类型，字典用"{ }"标识，它是一个无序的键(key) : 值(value)对集合。
# 键(key)必须使用不可变类型。
# 在同一个字典中，键(key)必须是唯一的。

dict = {}
dict['one'] = "1 - 菜鸟教程"
dict[2]     = "2 - 菜鸟工具"

tinydict = {'name': 'runoob','code':1, 'site': 'www.runoob.com'}
print(dict['one'])       # 输出键为 'one' 的值
print(dict[2])           # 输出键为 2 的值
print(tinydict)          # 输出完整的字典
print(tinydict.keys())   # 输出所有键
print(tinydict.values()) # 输出所有值
## 内置函数 clear keys, values
