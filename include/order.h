//
// Created by Lenovo on 2023/8/28.
//

#ifndef HOMEWORK_ORDER_H
#define HOMEWORK_ORDER_H
#include <iostream>
#include <utility>
#include "Utils.h"


const int orderPropertyCount = 10;

enum class OrderArrayOffSet{
    ID,
    V_NAME,
    PRODUCT,
    TYPE,
    MONEY,
    UNIT,
    NUM,
    TOTAL_MONEY,
    REQUEST,
    CONDITION
};

class Order{
public:
    Order(std::string formatInfo);
    Order(std::string i, std::string v, std::string p,
          std::string t, std::string m, std::string u,
          std::string n, std::string to, std::string r, std::string c):
          id(std::move(i)), v_name(std::move(v)), product(std::move(p)),
          type(std::move(t)), money(std::move(m)), unit(std::move(u)),
          num(std::move(n)), total_money(std::move(to)), request(std::move(r)), condition(std::move(c)){
        msg = id + " " + v_name + " " + product + " " + type + " " + money + " " + \
                unit + " " + num + " " + total_money + " " + request + " " + condition;
    }
    // 采购订单跟踪
    void showOrderInfo(){MSG(msg);}
    // 采购订单查询
    void showOrderQuery(){
        MSG(id + " " + v_name + " " + product + " " + type + " " + money + " " + \
        unit + " " + num + " " + total_money + " " + request);
    }
    // 采购订单管理
    std::string backMsg(){return id + "," + v_name + "," + product + "," + type + "," + money + "," + \
        unit + "," + num + "," + total_money +","+ request +","+ condition;}
    bool compareID(std::string ID){return ID == this->id;}
    void setCondition(const std::string& newCondition){condition = newCondition;}
private:
    std::string id; // 采购内部编号
    std::string v_name; // 供应商
    std::string product; // 产品名称
    std::string type; // 规格型号
    std::string money; // 单价
    std::string unit; // 计量单位
    std::string num; // 数量
    std::string total_money; // 总价
    std::string request; // 订单要求
    std::string condition; //订单状态
    std::string msg;
};
#endif //HOMEWORK_ORDER_H
