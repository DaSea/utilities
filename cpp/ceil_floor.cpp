#include <iostream>
#include <cmath>

int main(int argc, char const* argv[])
{
    double startx = -180;
    double starty = 90;
    double xmin = 114.373787,xmax=114.438751;
    double ymin = 30.457214, ymax=30.501108;
    double resolution = 0.0000761427;

    int beginCol = 0,endCol=0,beginRow=0,endRow = 0;
    double wr = 256*resolution;
    std::cout <<"wr:"<< wr << std::endl;
    std::cout <<"xmin-startx:"<< xmin-startx << std::endl;
    std::cout <<"(xmin-startx)/wr:"<< (xmin-startx)/wr << std::endl;
    beginCol = floor((xmin - startx) /wr);
    std::cout<<"xmax - startx"<<xmax - startx<<std::endl;
    std::cout<<"abs(xmax - startx):"<< fabs(xmax - startx)<<std::endl;
    std::cout <<"abs(xmax-startx)/wr:" << fabs(xmax - startx)/wr << std::endl;
    std::cout <<"fabs((xmax-startx)/wr):"<< fabs((xmax-startx)/wr) << std::endl;
    endCol = ceil(fabs(xmax - startx)/wr);
    beginRow = floor((starty-ymax)/wr);
    endRow = ceil(fabs(starty-ymin)/wr);

    std::cout<<"col:"<<beginCol<<"_"<<endCol<<std::endl;
    std::cout<<"col:"<<beginRow<<"_"<<endRow<<std::endl;

    return 0;
}
