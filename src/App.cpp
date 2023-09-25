//
// Created by Lenovo on 2023/8/28.
//
// App.cpp

#include "../include/App.h"
#include "../include/Menu.h"
#include "../include/MenuMgr.h"
const std::string VENDORPATH = std::string("../source/vendor.txt");
const std::string PRODUCTPATH = std::string("../source/product.txt");
const std::string  PURCHASEPATH = std::string("../source/purchase.txt");
const std::string  INQUIRYEPATH = std::string("../source/inquiry.txt");
const std::string  ORDERPATH = std::string("../source/order.txt");
Data data;
void App::init( ) {
    // preInit all basic data
    data.init();
}

void App::run( ) {
    bool running = true;
    while ( running ) {
        Menu * curMenu = MenuMgr::getInstance( ).currentMenu( ); //取当前活动菜单
        running = curMenu->process( ); //处理菜单
    }
}

void App::term( ) {
}