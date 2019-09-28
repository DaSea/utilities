#include <iostream>

enum EnumTest{
    ENUM_TEST_1 = 1,
    ENUM_TEST_2 = 2,
    ENUM_TEST_3 = 3
};

int main(int argc, char** argv)
{
    int num1 = 4;
    EnumTest tt = ENUM_TEST_1;
    
    std::cout<<num1<<" "<<tt<<std::endl;
    
    tt = static_cast<EnumTest>(num1);
    std::cout<<(int)tt<<std::endl;
    
    return 0;
}
