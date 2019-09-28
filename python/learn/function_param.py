# -*- coding: utf-8 -*-
#!/usr/bin/env python3

## POSITION_OR_KEYWORD ( 位置或关键字传参 )
def foo(a):
    print(a)

### 位置传参调用
foo(1)
### 关键字传参调用
foo(a=4)

## VAR_POSITIONAL( 可变的位置传参 )
### 通过* 前缀, 只能通过位置传参调用, 不能用关键字
### 以一个元组显示
def foo_var_pos(*tu):
    print(tu)
foo_var_pos()
foo_var_pos(1, 2.0, '3', True)

## KEYWORD_ONLY ( 关键字传参 )
### 只会在VAR_POSITIONAL类型的后面, 且不带**前缀, 这种只能通过关键字传参
### 不能通过位置传参
def foo_keyword_only(*, c):
    print(c)

foo_keyword_only(c=222)

## VAR_KEYWORD( 可变的关键字参数 )
### 只能通过**前缀来声明, 在函数内部通过字典表示
def foo_var_keyword(**vark):
    print(vark)

foo_var_keyword(a=1, b=3, c='22', d=False)

## POSITIONAL_ONLY( 被遗弃的 )


## 默认参数
### POSITION_OR_KEYWORD 和 KEYWORD_ONLY 可以定义默认参数, 其他俩种不可以
### 默认参数的位置
#### POSITION_OR_KEYWORD 类型的默认参数一定要放到后面
#### KEYWORD_ONLY 无要求
### 默认参数绝对不能设置为可变类型(比如list, dict), 不然如果你在函数内改变了, 下次调用时就不是默认参数了
def foo_default(p1, p2=2.0, *, k1, k2=None):
    a_list = k1 or list()
    pass

foo_default(1, k1='2')

## 接收参数的优先级
###  1. POSITION_OR_KEYWORD
###  2. KEYWORD_ONLY
###  3. VAR_POSITIONAL 和 VAR_KEYWORD

def foo_priority(a, *b, c, **d):
    print(a, b, c, d, sep='\n')

foo_priority(1, 2, '3', c=3, x=1, y=2)

## 适用场景
### 可变长位置参数VAR_POSITIONAL与KEYWORD_ONLY 配合使用
def my_print(*args, sep='', end='\n'):
    string = sep.join(map(str, args)) + end
    print(string)

my_print(1,2,[12, (12, {4,True})],(12.2,False))
my_print(1,2,[12, (12, {4,True})],(12.2,False), sep=', ')
my_print(1,2,[12, (12, {4,True})],(12.2,False), end='\ndone!\n')

