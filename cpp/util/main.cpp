/*
 * Copyright (C) 2016-11-23 Dasea
 *
 * Description: 测试大小端接口
 */
#include "endian_util.hpp"

#include <iostream>

using namespace dutil;

int main(int argc, char const* argv[])
{
    std::cout << "hello, world!" << std::endl;

    int endianorder = DEndianUtil::endianOrder();
    if (ENDIAN_ORDER_SMALL == endianorder) {
        std::cout << "小端" << std::endl;
    } else {
        std::cout << "大端" << std::endl;
    }
    DEndianUtil::test();
    return 0;
}
