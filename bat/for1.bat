@echo off
for %%i in (bbs,bathome,cn) do (
    echo %%i
)

echo ====列出所有文件====
for %%i in (*.*) do (
    echo "%%i"
)

echo ====列出txt类型的文件====
for %%i in (*.txt) do (
    echo "%%i"
)

echo ====列出文件名只有3个字符的bat文件====
for %%i in (???.bat) do (
    echo "%%i"
)

echo ====循环建立三个空文件====
for %%i in (1,2,3) do (
    type nul>test%%i.txt
)
pause