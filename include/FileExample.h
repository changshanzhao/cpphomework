//
// Created by Lenovo on 2023/8/28.
//

#ifndef HOMEWORK_FILEEXAMPLE_H
#define HOMEWORK_FILEEXAMPLE_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
using StringList = std::vector<std::string>;
#define DEBUG 0
class FileExample {
public:
// public stringList

    StringList stringList;

    void readDataFile( const string & fileName) {
        ifstream inFile( fileName, ios_base::in );
        string strRecord;
        //���ж��뵽strRecord�ַ�����
        while ( getline( inFile, strRecord ) ) {
            //���ַ������ָ����ָ��ɶ���ַ���
            stringList.push_back(strRecord);
        }
    }

    //���ַ������ָ����ָ��ɶ���ַ���
    void splitByDelimiter( const string & str, char delimiter ) {
        istringstream sstream( str );
        string field;
        while ( getline( sstream, field, delimiter ) ) {
            if(field.empty()){
                continue;
            }
            #if DEBUG
            cout << field << endl;
            #endif
            stringList.push_back(field);
        }


    }


};
#endif //HOMEWORK_FILEEXAMPLE_H
