//
// Created by Lenovo on 2023/8/28.
//

#ifndef HOMEWORK_MENUTYPE_H
#define HOMEWORK_MENUTYPE_H

enum class MenuType {
    MAIN_MENU = 0,
    VENDOR_MENU,	//供应商管理菜单
    PRODUCT_MENU,	//供应商商品菜单
    PURCHASE_MENU,	//采购项菜单
    INQUIRY_MENU,	//询价菜单
    ORDER_MENU,		//订单菜单
    EXPORT_MENU		//导出菜单
};
const int MenuTypeCount = ( int ) MenuType::EXPORT_MENU + 1;

#endif //HOMEWORK_MENUTYPE_H
