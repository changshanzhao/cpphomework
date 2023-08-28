//
// Created by Lenovo on 2023/8/28.
//

#ifndef HOMEWORK_PRODUCT_H
#define HOMEWORK_PRODUCT_H

#include <iostream>
#include <utility>

class Product{
public:
    Product(std::string v, std::string p, std::string t, std::string i):
    v_name(std::move(v)), p_name(std::move(p)), type(std::move(t)), info(std::move(i)){}

private:
    std::string v_name; // 供应商名称
    std::string p_name; // 产品名称
    std::string type; // 规格型号
    std::string info; // 产品说明
};
#endif //HOMEWORK_PRODUCT_H
