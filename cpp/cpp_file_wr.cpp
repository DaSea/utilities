#include <fstream>
#include <string>
#include <iostream>

void read_bfile(void) {
    // 读取二进制数据
    std::ifstream ifs;
    std::string filename = 'a.exe';
    ifs.open(filename, std::ios_base::in | std::ios_base::binary);
    if (!ifs.is_open()) {
        std::cout << "Open file failed!" << std::endl;
        return ;
    }

    // read file
    

    ifs.close();
}

int main(int argc, const char** argv) {
    std::ofstream ofs;

    // open file one
    ofs.open("./ifstream_str.cpp");
    if (std::ios_base::failbit ==  ofs.rdstate())
    {
        /* code */
        std::cout << "open failed!" << std::endl;
    }
    ofs.clear();
    ofs.close();

    // open file one
    ofs.open("./map_test.cpp");
    if (std::ios_base::failbit ==  ofs.rdstate())
    {
        /* code */
        std::cout << "open failed!" << std::endl;
    }
    ofs.clear();
    ofs.close();


    // open file one
    ofs.open("./ifstream_str1.cpp", std::ios::binary);
    std::cout << ofs.rdstate() << std::endl;
    if (std::ios_base::failbit ==  ofs.rdstate())
    {
        /* code */
        std::cout << "open failed!" << std::endl;

    }
    ofs.clear();
    ofs.close();

    std::ofstream ofs1('text.txt');
    std::cout << ofs1.rdstate() << std::endl;
    if (std::ios_base::failbit ==  ofs1.rdstate())
    {
        /* code */
        std::cout << "open failed!" << std::endl;

    }
    ofs.clear();

    ofs1.close();

    return 0;
}
