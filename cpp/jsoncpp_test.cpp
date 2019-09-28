#include <string>
#include <json/json.h>
#include <iostream>
#include <fstream>

#define LOGD_S(msg)

struct _KqExtent {
    double xmin;
    double ymin;
    double xmax;
    double ymax;
    _KqExtent()
    {
        xmin = 0;
        ymin = 0;
        xmax = 0;
        ymax = 0;
    }
};
//******************************************************OfflineTile
// 图层组合方式
enum _KqOfflineTileGroupMode {
    OLT_GROUP_MODE_MIN = 0,
    OLT_GROUP_MODE_DEFAULT = 1,
    OLT_GROUP_MODE_MAX = 2
};
// 瓦片切图方式
enum _KqOfflineTileCutMode {
    OLT_CUT_MODE_GOOGLE = 0,
    OLT_CUT_MODE_KQCUSTOM = 1,
    OLT_CUT_MODE_UNKONWN = 2
};

class _KqOfflineTileImageInfo{
public:
    std::string sFormat;
    _KqOfflineTileGroupMode groupMode;
    int tileHight;
    int tileWidth;
    _KqOfflineTileImageInfo(){
        sFormat = "PNG";
        groupMode = OLT_GROUP_MODE_DEFAULT;
        tileHight = 256;
        tileWidth = 256;
    }
};

class _KqOfflineTileScale {
public:
    int colCount;
    int rowCount;
    int level;
    int startCol;
    int startRow;
    double resolution;
    double scale;
    _KqOfflineTileScale(){
        colCount = 0;
        rowCount = 0;
        level = 0;
        startCol = 0;
        startRow = 0;
        resolution = 0.0;
        scale = 0.0;
    }
};

class _KqOfflineTileServiceInfo {
public:
    _KqOfflineTileImageInfo imageInfo;
    std::vector<std::string> layers;
    // 中心点
    double originX;
    double originY;
    // 范围
    _KqExtent mapRange;
    std::string projectString;
    _KqOfflineTileCutMode tileMode;
    // 瓦片集
    std::vector<_KqOfflineTileScale> scales;

    _KqOfflineTileServiceInfo(){
        originX = 0;
        originY = 0;
        projectString = "";
        tileMode = OLT_CUT_MODE_GOOGLE;
    }
};

std::ostream& operator<< (std::ostream& os, const _KqOfflineTileServiceInfo& serviceInfo){

    os<<serviceInfo.imageInfo.sFormat<<" "<<serviceInfo.imageInfo.groupMode<<" "<<serviceInfo.imageInfo.tileHight<<" "<<serviceInfo.imageInfo.tileWidth<<std::endl;
    os<<serviceInfo.originX<<" "<<serviceInfo.originY<<std::endl;
    os<<serviceInfo.projectString<<std::endl;
    os<<serviceInfo.mapRange.xmin<<" "<<serviceInfo.mapRange.ymin<<" "<<serviceInfo.mapRange.xmax<<" "<<serviceInfo.mapRange.ymax<<std::endl;
    os<<serviceInfo.tileMode<<std::endl;


    int count = serviceInfo.scales.size();
    for (int i = 0; i < count; ++i)
    {
        const _KqOfflineTileScale& scale = serviceInfo.scales[i];
        os<<scale.colCount<<" "<<scale.rowCount<<" "<<scale.level<<" "<<scale.startCol<<" "<<scale.startRow<<" "<<scale.resolution<<" "<<scale.scale<<std::endl;
    }

    return os;
}

_KqOfflineTileServiceInfo m_mapServiceInfo;

