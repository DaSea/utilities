@echo off
set /p str=请输入任意长度的字符串:
echo 你输入了字符串: "%str%"
call :stringlenth "%str%" num
echo 字符串长度: %num%
pause

:stringlenth
:: echo %1
:: 字符串计算子程序
set substr=%~1
:: echo %substr%
:: 参数%1 为字符串"%str%", %~1则为去掉双引号
if not defined substr goto :eof
set Ret=0

:stringlenth_continue
set /a Ret +=1
set substr=%substr:~0,-1%
echo %substr%
if defined substr goto stringlenth_continue
if not "%2"=="" set %2=%Ret%
goto :eof