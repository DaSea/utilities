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

struct WmtsKeyparam{
    long level;
    long row;
    long col;

    WmtsKeyparam()
    {
        level = -1;
        row = -1;
        col = -1;
    }
    WmtsKeyparam(long l, long r, long c)
    {
        level = l;
        row = r;
        col = c;
    }

    void toInvalid() {
        level = -1;
        row = -1;
        col = -1;
    }

    bool isInvalid() {
        return ((-1 == level) || (-1 == row) || (-1 == col));
    }

    WmtsKeyparam& operator=(const WmtsKeyparam& rhs) {
        level = rhs.level;
        col = rhs.col;
        row = rhs.row;

        return (*this);
    }
};

bool getKeyFromStr(std::string& keyStr, WmtsKeyparam& key)
{
    size_t nPos = std::string::npos, nPos2 = 0;
    std::string sLeft;

    nPos = keyStr.find('_');
    if(std::string::npos == nPos)
        return false;

    sLeft = keyStr.substr(nPos2, nPos-nPos2);
    key.level = atoi(sLeft.c_str());

    nPos2 = nPos+1;
    nPos = keyStr.find('_', nPos2);
    if(std::string::npos == nPos)
        return false;

    sLeft = keyStr.substr(nPos2, nPos-nPos2);
    key.row = atoi(sLeft.c_str());

    nPos2 = nPos + 1;
    nPos = keyStr.find('_', nPos2);
    if(std::string::npos != nPos)
        return false;

    sLeft = keyStr.substr(nPos2);
    key.col = atoi(sLeft.c_str());

    return true;
}

int getKeyFromStrTest(void)
{
    std::cout<<"Hello world!"<<std::endl;
    std::string ss = "18_33_4";
    WmtsKeyparam key;
    if (getKeyFromStr(ss, key)) {
        std::cout<<key.level<<" "<<key.row<<" "<<key.col<<std::endl;
    }

    ss = "18_3_3_";
    if(getKeyFromStr(ss, key)){
        std::cout<<"it is ok"<<std::endl;
    }else{
        std::cout<<"it is not ok"<<std::endl;
    }
    return 0;
}

struct MapTest{
public:
    int a;
    int b;
    int c;
    MapTest(){
    }
};

void map_test(void){
    std::map<int, MapTest*> maptt;
    MapTest* test = NULL;
    test = new MapTest();
    maptt[0] = test;

    test = NULL;
    test = new MapTest();
    maptt[1] = test;

    std::cout<<maptt[0]<<" "<<maptt[1]<<std::endl;

    if(maptt.end() != maptt.find(0)){
        std::cout<<"find key 0"<<std::endl;
        test = maptt[0];
        maptt.erase(0);
        delete test;
        test = NULL;
    }

    if(maptt.end() != maptt.find(1)){
        std::cout<<"find key 1"<<std::endl;
        test = maptt[1];
        maptt.erase(1);
        delete test;
        test = NULL;
    }


}
int getWkid(std::string& espg){
    std::string::size_type pos = espg.rfind(':');
    if(std::string::npos != pos){
        std::string wkid = espg.substr(pos + 1, espg.size() - pos -1);
        std::cout << wkid<<std::endl;
        return (atoi(wkid.c_str()));
    }

    return -1;
}

void string_assign(void) {
    std::string data;
    std::cout << "================================" << "\n";
    data.assign(100, 0);
    std::cout<<data<<": "<<data.size()<<" "<<data.capacity()<<std::endl;
    data = "hello, hello, hello, ";
    std::cout<<data<<": "<<data.size()<<" "<<data.capacity()<<std::endl;
    std::cout << "================================" << "\n";
    char arr[5] = {'n', 'i', 'h', 'a', 'o'};
    data.assign(arr, 5);
    std::cout<<data<<": "<<data.size()<<" "<<data.capacity()<<std::endl;
    std::cout << "================================" << "\n";

    std::string data1;
    data1.assign(20, 0);
    std::cout<<data1<<": "<<data1.size()<<" "<<data1.capacity()<<std::endl;
    data1 = "china, china!";
    std::cout<<data1<<": "<<data1.size()<<" "<<data1.capacity()<<std::endl;
    std::cout << "================================" << "\n";

    std::string data2;
    data2.assign(130, 0);
    std::cout<<data2<<": "<<data2.size()<<" "<<data2.length()<<" "<<data2.capacity()<<std::endl;
    data2.assign(50, 0);
    std::cout<<data2<<": "<<data2.size()<<" "<<data2.length()<<" "<<data2.capacity()<<std::endl;
    data2 = data + data1;
    std::cout<<data2<<": "<<data2.size()<<" "<<data2.length()<<" "<<data2.capacity()<<std::endl;
    std::cout << "================================" << "\n";
    data2.assign(50, 0);
    std::cout<<data2<<": "<<data2.size()<<" "<<data2.capacity()<<std::endl;
    data2.assign(150, 0);
    std::cout<<data2<<": "<<data2.size()<<" "<<data2.capacity()<<std::endl;
    std::cout << "================================" << "\n";
}

