//
// Created by Lenovo on 2023/8/28.
//
// App.cpp
#include "../include/FileExample.h"
#include "../include/App.h"
#include "../include/Menu.h"
#include "../include/MenuMgr.h"
#include "../include/inquiry.h"
#include "../include/product.h"
#include "../include/purchase.h"
#include "../include/vendor.h"
#include "../include/order.h"
const std::string VENDORPATH = std::string("../sourse/vendor.txt");
const std::string PRODUCTPATH = std::string("../sourse/product.txt");
const std::string  PURCHASEPATH = std::string("../sourse/purchase.txt");
const std::string  INQUIRYEPATH = std::string("../sourse/inquiry.txt");
const std::string  ORDERPATH = std::string("../sourse/order.txt");
Data data;
void App::init( ) {
    // preInit all basic data
    FileExample example;
    example.readDataFile(VENDORPATH);
    for(int i = 0; i < example.stringList.size(); i++)
    {
        data.appVendor.push_back(Vendor(example.stringList[i]));
    }

    example.stringList.clear();

    example.readDataFile(PRODUCTPATH);
    for(int i = 0; i < example.stringList.size(); i++)
    {
        data.appProduct.push_back(Product(example.stringList[i]));
    }

    example.stringList.clear();

    example.readDataFile(PURCHASEPATH);
    for(int i = 0; i < example.stringList.size(); i++)
    {
        data.appPurchase.push_back(Purchase(example.stringList[i]));
    }

    example.stringList.clear();

    example.readDataFile(INQUIRYEPATH);
    for(int i = 0; i < example.stringList.size(); i++)
    {
        data.appPurchase.push_back(Purchase(example.stringList[i]));
    }

    example.stringList.clear();

    example.readDataFile(ORDERPATH);
    for(int i = 0; i < example.stringList.size(); i++)
    {
        data.appPurchase.push_back(Purchase(example.stringList[i]));
    }
}

void App::run( ) {
    bool running = true;
    while ( running ) {
        Menu * curMenu = MenuMgr::getInstance( ).currentMenu( ); //取当前活动菜单
        running = curMenu->process( ); //处理菜单
    }
}

void App::term( ) {}