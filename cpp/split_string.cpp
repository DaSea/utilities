#include <iostream>
#include <string>
#include <cstdlib>

bool GetTileColOrRow(std::string& fullpath, long& col, long& row)
{
    // "%s\\%d\\%d_%d\\%d_%d\\%d\\%d_%d.%s",sRoot,nLevel, x1, y1, x2, y2, x3, col,row,sExt);
    size_t nPos = std::string::npos, nPos2 = 0;
    std::string sLeft;

    nPos = fullpath.rfind('/');
    if (std::string::npos == nPos) return false;

    nPos2 = fullpath.rfind('_');
    if(std::string::npos == nPos2) return false;

    sLeft = fullpath.substr(nPos+1, nPos2 - nPos);
    col = atol(sLeft.c_str());

    nPos = fullpath.rfind('.');
    if (std::string::npos == nPos) return false;

    sLeft = fullpath.substr(nPos2+1, nPos - nPos2);
    row = atol(sLeft.c_str());

    return true;
}

int main(int argc, char const *argv[])
{
    std::string fullpath = "E:/Company/ZiLiao/14/2_0/39_68/0/23946_6811.png";
    long col = 0;
    long row = 0;
    GetTileColOrRow(fullpath, col, row);

    std::cout<<fullpath<<std::endl;

    std::cout<<"Col: "<<col<<std::endl;
    std::cout<<"Row: "<<row<<std::endl;

    return 0;
}