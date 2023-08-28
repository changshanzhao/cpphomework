//
// Created by Lenovo on 2023/8/28.
//

// App.cpp
#include "App.h"
#include "Menu.h"
#include "MenuMgr.h"

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
}