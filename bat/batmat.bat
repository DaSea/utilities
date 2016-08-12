@echo off&color a&mode con cols=90 lines=12
title 截取字符练习工具 by bat-zw19750516
set var=1234567890一二三四五六七八九零
cls&echo.&echo  原始图案为：%var%
echo.&echo  注意前面有10个阿拉伯数字后面有10个语文数字,等下截取后记得看下。
echo.&echo  命令形式为：%%var:~m,n%%,其中的m为第一个参数可负可正可为零，n为第二个参数可负可正不为零。
echo.&echo  为了方便重复练习没有设置退出,要退出请直接关闭窗口。
echo.&echo  请按任意键开始练习。&pause>nul

:begin
set a=&set b=&set "c="
cls&echo.&set /p a= 请输入第一个参数（应为小于20的整数）：
echo %a:-=%|findstr "[^0-9]"&&goto wrong
if "%a%" equ "" goto wrong
if %a% geq 20 goto wrong
cls&echo.&set /p b= 请输入第二个参数（应为大于-20并不为零的整数）：
echo %b:-=%|findstr "[^0-9]"&&goto wrong
if "%b%" equ "" goto wrong
if %b% equ 0 goto wrong
if %b% lss -20 goto wrong
set /a c=20-a b
if %a% lss 0 if %b% lss 0 if %a% geq %b% goto wrong
if %a% gtr 0 if %b% lss 0 if %c% leq 0 goto wrong
cls&echo.&echo  原始图案为： %var%
echo.&echo  你输入的截取命令是： %%var:~%a%,%b%%%
echo.&call,echo  截取到的图案是 ：%%var:~%a%,%b%%%
echo.&echo  请按任意键再次练习。&pause>nul&goto begin

:wrong
cls&echo.&echo  输入不合要求，请正确输入。&ping /n 2 127.1 >nul&goto begin

