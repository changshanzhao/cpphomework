//
// Created by Lenovo on 2023/8/28.
//
#include "../include/MenuFactory.h"
#include "../include/Menu.h"

/*
MAIN_MENU = 0,
VENDOR_MENU,	//供应商管理菜单
PRODUCT_MENU,	//供应商商品菜单
PURCHASE_MENU,	//采购项菜单
INQUIRY_MENU,	//询价菜单
ORDER_MENU,		//订单菜单
EXPORT_MENU		//导出菜单
*/

Menu * MyMenuFactory::createMenu( MenuType menuType ) {
    if ( menuType == MenuType::MAIN_MENU )
        return new MainMenu( );
    else if ( menuType == MenuType::VENDOR_MENU )
        return new VendorMenu( );
    else if ( menuType == MenuType::PRODUCT_MENU )
        return new ProductMenu( );
    else if ( menuType == MenuType::PURCHASE_MENU )
        return new PurchaseMenu( );
    else if ( menuType == MenuType::INQUIRY_MENU )
        return new InquiryMenu( );
    else if ( menuType == MenuType::ORDER_MENU )
        return new OrderMenu( );
    else if ( menuType == MenuType::EXPORT_MENU )
        return new ExportMenu( );

    return nullptr;
}