#include <iostream>
typedef unsigned char u1;
typedef char i1;
typedef float f4;
typedef double f8;
typedef unsigned short u2;
typedef short i2;
typedef unsigned int u4;
typedef int i4;
typedef unsigned long DWORD;
// 大端还是小端
#define ENDIAN_ORDER_BIG    (0)
#define ENDIAN_ORDER_SMALL  (1)

// 大端还是小端
i1 m_endianOrder;

void packU2ToBuffer(i1* buff, u2 dec) {
    if (ENDIAN_ORDER_BIG == m_endianOrder) {
        std::cout<<"big->small"<<std::endl;
        buff[0] = (i1)(u1)(dec&0x00ff);
        buff[1] = (i1)(u1)((dec>>8)&0x00ff);
    } else {
        memcpy(buff, &dec, 2);
    }
}

void packU4ToBuffer(i1* buff, u4 dec) {
    if (ENDIAN_ORDER_BIG == m_endianOrder) {
        packU2ToBuffer(buff, dec&0x0000ffff);
        packU2ToBuffer(buff+2, (dec>>16)&0x0000ffff);
    } else {
        memcpy(buff, &dec, 4);
    }
}

u2 getU2FromBuffer(i1* buff) {
    u2 ret = 0;
    if (ENDIAN_ORDER_BIG == m_endianOrder) {
        ret = ((((u2)buff[1]<<8)&0xff00) | ((u2)buff[0] & 0x00ff));
    } else {
        memcpy(&ret, buff, 2);
    }
    return (ret);
}

u4 getU4FromBuffer(i1* buff) {
    u4 ret = 0;
    if (ENDIAN_ORDER_BIG == m_endianOrder) {
        ret = ((((u4)buff[3] << 24) & 0xff0000ff)
            |  (((u4)buff[2] << 16) & 0x00ff0000)
            |  (((u4)buff[1] << 8 ) & 0x0000ff00)
            |  (((u4)buff[0]) & 0x000000ff));
    } else {
        memcpy(&ret, buff, 4);
        // ret = ((((u4)buff[0] << 24) & 0xff0000ff)
        //     |  (((u4)buff[1] << 16) & 0x00ff0000)
        //     |  (((u4)buff[2] << 8 ) & 0x0000ff00)
        //     |  (((u4)buff[3]) & 0x000000ff));
    }

    return (ret);
}

void testPackU2() {
    u2 dec = 0x1122;
    i1 buffer[3] = {0};
    m_endianOrder = ENDIAN_ORDER_BIG;
    packU2ToBuffer(buffer, dec);
    std::cout << "大端数据打包成小端序数据" <<std::hex<<(int)buffer[0]<<(int)buffer[1]<<std::endl;

    i1 buffer1[3] = {0};
    m_endianOrder = ENDIAN_ORDER_SMALL;
    packU2ToBuffer(buffer1, dec);
    std::cout << "小端数据打包成小端序数据:" <<std::hex<<(int)buffer1[0]<<(int)buffer1[1]<<std::endl;
}

void testPackU4() {
    u4 dec = 0x11223344;
    i1 buffer[5] = {0};
    m_endianOrder = ENDIAN_ORDER_BIG;
    packU4ToBuffer(buffer, dec);
    std::cout << "大端:" <<std::hex<<(int)buffer[0]<<(int)buffer[1]<<(int)buffer[2]<<(int)buffer[3]<< std::endl;

    i1 buffer1[5] = {0};
    m_endianOrder = ENDIAN_ORDER_SMALL;
    packU4ToBuffer(buffer1, dec);
    std::cout << "小端:" <<std::hex<<(int)buffer1[0]<<(int)buffer1[1]<<(int)buffer1[2]<<(int)buffer1[3]<< std::endl;
}

void testU2() {
    // unpack
    m_endianOrder = ENDIAN_ORDER_BIG; // 当前是大端
    i1 buffer[] = {0x22, 0x11};
    u2 dec = getU2FromBuffer(buffer);
    std::cout << "small->big: "<<std::dec<<dec << std::endl;

    m_endianOrder = ENDIAN_ORDER_SMALL;
    dec = getU2FromBuffer(buffer);
    std::cout << "small->small: "<<std::dec<<dec << std::endl;

    memcpy(&dec, buffer, 2);
    std::cout << "memcpy: "<<std::dec<<dec << std::endl;
}

void testU4() {
    m_endianOrder = ENDIAN_ORDER_BIG;
    i1 buffer[] = {0x44, 0x33, 0x22, 0x11};
    u4 dec = getU4FromBuffer(buffer);
    std::cout << "small -> big: "<<dec << std::endl;

    m_endianOrder = ENDIAN_ORDER_SMALL;
    dec = getU4FromBuffer(buffer);
    std::cout << "smallk->small: "<<dec << std::endl;

    memcpy(&dec, buffer, 4);
    std::cout << "memcpy: "<<dec << std::endl;
}


int main(int argc, char const* argv[])
{
    std::cout << "hello, world!" << std::endl;

    union {
        unsigned int a;
        unsigned char b;
    }c;
    c.a = 1;
    if (1 == c.b) {
        std::cout<<"小端序"<<std::endl;
    } else {
        std::cout << "大端序" << std::endl;
    }

    std::cout << "unpack u2 =============" << std::endl;
    testU2();
    std::cout << "unpack u2 =============" << std::endl;
    testU4();
    std::cout << "pack u2 ===============" << std::endl;
    testPackU2();
    std::cout << "pack u4 ===============" << std::endl;
    testPackU4();

    return 0;
}
