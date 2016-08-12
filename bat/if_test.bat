@echo off
echo ///////////////////////////////////////////////////////
echo if 测试
echo ///////////////////////////////////////////////////////
dir a:\
rem 如果推出代码为1(不成功) 就跳至标题1处执行
if errorlevel 1 goto 1
rem 如果推出代码为0(成功) 就跳至标题0处执行
if errorlevel 0 goto 0
:0
echo 命令执行成功
goto next

:1
echo 命令执行不成功
goto next


rem 下面主要测试变量相等的
:next
if not %1 == 1 goto no
echo 变量不相等
goto exit

:no
echo 变量相等
goto exit

rem 下面主要测试文件是否存在的
:exit
echo 程序从这里退出
if exist called.bat goto FILE1
echo 文件不存在
goto next2

:FILE1
echo 文件存在
goto next2

:next2
echo 从这里结束

rem 查看当前环境变量
set PATH
echo //////////////////////设置local前//////////////
setlocal
rem 重新设置环境变量, 只在当前文件有效
set PATH=E:\self
echo //////////////////////设置local后//////////////
set PATH
endlocal
echo //////////////////////解除local设置//////////////
set PATH

echo //////////////////////////////////////////////
echo shift测试
echo //////////////////////////////////////////////
echo %1 %2 %3 %4 %5 %6 %7 %8 %9
shift
echo %1 %2 %3 %4 %5 %6 %7 %8 %9
shift
echo %1 %2 %3 %4 %5 %6 %7 %8 %9

@echo on
