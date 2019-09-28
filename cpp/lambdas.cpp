/*
 * Copyright (C) strftime("%Y-%m-%d") Dasea <hello@world.com>
 *
 * Description: You will get it!
 */

#include <iostream>
#include <string>

int main(int argc, char const* argv[])
{
    // call lambda directly
    []{
        std::cout << "hello lambda!" << std::endl;
    }();

    // pass it to object then call
    auto l = []{
        std::cout << "hello lambda test 2!" << std::endl;
    };
    l();

    std::string str;
    str.

    //
    auto l3 = [](const std::string& s){
        std::cout << "hello"<< s << std::endl;
    };
    l3("fuck woman!");

    int unit = 0;
    unit = 10;

    return 0;
}
