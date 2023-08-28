//
// Created by Lenovo on 2023/8/28.
//

#ifndef HOMEWORK_FILEEXAMPLE_H
#define HOMEWORK_FILEEXAMPLE_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class FileExample {
public:
    void readDataFile( const string & fileName ) {
        ifstream inFile( fileName, ios_base::in );
        string strRecord;
        //逐行读入到strRecord字符串中
        while ( getline( inFile, strRecord ) ) {
            //将字符串按分隔符分隔成多个字符串
            splitByDelimiter( strRecord, ',' );
            cout << "-----------" << endl;
        }
    }

    //将字符串按分隔符分隔成多个字符串
    void splitByDelimiter( const string & str, char delimiter ) {
        istringstream sstream( str );
        string field;
        while ( getline( sstream, field, delimiter ) ) {
            cout << field << endl;
        }
    }

    //输出到文本文件
    void writeDataFile( const string& fileName) {
        ofstream outFile( fileName, ios_base::out );
        outFile << "abc1" << endl;
        outFile << "abc2" << endl;
    }
};
#endif //HOMEWORK_FILEEXAMPLE_H
