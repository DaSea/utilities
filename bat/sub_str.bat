@echo off
echo "%time%"
echo �������е����������
echo ��ȫ·����%0
echo ȥ�����ţ�%~0
echo ���ڷ�����%~d0
echo ����·����%~p0
echo �ļ�����%~n0
echo ��չ����%~x0
echo �ļ����ԣ�%~a0
echo �޸�ʱ�䣺%~t0
echo �ļ���С��%~z0

set aa=C:\Windows\PPP\a.btx
call :deal aaa %aa% "c c" ddd eee
pause>nul
:deal
��echo %%0 = %0
��echo %%1 = %1
��echo %%2 = %2
��echo %%3 = %3
��echo %%4 = %4
��echo %%5 = %5

pause
