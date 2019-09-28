#include <iostream>
#include <cstdlib>
#include <map>
#include <sstream>
#include <cstring>

typedef unsigned char u1;
typedef char i1;
typedef float f4;
typedef double f8;
typedef unsigned short u2;
typedef short i2;
typedef unsigned int u4;
typedef int i4;
typedef unsigned long DWORD;

#define GPSMAXCHN        ( 20 )  //The channel number of GPS receiver
#define GLOMAXCHN        ( 20 )  //The channel number of GLONASS receiver
#define COMMAXCHN        ( 20 )  //The channel number of Compass receiver
#define GALMAXCHN        ( 20 )  //The channel number of Galileo receiver
#define GNSSMAXCHN       ( GPSMAXCHN+GLOMAXCHN+COMMAXCHN+GALMAXCHN)

// GNSS类型
#define GNSS_GPS            0       // GPS卫星
#define GNSS_GLONASS        1       // GLONASS卫星
#define GNSS_GALILEO        2       // GALILEO卫星
#define GNSS_SBAS           3       // SBAS卫星
#define GNSS_BD             4       // 北斗卫星
#define GNSS_UNKNOW         5       // 其它卫星

// 南瓜头板卡类型BoardType
enum GPSBOARDTYPE {
    kBTYPE_UnKnown = 0,
    kBTYPE_NovAtelOEM6 = 1,
    kBTYPE_TrimbleRT27 = 2,
    kBTYPE_ComNav = 3,
    kBTYPE_Count = 4,
};

//GSV
struct GSV  //结构体太大了???
{
    i4 i4TotalNumOfMess;        // GSV数据的总数
    i4 i4CurrentNumOfMess;      // 当前数据编号
    i4 i4NumSateInView;         // 可见卫星个数
    i4 i4PRN[GNSSMAXCHN];       // 卫星编号
    i4 i4SateType[GNSSMAXCHN];  // 卫星类型
    i4 i4Elevation[GNSSMAXCHN]; // 卫星仰角
    i4 i4Azimuth[GNSSMAXCHN];   // 卫星方位角
    i4 i4SNR[GNSSMAXCHN];       // L1
    GSV(){
        i4TotalNumOfMess = 0;        // GSV数据的总数
        i4CurrentNumOfMess = 0;      // 当前数据编号
        i4NumSateInView = 0;         // 可见卫星个数
        memset(i4PRN, 0, sizeof(i4)*GNSSMAXCHN);
        memset(i4SateType, 0, sizeof(i4)*GNSSMAXCHN);
        memset(i4Elevation, 0, sizeof(i4)*GNSSMAXCHN);
        memset(i4Azimuth, 0, sizeof(i4)*GNSSMAXCHN);
        memset(i4Azimuth, 0, sizeof(i4)*GNSSMAXCHN);
        memset(i4SNR, 0, sizeof(i4)*GNSSMAXCHN);
    }
};

GPSBOARDTYPE boardType = kBTYPE_ComNav;
GSV m_GSVData;
int m_nGSVNum = 0;
bool m_bResolveGSVFirst = false;

#define DEBUG_GPS_OUT(...)

