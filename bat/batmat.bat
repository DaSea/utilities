@echo off&color a&mode con cols=90 lines=12
title ��ȡ�ַ���ϰ���� by bat-zw19750516
set var=1234567890һ�����������߰˾���
cls&echo.&echo  ԭʼͼ��Ϊ��%var%
echo.&echo  ע��ǰ����10�����������ֺ�����10����������,���½�ȡ��ǵÿ��¡�
echo.&echo  ������ʽΪ��%%var:~m,n%%,���е�mΪ��һ�������ɸ�������Ϊ�㣬nΪ�ڶ��������ɸ�������Ϊ�㡣
echo.&echo  Ϊ�˷����ظ���ϰû�������˳�,Ҫ�˳���ֱ�ӹرմ��ڡ�
echo.&echo  �밴�������ʼ��ϰ��&pause>nul

:begin
set a=&set b=&set "c="
cls&echo.&set /p a= �������һ��������ӦΪС��20����������
echo %a:-=%|findstr "[^0-9]"&&goto wrong
if "%a%" equ "" goto wrong
if %a% geq 20 goto wrong
cls&echo.&set /p b= ������ڶ���������ӦΪ����-20����Ϊ�����������
echo %b:-=%|findstr "[^0-9]"&&goto wrong
if "%b%" equ "" goto wrong
if %b% equ 0 goto wrong
if %b% lss -20 goto wrong
set /a c=20-a b
if %a% lss 0 if %b% lss 0 if %a% geq %b% goto wrong
if %a% gtr 0 if %b% lss 0 if %c% leq 0 goto wrong
cls&echo.&echo  ԭʼͼ��Ϊ�� %var%
echo.&echo  ������Ľ�ȡ�����ǣ� %%var:~%a%,%b%%%
echo.&call,echo  ��ȡ����ͼ���� ��%%var:~%a%,%b%%%
echo.&echo  �밴������ٴ���ϰ��&pause>nul&goto begin

:wrong
cls&echo.&echo  ���벻��Ҫ������ȷ���롣&ping /n 2 127.1 >nul&goto begin

