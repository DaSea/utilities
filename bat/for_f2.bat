@echo off
:: delims���治���пո�, tokens֮ǰ��Ҫ�пո�
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
:: ������;��ͷ����
for /f "eol=;" %%i in (test4.txt) do echo %%i

echo -----------------------------------------------
:: eol����ֻ��ָ��һ���ַ�
for /f "eol=," %%i in (test4.txt) do echo %%i

echo -----------------------------------------------
for /f %%i in ('dir /a-d /b test*.txt') do echo %%i

pause