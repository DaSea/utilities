@echo off
setlocal enabledelayedexpansion
:: 一般是复合语句的时候需要使用延迟变量

echo =============================================
:: 错误, var不会正确被识别
for /l %%i in (1,1,5) do (
    set /a var =%%i 
    echo %var%
)

echo =============================================
:: 开启环境变量延迟扩展 可以正确使用var
for /l %%i in (1,1,5) do (
    set /a var =%%i 
    echo !var!
)

echo =============================================
:: 错误,找不到var
set var1=test & echo %var1%
:: 正确
set var2=test & echo !var2!

echo =============================================
for /f  "tokens=* delims=" %%i in ("Hello world.") do (
    set n=%%i
    set n=!n:ld.=t!
    set n=!n:o w= S!
    set n=!n:He=Wi!
    echo !n!
)

echo =============================================
set mm=boy
set mm=girl&echo %mm%
set mm=girl&echo !mm!

echo =============================================
set var=abc
for /l %%i in (1 1 5) do (
    set var%%i=%%i
    echo %var%
    echo !var!
)
echo %var1% %var2% %var3% %var4% %var5%
echo !var1! !var2! !var3! !var4! !var5!

echo =============================================
:: 使用变量嵌套变量也可以使用变量延迟
:: call 这里实际是对命令行进行重新组织扩展，先扩展%%b%a%%%里面的%a%，使%a%变成a的值1，再用cal来扩展%b1%
::set a=1&set b1=10
::call,echo %%b%a%%%
set /a a=1,b1=10
Setlocal EnableDelayedExpansion
echo:!b%a%!

echo =============================================
set a=1000
set b=dd
set a%b%=9000
set c=!a%b%! 
echo %c%

pause