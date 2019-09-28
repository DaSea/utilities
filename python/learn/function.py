# -*- coding: utf-8 -*-
#!/bin/python
import sys
# 计算面积函数
def area(width, height):
    return width * height
 
def print_welcome(name):
    print("Welcome", name)

print_welcome("Runoob")
w = 4
h = 5
print("width =", w, " height =", h, " area =", area(w, h))

# 定义函数
def printme( str ):
   "打印任何传入的字符串"
   print (str)
   return
 
# 调用函数
printme("我要调用用户自定义函数!")
printme("再次调用同一函数")

# 按值传递参数和按引用传递参数
# 在 Python 中，所有参数（变量）都是按引用传递。如果你在函数里修改了参数，那么在调用这个函数的函数里，原始的参数也被改变了。例如：
# 可写函数说明
def changeme( mylist ):
   "修改传入的列表"
   mylist.append([1,2,3,4]);
   print ("函数内取值: ", mylist)
   return

# 调用changeme函数
mylist = [10,20,30];
changeme(mylist);
print ("函数外取值: ", mylist)


# 参数
# 以下是调用函数时可使用的正式参数类型：
#     必需参数
#     关键字参数
#     默认参数
#     不定长参数

# 必需参数
# 必需参数须以正确的顺序传入函数。调用时的数量必须和声明时的一样。
# 调用printme()函数，你必须传入一个参数，不然会出现语法错误：
#可写函数说明
def printme( str ):
   "打印任何传入的字符串"
   print(str)
   return
#调用printme函数
# printme() #error

# 关键字参数
# 关键字参数和函数调用关系紧密，函数调用使用关键字参数来确定传入的参数值。
# 使用关键字参数允许函数调用时参数的顺序与声明时不一致，因为 Python 解释器能够用参数名匹配参数值。
# 以下实例在函数 printme() 调用时使用参数名：
#可写函数说明
def printme(str1, str):
   "打印任何传入的字符串"
   print(str)
   return
#调用printme函数
printme(str = "菜鸟教程", str1='hello')

# 默认参数
# 调用函数时，如果没有传递参数，则会使用默认参数。以下实例中如果没有传入 age 参数，则使用默认值：
#可写函数说明
def printinfo( name, age = 35):
   "打印任何传入的字符串"
   print ("名字: ", name)
   print ("年龄: ", age)
   return
#调用printinfo函数
printinfo( age=50, name="runoob" )
print ("------------------------")
printinfo( name="runoob" )

# 不定长参数
# 你可能需要一个函数能处理比当初声明时更多的参数。这些参数叫做不定长参数，和上述2种参数不同，声明时不会命名。基本语法如下：
# def functionname([formal_args,] *var_args_tuple ):
#    "函数_文档字符串"
#    function_suite
#    return [expression]

# 加了星号（*）的变量名会存放所有未命名的变量参数。如果在函数调用时没有指定参数，它就是一个空元组。我们也可以不向函数传递未命名的变量。如下实例：
# 可写函数说明
def printinfo( arg1, *vartuple ):
   "打印任何传入的参数"
   print("输出: ")
   print(arg1)
   for var in vartuple:
      print(var)
   return
# 调用printinfo 函数
printinfo( 10 )
printinfo( 70, 60, 50 );

# 匿名函数
# python 使用 lambda 来创建匿名函数。
# 所谓匿名，意即不再使用 def 语句这样标准的形式定义一个函数。
#     lambda 只是一个表达式，函数体比 def 简单很多。
#     lambda的主体是一个表达式，而不是一个代码块。仅仅能在lambda表达式中封装有限的逻辑进去。
#     lambda 函数拥有自己的命名空间，且不能访问自有参数列表之外或全局命名空间里的参数。
#     虽然lambda函数看起来只能写一行，却不等同于C或C++的内联函数，后者的目的是调用小函数时不占用栈内存从而增加运行效率。
# 语法
# lambda 函数的语法只包含一个语句，如下：
# lambda [arg1 [,arg2,.....argn]]:expression

# 可写函数说明
sum = lambda arg1, arg2: arg1 + arg2
# 调用sum函数
print ("相加后的值为 : ", sum( 10, 20 ))
print ("相加后的值为 : ", sum( 20, 20 ))

# 预定义的清理行为
# 一些对象定义了标准的清理行为，无论系统是否成功的使用了它，一旦不需要它了，那么这个标准的清理行为就会执行。
# 这面这个例子展示了尝试打开一个文件，然后把内容打印到屏幕上:
for line in open("myfile.txt"):
    print(line, end="")

# 以上这段代码的问题是，当执行完毕后，文件会保持打开状态，并没有被关闭。
# 关键词 with 语句就可以保证诸如文件之类的对象在使用完之后一定会正确的执行他的清理方法:
with open("myfile.txt") as f:
    for line in f:
        print(line, end="")
# 以上这段代码执行完毕后，就算在处理过程中出问题了，文件 f 总是会关闭。 
