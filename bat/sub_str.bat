@echo off
echo "%time%"
echo 正在运行的这个批处理：
echo 完全路径：%0
echo 去掉引号：%~0
echo 所在分区：%~d0
echo 所处路径：%~p0
echo 文件名：%~n0
echo 扩展名：%~x0
echo 文件属性：%~a0
echo 修改时间：%~t0
echo 文件大小：%~z0

set aa=C:\Windows\PPP\a.btx
call :deal aaa %aa% "c c" ddd eee
pause>nul
:deal
　echo %%0 = %0
　echo %%1 = %1
　echo %%2 = %2
　echo %%3 = %3
　echo %%4 = %4
　echo %%5 = %5

pause
