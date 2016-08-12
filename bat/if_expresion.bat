@echo off
goto errorlevel
set /p var1=请输入字符串1:
set /p var2=请输入字符串2:
if %var1% == %var2% (
    echo 输入的字符串相等
) else echo 输入的字符串不相等

if "a" == "A" (
    echo 输入的俩个字符相同
) else echo 输入的俩个字符不同

if /i "a" == "A" (
    echo 输入的俩个字符相同
) else echo 输入的俩个字符不同

set /p num1=请输入数字:
if %num1% geq 10 (
    echo 此数大于10
) else (
    echo 此数小于10
)

:: 字符串比较而不是数字
if "12" lss "4" (
    echo 12竟然会小于4!
) else (
    echo 12当然不会小于4
)

if 12 lss 4 (
    echo 12竟然会小于4!
) else (
    echo 12当然不会小于4
)

if exist "e:" (echo e盘存在) else echo e盘不存在

if exist d:\123.bat (echo 123.bat文件存在) else echo 123.bat文件不存在

dir /a-d d:\123.bat >nul 2>nul
if %errorlevel%==0 (echo 123.bat文件存在!) else echo 123.bat文件不存在

:: 判断文件夹是否存在
if exist test\ (echo test是文件夹) else echo test是文件
if exist test\. (echo test是文件夹) else echo test是文件
if exist test\nul (echo test是文件夹) else echo test是文件

:variable
if defined a (echo 变量a已定义) else echo 变量a没被定义

echo a=
set a=
if defined a (echo 变量a已定义) else echo 变量a没被定义

echo a=10
set a=10
if defined a (echo 变量a已定义) else echo 变量a没被定义

set var5=5
if defined var5 (echo 变量var5已定义) else (echo 变量var5没有被定义)
set /p var6=请输入一个数字:
if defined %var6% (echo 变量var6已定义) else (echo 变量var6没有被定义)

set var7=5
if defined var7 (echo 变量var7已定义) else (echo 变量var7没有被定义)
set /p var8=请输入一个数字:
if defined var8 (echo 变量var8已定义) else (echo 变量var8没有被定义)

:errorlevel
net user
if %errorlevel% ==0 (echo neu user执行成功) else (echo net user命令执行失败)

set /p input=请输入任意一条命令： 
if errorlevel 0 (echo %input% 命令执行成功) else (echo %input% 命令执行失败)

pause