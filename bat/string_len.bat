@echo off
set /p str=���������ⳤ�ȵ��ַ���:
echo ���������ַ���: "%str%"
call :stringlenth "%str%" num
echo �ַ�������: %num%
pause

:stringlenth
:: echo %1
:: �ַ��������ӳ���
set substr=%~1
:: echo %substr%
:: ����%1 Ϊ�ַ���"%str%", %~1��Ϊȥ��˫����
if not defined substr goto :eof
set Ret=0

:stringlenth_continue
set /a Ret +=1
set substr=%substr:~0,-1%
echo %substr%
if defined substr goto stringlenth_continue
if not "%2"=="" set %2=%Ret%
goto :eof