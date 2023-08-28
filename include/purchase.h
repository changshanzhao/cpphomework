//
// Created by Lenovo on 2023/8/28.
//

#ifndef HOMEWORK_PURCHASE_H
#define HOMEWORK_PURCHASE_H
#include <iostream>
#include <utility>
class Purchase{
public:
    Purchase(std::string i, std::string na, std::string nu,
             std::string t, std::string r) : id(std::move(i)),
             name(std::move(na)),num(std::move(nu)),
             type(std::move(t)), request(std::move(r)){}
private:
    std::string id; // 内部编号
    std::string name; // 内部名
    std::string num; // 数量
    std::string type; // 规格型号
    std::string request; //采购要求
};
#endif //HOMEWORK_PURCHASE_H
