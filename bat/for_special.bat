@echo off
echo ------------------------------------------------
:: 找不到文件
for /f %%i in (test .txt) do echo %%i
:: 当成字符串处理
for /f %%i in ("test .txt") do echo %%i
:: 错误
for /f %%i in ('test .txt') do echo %%i
:: 找不到文件
for /f %%i in (`test .txt`) do echo %%i

echo ------------------------------------------------
:: for /f "delims==" %%i in ('set') do echo %%i

echo ------------------------------------------------
:: 使用usebakq时候需要将(command1)的单引号改为 反引号 `(1旁边的)
:: for /f "usebackq delims==" %%i in (`set`) do echo %%i

echo ------------------------------------------------
for /f "usebackq" %%i in ("test .txt") do echo %%i
pause