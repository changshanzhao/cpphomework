//
// Created by Lenovo on 2023/8/28.
//

#ifndef HOMEWORK_VENDOR_H
#define HOMEWORK_VENDOR_H


#include <iostream>
#include <utility>
#include "vendor.h"
#include "FileExample.h"
#include "Utils.h"

enum class VendorArrayOffset{
    NAME,
    ADDR,
    TYPE,
    PEO,
    PEO_PHONE,
    POS,
    LEVEL
};

const int vendorPropertyCount = 7;

class Vendor{
private:
    std::string name; // ��Ӧ������
    std::string addr; // ��Ӧ�̵�ַ
    std::string type; // ��ҵ����
    std::string peo; // ��ϵ��
    std::string peo_phone; // ��ϵ�˵绰
    std::string pos; // ��Ӧ��ְλ
    std::string level; // ��Ӧ���Ǽ�
    std::string msg; // ͵��������չʾ��
public:
    Vendor();
    Vendor(std::string linedInfoFromTxt);
    void showVendorInfo();
    bool compareName(std::string name) {
        return name == this->name;
    }
    Vendor(std::string n, std::string a, std::string t,
           std::string p, std::string p_p, std::string po,
           std::string l) : name(std::move(n)), addr(std::move(a)),
                            type(std::move(t)),peo(std::move(p)), peo_phone(std::move(p_p)),
                            pos(std::move(po)), level(std::move(l)){
        msg = name + " " + addr + " " + type + " " + peo + " " + peo_phone + " " + pos + " " + level;
    }

    std::string backMsg(){return msg;}
};
#endif //HOMEWORK_VENDOR_H
