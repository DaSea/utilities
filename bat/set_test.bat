@echo off
goto substr

:general
set var=abcd
echo var��ֵΪ%var%

:: �������,ʹ���Ϊδ����״̬
set var=
if defined var (echo var��ֵΪ%var%) else echo varû�и�ֵ

set var1=""
if defined var1 (echo var1��ֵΪ%var1%) else echo var1û�и�ֵ

:: set�������ṩһ����������,���û��Լ����������ֵ,
:: Ȼ�����������������ֵ������Ӧ����,ֻ��Ҫ��һ��"/P"�����Ϳ�����!
set /p var2=�����������ֵ: 
echo ��������%var2% 

:replace
set a= bbs. bathome.cn
echo �滻ǰΪ:"%a%"

:: ɾ������Ŀո�
set var=%a: =%
echo �滻��Ϊ: %var%

set var1= %a:.=����%
echo �滻��Ϊ: %var1%

:substr
set a=www.github.com
echo Դ�ַ���Ϊ: %a%
set var=%a:~3,5%
echo ��ȡ��һ��: %var%

:: ������-1��ʼ
:: �ӵ�һ��������������֮ǰ��(ww.github.)
set var3=%a:~1,-3%
echo %var3%

:: ����������֮���(com)
set var4=%a:~-3%
echo %var4%

:: �ӵ�����������ʼȡ�����ַ�(co)
set var1=%a:~-3,2%
echo %var1%

::�ӵ�������ʼ������(.github.com)
set var2=%a:~3%
echo %var2%
pause