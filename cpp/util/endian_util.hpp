/*
 * Copyright (C) 2016-11-23 Dasea
 *
 * Description: 大端小端的一个转换类
 */
#ifndef __ENDIAN_UTIL_HPP__
#define __ENDIAN_UTIL_HPP__

namespace dutil {

/**
 * 大小端类型
 **/
#define ENDIAN_ORDER_SMALL (1)
#define ENDIAN_ORDER_BIG (2)

/**
 * 大小端操作类
 */
class DEndianUtil {
public:
    static int endianOrder();

    // 由大端的buffer获取实际数据(当前系统字节序)
    // 0x11223344: buffer[0]=0x11; buffer[1]=0x22; buffer[2]=0x33;buffer[3]=0x44
    static void convertFromBigOrderBuffer(const char* buffer, int& dec);
    static void convertFromBigOrderBuffer(const char* buffer, short& dec);
    static void convertFromBigOrderBuffer(const char* buffer, float& dec);
    static void convertFromBigOrderBuffer(const char* buffer, double& dec);

    // 由小端的buffer获取实际数据(当前系统字节序)
    // 0x11223344: buffer[0]=0x44; buffer[1]=0x33; buffer[2]=0x22;buffer[3]=0x11
    static void convertFromLittleOrderBuffer(const char* buffer, int& dec);
    static void convertFromLittleOrderBuffer(const char* buffer, short& dec);
    static void convertFromLittleOrderBuffer(const char* buffer, float& dec);
    static void convertFromLittleOrderBuffer(const char* buffer, double& dec);

    // 由数据获取大端buffer
    static void convertToBigOrderBuffer(char* buffer, int dec);
    static void convertToBigOrderBuffer(char* buffer, short dec);
    static void convertToBigOrderBuffer(char* buffer, float dec);
    static void convertToBigOrderBuffer(char* buffer, double dec);

    // 由数据获取小端buffer
    static void convertToLittleOrderBuffer(char* buffer, int dec);
    static void convertToLittleOrderBuffer(char* buffer, short dec);
    static void convertToLittleOrderBuffer(char* buffer, float dec);
    static void convertToLittleOrderBuffer(char* buffer, double dec);

    // test
    static void test();

private:
    static void _judgeEndianOrder();

private:
    static int _endianOrder;
};
} // namespace dutil

#endif // __ENDIAN_UTIL_HPP__