// 功能：分析GSV字符串，获取卫星相关信息
// 参数：GSV原始字符串
// 返回：无
void SetGSVData(std::string &data) {
    DEBUG_GPS_OUT("****GPSDataMgr:SetGSVData begin**");
    std::cout<<data<<std::endl;

    if(std::string::npos == data.find('*')){
        std::cout<<"Invalid gsv data!"<<std::endl;
        return ;
    }

    std::string strTemp;
    std::string::size_type pos1 = std::string::npos;
    std::string::size_type pos2 = std::string::npos;

    // GSV数据更新
    // i4 i4SateN = 0; // 卫星编号
    // i4 i4Saten = 0; // 每条GSV语句的可见卫星的总数
    i4 i4GSVNum = 0;  // 本句GSV的编号
    i4 i4GSVCount = 0;  //  GSV语句总数
    // i4 i4StartN = 0;  // 各种卫星类型在数组中开始的位置
    i1 i1GNSSType = -1;  // 卫星类型

    // 判断帧头
    if (data.find("GPGSV") != std::string::npos) {
        std::cout<<"GPGSV GPRS"<<std::endl;
        // i4StartN = 0;
        i1GNSSType = GNSS_GPS;
    } else if (data.find("GLGSV") != std::string::npos) {
        std::cout<<"Glnass"<<std::endl;
        // i4StartN = GPSMAXCHN;
        i1GNSSType = GNSS_GLONASS;
    } else if (data.find("BDGSV") != std::string::npos) {
        std::cout<<"北斗卫星"<<std::endl;
        // i4StartN = GPSMAXCHN + GLOMAXCHN;
        i1GNSSType = GNSS_BD;
    } else {
        // 奇怪的类型
        std::cout<<"Unknown type!"<<std::endl;
        return;
    }

    if (m_bResolveGSVFirst) {
        memset(&m_GSVData, 0, sizeof(GSV));
        m_nGSVNum = 0;
        m_bResolveGSVFirst = false;
    }

    // <1> GSV语句的总数
    pos1 = data.find(',', 3);
    pos2 = data.find(',', pos1 + 1);
    strTemp = data.substr(pos1+1, pos2 - pos1 - 1);
    std::cout<<"GSV语句总数:"<<strTemp<<std::endl;
    i4GSVCount = m_GSVData.i4TotalNumOfMess = atoi(strTemp.c_str());

    // <2> 本句GSV的编号
    pos1 = data.find(',', pos2 + 1);
    strTemp = data.substr(pos2+1, pos1 - pos2 - 1);
    std::cout<<"当前GSV语句编号:"<<strTemp<<std::endl;
    m_GSVData.i4CurrentNumOfMess = atoi(strTemp.c_str());
    i4GSVNum = m_GSVData.i4CurrentNumOfMess;

    // <3> 可见卫星的总数，GPS范围为00至12
    pos2 = data.find(',', pos1 + 1);
    // strTemp = sGsvArray.at(3);

    if (i4GSVNum <= i4GSVCount) {
        // 当前卫星在此GSV语句中的编号, 最大为4, 或者没有
        int index = 0;
        while (index < 4) {
            // <4> 卫星编号，范围是01至32(GPS)
            pos1 = data.find(',', pos2+1);
            strTemp = data.substr(pos2+1, pos1-pos2-1);
            if (strTemp.empty()) {
                break;
            }
            // std::cout<<strTemp<<" ";
            m_GSVData.i4PRN[m_nGSVNum] = atoi(strTemp.c_str());
            m_GSVData.i4SateType[m_nGSVNum] = i1GNSSType;

            if (boardType == kBTYPE_NovAtelOEM6 && i1GNSSType == GNSS_BD) {
                m_GSVData.i4PRN[m_nGSVNum] += 100;
            } else if (boardType == kBTYPE_ComNav&& i1GNSSType == GNSS_GLONASS) {
                m_GSVData.i4PRN[m_nGSVNum] += 27;
            }

            // <5>卫星仰角，范围是00至90度
            pos2 = data.find(',', pos1+1);
            strTemp = data.substr(pos1+1, pos2 - pos1 - 1);
            // std::cout<<strTemp<<" ";
            m_GSVData.i4Elevation[m_nGSVNum] = atoi(strTemp.c_str());
            
            // <6>卫星方位角，范围是000至359度，实际值。
            pos1 = data.find(',', pos2 + 1);
            strTemp = data.substr(pos2+1, pos1 - pos2 - 1);
            // std::cout<<strTemp<<" ";
            m_GSVData.i4Azimuth[m_nGSVNum] = atoi(strTemp.c_str());

            // <7>讯号噪声比（C/No），范围是00至99 dB；无表未接收到讯号
            pos2 = data.find(',', pos1+1);
            if (std::string::npos == pos2) {
                pos2 = data.find('*', pos1+1);
                strTemp = data.substr(pos1+1, pos2-pos1-1);
                // std::cout<<strTemp<<std::endl;
                m_GSVData.i4SNR[m_nGSVNum] = atoi(strTemp.c_str());
                ++m_nGSVNum;
                break;
            }
            strTemp = data.substr(pos1+1, pos2-pos1-1);
            // std::cout<<strTemp<<std::endl;
            m_GSVData.i4SNR[m_nGSVNum] = atoi(strTemp.c_str());
            
            ++m_nGSVNum;
            ++index;
        }
    }
#if 0
    if (i4GSVN <= i4GSVn) {
        i4 i4Pos = 0;
        i4Saten = (sGsvArray.size() - 4) / 4;
        for (i4SateN = 0; i4SateN < i4Saten; i4SateN++) {
            i4Pos = i4StartN + i4SateN + (i4GSVN - 1) * 4;

            // <4> 卫星编号，范围是01至32(GPS)
            strTemp = sGsvArray.at(4 + 4 * i4SateN);
            m_GSVData.i4PRN[i4Pos] = atoi(strTemp.c_str());
            m_GSVData.i4SateType[i4Pos] = i1GNSSType;
            m_nGSVNum++;

            if (boardType == kBTYPE_NovAtelOEM6 && i1GNSSType == GNSS_BD) {
                m_GSVData.i4PRN[i4Pos] += 100;
            } else if (boardType == kBTYPE_ComNav&& i1GNSSType == GNSS_GLONASS) {
                m_GSVData.i4PRN[i4Pos] += 27;
            }

            // <5>卫星仰角，范围是00至90度
            strTemp = sGsvArray.at(5 + 4 * i4SateN);
            m_GSVData.i4Elevation[i4Pos] = atoi(strTemp.c_str());

            // <6>卫星方位角，范围是000至359度，实际值。
            strTemp = sGsvArray.at(6 + 4 * i4SateN);
            m_GSVData.i4Azimuth[i4Pos] = atoi(strTemp.c_str());

            // <7>讯号噪声比（C/No），范围是00至99 dB；无表未接收到讯号。
            strTemp = sGsvArray.at(7 + 4 * i4SateN);
            if (i4SateN == i4Saten) {
                strTemp = strTemp.substr(0, strTemp.find('*'));
            }
            m_GSVData.i4SNR[i4Pos] = atoi(strTemp.c_str());
        }
    }
#endif

    DEBUG_GPS_OUT("****GPSDataMgr:SetGSVData end**");
}

