@echo off
echo -----------------------------------------
for /f %%i in (test1.txt) do (
    echo ===========
    echo %%i
)

echo -----------------------------------------
for /f "delims=," %%i in (test1.txt) do (
    echo ===========
    echo %%i
)
echo -----------------------------------------
for /f "delims=.," %%i in (test1.txt) do (
    echo ===========
    echo %%i
)

pause