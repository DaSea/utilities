@echo off
goto ltest

:dtest
echo -------------------------------------------------------
:: 打印c盘目录
for /d %%i in (c:\*) do echo %%i

echo -------------------------------------------------------
:: 打印c盘目录五个字符的目录
for /d %%i in (?????) do echo %%i

echo -------------------------------------------------------
:: 如果路径有空格, 用双引号
for /d %%i in ("c:\Program files\*") do echo %%i

echo ------------------------------------------------------
:: 搜索以w开头的
for /d %%i in (c:\w*) do echo %%i

echo ------------------------------------------------------
:: 搜索以w开头的, 以s结尾的
for /d %%i in (c:\w*s) do echo %%i

echo ------------------------------------------------------
:: 删除当前目录下的文件夹
:: for /d %%i in (*) do rd /s /q "%%i"
:: 上面的可以写作如下, 测试成功后，把echo 去掉，这时执行命令才会生效，防止出错！
:: for /d %%i in (*)do echo rd /s /q "%%~fi"

: rtest
echo ------------------------------------------------------
:: set 中的文件名如果含有通配符(？或*)，则列举/R 参数指定的目录及其下面的所有子目录中与 set 相符合的
:: 所有文件，无相符文件的目录则不列举。 
for /r %%i in (*.txt) do echo %%i

echo ------------------------------------------------------
:: set  中为具体文件名，不含通配符，则枚举该目录树（即列举该目录及其下面的所有子目录），
:: 而不管set 中的指定文件是否存在。这与前面所说的单点（.）枚举目录树是一个道理，
:: 单点代表当前目录，也可视为一个文件。
for /r %%i in (test.txt) do echo %%i
:: test6.txt不存在也枚举出来
for /r %%i in (test6.txt) do echo %%i
echo ------------------------------------------------------
:: 判断是否存在
for /r %%i in (test.txt) do if exist %%i echo %%i


:ltest
echo ------------------------------------------------------
for /l %%i in (1,3,10) do echo %%i

echo ------------------------------------------------------
:: for /l %%i in (1,1,5) do start cmd
for /l %%i in (1,1,5) do md %%i

echo ------------------------------------------------------
:: 搜索以w开头的, 以s结尾的
echo ------------------------------------------------------
:: 搜索以w开头的, 以s结尾的
pause