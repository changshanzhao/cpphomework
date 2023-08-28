//
// Created by Lenovo on 2023/8/28.
//

// App.cpp
#include "../include/App.h"
#include "../include/Menu.h"
#include "../include/MenuMgr.h"
#include "../include/inquiry.h"
#include "../include/product.h"
#include "../include/purchase.h"
#include "../include/vendor.h"
#include "../include/order.h"
void App::init( ) {

}

void App::run( ) {
    bool running = true;
    while ( running ) {
        Menu * curMenu = MenuMgr::getInstance( ).currentMenu( ); //取当前活动菜单
        running = curMenu->process( ); //处理菜单
    }
}

void App::term( ) {

<<<<<<< HEAD
    
=======
>>>>>>> 1d87cde215c303d363a9c960c341e4e647301d29
}