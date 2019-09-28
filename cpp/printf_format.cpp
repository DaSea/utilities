#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>

#define MAX_TILE_PATH (512)

char buffer1[MAX_TILE_PATH] = {0};

std::string format = "png";
std::string path = "/sdcard/maponline/wmts(to.tianditu.com)/cva/c/";
char* getTilePath(long level, long row, long col);

int other(void)
{
    double dd = 2348832.7867976787;

    char buffer[32] = {0};
    sprintf(buffer, "%#.16g", dd);
    printf("%s\n", buffer);

    long level = 10;
    long row = 300;
    long col = 888;

    std::string fullpath;
    fullpath = getTilePath(level, row, col);
    std::cout << fullpath << std::endl;

    level = 21;
    row = 53322;
    col = 33455;
    fullpath = getTilePath(level, row, col);
    std::cout << fullpath << std::endl;

    level = 20;
    row = 53;
    col = 33;
    fullpath = getTilePath(level, row, col);
    std::cout << fullpath << std::endl;

    return 0;
}


char* getTilePath(long level, long row, long col) {
    int x1 = col / 10000;
    int y1 = row / 10000;
    int x2 = col % 10000 / 100;
    int y2 = row % 10000 / 100;
    int x3 = ((col % 100 ) > 49 ) ? 1 : 0;

    // 需要采用c语言的形式格式化
    int status = snprintf(buffer1, MAX_TILE_PATH,
        "%s%ld/%d/%d/%d/%d/%d/%ld_%ld.%s",
        path.c_str(), level, x1, y1, x2,
        y2, x3, col, row, format.c_str());
    if(-1 == status) {
        std::cout<<"Get tile path error!"<<", len: "<<status<<std::endl;
    }
    std::cout<<buffer1<<", len: "<<status<<std::endl;

    return buffer1;
}

void other(long level, long row, long col) {
    int x1 = col / 10000;
    int y1 = row / 10000;
    int x2 = col % 10000 / 100;
    int y2 = row % 10000 / 100;
    int x3 = ((col % 100 ) > 49 ) ? 1 : 0;

    level = 21;
    row = 53322;
    col = 33455;
    int status = snprintf(buffer1, MAX_TILE_PATH,
        "%s%ld/%d/%d/%d/%d/%d/%ld_%ld.%s",
        path.c_str(), level, x1, y1, x2,
        y2, x3, col, row, format.c_str());
    if(-1 == status) {
        std::cout<<"Get tile path error!"<<std::endl;
    }
    std::cout<<buffer1<<", len: "<<status<<std::endl;

    level = 20;
    row = 38;
    col = 33;
    status = snprintf(buffer1, MAX_TILE_PATH,
        "%s%ld/%d/%d/%d/%d/%d/%ld_%ld.%s",
        path.c_str(), level, x1, y1, x2,
        y2, x3, col, row, format.c_str());
    if(-1 == status) {
        std::cout<<"Get tile path error!"<<", len: "<<status<<std::endl;
    }
    std::cout<<buffer1<<", len: "<<status<<std::endl;
}

void wmsMapUrl() {
    std::stringstream m_mapStream;
    std::string m_mapUrl;
    char m_mapUrlBuffer[512] = {0};
    std::string m_urlBase = "http://sampleserver1.arcgisonline.com/ArcGIS/services/Specialty/ESRI_StatesCitiesRivers_USA/MapServer/WMSServe";
    std::string layers = "0,1,2";
    std::string styles = "";
    std::string version = "1.3.0";
    double xmin = 37365253.942168809473514557;
    double xmax = 37423303.942168809473514557;
    double ymin = 4124565.759029826149344444;
    double ymax = 4187271.759029826149344444;
    std::string crs = "CRS:84";
    long width = 1024;
    long height = 1024;
    std::string format = "image/png";
    std::string strTransparent = "TRUE";

    time_t tm1 = time(NULL);
    m_mapStream.str("");
    m_mapStream.clear();
    m_mapStream<<m_urlBase<<"?SERVICE=WMS&VERSION="<<version;
    m_mapStream<<"&REQUEST=GetMap&LAYERS="<<layers;
    m_mapStream<<"&STYLES="<<styles;
    m_mapStream<<std::setiosflags(std::ios::fixed)<<std::setprecision(14)
        <<"&BBOX="<<xmin<<","<<ymin<<","<<xmax<<","<<ymax;
    m_mapStream<<"&CRS="<<crs;
    m_mapStream<<"&FORMAT="<<format;
    m_mapStream<<"&WIDTH="<<width<<"&HEIGHT="<<height;
    m_mapStream<<"&TRANSPARENT="<<strTransparent;
    m_mapUrl = m_mapStream.str();

    time_t tm2 = time(NULL);
    std::cout << "tm:"<<tm2-tm1 << std::endl;
    std::cout << m_mapUrl<< std::endl;


    std::cout << "=========================================================" << std::endl;
    tm1 = time(NULL);
    int status = snprintf(m_mapUrlBuffer, 512,
    "%s?SERVICE=WMS&VERSION=%s&REQUEST=GetMap&LAYERS=%s&STYLES=%s&BBOX=%.14f,%.14f,%.14f,%.14f&CRS=%s&FORMAT=%s&WIDTH=%ld&HEIGHT=%ld&TRANSPARENT=%s",
    m_urlBase.c_str(), version.c_str(), layers.c_str(), styles.c_str(),
    xmin, ymin, xmax, ymax, crs.c_str(), format.c_str(), width, height, strTransparent.c_str()
    );
    tm2 = time(NULL);
    std::cout << "tm:" <<tm2-tm1<< std::endl;
    std::cout <<m_mapUrlBuffer << std::endl;
}

