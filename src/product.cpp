//
// Created by ³Â¹ÚºÀ on 2023/8/28.
//
#include "../include/product.h"
#include "../include/FileExample.h"


Product::Product(std::string formatInfo) {
    FileExample example;
    example.splitByDelimiter(formatInfo, ',');
    if(example.stringList.size() == 4)
    {
        v_name = example.stringList[static_cast<int>(ProductArrayOffSet::V_NAME)];
        p_name = example.stringList[static_cast<int>(ProductArrayOffSet::P_NAME)];
        type = example.stringList[static_cast<int>(ProductArrayOffSet::TYPE)];
        info = example.stringList[static_cast<int>(ProductArrayOffSet::INFO)];
    }

    msg = formatInfo;
}

void Product::showProductInfo() {
    MSG(msg);
}