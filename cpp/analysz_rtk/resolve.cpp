#include <iostream>
#include <cstring>
#include <fstream>

int orderFindBinStr(const char* pattern, int patternLen, char* src, int srcLen) {
    int i = 0;
    int findPos = -1;

    for (; i < srcLen - patternLen; ++i) {
        if (0 == strncmp(src + i, pattern, patternLen)) {
            findPos = i;
            break;
        }
    }

    return (findPos);
}

int findCharInSrc(char dd, char* src, int start, int len) {
    int i = 0;
    int findPos = -1;
    for (i = start; i < len; ++i) {
        if (dd == src[i]) {
            findPos = i;
            break;
        }
    }

    return (findPos);
}

void writeToFile(const char* data, int length) {
    char filename[] = "test1.kqs";
    std::ofstream ofs(filename, std::ofstream::binary);

    ofs.write(data, length);
    ofs.close();
}

void writeToFile1(const char* data, int length) {
    char filename[] = "test2.kqs";
    std::ofstream ofs(filename, std::ofstream::binary);

    ofs.write(data, length);
    ofs.close();
}

void findZdaAndResolve(char* buffer, int size);
int main(int argc, char const *argv[]) {
    // const char data[] = "$GPZDA,081044.00,19,03,2015,,*62";
    // const char data[] = "M8$KQ$GPGGA,025425.00,3028.77191570,N,11423.85002500,E,1,10,1.0,19.563,M,-14.222,M,,*77";
    // char pdata[] =  "M8$KQ$GPZDA,081044.00,19,03,2015,,*62da$GPGGA,025425.00,3028.77191570,N,11423.85002500,E,1,10,1.0,19.563,M,-14.222,M,,*77";
    char originData[] =  "M8**********************888$GPGGA,025425.00,3028.77191570,N,11423.85002500,E,1,10,1.0,19.563,M,-14.222,M,,*77daxxxxxxx$GPZDA,081044.00,19,03,2015,,*62daM8";
    int length = strlen(originData);
    std::cout << "length:"<<length << std::endl;

    // 读文件
    std::ifstream ifs("recorddata24.kqs", std::ifstream::binary);

    // get pointer to associated buffer object
    std::filebuf* pbuf = ifs.rdbuf();
    std::size_t size = pbuf->pubseekoff (0,ifs.end,ifs.in);
    std::cout << "file size: "<<size << std::endl;
    pbuf->pubseekpos (0,ifs.in);
    char* buffer=new char[size];
    pbuf->sgetn (buffer,size);
    ifs.close();
    // std::cout.write (buffer,size);

    // 如果消息的开头包含zda的话, 找到并解析
    findZdaAndResolve(buffer, size);

    delete[] buffer;
    return 0;
}

