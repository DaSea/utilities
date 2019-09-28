/**
* һ����Ƭ���м䵽���߽��е���ɢ��ʾ���㷨
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

    // ѭ���ҳ����ʵ�key
    long rowNum = 0, colNum = 0;
    // �к��еĿ�ͷ��0��ʼ
    if((0 == (endRow - beginRow) % 2) && (0 != (endCol - beginCol) % 2)) {
        // ������,ż����
        rowNum = 1; colNum = 2;
        std::cout << "������,ż����" << rowNum << " " << colNum << std::endl;
    }
    else if((0 != (endRow - beginRow) % 2) && (0 == (endCol - beginCol) % 2)) {
        // ż����,������
        rowNum = 2; colNum = 1;
        std::cout << "ż����,������" << rowNum << " " << colNum << std::endl;
    }
    else if((0 == (endRow - beginRow) % 2) && (0 == (endCol - beginCol) % 2)) {
        // ������,������
        rowNum = 1; colNum = 1;
        std::cout << "������,������" << rowNum << " " << colNum << std::endl;
    }
    else if((0 != (endRow - beginRow) % 2) && (0 != (endCol - beginCol) % 2)) {
        // ż����,ż����
        rowNum = 2; colNum = 2;
        std::cout << "ż����,ż����" <<rowNum<<" "<<colNum<< std::endl;
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

        // ��Ҫ�ж�������Χ
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

    // ѭ���ҳ����ʵ�key
    long rowNum = 0, colNum = 0;
    // �к��еĿ�ͷ��0��ʼ
    if((0 == (endRow - beginRow) % 2) && (0 != (endCol - beginCol) % 2)) {
        // ������,ż����
        rowNum = 1; colNum = 2;
        LOGD_S("������, ż����: %ld, %ld", rowNum, colNum);
    }
    else if((0 != (endRow - beginRow) % 2) && (0 == (endCol - beginCol) % 2)) {
        // ż����,������
        rowNum = 2; colNum = 1;
        LOGD_S("ż����,������: %ld, %ld", rowNum, colNum);
    }
    else if((0 == (endRow - beginRow) % 2) && (0 == (endCol - beginCol) % 2)) {
        // ������,������
        rowNum = 1; colNum = 1;
        LOGD_S("������,������: %ld, %ld", rowNum, colNum);
    }
    else if((0 != (endRow - beginRow) % 2) && (0 != (endCol - beginCol) % 2)) {
        // ż����,ż����
        rowNum = 2; colNum = 2;
        LOGD_S("ż����,ż����: %ld, %ld", rowNum, colNum);
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

        // ��Ҫ�ж�������Χ
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
    std::cout << "��Ƭ����Ϊ:"<< count << std::endl;
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
    // ���ܴ����������
    // row-col(1, ����:ż��; 2,ż��:����; 3,����:����; 4, ż��:ż��)
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
    // 1, ����:ż��
    //std::cout << "=========================����: ż��(4, 5)============================" << std::endl;
    //key_calc(0, 2, 0, 4);
    //std::cout << "===============================================================" << std::endl;
    //// 2, ż��:����
    //std::cout << "=========================ż��:����(3, 4)============================" << std::endl;
    //key_calc(2, 5, 1, 5);
    //std::cout << "===============================================================" << std::endl;
    //// 3, ����:����
    //std::cout << "=========================����:����(4, 6)============================" << std::endl;
    //key_calc(4, 8, 1, 5);
    //std::cout << "===============================================================" << std::endl;

    // 4, ż��:ż��
    //std::cout << "=========================ż��:ż��(5, 5)============================" << std::endl;
    //key_calc(4, 7, 20, 25);
    //std::cout << "===============================================================" << std::endl;
    return 0;
}
