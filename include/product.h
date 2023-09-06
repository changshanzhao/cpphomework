//
// Created by Lenovo on 2023/8/28.
//

#ifndef HOMEWORK_PRODUCT_H
#define HOMEWORK_PRODUCT_H

enum class ProductArrayOffSet{
    V_NAME,
    P_NAME,
    TYPE,
    INFO
};

const int productPropertyCount = 4;

#include <iostream>
#include <utility>
#include "Utils.h"
class Product{
public:
    Product(std::string formatInfo);
    Product(std::string v, std::string p, std::string t, std::string i):
    v_name(std::move(v)), p_name(std::move(p)), type(std::move(t)), info(std::move(i)){
        msg = v_name + " " + p_name + " " + type + " " + info;
    }
    bool compareVName(std::string& name) {return v_name == name;}
    bool comparePName(std::string& name) {return p_name == name;}
    void showProductInfo();
    std::string backMsg(){return v_name + "," + p_name + "," + type + "," + info;}
private:
    std::string v_name; // 供应商名称
    std::string p_name; // 产品名称
    std::string type; // 规格型号
    std::string info; // 产品说明
    std::string msg;
};
#endif //HOMEWORK_PRODUCT_H
