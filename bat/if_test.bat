@echo off
echo ///////////////////////////////////////////////////////
echo if ����
echo ///////////////////////////////////////////////////////
dir a:\
rem ����Ƴ�����Ϊ1(���ɹ�) ����������1��ִ��
if errorlevel 1 goto 1
rem ����Ƴ�����Ϊ0(�ɹ�) ����������0��ִ��
if errorlevel 0 goto 0
:0
echo ����ִ�гɹ�
goto next

:1
echo ����ִ�в��ɹ�
goto next


rem ������Ҫ���Ա�����ȵ�
:next
if not %1 == 1 goto no
echo ���������
goto exit

:no
echo �������
goto exit

rem ������Ҫ�����ļ��Ƿ���ڵ�
:exit
echo ����������˳�
if exist called.bat goto FILE1
echo �ļ�������
goto next2

:FILE1
echo �ļ�����
goto next2

:next2
echo ���������

rem �鿴��ǰ��������
set PATH
echo //////////////////////����localǰ//////////////
setlocal
rem �������û�������, ֻ�ڵ�ǰ�ļ���Ч
set PATH=E:\self
echo //////////////////////����local��//////////////
set PATH
endlocal
echo //////////////////////���local����//////////////
set PATH

echo //////////////////////////////////////////////
echo shift����
echo //////////////////////////////////////////////
echo %1 %2 %3 %4 %5 %6 %7 %8 %9
shift
echo %1 %2 %3 %4 %5 %6 %7 %8 %9
shift
echo %1 %2 %3 %4 %5 %6 %7 %8 %9

@echo on
