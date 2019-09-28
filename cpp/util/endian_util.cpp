/*
 * Copyright (C) 2016-11-23 Dasea
 *
 * Description: 大小端转换类实现
 */
#include "endian_util.hpp"
#include <cstring>
#include <iostream>
#include <cstdint>

namespace dutil {
int DEndianUtil::_endianOrder = ENDIAN_ORDER_SMALL;

int DEndianUtil::endianOrder() {
    _judgeEndianOrder();
    return (_endianOrder);
}


void DEndianUtil::convertFromBigOrderBuffer(const char* buffer, int& dec) {
    _judgeEndianOrder();
    if (ENDIAN_ORDER_BIG == _endianOrder) {
        memcpy(&dec, buffer, sizeof(int));
    } else {
        dec = ((((int)buffer[0] << 24) & 0xff000000)
               | (((int)buffer[1] << 16) & 0x00ff0000)
               | (((int)buffer[2] << 8 ) & 0x0000ff00)
               | (((int)buffer[3]) & 0x000000ff));
    }
}
void DEndianUtil::convertFromBigOrderBuffer(const char* buffer, short& dec) {
    _judgeEndianOrder();
    if (ENDIAN_ORDER_BIG == _endianOrder) {
        memcpy(&dec, buffer, sizeof(short));
    } else {
        dec = ((((short)buffer[0]<<8) & 0xff00)
               | ((short)buffer[1] & 0x00ff));
    }
}
void DEndianUtil::convertFromBigOrderBuffer(const char* buffer, float& dec) {
    _judgeEndianOrder();
    if (ENDIAN_ORDER_BIG == _endianOrder) {
        memcpy(&dec, buffer, sizeof(float));
    } else {
        union {
            int idec;
            float fdec;
        } u;
        convertFromBigOrderBuffer(buffer, u.idec);
        dec = u.fdec;
    }
}
void DEndianUtil::convertFromBigOrderBuffer(const char* buffer, double& dec) {
    _judgeEndianOrder();
    if (ENDIAN_ORDER_BIG == _endianOrder) {
        memcpy(&dec, buffer, sizeof(double));
    } else {
        union {
            int64_t idec;
            double  fdec;
        } u;
        u.idec = ((((int64_t)buffer[7]) & 0x00000000000000ff)
                  | (((int64_t)buffer[6]<<8) & 0x000000000000ff00)
                  | (((int64_t)buffer[5]<<16) & 0x0000000000ff0000)
                  | (((int64_t)buffer[4]<<24) & 0x00000000ff000000)
                  | (((int64_t)buffer[3]<<32) & 0x000000ff00000000)
                  | (((int64_t)buffer[2]<<40) & 0x0000ff0000000000)
                  | (((int64_t)buffer[1]<<48) & 0x00ff000000000000)
                  | (((int64_t)buffer[0]<<56) & 0xff00000000000000));
        dec = u.fdec;
    }
}
void DEndianUtil::convertFromLittleOrderBuffer(const char* buffer, int& dec) {
    _judgeEndianOrder();
    if (ENDIAN_ORDER_SMALL == _endianOrder) {
        memcpy(&dec, buffer, sizeof(int));
    } else {
        dec = ((((int)buffer[0]) & 0x000000ff)
               | (((int)buffer[1] << 8) & 0x00ff0000)
               | (((int)buffer[2] << 16 ) & 0x0000ff00)
               | (((int)buffer[3] << 24) & 0xff000000));
    }
}
void DEndianUtil::convertFromLittleOrderBuffer(const char* buffer, short& dec) {
    _judgeEndianOrder();
    if (ENDIAN_ORDER_SMALL == _endianOrder) {
        memcpy(&dec, buffer, sizeof(short));
    } else {
        dec = ((((short)buffer[1] << 8) & 0xff00)
               | ((short)buffer[0] & 0x00ff));
    }
}
void DEndianUtil::convertFromLittleOrderBuffer(const char* buffer, float& dec) {
    _judgeEndianOrder();
    if (ENDIAN_ORDER_SMALL == _endianOrder) {
        memcpy(&dec, buffer, sizeof(float));
    } else {
        union {
            int idec;
            float fdec;
        }u;
        convertFromLittleOrderBuffer(buffer, u.idec);
        dec = u.fdec;
    }
}
void DEndianUtil::convertFromLittleOrderBuffer(const char* buffer, double& dec) {
    _judgeEndianOrder();
    if (ENDIAN_ORDER_SMALL == _endianOrder) {
        memcpy(&dec, buffer, sizeof(double));
    } else {
        union {
            int64_t idec;
            double  fdec;
        } u;
        u.idec = ((((int64_t)buffer[0]) & 0x00000000000000ff)
                  | (((int64_t)buffer[1]<<8) & 0x000000000000ff00)
                  | (((int64_t)buffer[2]<<16) & 0x0000000000ff0000)
                  | (((int64_t)buffer[3]<<24) & 0x00000000ff000000)
                  | (((int64_t)buffer[4]<<32) & 0x000000ff00000000)
                  | (((int64_t)buffer[5]<<40) & 0x0000ff0000000000)
                  | (((int64_t)buffer[6]<<48) & 0x00ff000000000000)
                  | (((int64_t)buffer[7]<<56) & 0xff00000000000000));
        dec = u.fdec;
    }
}

void DEndianUtil::convertToBigOrderBuffer(char* buffer, int dec) {
    _judgeEndianOrder();
    if (ENDIAN_ORDER_BIG == _endianOrder) {
        memcpy(buffer, &dec, sizeof(int));
    } else {
        buffer[0] = static_cast<char>((dec & 0xff000000) >> 24);
        buffer[1] = static_cast<char>((dec & 0x00ff0000) >> 16);
        buffer[2] = static_cast<char>((dec & 0x0000ff00) >> 8);
        buffer[3] = static_cast<char>(dec & 0x000000ff);
    }
}
void DEndianUtil::convertToBigOrderBuffer(char* buffer, short dec) {
    _judgeEndianOrder();
    if (ENDIAN_ORDER_BIG == _endianOrder) {
        memcpy(buffer, &dec, sizeof(short));
    } else {
        buffer[0] = static_cast<char>((dec & 0xff00) >> 8);
        buffer[1] = static_cast<char>(dec & 0x00ff);
    }
}
void DEndianUtil::convertToBigOrderBuffer(char* buffer, float dec) {
    _judgeEndianOrder();
    if (ENDIAN_ORDER_BIG == _endianOrder) {
        memcpy(buffer, &dec, sizeof(float));
    } else {
        union {
            int idec;
            float fdec;
        } u;
        u.fdec = dec;
        convertFromLittleOrderBuffer(buffer, u.idec);
    }
}
void DEndianUtil::convertToBigOrderBuffer(char* buffer, double dec) {
    _judgeEndianOrder();
    if (ENDIAN_ORDER_BIG == _endianOrder) {
        memcpy(buffer, &dec, sizeof(double));
    } else {
        union {
            int64_t idec;
            double fdec;
        } u;
        u.fdec = dec;
        buffer[0] = static_cast<char>((u.idec & 0xff00000000000000) >> 56);
        buffer[1] = static_cast<char>((u.idec & 0x00ff000000000000) >> 48);
        buffer[2] = static_cast<char>((u.idec & 0x0000ff0000000000) >> 40);
        buffer[3] = static_cast<char>((u.idec & 0x000000ff00000000) >> 32);
        buffer[4] = static_cast<char>((u.idec & 0x00000000ff000000) >> 24);
        buffer[5] = static_cast<char>((u.idec & 0x0000000000ff0000) >> 16);
        buffer[6] = static_cast<char>((u.idec & 0x000000000000ff00) >> 8);
        buffer[7] = static_cast<char>(u.idec & 0x000000000000000ff);
    }
}
void DEndianUtil::convertToLittleOrderBuffer(char* buffer, int dec) {
    _judgeEndianOrder();
    if (ENDIAN_ORDER_SMALL == _endianOrder) {
        memcpy(buffer, &dec, sizeof(int));
    } else {
        buffer[3] = static_cast<char>((dec & 0xff000000) >> 24);
        buffer[2] = static_cast<char>((dec & 0x00ff0000) >> 16);
        buffer[1] = static_cast<char>((dec & 0x0000ff00) >> 8);
        buffer[0] = static_cast<char>(dec & 0x000000ff);
    }
}
void DEndianUtil::convertToLittleOrderBuffer(char* buffer, short dec) {
    _judgeEndianOrder();
    if (ENDIAN_ORDER_SMALL == _endianOrder) {
        memcpy(buffer, &dec, sizeof(short));
    } else {
        buffer[1] = static_cast<char>((dec & 0xff00) >> 8);
        buffer[0] = static_cast<char>(dec & 0x00ff);
    }
}
void DEndianUtil::convertToLittleOrderBuffer(char* buffer, float dec) {
    _judgeEndianOrder();
    if (ENDIAN_ORDER_BIG == _endianOrder) {
        memcpy(buffer, &dec, sizeof(float));
    } else {
        union {
            int idec;
            float fdec;
        } u;
        u.fdec = dec;
        convertFromLittleOrderBuffer(buffer, u.idec);
    }
}
void DEndianUtil::convertToLittleOrderBuffer(char* buffer, double dec) {
    _judgeEndianOrder();
    if (ENDIAN_ORDER_SMALL == _endianOrder) {
        memcpy(buffer, &dec, sizeof(double));
    } else {
        union {
            int64_t idec;
            double fdec;
        } u;
        u.fdec = dec;
        buffer[7] = static_cast<char>((u.idec & 0xff00000000000000) >> 56);
        buffer[6] = static_cast<char>((u.idec & 0x00ff000000000000) >> 48);
        buffer[5] = static_cast<char>((u.idec & 0x0000ff0000000000) >> 40);
        buffer[4] = static_cast<char>((u.idec & 0x000000ff00000000) >> 32);
        buffer[3] = static_cast<char>((u.idec & 0x00000000ff000000) >> 24);
        buffer[2] = static_cast<char>((u.idec & 0x0000000000ff0000) >> 16);
        buffer[1] = static_cast<char>((u.idec & 0x000000000000ff00) >> 8);
        buffer[0] = static_cast<char>(u.idec & 0x000000000000000ff);
    }
}
void DEndianUtil::test() {
    char buffer[4] = {0};
    int testu4 = 0x11223344;
    std::cout << testu4 << std::endl;
    memcpy(buffer, &testu4, 4);
    std::cout << buffer[0] << ":"<<buffer[1] <<":"<<buffer[2]<<":"<<buffer[3] << std::endl;

    int dec = 0;
    convertFromLittleOrderBuffer(buffer, dec);
    std::cout << dec << std::endl;
    memcpy(buffer, &dec, 4);
    std::cout << buffer[0] << ":"<<buffer[1] <<":"<<buffer[2]<<":"<<buffer[3] << std::endl;

    // 由大端的buffer获取实际数据
    char bigorderbuffer[4] = {0x11, 0x22, 0x33, 0x44};
    int dec_i = 0; short dec_s = 0;
    convertFromBigOrderBuffer(bigorderbuffer, dec_i);
    convertFromBigOrderBuffer(bigorderbuffer, dec_s);
    std::cout << "int: "<<dec_i<<"; short:"<<dec_s << std::endl;

    // 从实际数据获取buffer
    char get_bigbuffer[4] = {0};
    convertToBigOrderBuffer(get_bigbuffer, testu4);
    std::cout << (int)get_bigbuffer[0] << ":"<<(int)get_bigbuffer[1]
        <<":"<<(int)get_bigbuffer[2]<<":"<<(int)get_bigbuffer[3] << std::endl;
    char get_smallbuffer[4] = {0};
    convertToLittleOrderBuffer(get_smallbuffer, testu4);
    std::cout << (int)get_smallbuffer[0] << ":"<<(int)get_smallbuffer[1]
        <<":"<<(int)get_smallbuffer[2]<<":"<<(int)get_smallbuffer[3] << std::endl;
}

void DEndianUtil::_judgeEndianOrder() {
    union {
        unsigned int a;
        unsigned char b;
    }c;
    c.a = 1;
    if (1 == c.b) {
        _endianOrder = ENDIAN_ORDER_SMALL;
    } else {
        _endianOrder = ENDIAN_ORDER_BIG;
    }
}

} // namespace dutil
