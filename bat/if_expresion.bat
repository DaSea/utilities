@echo off
goto errorlevel
set /p var1=�������ַ���1:
set /p var2=�������ַ���2:
if %var1% == %var2% (
    echo ������ַ������
) else echo ������ַ��������

if "a" == "A" (
    echo ����������ַ���ͬ
) else echo ����������ַ���ͬ

if /i "a" == "A" (
    echo ����������ַ���ͬ
) else echo ����������ַ���ͬ

set /p num1=����������:
if %num1% geq 10 (
    echo ��������10
) else (
    echo ����С��10
)

:: �ַ����Ƚ϶���������
if "12" lss "4" (
    echo 12��Ȼ��С��4!
) else (
    echo 12��Ȼ����С��4
)

if 12 lss 4 (
    echo 12��Ȼ��С��4!
) else (
    echo 12��Ȼ����С��4
)

if exist "e:" (echo e�̴���) else echo e�̲�����

if exist d:\123.bat (echo 123.bat�ļ�����) else echo 123.bat�ļ�������

dir /a-d d:\123.bat >nul 2>nul
if %errorlevel%==0 (echo 123.bat�ļ�����!) else echo 123.bat�ļ�������

:: �ж��ļ����Ƿ����
if exist test\ (echo test���ļ���) else echo test���ļ�
if exist test\. (echo test���ļ���) else echo test���ļ�
if exist test\nul (echo test���ļ���) else echo test���ļ�

:variable
if defined a (echo ����a�Ѷ���) else echo ����aû������

echo a=
set a=
if defined a (echo ����a�Ѷ���) else echo ����aû������

echo a=10
set a=10
if defined a (echo ����a�Ѷ���) else echo ����aû������

set var5=5
if defined var5 (echo ����var5�Ѷ���) else (echo ����var5û�б�����)
set /p var6=������һ������:
if defined %var6% (echo ����var6�Ѷ���) else (echo ����var6û�б�����)

set var7=5
if defined var7 (echo ����var7�Ѷ���) else (echo ����var7û�б�����)
set /p var8=������һ������:
if defined var8 (echo ����var8�Ѷ���) else (echo ����var8û�б�����)

:errorlevel
net user
if %errorlevel% ==0 (echo neu userִ�гɹ�) else (echo net user����ִ��ʧ��)

set /p input=����������һ����� 
if errorlevel 0 (echo %input% ����ִ�гɹ�) else (echo %input% ����ִ��ʧ��)

pause