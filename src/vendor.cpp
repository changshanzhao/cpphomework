//
// Created by Lenovo on 2023/8/28.
//
#include "../include/vendor.h"
#include "../include/FileExample.h"
Vendor::Vendor(std::string linedInfoFromTxt) {

    FileExample spliter;
    spliter.splitByDelimiter(linedInfoFromTxt, ' ');
    msg = linedInfoFromTxt;
    if(!spliter.stringList.empty() && spliter.stringList.size() == 7)
    {
        name = spliter.stringList[0]; // ��Ӧ������
        addr = spliter.stringList[1]; // ��Ӧ�̵�ַ
        type = spliter.stringList[2]; // ��ҵ����
        peo  = spliter.stringList[3]; // ��ϵ��
        peo_phone = spliter.stringList[4]; // ��ϵ�˵绰
        pos = spliter.stringList[5]; // ��Ӧ��ְλ
        level = spliter.stringList[6]; // ��Ӧ���Ǽ�
    }
}

void Vendor::showVendorInfo() {
    std::cout << msg << std::endl;
}