void wmtsMapUfl() {
    std::string m_tileBaseUrl = "http://t0.tianditu.com/cva_c/wmts?SERVICE=WMTS&REQUEST=GetTile";
    std::string version = "1.0.0";
    std::string layerName = "cva";
    std::string style = "default";
    std::string format = "tiles";
    std::string matrixSet = "c";
    long level = 7;
    long row = 33;
    long col = 37;

    std::stringstream m_stream;
    std::string m_tileUrl;
    m_stream<<m_tileBaseUrl;
    m_stream<<"&VERSION="<<version;
    m_stream<<"&LAYER="<<layerName;
    m_stream<<"&STYLE="<<style;
    m_stream<<"&FORMAT="<<format;
    m_stream<<"&TILEMATRIXSET="<<matrixSet;
    m_stream<<"&TILEMATRIX="<<level;
    m_stream<<"&TILEROW="<<row<<"&TILECOL="<<col;
    m_tileUrl = m_stream.str();
    std::cout << m_tileUrl << std::endl;

    std::cout << "================================" << std::endl;
    char m_tileUrlBuffer[512] = {0};
    int status = snprintf(m_tileUrlBuffer, 512,
    "%s&VERSION=%s&LAYER=%s&STYLE=%s&FORMAT=%s&TILEMATRIXSET=%s&TILEMATRIX=%ld&TILEROW=%ld&TILECOL=%ld",
    m_tileBaseUrl.c_str(), version.c_str(), layerName.c_str(), style.c_str(),
    format.c_str(), matrixSet.c_str(), level, row, col
    );
    std::cout << m_tileUrlBuffer << std::endl;
}

void arcdynamicMapUrl() {
    std::string layers = "0,1,2";
    double xmin = 37365253.942168809473514557;
    double xmax = 37423303.942168809473514557;
    double ymin = 4124565.759029826149344444;
    double ymax = 4187271.759029826149344444;
    long width = 1024;
    long height = 1024;

    // urlbase: http://192.168.1.120:6080/arcgis/rest/services/ydzf84/basemap/MapServer
    // /export?dpi=96&
    // transparent=true&format=png8&
    // bbox=114.37919284549102,30.471960824857685,114.42528827856188,30.49205193259525
    // &bboxSR=4326&
    // imageSR=4326&size=1333,581&f=image
    std::string m_urlBase = "http://192.168.1.120:6080/arcgis/rest/services/ydzf84/basemap/MapServer";
    long wkid = 4326;
    bool transpant = true;
    std::string formatSuffix = "png";
    std::string formatPrefix = "image";

    std::string requestUrl; // = m_urlBase + "/export?dpi=96";
    std::stringstream ss;
    ss<<m_urlBase<<"/export?dpi=96";
    ss<<"&transparent="<<transpant;
    ss<<"&format="<<formatSuffix;
    ss<<std::setiosflags(std::ios::fixed)<<std::setprecision(14)
        <<"&bbox="<<xmin<<","<<ymin<<","<<xmax<<","<<ymax;
    ss<<"&bboxSR="<<wkid;
    ss<<"&imageSR="<<wkid;
    ss<<"&size="<<width<<","<<height;
    ss<<"&f="<<formatPrefix;
    ss<<"&layers=show:"<<layers;
    requestUrl = ss.str();
    std::cout << requestUrl << std::endl;

    std::cout << "==========================================" << std::endl;
    char m_mapUrlBuffer[512] = {0};
    int status = snprintf(m_mapUrlBuffer, 512,
        "%s/export?dpi=96&transparent=%d&format=%s&bbox=%.14f,%.14f,%.14f,%.14f&bboxSR=%ld&imageSR=%ld&size=%ld,%ld&f=%s&layers=show:%s",
        m_urlBase.c_str(), transpant, formatSuffix.c_str(),
        xmin, ymin, xmax, ymax, wkid, wkid, width, height, formatPrefix.c_str(), layers.c_str());
    std::cout << m_mapUrlBuffer << std::endl;
}

int main(int argc, char const *argv[]) {
    // wmsMapUrl();
    // wmtsMapUfl();
    arcdynamicMapUrl();
    return 0;
}