void stringInTest(void) {
    std::stringstream ss;
    std::string str = "124 33 ff*44";
    ss.str(str);
    str.replace(str.begin(), str.end(), 1, ' ');

    int a,c;
    std::string temp;
    ss>>a>>temp>>c;
    std::cout<<a<<":" <<temp<<":"<<c<<std::endl;
    std::cout<<ss.str()<<std::endl;

    int b;
    ss>>b;
    std::cout<<b<<std::endl;

    std::string str2("The quick brown fox jumps over the lazy dog.");
    str2.replace(10, 5, "red"); // (4)
    str2.replace(str2.begin(), str2.begin() + 3, 2, 'A'); // (5)
    std::cout << str2 << '\n';

    // $GPGGA,000000.00,0000.00000000,N,00000.00000000,E,0,00,0.0,0.000,M,0.000,M,,*5D
    std::string gga = "$GPGGA 075733.00 3028.80334179 N 11423.99403305 E 1 24 0.7 40.920 M -14.212 M 0 10*70";
    std::stringstream ggaStream(gga);
    double time;
    ggaStream>>temp>>time;
    std::cout<<temp<<time<<std::endl;
}

void stringOutTest(void) {

}

void testBigSmall(void) {
    WmtsKeyparam param;
    std::string key = "12_21_22";

    std::cout<<sizeof(param)<<std::endl;
    std::cout<<sizeof(key)<<std::endl;

    std::cout<<param.isInvalid()<<std::endl;

    param.toInvalid();
    std::cout<<param.isInvalid()<<std::endl;
    std::cout<<sizeof(param)<<std::endl;
}

void testStrCAddress() {
    std::string str = "hello, world";
    std::cout << str << std::endl;
    std::cout<<std::ios::hex<<str.c_str()<<std::endl;
    char* cc = const_cast<char*>(str.c_str());
    std::cout<<"static_cast<void *>(&c)="<< static_cast<void*>(cc) <<std::endl;
    std::cout << "size:"<<str.length()<<";pacity: "<<str.capacity() << std::endl;
    std::cout<<"static_cast<void *>(&str)="<< &str <<std::endl;

    str = "coding!";
    std::cout << str << std::endl;
    std::cout<<std::ios::hex<<str.c_str()<<std::endl;
    char* rr = const_cast<char*>(str.c_str());
    std::cout<<"static_cast<void *>(&c)="<< static_cast<void*>(rr) <<std::endl;
    std::cout << "size:"<<str.length()<<";pacity: "<<str.capacity() << std::endl;
}

void testGSTData() {
    std::string gst = "$GNGST,082751.00,5.025,0.705,0.633,18.3,0.699,0.641,1.482*76";
    std::string::size_type pos1 = std::string::npos;
    std::string::size_type pos2 = std::string::npos;
    std::string sst = "";

    // 8
    pos1 = gst.find('*');
    pos2 = gst.rfind(',');
    sst = gst.substr(pos2 + 1, pos1 - pos2 - 1);
    std::cout<<sst<<std::endl;
    double n = atof(sst.c_str());
    std::cout<<n<<std::endl;

    // 7
    pos1 = gst.rfind(',', pos2 - 1);
    sst = gst.substr(pos1+1, pos2 - pos1 - 1);
    std::cout<<sst<<std::endl;
    double e = atof(sst.c_str());
    std::cout<<e<<std::endl;

    //6
    pos2 = gst.rfind(',', pos1 - 1);
    sst = gst.substr(pos2+1, pos1 - pos2 - 1);
    std::cout<<sst<<std::endl;
    double u = atof(sst.c_str());
    std::cout<<u<<std::endl;
}
/*
 * ZDA数据更新
 * $GPZDA,074024.00,30,09,2014,,*6E
 * $GPZDA, _1_ , _2_ , _3_ , _4_ , _5_ ,*6E
 * 需要获取_2_,_3_,_4_中的数据
 */
