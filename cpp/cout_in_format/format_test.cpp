/**
* 测试c++怎么格式化输出
**/
#include <iostream>
#include <sstream>
#include <iomanip>

void bool_test() {
    //  输出true or false
    std::cout << std::boolalpha
                  << "boolalpha true: " << true << '\n'
                  << "boolalpha false: " << false << '\n';
    // 输出0 or 1
    std::cout << std::noboolalpha
                  << "noboolalpha true: " << true << '\n'
                  << "noboolalpha false: " << false << '\n';
    // booalpha parse
    bool b1, b2;
    std::istringstream is("true false");
    is >> std::boolalpha >> b1 >> b2;
    std::cout << '\"' << is.str() << "\" parsed as " << b1 << ' ' << b2 << '\n';
}

void integer_out_test() {
    // 输出指定进制的整数
    std::cout<<"无前导: "<<'\n'<<std::noshowbase
        << "The number 42 in octal:   " << std::oct << 42 << '\n'
        << "The number 42 in decimal: " << std::dec << 42 << '\n'
        << "The number 42 in hex:     " << std::hex << 42 << '\n';

    // 添加进制的前导
    std::cout << "有前导" <<'\n'<<std::showbase
        << "The number 42 in octal:   " << std::oct << 42 << '\n'
        << "The number 42 in decimal: " << std::dec << 42 << '\n'
        << "The number 42 in hex:     " << std::hex << 42 << '\n';

    // 通过掩码设置进制
    std::cout << "掩码操作进制显示" << std::endl;
    int num = 150;
    std::cout.setf(std::cout.oct, std::cout.basefield);
    std::cout.setf(std::cout.showbase);
    std::cout << num << '\n';

    std::cout.setf (std::cout.dec , std::cout.basefield);
    std::cout.setf (std::cout.showbase);
    std::cout << num << '\n';

    std::cout.setf(std::cout.hex, std::cout.basefield);
    std::cout.setf(std::cout.showbase);
    std::cout << num << '\n';

}

void aligment_test() {
    // 对齐
    std::cout << "===============对齐与填充操作=======================" << std::endl;
    std::cout << "Left fill:\n" << std::left << std::setfill('*')
             << std::setw(12) << -1.23  << '\n'
             << std::setw(12) << std::showpos << 1.23  << '\n'
             << std::setw(12) << std::dec << std::noshowpos <<std::showbase << 42 << '\n'
             << std::setw(12) << std::dec << std::showpos << std::showbase << 42 << '\n'
             << std::setw(12) << std::hex << std::showbase << 42 << '\n' <<'\n';

   std::cout << "Internal fill:\n" << std::internal
             << std::setw(12) << -1.23  << '\n'
             << std::setw(12) << std::showpos << 1.23  << '\n'
             << std::setw(12) << std::dec << std::noshowpos << std::showbase << 42 << '\n'
             << std::setw(12) << std::dec << std::showpos << std::showbase << 42 << '\n'
             << std::setw(12) << std::hex << std::showbase<< 42 << '\n'<< '\n';

   std::cout << "Right fill:\n" << std::right
             << std::setw(12) << -1.23  << '\n'
             << std::setw(12) << std::showpos << 1.23  << '\n'
             << std::setw(12) << std::dec << std::noshowpos << std::showbase << 42 << '\n'
             << std::setw(12) << std::dec << std::showpos << std::showbase << 42 << '\n'
             << std::setw(12) << std::hex << std::showbase << 42 << '\n'<< '\n';
}

void float_test() {
    int originPrecision = std::cout.precision();
    std::cout << "===========================================================" << std::endl;
    std::cout << "精度使用, 初始精度: "<<originPrecision << std::endl;
    std::cout <<std::setprecision(4) <<12.345678 <<std::endl ;    // 12.35  rounded!
    std::cout <<std::setprecision(10) <<12.345678 <<std::endl ;   // 12.345678 其实内部发生了 rounded, 而结果正好进位, 与原值相同

    std::cout << "===========================================================" << std::endl;
    std::cout << "小数的表示形式的使用" << std::endl;
    std::cout << "当前精度: "<<std::cout.precision() << std::endl;
    double f = 101 / 6.0 ;
    std::cout << "小数的表现形式:" << std::endl;
    std::cout <<"定点小数:"<<std::fixed << f <<std::endl ;
    std::cout <<"科学计数法:"<<std::scientific <<f <<std::endl ;
    std::cout <<"上一次设置的形式:"<<f*10 << std::endl;

    std::cout << "===========================================================" << std::endl;
    std::cout << "表现形式恢复为默认值, 这时候精度就表示小数的有效位数" << std::endl;
    std::cout.unsetf(std::ostream::floatfield);
    std::cout << "当前有效位数: "<<std::cout.precision() << std::endl;
    std::cout << f <<std::endl ;

    std::cout << "===========================================================" << std::endl;
    std::cout << "恢复为初始精度:"<<std::setprecision(originPrecision) << std::endl;
    std::cout << "当前精度: "<<std::cout.precision() << std::endl;

    std::cout << "===========================================================" << std::endl;
    std::cout << "显示十进制浮点" << std::endl;
    std::cout << "不显示浮点:"<<12.0 << std::endl;
    std::cout << "显示浮点:"<< std::showpoint<<10.0 << std::endl;
    std::cout << "不显示浮点:"<< std::noshowpoint<<10.0 << std::endl;
}

void address_out() {
    int a = 10;
    std::cout << "基本数据类型地址:" << static_cast<void*>(&a) << std::endl;

    std::string str = "hello!";
    std::cout << "string类型首地址:"<< static_cast<void*>(&str) << std::endl;

    char* strc = const_cast<char*>(str.c_str());
    std::cout << "string里面存放内容的地址:"<< static_cast<void*>(strc) << std::endl;
    std::cout << "string里面存放内容的地址:"<< static_cast<void*>(const_cast<char*>(str.c_str())) << std::endl;
}

int main(int argc, char const* argv[])
{
    // bool_test();

    // integer_out_test();

    // aligment_test();

    // float_test();

    address_out();

    return 0;
}
