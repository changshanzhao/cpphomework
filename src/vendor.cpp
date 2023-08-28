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
        name = spliter.stringList[0]; // 供应商名称
        addr = spliter.stringList[1]; // 供应商地址
        type = spliter.stringList[2]; // 企业类型
        peo  = spliter.stringList[3]; // 联系人
        peo_phone = spliter.stringList[4]; // 联系人电话
        pos = spliter.stringList[5]; // 供应商职位
        level = spliter.stringList[6]; // 供应商星级
    }
}

void Vendor::showVendorInfo() {
    std::cout << msg << std::endl;
}