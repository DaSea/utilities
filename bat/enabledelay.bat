@echo off
setlocal enabledelayedexpansion
:: һ���Ǹ�������ʱ����Ҫʹ���ӳٱ���

echo =============================================
:: ����, var������ȷ��ʶ��
for /l %%i in (1,1,5) do (
    set /a var =%%i 
    echo %var%
)

echo =============================================
:: �������������ӳ���չ ������ȷʹ��var
for /l %%i in (1,1,5) do (
    set /a var =%%i 
    echo !var!
)

echo =============================================
:: ����,�Ҳ���var
set var1=test & echo %var1%
:: ��ȷ
set var2=test & echo !var2!

echo =============================================
for /f  "tokens=* delims=" %%i in ("Hello world.") do (
    set n=%%i
    set n=!n:ld.=t!
    set n=!n:o w= S!
    set n=!n:He=Wi!
    echo !n!
)

echo =============================================
set mm=boy
set mm=girl&echo %mm%
set mm=girl&echo !mm!

echo =============================================
set var=abc
for /l %%i in (1 1 5) do (
    set var%%i=%%i
    echo %var%
    echo !var!
)
echo %var1% %var2% %var3% %var4% %var5%
echo !var1! !var2! !var3! !var4! !var5!

echo =============================================
:: ʹ�ñ���Ƕ�ױ���Ҳ����ʹ�ñ����ӳ�
:: call ����ʵ���Ƕ������н���������֯��չ������չ%%b%a%%%�����%a%��ʹ%a%���a��ֵ1������cal����չ%b1%
::set a=1&set b1=10
::call,echo %%b%a%%%
set /a a=1,b1=10
Setlocal EnableDelayedExpansion
echo:!b%a%!

echo =============================================
set a=1000
set b=dd
set a%b%=9000
set c=!a%b%! 
echo %c%

pause