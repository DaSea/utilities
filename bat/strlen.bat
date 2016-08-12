@echo off
set /p str=请输入任意长度的字符串:
echo 你输入了字符串:"%str%"
call :stringlenth "%str%" num
echo 字符串长度为：%num%
pause

:stringLenth
::字符串长度计算子程序
set thestring=%~1
::参数%1 为字符串"%str%"，%~1则去掉"%str%"的双引号。
if not defined theString goto :eof
set Return=0

:stringLenth_continue
set /a Return +=1
set thestring=%thestring:~0,-1%
::偏移量为1,截取倒数第1位前的所有字符。
if defined thestring goto stringLenth_continue
if not "%2"=="" set %2=%Return%
::参数%2为返回变量num的名称，不能含空格或特殊字符。
goto :eof