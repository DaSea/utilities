# -*- coding: utf-8 -*-
#!/bin/python

import re

# re.match 尝试从字符串的起始位置匹配一个模式，如果不是起始位置匹配成功的话，match()就返回none。
# 函数语法：
# re.match(pattern, string, flags=0)
# 正则表达式修饰符 - 可选标志

# # 正则表达式可以包含一些可选标志修饰符来控制匹配的模式。修饰符被指定为一个可选的标志。多个标志可以通过按位 OR(|) 它们来指定。如 re.I | re.M 被设置成 I 和 M 标志：
# # 修饰符	描述
# # re.I	使匹配对大小写不敏感
# # re.L	做本地化识别（locale-aware）匹配
# # re.M	多行匹配，影响 ^ 和 $
# # re.S	使 . 匹配包括换行在内的所有字符
# # re.U	根据Unicode字符集解析字符。这个标志影响 \w, \W, \b, \B.
# # re.X	该标志通过给予你更灵活的格式以便你将正则表达式写得更易于理解

print(re.match("www", "www.baidu.com").span())
print(re.match("www", "www.baidu.com"))
print(re.match("com", "www.baidu.com"))

line = "Cats are smarter than dogs"
matchObj = re.match(r'(.*) are (.*?) .*', line, re.M|re.I)
if matchObj:
    print("matchObj.group() : ", matchObj.group())
    print("matchObj.group(1) : ", matchObj.group(1))
    print("matchObj.group(2) : ", matchObj.group(2))
else:
    print("No match!!")

matchObj = re.match( r'dogs', line, re.M|re.I)
if matchObj:
    print("match --> matchObj.group() : ", matchObj.group())
else:
    print("No match!!")

matchObj = re.search( r'dogs', line, re.M|re.I)
if matchObj:
    print ("search --> matchObj.group() : ", matchObj.group())
else:
    print ("No match!!")

# 检索和替换
# Python 的re模块提供了re.sub用于替换字符串中的匹配项。
# 语法：
# re.sub(pattern, repl, string, count=0)
# 返回的字符串是在字符串中用 RE 最左边不重复的匹配来替换。如果模式没有发现，字符将被没有改变地返回。
# 可选参数 count 是模式匹配后替换的最大次数；count 必须是非负整数。缺省值是 0 表示替换所有的匹配。

phone = "2004-959-559 # 这是一个电话号码"
# 删除注释
num = re.sub(r'#.*$', "", phone)
print ("电话号码 : ", num)
# 移除非数字的内容
num = re.sub(r'\D', "", phone)
print ("电话号码 : ", num)
