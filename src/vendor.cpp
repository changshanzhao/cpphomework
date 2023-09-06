
#include "../include/vendor.h"
#include "../include/FileExample.h"
Vendor::Vendor(std::string linedInfoFromTxt) {

    FileExample spliter;
    spliter.splitByDelimiter(linedInfoFromTxt, ' ');
    msg = linedInfoFromTxt;
    if(!spliter.stringList.empty() && spliter.stringList.size() == 7)
    {
        name = spliter.stringList[0];
        addr = spliter.stringList[1];
        type = spliter.stringList[2];
        peo  = spliter.stringList[3];
        peo_phone = spliter.stringList[4];
        pos = spliter.stringList[5];
        level = spliter.stringList[6];
    }
}

void Vendor::showVendorInfo() {
    std::cout << msg << std::endl;
}