@echo off
for %%i in (bbs,bathome,cn) do (
    echo %%i
)

echo ====�г������ļ�====
for %%i in (*.*) do (
    echo "%%i"
)

echo ====�г�txt���͵��ļ�====
for %%i in (*.txt) do (
    echo "%%i"
)

echo ====�г��ļ���ֻ��3���ַ���bat�ļ�====
for %%i in (???.bat) do (
    echo "%%i"
)

echo ====ѭ�������������ļ�====
for %%i in (1,2,3) do (
    type nul>test%%i.txt
)
pause