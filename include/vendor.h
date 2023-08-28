//
// Created by Lenovo on 2023/8/28.
//

#ifndef HOMEWORK_VENDOR_H
#define HOMEWORK_VENDOR_H
#include <iostream>
#include <utility>

class Vendor{
public:
    Vendor(std::string n, std::string a, std::string t,
           std::string p, std::string p_p, std::string po,
           std::string l) : name(std::move(n)), addr(std::move(a)),
           type(std::move(t)),peo(std::move(p)), peo_phone(std::move(p_p)),
           pos(std::move(po)), level(std::move(l)){}

private:
    std::string name; // 供应商名称
    std::string addr; // 供应商地址
    std::string type; // 企业类型
    std::string peo; // 联系人
    std::string peo_phone; // 联系人电话
    std::string pos; // 供应商职位
    std::string level; // 供应商星级
};
#endif //HOMEWORK_VENDOR_H
