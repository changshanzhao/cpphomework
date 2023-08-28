//
// Created by Lenovo on 2023/8/28.
//

#include "Menu.h"
#include "MenuMgr.h"
#include "MenuType.h"
#include "MenuFactory.h"

// 单例
MenuMgr& MenuMgr::getInstance( ) {
    static std::shared_ptr<MenuMgr>  mgr( new MenuMgr() );
    return *mgr;
}

// 构造函数
MenuMgr::MenuMgr( ) {
    std::shared_ptr<MenuFactory> fac = std::make_shared<MyMenuFactory>( );
    for ( int menuID = 0; menuID < MenuTypeCount; menuID++ )
        mVctMenus.push_back( fac->createMenu( MenuType(menuID) ));

    mCurrentMenu = mVctMenus[ 0 ]; //初始为主菜单
}

// 析构时，释放全部Menu
MenuMgr::~MenuMgr( ) {
    for ( Menu * pMenu : mVctMenus )
        delete pMenu;
}
