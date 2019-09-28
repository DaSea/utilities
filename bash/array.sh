#!/bin/bash

## 数组(下标从0开始)
### 需注意IFS环境变量, Input field separator, 保存了数组中元素的分割符
fruits[0]=Apple
fruits[1]=Orange # 通过下标赋值创建数组
fruits[2]="Hello pig"
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
fruits=(xiaohua "${fruits[@]}" Banana Cherry)
echo ${fruits[@]}
### 删除数组中元素
unset fruits[0]
echo ${fruits[@]}