void testZDAData() {
    std::string gst = "$GPZDA,074024.00,30,09,2014,,*6E";
    std::string::size_type pos1 = std::string::npos;
    std::string::size_type pos2 = std::string::npos;
    std::string sst = "";

    // 1
    pos1 = gst.find(',');
    pos2 = gst.find(',', pos1+1);

    // 2 日
    pos1 = gst.find(',', pos2 + 1);
    sst = gst.substr(pos2 + 1, pos1 - pos2 - 1);
    std::cout<<sst<<std::endl;
    int n = atoi(sst.c_str());
    std::cout<<n<<std::endl;

    // 3 月
    pos2 = gst.find(',', pos1 + 1);
    sst = gst.substr(pos1+1, pos2 - pos1 - 1);
    std::cout<<sst<<std::endl;
    int e = atoi(sst.c_str());
    std::cout<<e<<std::endl;

    //4 年
    pos1 = gst.find(',', pos2 + 1);
    sst = gst.substr(pos2+1, pos1 - pos2 - 1);
    std::cout<<sst<<std::endl;
    int u = atof(sst.c_str());
    std::cout<<u<<std::endl;
}

// GSA
struct GSA {
    char chUsedIdx; // 有效卫星的颗数
    char chMode1;
    short chMode2;
    float dPdop;
    float dHdop;
    float dVdop;
    int iSateUsed[80]; // 记录当前用于参与结算的卫星编号
    GSA(){
        chUsedIdx = 0;
        chMode1 = 'A';
        chMode2 = 1;
        dPdop = 0.0;
        dHdop = 0.0;
        dVdop = 0.0;
        memset(iSateUsed, 0, sizeof(int)*80);
    }
};
static GSA m_GSAData;
void testOneGsa(std::string& data);
void testGSAData() {
    std::string data1 = "$GPGSA,M,3,06,02,13,12,05,10,26,,,,,,1.9,1.0,1.6*35";
    testOneGsa(data1);
    std::string data2 = "$BDGSA,M,3,143,144,146,148,149,,,,,,,,1.9,1.0,1.6*14";
    testOneGsa(data2);
    std::string data3 = "$GLGSA,M,3,55,42,56,41,,,,,,,,,1.9,1.0,1.6*2C";
    testOneGsa(data3);

    std::cout<<m_GSAData.chMode1<<" "<<m_GSAData.chMode2<<std::endl;
    for (int i = 0; i < m_GSAData.chUsedIdx; i++) {
        std::cout<<m_GSAData.iSateUsed[i]<<std::endl;
    }
    std::cout<<"HDOP:"<<m_GSAData.dHdop<<"; VDOP:"<<m_GSAData.dVdop<<"; PDOP:"<<m_GSAData.dPdop<<std::endl;
}
void testOneGsa(std::string& data) {
    if (std::string::npos == data.find('*', 17)) {
        std::cout<<"Invalid data!"<<std::endl;
        return ;
    }

    std::cout<<data<<std::endl;

    std::string::size_type pos1 = std::string::npos;
    std::string::size_type pos2 = std::string::npos;
    std::string sst = "";

// 获取gsa的信息
    pos1 = data.find(',', 2);
    pos2 = data.find(',', pos1+1);
    if(0 == m_GSAData.chUsedIdx) {
        m_GSAData.chMode1 = data.at(pos1+1);
        m_GSAData.chMode2 = data.at(pos2+1);
        // std::cout<<"mode1:"<<m_GSAData.chMode1<<"; mode2:"<<m_GSAData.chMode2<<std::endl;
    }

    // 可以累计
    // 获取参与解算的卫星编号(12)
    // GPS:1-32; SBAS: SBAS: 33-64; Glonass:64+
    // std::cout<<"pos1: "<<pos1<<";pos2:"<<pos2<<std::endl;
    pos2 = data.find(',', pos2+1);
    for(int i = 0; i < 12; ++i){
        // std::cout<<"pos1: "<<pos1<<";pos2:"<<pos2<<std::endl;
        pos1 = pos2;
        pos2 = data.find(',', pos1+1);
        sst = data.substr(pos1 + 1, pos2 - pos1 - 1);
        if (!sst.empty()) {
            // std::cout<<sst<<std::endl;
            m_GSAData.iSateUsed[m_GSAData.chUsedIdx] = atoi(sst.c_str());
            m_GSAData.chUsedIdx++;
        }
    }

    // 获取HDOP,PDOP,VDOP等
    pos1 = data.find(',', pos2+1);
    sst = data.substr(pos2+1, pos1 - pos2 - 1);
    // std::cout<<"HDOP:"<<sst<<std::endl;
    m_GSAData.dPdop = atof(sst.c_str());

    pos2 = data.find(',', pos1+1);
    sst = data.substr(pos1+1, pos2 - pos1 - 1);
    // std::cout<<"PDOP:"<<sst<<std::endl;
    m_GSAData.dHdop = atof(sst.c_str());

    pos1 = data.find('*', pos2+1);
    sst = data.substr(pos2+1, pos1 - pos2 - 1);
    // std::cout<<"VDOP:"<<sst<<std::endl;
    m_GSAData.dVdop = atof(sst.c_str());
    // m_GSAData.dPdop = atof(sZdaArray.at(15).c_str());
    // m_GSAData.dHdop = atof(sZdaArray.at(16).c_str());
    // m_GSAData.dVdop = atof(sZdaArray.at(17).c_str());
}
struct GGA {
    i4 chHour;                    //1 byte
    i4 chMinute;
    f8 dSecond;

