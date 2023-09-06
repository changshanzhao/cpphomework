//
// Created by Lenovo on 2023/8/28.
//

#ifndef HOMEWORK_PURCHASE_H
#define HOMEWORK_PURCHASE_H
#include <iostream>
#include <utility>
#include "Utils.h"

enum class PurchaseArrayOffSet{
    ID,
    NAME,
    NUM,
    TYPE,
    REQUEST
};

const int purchasePropertyCount = 5;

class Purchase{
public:
    Purchase(std::string formatInfo);
    Purchase(std::string i, std::string na, std::string nu,
             std::string t, std::string r) : id(std::move(i)),
             name(std::move(na)),num(std::move(nu)),
             type(std::move(t)), request(std::move(r)){
        msg = id + " " + name + " " + num + " " + type + " " + request;
    }
    void showPurchaseInfo();
    std::string backMsg(){return id + "," + name + "," + num + "," + type + "," + request;}
private:
    std::string id; // 内部编号
    std::string name; // 内部名
    std::string num; // 数量
    std::string type; // 规格型号
    std::string request; //采购要求
    std::string msg;
};
#endif //HOMEWORK_PURCHASE_H
