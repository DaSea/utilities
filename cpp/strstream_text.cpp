#include <sstream>
#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
    std::stringstream dyn;
    std::string ss;
    dyn<<"test: "<<1.23;
    // dyn>>ss;
    ss = dyn.str();
    std::cout << "The output stream: " << dyn.str()<<"; count: " <<dyn.gcount()<< std::endl;
    std::cout << ss << std::endl;

    dyn.str("");
    dyn.clear();

    dyn<<"hello";
    std::cout <<"The output stream: " << dyn.str()<<"; count: "<<dyn.gcount() << std::endl;
    dyn>>ss;
    std::cout << ss << std::endl;

    int i = 1004;
    long l = i;
    long long ll = l;
    std::cout << i << " " << l  <<" " <<ll << std::endl;

    
    return 0;
}
