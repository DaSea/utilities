#include <iostream>
#include <string>
#include <fstream>

// #define M (249997)

// BKDR hash function
unsigned int BKDRHash(const char* srcStr) {
    static unsigned int seed = 131;
    static unsigned int M = 249997;

    unsigned int hash = 0;

    char* str = const_cast<char*>(srcStr);
    while (*str) {
        hash = hash*seed + (*str++);
    }

    return (hash % M);
}

int main(int argc, char const* argv[])
{
    std::ifstream in("str_hash.txt", std::ios::in);
    if (!in.is_open()) {
        std::cout << "open failed!!" << std::endl;
        return 0;
    }

    std::string line;
    for (std::string line; std::getline(in, line); ) {
        unsigned int hashret = BKDRHash(line.c_str());
        std::cout << hashret << std::endl;
    }

    // std::string path1 = "/sdcard/maponline/tianditu/1.png";
    // unsigned int hh = BKDRHash(path1.c_str());
    // std::cout << hh << std::endl;
    return 0;
}