bool parse(std::string& capabilities){
    // 分析服务信息
    Json::Value root;
    Json::Reader reader;
    if(!reader.parse(capabilities, root)){
        LOGD_S("Read offline tile service info failed!");
        return false;
    }

    LOGD_S("Read offline tile service info success!");
    // imageSetting
    Json::Value& valImageSet = root["ImageSetting"];
    if(!valImageSet.isNull()) {
        m_mapServiceInfo.imageInfo.sFormat = valImageSet["Format"].asString();

        int groupMode = valImageSet["GroupMode"].asInt();
        if((OLT_GROUP_MODE_MIN < groupMode) && (OLT_GROUP_MODE_MAX > groupMode)) {
            m_mapServiceInfo.imageInfo.groupMode = static_cast<_KqOfflineTileGroupMode>(groupMode);
        }else{
            m_mapServiceInfo.imageInfo.groupMode = OLT_GROUP_MODE_DEFAULT;
        }

        m_mapServiceInfo.imageInfo.tileHight = valImageSet["Height"].asInt();
        m_mapServiceInfo.imageInfo.tileWidth = valImageSet["Width"].asInt();
    }else{
        LOGD_S("No imageSetting property!");
    }

    // layers
    Json::Value& valLayers = root["Layers"];
    if(!valLayers.isNull()){
        LOGD_S("Layers property!");
    }else{
        LOGD_S("No layers property!");
    }

    // MapOrigin
    Json::Value& valMapOrigin = root["MapOrigin"];
    if((!valMapOrigin.isNull()) && (valMapOrigin.size() >= 2)){
        m_mapServiceInfo.originX = valMapOrigin[0].asDouble();
        m_mapServiceInfo.originY = valMapOrigin[1].asDouble();
    }else{
        LOGD_S("No MapOrigin property!");
    }

    // MapRange
    Json::Value& valMapRange = root["MapRange"];
    if((!valMapRange.isNull()) && (valMapRange.size() >= 4)){
        m_mapServiceInfo.mapRange.xmin = valMapRange[0].asDouble();
        m_mapServiceInfo.mapRange.ymin = valMapRange[1].asDouble();
        m_mapServiceInfo.mapRange.xmax = valMapRange[2].asDouble();
        m_mapServiceInfo.mapRange.ymax = valMapRange[3].asDouble();
    }else{
        LOGD_S("No MapRange property!");
    }

    // ProjectString
    Json::Value& valProjectString = root["ProjectString"];
    if(!valProjectString.isNull()) {
        m_mapServiceInfo.projectString = valProjectString.asString();
    }else{
        LOGD_S("No ProjectString property!");
    }

    // TileMode
    Json::Value& valTileMode = root["TileMode"];
    if(!valTileMode.isNull()) {
        std::string strMode = valTileMode.asString();
        if("Google" == strMode) {
            m_mapServiceInfo.tileMode = OLT_CUT_MODE_GOOGLE;
        } else if("KQCustom" == strMode) {
            m_mapServiceInfo.tileMode = OLT_CUT_MODE_KQCUSTOM;
        } else{
            m_mapServiceInfo.tileMode = OLT_CUT_MODE_UNKONWN;
        }
    }else{
        LOGD_S("No TileMode property!");
    }

    // Scales
    Json::Value& valScales = root["Scales"];
    if(valScales.isNull()){
        LOGD_S("No Scales property!");
        return false;
    }

    int scaleCount = valScales.size();
    for(int i = 0; i < scaleCount; i++) {
        m_mapServiceInfo.scales.push_back(_KqOfflineTileScale());

        Json::Value& tmp = valScales[i];
        _KqOfflineTileScale& tileScale = m_mapServiceInfo.scales.back();
        tileScale.colCount = tmp["ColCount"].asInt();
        tileScale.rowCount = tmp["RowCount"].asInt();
        tileScale.level = tmp["Level"].asInt();
        tileScale.startRow = tmp["StartRow"].asInt();
        tileScale.startCol = tmp["StartCol"].asInt();
        tileScale.resolution = tmp["Resolution"].asDouble();
        tileScale.scale = tmp["Scale"].asDouble();
    }

    return true;
}

bool readTileInfo(std::string& info)
{
    // 读取文件分析
    std::string fullpath = "json_test.txt";

    std::ifstream ftileinfo(fullpath.c_str(), std::ifstream::in);
    if(!ftileinfo.is_open()){
        LOGD_S("Open file failed!");
        return NULL;
    }

    // 内存大小计算及分配
    ftileinfo.seekg(0, ftileinfo.end);
    int len = ftileinfo.tellg();
    ftileinfo.seekg(0, ftileinfo.beg);
    if(0 >= len){
        LOGD_S("Invalid file!");
        ftileinfo.close();
        return NULL;
    }

    info.resize(len, ' ');
    char* data = &*info.begin();
    // 读文件
    ftileinfo.read(data, len);
    ftileinfo.close();

    return true;
}

int main(int argc, char const *argv[])
{
    std::string info;
    if(!readTileInfo(info)){
        std::cout<<"Read file failed!"<<std::endl;
        return 1;
    }

    parse(info);

    std::cout<<m_mapServiceInfo<<std::endl;
    return 0;
}
