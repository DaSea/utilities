@echo off
set /p str=���������ⳤ�ȵ��ַ���:
echo ���������ַ���:"%str%"
call :stringlenth "%str%" num
echo �ַ�������Ϊ��%num%
pause

:stringLenth
::�ַ������ȼ����ӳ���
set thestring=%~1
::����%1 Ϊ�ַ���"%str%"��%~1��ȥ��"%str%"��˫���š�
if not defined theString goto :eof
set Return=0

:stringLenth_continue
set /a Return +=1
set thestring=%thestring:~0,-1%
::ƫ����Ϊ1,��ȡ������1λǰ�������ַ���
if defined thestring goto stringLenth_continue
if not "%2"=="" set %2=%Return%
::����%2Ϊ���ر���num�����ƣ����ܺ��ո�������ַ���
goto :eof