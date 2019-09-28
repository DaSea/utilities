#!/bin/bash

# local var
username = 'DaSea' # 声明变量
echo $usrname # 使用变量
unset $usrname # 删除变量

# 也可以用local关键字声明属于某个函数的局部变量, 在函数结束时消失
local local_var = "i am a local var"


# 环境变量
export USER_NAME = "DaSea"
echo $USER_NAME # 使用

# 常用环境变量
echo $HOME
echo $PATH
echo $PWD
echo $RANDOM
echo $UID
echo $PS1
echo $PS2

# 位置参数
# $0 脚本名称
# $1 ... $9 第一个到第九个参数列表
# ${10} ... ${N} 第十到第N个
# $* or $@ 除了$0 外的所有位置参数
# $# 不包括$0在内的参数个数
# $FUNCNAME 函数名称(仅在函数内有效)

# 如果变量为空, 赋给他们初始值
${VAR:='default'}
${$1:='first'}
FOO=${FOO:-'default'}

# shell 扩展

## 大括号扩展
### 字符区间等
echo beg{i, a, e}n
### 循环迭代的区间
echo {0..4} # 0 1 2 3 4
echo {00..8..2} # 00 02 04 06 08

## 命名置换
### 命令置换允许我们对一个命名求值,并将结果放到另一个命令或表达式中
now = `date +%T`
# or
now1 = $(date +%T)
echo $now
echo $now1

## 算数扩展 $((算数表达式))
x = 4
y = 7
echo $((x + y))
echo $((++x + y++))
echo $((x+y))

## 单引号与双引号
### 双引号, 变量引用或命令置换是会被展开的,而单引号则不会
echo "Your home: $HOME" # Your home: /home/<name>
echo 'Your home: $HOME' # Your home: $HOME

### 当局部变量或环境变量中包含空格时,需格外注意
input = "A String with   strange   whitespace"
echo $input
echo "$input"

FILE = "Favorite things.txt"
echo $FILE # 尝试输出俩个文件, Favorite 和 things.txt
echo "$FILE" # 输出一个

## 数组(下标从0开始)
### 需注意IFS环境变量, Input field separator, 保存了数组中元素的分割符
fruits[0] = Apple
fruits[1] = Orange # 通过下标赋值创建数组
fruits[2] = "Hello pig"
# echo one
echo ${fruits[1]}
# echo all
echo ${fruits[*]}
echo ${fruits[@]}
#### 每个元素占一行输出
printf "+ %s\n" ${fruits[*]} # 第二个元素中的Hello pig会输出俩个
printf "+ %s\n" "${fruits[*]}" # 只会输出一行, 提前展开
printf "+ %s\n" ${fruits[@]}
printf "+ %s\n" "${fruits[@]}"
#### 在引号内,${fruits[@]}将数组中的每个元素扩展为一个单独的参数, 数组中的空格得以保留
### 数组切片
echo ${fruits[@]:0:2} # 从0开始, 长度为2的元素
### 向数组中添加元素
fruits = (xiaohua "${fruits[@]}" Banana Cherry)
echo ${fruits[@]}
### 删除数组中元素
unset fruits[0]
echo ${fruits[@]}

## 基元和组合表达式

## 函数
my_func() {
    # 语句
}
my_func # 调用

### 带参数的函数
greeting() {
    # 如果$1非空
    if [[ -n $1 ]]; then
        echo "Hello, $1"
    else
        echo "Hello, unknown!"
    fi
}
greeting Feng
greeting
