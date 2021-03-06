@echo off
echo ///////////////////////////////////
echo dir学习
echo //////////////////////////////////
echo 输出dir帮助
dir /?

echo;
echo //////////////////////////////////
echo 普通输出
echo //////////////////////////////////
dir c:\

echo;
echo //////////////////////////////////
echo 只输出文件名
echo //////////////////////////////////
dir /b c:\

echo;
echo //////////////////////////////////
echo 对于很多数据分页输出
echo //////////////////////////////////
dir /p c:\

echo;
echo //////////////////////////////////
echo 按属性输出
echo //////////////////////////////////
:: 列出隐藏的文件
dir /ah c:\
:: 列出所有的文件
dir /ad c:\
:: 列出C:\下所有的文件夹，但不包含隐含的文件夹。
dir /ad-h c:\

echo;
echo //////////////////////////////////
echo 按分类输出
echo //////////////////////////////////
:: 优先列出文件夹，并且文件夹和文件都按字母顺序排列。
dir /ogn c:\
:: /o:排序方式 参数指定了dir命令显示命令结果时的排序方式，排序方式设为“n”即代表按照文件名的字母顺序排列
dir /on c:\

echo;
echo //////////////////////////////////
echo 其他
echo //////////////////////////////////

@echo on