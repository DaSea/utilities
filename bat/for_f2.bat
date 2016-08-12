@echo off
:: delims后面不能有空格, tokens之前需要有空格
::for /f "delims=, tokens=3" %%i in (test2.txt) do (
::    echo %%i
::)

for /f "tokens=1-3" %%i in (test2.txt) do (
    echo %%i
    echo %%j
    echo %%k
)

echo -----------------------------------------------
for /f "delims=, tokens=2-5" %%i in (test3.txt) do (
    echo %%i
    echo %%j
    echo %%k
    echo %%l
)
echo -----------------------------------------------
for /f "delims=, tokens=2,3-5" %%i in (test3.txt) do (
    echo %%i
    echo %%j
    echo %%k
    echo %%l
)
echo -----------------------------------------------
for /f "skip=2" %%i in (test3.txt) do echo %%i

echo -----------------------------------------------
:: 忽略以;开头的行
for /f "eol=;" %%i in (test4.txt) do echo %%i

echo -----------------------------------------------
:: eol后面只能指定一个字符
for /f "eol=," %%i in (test4.txt) do echo %%i

echo -----------------------------------------------
for /f %%i in ('dir /a-d /b test*.txt') do echo %%i

pause