    i1 chNorthOrSouth;
    i1 chEastOrWest;
    f8 dB;
    f8 dL;
    i4 chQuality;/*positioning status flag: 0, invalid; 1, single positioning; 2, float resolution carrier phase differential positioning;
     3, fixed resolution carrier phase differential positioning; 4, code pseudorange differential positioning*/
    i4 chSatNumberToSolute;
    f8 dHDOP;
    f8 dAltitude;
    f8 dGeoidalSep;
    f8 dAgeOfRTCM;                    //the period of differential correction
    i4 iIDOfBaseStation;

    GGA() {
        chHour = 0;
        chMinute = 0;
        dSecond = 0;

        chNorthOrSouth = 0;
        chEastOrWest = 0;
        dB = 0;
        dL = 0;
        chQuality = 0;
        chSatNumberToSolute = 0;
        dHDOP = 0;
        dAltitude = 0;
        dGeoidalSep = 0;
        dAgeOfRTCM = 0;
        iIDOfBaseStation = 0;
    }
};
static GGA m_GGAData;
void SetGGAData(std::string& data);
void testGGAData() {
    // std::string gga = "$GPGGA,091416.00,0000.00000000,N,00000.00000000,E,0,00,0.0,0.000,M,0.000,M,,*56";
    std::string gga = "$GPGGA,020825.00,3028.82319561,N,11424.03422005,E,1,04,6.4,46.642,M,-14.209,M,,*7C";
    SetGGAData(gga);
}
#define DEBUG_GGA_OUT(...)
void SetGGAData(std::string& data) {
    std::cout<<data<<std::endl;
    // "$GPGGA:1,091416.00:2,0000.00000000:3,
    // N:4,00000.00000000:5,E:6,0:7,00:8,0.0:9,0.000:10,M:11,0.000:12,M:13,:14,:15*56"
    // GGA数据更新
    std::string strTemp;
    std::string::size_type pos1 = std::string::npos;
    std::string::size_type pos2 = std::string::npos;

    // <1> UTC时间，hhmmss.ss（时分秒）格式
    // strTemp = sGpggaArray.at(1);
    pos1 = data.find(',', 3);
    pos2 = data.find(',', pos1+1);
    strTemp = data.substr(pos1+1, pos2 - pos1 - 1);
    std::cout<<"<1>:"<<strTemp<<std::endl;
    // CCommTools::UtcToBj_HMS(strTemp, m_GGAData);

    // <2> 纬度ddmm.mmmm（度分）格式（前面的0也将被传输）
    // strTemp = sGpggaArray.at(2);
    // m_GGAData.dB = atof(strTemp)/100.0;
    // m_GGAData.dB = CCommTools::FormatDegreeForBFromGGA(strTemp);
    pos1 = data.find(',', pos2 + 1);
    strTemp = data.substr(pos2+1, pos1 - pos2 - 1);
    std::cout<<"<2>:"<<strTemp<<std::endl;

    // <3> 纬度半球N（北半球）或S（南半球）
    // strTemp = sGpggaArray.at(3);
    // if (strTemp == "N") {
    //     m_GGAData.chNorthOrSouth = 'N';
    // } else {
    //     m_GGAData.chNorthOrSouth = 'S';
    // }
    pos2 = data.find(',', pos1+1);
    strTemp = data.substr(pos1+1, pos2 - pos1 - 1);
    std::cout<<"<3>:>"<<strTemp<<std::endl;

    // <4> 经度dddmm.mmmm（度分）格式（前面的0也将被传输）
    // strTemp = sGpggaArray.at(4);
    //m_GGAData.dL = atof(strTemp)/100.0;
    // m_GGAData.dL = CCommTools::FormatDegreeForLFromGGA(strTemp);
    pos1 = data.find(',', pos2 + 1);
    strTemp = data.substr(pos2+1, pos1-pos2-1);
    std::cout<<"<4>:"<<strTemp<<std::endl;

    // <5> 经度半球E（东经）或W（西经）
    // strTemp = sGpggaArray.at(5);
    // if (strTemp == "E") {
    //     m_GGAData.chEastOrWest = 'E';
    // } else {
    //     m_GGAData.chEastOrWest = 'W';
    // }
    pos2 = data.find(',', pos1+1);
    strTemp = data.substr(pos1+1, pos2-pos1-1);
    std::cout<<"<5>:"<<strTemp<<std::endl;

    // <6> GPS状态：0=未定位，1=非差分定位，2=差分定位，6=正在估算
    // m_GGAData.chQuality = atoi(sGpggaArray.at(6).c_str());
    pos1 = data.find(',', pos2+1);
    strTemp = data.substr(pos2+1, pos1 - pos2 - 1);
    std::cout<<"<6>:"<<strTemp<<std::endl;

    // <7> 正在使用解算位置的卫星数量（00~12）（前面的0也将被传输）
    // m_GGAData.chSatNumberToSolute = atoi(sGpggaArray.at(7).c_str());
    pos2 = data.find(',', pos1 + 1);
    strTemp = data.substr(pos1+1, pos2 - pos1 - 1);
    std::cout<<"<7>:"<<strTemp<<std::endl;

    // <8> HDOP水平精度因子（0.5~99.9）
    // m_GGAData.dHDOP = atof(sGpggaArray.at(8).c_str());
    pos1 = data.find(',', pos2+1);
    strTemp = data.substr(pos2+1, pos1 - pos2 - 1);
    std::cout<<"<8>:"<<strTemp<<std::endl;

    // <9> 海拔高度（-9999.9~99999.9）
    // m_GGAData.dAltitude = atof(sGpggaArray.at(9).c_str());
    pos2 = data.find(',', pos1 + 1);
    strTemp = data.substr(pos1+1, pos2 - pos1 - 1);
    std::cout << "<9>:"<<strTemp << std::endl;
    // 减去天线高，获取真正的大地高
    // m_GGAData.dAltitude -= m_f8AntennaH;
    
    // 10
    pos1 = data.find(',', pos2 + 1);
    strTemp = data.substr(pos2+1, pos1 - pos2 - 1);
    std::cout<<"<10>:"<<strTemp<<std::endl;

    // <10> 地球椭球面相对大地水准面的高度(高程误差值)
    // m_GGAData.dGeoidalSep = atof(sGpggaArray.at(11).c_str());
    pos2 = data.find(',', pos1 + 1);
    strTemp = data.substr(pos1+1, pos2 - pos1 - 1);
    std::cout<<"<11>:"<<strTemp<<std::endl;

    // 12
    pos1 = data.find(',', pos2 + 1);
    strTemp = data.substr(pos2+1, pos1 - pos2 - 1);
    std::cout<<"<12>:"<<strTemp<<std::endl;

    // <11> 差分时间（从最近一次接收到差分信号开始的秒数，如果不是差分定位将为空）
    // m_GGAData.dAgeOfRTCM = atof(sGpggaArray.at(13).c_str());
    pos2 = data.find(',', pos1 + 1);
    strTemp = data.substr(pos1+1, pos2 - pos1 - 1);
    std::cout<<"<13>:"<<strTemp<<std::endl;

    // <12> 差分站ID号0000~1023（前面的0也将被传输，如果不是差分定位将为空）
    // strTemp = sGpggaArray.at(14);
    // strTemp = strTemp.substr(0, strTemp.find('*'));
    // m_GGAData.iIDOfBaseStation = atoi(strTemp.c_str());
    pos1 = data.find('*', pos2 + 1);
    strTemp = data.substr(pos2+1, pos1 - pos2 - 1);
    std::cout<<"<14>:"<<strTemp<<std::endl;

    // 通知更新
    // GlobalMgr::notifyGgaUpdate();

    DEBUG_GGA_OUT("****GPSDataMgr:SetGGData end**");
}
int main(int argc, char const* argv[])
{
    // map_test();

    // std::string espg = "ESPG:4356";
    // int wkid = getWkid(espg);
    // std::cout<<wkid<<std::endl;

    // string_assign();

    // string >> << ??
    // stringInTest();
    // stringOutTest();

    // testBigSmall();

    // testStrCAddress();

    testGSTData();
    // testZDAData();
    testGSAData();
    testGGAData();
    return 0;
}
