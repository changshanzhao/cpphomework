//
// Created by Lenovo on 2023/8/28.
//
#include "../include/MenuFactory.h"
#include "../include/Menu.h"

/*
MAIN_MENU = 0,
VENDOR_MENU,	//��Ӧ�̹���˵�
PRODUCT_MENU,	//��Ӧ����Ʒ�˵�
PURCHASE_MENU,	//�ɹ���˵�
INQUIRY_MENU,	//ѯ�۲˵�
ORDER_MENU,		//�����˵�
EXPORT_MENU		//�����˵�
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