void outGSVInfo() {
    std::cout<<"卫星总颗数:"<<m_nGSVNum<<std::endl;
    for (size_t i = 0; i < m_nGSVNum; i++) {
        std::cout<<"卫星类型:"<<m_GSVData.i4SateType[i]
        <<" ;编号:"<<m_GSVData.i4PRN[i]
        <<" ;仰角:"<<m_GSVData.i4Elevation[i]
        <<" ;方位角:"<<m_GSVData.i4Azimuth[i]
        <<" ;噪声比:"<<m_GSVData.i4SNR[i]<<std::endl;
    }
}

void testGsv() {
    m_bResolveGSVFirst = true;
    std::string gsv1 = "$GPGSV,3,1,5,27,32,179,40,32,15,149,34*4F";
    std::string gsv2 = "$GLGSV,3,2,5,81,21,152,*6D";
    std::string gsv3 = "$GBDGSV,3,3,5,106,28,189,36,109,44,214,42*1B";
    SetGSVData(gsv1);
    SetGSVData(gsv2);
    SetGSVData(gsv3);

    outGSVInfo();
}

void testGsv2() {
    m_bResolveGSVFirst = true;
    std::string gsv0 = "$GPGSV,3,1,09,06,48,054,42,02,57,341,50,13,29,064,36,12,33,265,44*70";
    std::string gsv1 = "$GPGSV,3,2,09,05,54,246,51,09,26,056,,17,25,139,,10,64,028,50*79";
    std::string gsv2 = "$GPGSV,3,3,09,26,08,184,42,,,,,,,,,,,,*47";
    std::string gsv3 = "$BDGSV,2,1,06,141,43,138,,143,54,188,44,144,29,117,39,146,80,275,46*6C";
    std::string gsv4 = "$BDGSV,2,2,06,148,68,135,46,149,53,235,43,,,,,,,,*61";
    std::string gsv5 = "$GLGSV,1,1,04,55,42,114,46,42,45,217,48,56,60,003,52,41,76,014,51*6A";

    SetGSVData(gsv0);
    SetGSVData(gsv1);
    SetGSVData(gsv2);
    SetGSVData(gsv3);
    SetGSVData(gsv4);
    SetGSVData(gsv5);
    
    outGSVInfo();
}

int main(void) {
    testGsv();
    testGsv2();

    return 0;
}