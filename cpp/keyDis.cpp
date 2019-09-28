/**
* 一个瓦片从中间到俩边进行的扩散显示的算法
**/
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <set>
#include <list>
#include <vector>

#define LOGD_S(msg, ...)

std::vector<std::string> m_requestDownload;
void key_calc(long beginRow, long endRow, long beginCol, long endCol)
{
    //if((beginRow == endRow) || (beginCol == endCol)) {
    //    return;
    //}

    long startRow = static_cast<long>(floor((beginRow + endRow) / 2));
    long startCol = static_cast<long>(floor((beginCol + endCol) / 2));
    std::cout << "start row-col: " << startRow << "_" << startCol << std::endl;

    // 循环找出合适的key
    long rowNum = 0, colNum = 0;
    // 行和列的开头以0开始
    if((0 == (endRow - beginRow) % 2) && (0 != (endCol - beginCol) % 2)) {
        // 奇数行,偶数列
        rowNum = 1; colNum = 2;
        std::cout << "奇数行,偶数列" << rowNum << " " << colNum << std::endl;
    }
    else if((0 != (endRow - beginRow) % 2) && (0 == (endCol - beginCol) % 2)) {
        // 偶数行,奇数列
        rowNum = 2; colNum = 1;
        std::cout << "偶数行,奇数列" << rowNum << " " << colNum << std::endl;
    }
    else if((0 == (endRow - beginRow) % 2) && (0 == (endCol - beginCol) % 2)) {
        // 奇数行,奇数列
        rowNum = 1; colNum = 1;
        std::cout << "奇数行,奇数列" << rowNum << " " << colNum << std::endl;
    }
    else if((0 != (endRow - beginRow) % 2) && (0 != (endCol - beginCol) % 2)) {
        // 偶数行,偶数列
        rowNum = 2; colNum = 2;
        std::cout << "偶数行,偶数列" <<rowNum<<" "<<colNum<< std::endl;
    }


    std::stringstream ss;
    std::set<std::string> dlSet;
    long idxRow = 0, idxCol = 0;
    long level = 5;
    int forCount = 0;
    bool isRowEnd = false, isColEnd = false;
    std::string key;
    while(1) {
        long rowCount = startRow + rowNum + forCount;
        rowCount = (rowCount >= endRow) ? endRow : rowCount;
        idxRow = startRow - forCount;
        idxRow = (idxRow <= beginRow) ? beginRow : idxRow;

        if((idxRow == beginRow) && (rowCount == endRow))
            isRowEnd = true;

        // 需要判断俩个范围
        std::cout << "rowcount: " << rowCount << std::endl;
        for(; idxRow < rowCount; idxRow++) {
            long colCount = startCol + colNum+forCount;
            colCount = (colCount >= endCol) ? endCol : colCount;
            idxCol = startCol - forCount;
            idxCol = (idxCol <= beginCol) ? beginCol : idxCol;
            if((idxCol == beginCol) && (colCount == endCol))
                isColEnd = true;

            for(; idxCol < colCount; ++idxCol) {
                ss.str("");
                ss.clear();
                ss << level<<"_"<<idxRow << "_" << idxCol;
                key = ss.str();
                if(dlSet.end() == dlSet.find(key)) {
                    dlSet.insert(key);
                    m_requestDownload.push_back(key);
                }
            }
        }
        forCount++;

        if(isRowEnd)
            if(isColEnd)
                break;
    }
    dlSet.clear();                                                              

    std::vector<std::string>::iterator it = m_requestDownload.begin();
    std::cout << "downlaod size: " << m_requestDownload.size() << std::endl;
    for(; it != m_requestDownload.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    //m_requestDownload.sort();
    std::cout << "===================sort================================" << std::endl;
    it = m_requestDownload.begin();
    for(; it != m_requestDownload.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
    m_requestDownload.clear();
}

std::set<std::string> m_sortSet;
void TileSort(long level, long beginRow, long endRow, long beginCol,
                            long endCol, std::vector<std::string>& displayVec)
{
    if((beginRow == endRow) || (beginCol == endCol)) {
        return;
    }

    long startRow = static_cast<long>(floor((beginRow + endRow) / 2));
    long startCol = static_cast<long>(floor((beginCol + endCol) / 2));
    LOGD_S("start row-col:%ld %ld ", startRow, startCol);

    // 循环找出合适的key
    long rowNum = 0, colNum = 0;
    // 行和列的开头以0开始
    if((0 == (endRow - beginRow) % 2) && (0 != (endCol - beginCol) % 2)) {
        // 奇数行,偶数列
        rowNum = 1; colNum = 2;
        LOGD_S("奇数行, 偶数列: %ld, %ld", rowNum, colNum);
    }
    else if((0 != (endRow - beginRow) % 2) && (0 == (endCol - beginCol) % 2)) {
        // 偶数行,奇数列
        rowNum = 2; colNum = 1;
        LOGD_S("偶数行,奇数列: %ld, %ld", rowNum, colNum);
    }
    else if((0 == (endRow - beginRow) % 2) && (0 == (endCol - beginCol) % 2)) {
        // 奇数行,奇数列
        rowNum = 1; colNum = 1;
        LOGD_S("奇数行,奇数列: %ld, %ld", rowNum, colNum);
    }
    else if((0 != (endRow - beginRow) % 2) && (0 != (endCol - beginCol) % 2)) {
        // 偶数行,偶数列
        rowNum = 2; colNum = 2;
        LOGD_S("偶数行,偶数列: %ld, %ld", rowNum, colNum);
    }

    std::stringstream ss;
    long idxRow = 0, idxCol = 0;
    long forCount = 0;
    bool isRowEnd = false, isColEnd = false;
    std::string key;
    while(1) {
        long rowCount = startRow + rowNum + forCount;
        rowCount = (rowCount >= endRow) ? endRow : rowCount;
        idxRow = startRow - forCount;
        idxRow = (idxRow <= beginRow) ? beginRow : idxRow;

        if((idxRow == beginRow) && (rowCount == endRow))
            isRowEnd = true;

        // 需要判断俩个范围
        for(; idxRow < rowCount; idxRow++) {
            long colCount = startCol + colNum + forCount;
            colCount = (colCount >= endCol) ? endCol : colCount;
            idxCol = startCol - forCount;
            idxCol = (idxCol <= beginCol) ? beginCol : idxCol;
            if((idxCol == beginCol) && (colCount == endCol))
                isColEnd = true;

            for(; idxCol < colCount; ++idxCol) {
                ss.str("");
                ss.clear();
                ss << level << "_" << idxRow << "_" << idxCol;
                key = ss.str();
                if(m_sortSet.end() == m_sortSet.find(key)) {
                    m_sortSet.insert(key);
                    m_requestDownload.push_back(key);
                    displayVec.push_back(key);
                }
            }
        }
        forCount++;

        if(isRowEnd)
            if(isColEnd)
                break;
    }
    m_sortSet.clear();
}

void old_calc(long beginRow, long endRow, long beginCol, long endCol) {
    long level = 5;
    int count = 0;
    for(long i = beginRow; i < endRow; ++i) {
        for(long j = beginCol; j < endCol; ++j) {
            std::cout << level << "_" << i << "_" << j << std::endl;
            count++;
        }
    }
    std::cout << "瓦片个数为:"<< count << std::endl;
}

void display_download()
{
    std::cout << "===================display download"<< m_requestDownload.size() << std::endl;
    for(int i = 0; i < m_requestDownload.size(); ++i)
    {
        std::cout << m_requestDownload[i]<< std::endl;
    }
    std::cout << "===================display end!======================================" << std::endl;
}

int main(int argc, char const* argv[])
{
    // 可能存在四种情况
    // row-col(1, 奇数:偶数; 2,偶数:奇数; 3,奇数:奇数; 4, 偶数:偶数)
    long beginRow = 0, endRow = 0, beginCol = 0, endCol = 0;
    //std::cout << "===============================================================" << std::endl;
    //old_calc(2, 2, 0, 4);
    ////std::cout << "===============================================================" << std::endl;
    //key_calc(2, 2, 0, 4);
    std::cout << "================= uuuu==============================================" << std::endl;

    std::vector<std::string> dispVec;
    TileSort(3, 2, 3, 4, 5, dispVec);
    display_download();

    old_calc(2, 3, 4, 5);
    
    std::cout << "======================lllll=========================================" << std::endl;
    // 1, 奇数:偶数
    //std::cout << "=========================奇数: 偶数(4, 5)============================" << std::endl;
    //key_calc(0, 2, 0, 4);
    //std::cout << "===============================================================" << std::endl;
    //// 2, 偶数:奇数
    //std::cout << "=========================偶数:奇数(3, 4)============================" << std::endl;
    //key_calc(2, 5, 1, 5);
    //std::cout << "===============================================================" << std::endl;
    //// 3, 奇数:奇数
    //std::cout << "=========================奇数:奇数(4, 6)============================" << std::endl;
    //key_calc(4, 8, 1, 5);
    //std::cout << "===============================================================" << std::endl;

    // 4, 偶数:偶数
    //std::cout << "=========================偶数:偶数(5, 5)============================" << std::endl;
    //key_calc(4, 7, 20, 25);
    //std::cout << "===============================================================" << std::endl;
    return 0;
}