void findZdaAndResolve(char* buffer, int length) {
    char* pdata = buffer;
    std::cout << "length: "<<length << std::endl;

    int startPos = 0;
    // 搜索ZDA
    for (int i = 0; i < 10; ++i) {
        if (('$' == pdata[i]) && ('G' == pdata[i+1])) {
            if (0 == strncmp(pdata+i+1, "GPZDA", 5)) {
                std::cout << "消息的开头处有ZDA, 一般是诺瓦泰板卡!" << std::endl;
                // 消息的开头有ZDA消息, 进行单独处理
                // 找到ZDA的尾部
                std::cout << "i:"<<i << std::endl;
                for (int j = i+12; j < 45; ++j) {
                    // std::cout << "j:"<<j<<"-"<<pdata[j] << std::endl;
                    if('*' == pdata[j]) {
                        std::cout << "j:"<<j << std::endl;
                        // 找到了结尾
                        startPos = j + 5;

                        // 解析ZDA数据
                        char temp = pdata[j+3];
                        pdata[j+3] = '\0';
                        // pdata[j+4] = '\0';
                        std::cout<<strlen(pdata+i)<<std::endl;
                        // _gpsDataMgr->SetZDAData(pdata + i, j+5-i);
                        std::cout << "ZDA:"<<pdata+i <<"== len:"<<strlen(pdata+i)<< std::endl;
                        pdata[j+3] = temp;
                        // std::cout << "ZDA:"<<pdata+i <<"== len:"<<strlen(pdata+i)<< std::endl;
                        // std::cout << "other:"<<pdata+startPos << std::endl;
                        break;
                    }
                }

                break;
            }else{
                std::cout << "开始处没有ZDA!" << std::endl;
            }
        }else{
            std::cout << "开始处没有$G的相关信息!" << std::endl;
        }
    }
    std::cout << "下一段数据的开始: "<< startPos << std::endl;
    // std::cout << pdata+startPos<<"="<<strlen(pdata+startPos) << std::endl;

    pdata = pdata + startPos;
    length = length - startPos;
    std::cout << "下一段数据的长度:"<<length << std::endl;
    std::cout << "==========================================================" << std::endl;

    int ggaStartPos = orderFindBinStr("GGA", 3, pdata, length);
    int invalidLen = 0;
    int _ggaDataLen = 0;
    // 搜索GGA
    if (-1 != ggaStartPos) {
        ggaStartPos -= 3;
        ggaStartPos = (ggaStartPos < 0) ? 0 : ggaStartPos;
        std::cout << "ggaStartPos: "<<ggaStartPos << std::endl;
        // 搜索 * 号
        long endPos = findCharInSrc('*', pdata, ggaStartPos + 18, length);
        if (endPos > ggaStartPos) {
            std::cout << "有完整的gga信息" << std::endl;
            // endPos += startPos;
            std::cout << "endPos:"<<endPos << std::endl;
            //_gpsDataMgr->SetGGAData(pdata + ggaStartPos, endPos - ggaStartPos + 3);
            char temp = pdata[endPos + 3];
            pdata[endPos+3] = '\0';
            std::cout << "gga:"<<pdata+ggaStartPos << std::endl;
            // 调用解析gga的接口
            //_gpsDataMgr->SetGGAData(pdata + ggaStartPos, endPos - ggaStartPos + 3);
            pdata[endPos+3] = temp;

            _ggaDataLen = endPos - ggaStartPos + 3;
            std::cout << "ggalen:"<<_ggaDataLen << std::endl;
            // _ggaData.assign(pdata+ggaStartPos, _ggaDataLen);
        }else{
            std::cout << "不完整的GGA信息!" << std::endl;
        }

        // 防止GGA在接收的数据开始或者中间部位
        if(ggaStartPos < 10) {
            // GGA在开始位置
            std::cout<<"GGA在开始处!"<<std::endl;
            // ggaStartPos = endPos + 4;
            startPos = endPos + 4;
            invalidLen = _ggaDataLen;
        }else{
            // GGA在中间位置
            std::cout<<"GGA在中间"<<std::endl;
            // ggaStartPos = 0;
            invalidLen = 0;
        }
    }else{
        // ggaStartPos = 0;
        invalidLen = 0;
    }
    std::cout << "下一段数据的开始:"<<startPos << std::endl;

    int pos = 0;
    pdata = pdata + invalidLen;
    length = length - invalidLen;
    std::cout << "剩下的数据长度:"<<length << std::endl;
    std::cout << "================================================" << std::endl;
    do {
        // 判断是否是GGA，GSV等数据
        if (('$' == pdata[pos]) && ('G' == pdata[pos + 1])) {
            std::cout << "pos:" <<pos<< std::endl;
            if (pos > 200) {
                // 解析原始数据
                // _gpsDataMgr->ResolveGpsObsInfo(kBTYPE_TrimbleRT27,pdata, pos + 1);
                // 将原始数据写入文件用于判断是否正确
                writeToFile(pdata, pos+1);
            }

            if (length - pos > 100) {
                // 分析GGA并解析
                // GpsDataConvertAndResolve(pdata + pos, length - pos);
                writeToFile1(pdata + pos, length - pos);
                std::cout << "============================gps data========" << std::endl;
                std::cout << pdata+pos << std::endl;
            }

            pos = length;
            break;
        } else {
            pos++;
        }
    } while (pos < length - 3);
}
