//
// Created by Lenovo on 2023/8/28.
//

#ifndef HOMEWORK_INQUIRY_H
#define HOMEWORK_INQUIRY_H
#include <utility>
#include "Utils.h"
#include "iostream"

const int inquiryPropertyCount = 9;

enum class InquiryArrayOffSet{
    ID,
    V_NAME,
    PRODUCT,
    TYPE,
    INFO,
    MONEY,
    M_INFO,
    EVALUATE,
    LEVEL
};

class Inquiry{
public:
    Inquiry(std::string info);
    Inquiry(std::string i, std::string v, std::string p,
            std::string t, std::string in, std::string m,
            std::string m_i, std::string e, std::string l):
            id(std::move(i)), v_name(std::move(v)), product(std::move(p)),
            type(std::move(t)), info(std::move(in)), money(std::move(m)),
            m_info(std::move(m_i)), evaluate(std::move(e)), level(std::move(l)){
        msg = id + " " + v_name + " " + product + " " + type + " " + info + " " + \
                money + " " + m_info + " " + evaluate + " " + level;
    }
    void showInquiryInfo(){MSG(msg);}
    std::string backMsg(){return id + "," + v_name + "," + product + "," + type + "," + info + "," + \
                money + "," + m_info + "," + evaluate + "," + level;}
    bool compareVName(std::string name){return name == v_name;}
    bool compareProductName(std::string name){return name == product;}
    bool compareID(std::string ID){return ID == this->id;}
private:
    std::string id; // 内部编号
    std::string v_name; // 供应商
    std::string product; // 产品名称
    std::string type; // 规格型号
    std::string info; // 产品说明
    std::string money; // 报价
    std::string m_info; // 报价说明
    std::string evaluate; // 询价过程评价
    std::string level; // 询价过程星级
    std::string msg;
};



#endif //HOMEWORK_INQUIRY_H
