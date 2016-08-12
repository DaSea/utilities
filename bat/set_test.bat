@echo off
goto substr

:general
set var=abcd
echo var的值为%var%

:: 清除变量,使其成为未定义状态
set var=
if defined var (echo var的值为%var%) else echo var没有赋值

set var1=""
if defined var1 (echo var1的值为%var1%) else echo var1没有赋值

:: set还可以提供一个交互界面,让用户自己输入变量的值,
:: 然后我们在来根据这个值来做相应操作,只需要加一个"/P"参数就可以了!
set /p var2=请输入变量的值: 
echo 您输入了%var2% 

:replace
set a= bbs. bathome.cn
echo 替换前为:"%a%"

:: 删除里面的空格
set var=%a: =%
echo 替换后为: %var%

set var1= %a:.=逗号%
echo 替换后为: %var1%

:substr
set a=www.github.com
echo 源字符串为: %a%
set var=%a:~3,5%
echo 截取的一点: %var%

:: 倒数从-1开始
:: 从第一个到倒数第三个之前的(ww.github.)
set var3=%a:~1,-3%
echo %var3%

:: 倒数第三个之后的(com)
set var4=%a:~-3%
echo %var4%

:: 从倒数第三个开始取俩个字符(co)
set var1=%a:~-3,2%
echo %var1%

::从第三个开始到结束(.github.com)
set var2=%a:~3%
echo %var2%
pause