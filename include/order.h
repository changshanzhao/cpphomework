//
// Created by Lenovo on 2023/8/28.
//

#ifndef HOMEWORK_ORDER_H
#define HOMEWORK_ORDER_H
#include <iostream>
#include <utility>
#include "Utils.h"


const int orderPropertyCount = 9;

enum class OrderArrayOffSet{
    ID,
    V_NAME,
    PRODUCT,
    TYPE,
    MONEY,
    UNIT,
    NUM,
    TOTAL_MONEY,
    REQUEST
};

class Order{
public:
    Order(std::string formatInfo);
    Order(std::string i, std::string v, std::string p,
          std::string t, std::string m, std::string u,
          std::string n, std::string to, std::string r):
          id(std::move(i)), v_name(std::move(v)), product(std::move(p)),
          type(std::move(t)), money(std::move(m)), unit(std::move(u)),
          num(std::move(n)), total_money(std::move(to)), request(std::move(r)){

        msg = id + " " + v_name + " " + product + " " + type + " " + money + " " + \
        unit + " " + num + " " + total_money + " " + request;
    }
    void showOrderInfo(){MSG(msg);}
    void showOrderQuery(){
        MSG(id + " " + v_name + " " + product + " " + type + " " + money + " " + \
        unit + " " + num + " " + total_money);
    }
    std::string backMsg(){return id + "," + v_name + "," + product + "," + type + "," + money + "," + \
        unit + "," + num + "," + total_money;}
    bool compareID(std::string ID){return ID == this->id;}
private:
    std::string id; // �ɹ��ڲ����
    std::string v_name; // ��Ӧ��
    std::string product; // ��Ʒ����
    std::string type; // ����ͺ�
    std::string money; // ����
    std::string unit; // ������λ
    std::string num; // ����
    std::string total_money; // �ܼ�
    std::string request; // ����Ҫ��
    std::string msg;
};
#endif //HOMEWORK_ORDER_H
