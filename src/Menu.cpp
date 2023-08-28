// Menu.cpp
#include <iostream>
using namespace std;
#include "../include/Menu.h"
#include "../include/MenuMgr.h"
#include "../include/MenuType.h"
#include "../include/FileExample.h"
int Menu::selectMenuItem( ) {
	int choice = 0;
	cin >> choice;
	return choice;
}

bool Menu::process()
{
    display( );
    int choice = selectMenuItem( );
    return doChoice( choice );
}



void MainMenu::display( ) const {
	system( "clear" );
	cout << "\n\t	主菜单\n\n";	
	cout << "\t	1. 供应商管理\n";
	cout << "\t	2. 供应商产品管理\n";
	cout << "\t	3. 采购项管理\n";
	cout << "\t	4. 询价管理\n";
	cout << "\t	5. 订单管理\n";
	cout << "\t	6. 信息导出\n";
	cout << "\t	0. 退出\n\n";

	cout << "\t 请选择（0-6）：";
}

bool MainMenu::doChoice( int choice ) {
	switch ( choice ) {
	case 0:
		return false;  //退出终止
	case 1:
		//转到供应商管理菜单
		MenuMgr::getInstance( ).setCurrentMenu( MenuType::VENDOR_MENU );
		break;
	case 2:
		//转到供应商商品菜单
		MenuMgr::getInstance( ).setCurrentMenu( MenuType::PRODUCT_MENU );
		break;
	case 3:
		//转到采购项菜单
		MenuMgr::getInstance( ).setCurrentMenu( MenuType::PURCHASE_MENU );
		break;
	case 4:
		//转到询价菜单
		MenuMgr::getInstance( ).setCurrentMenu( MenuType::INQUIRY_MENU );
		break;
	case 5:
		//转到订单菜单
		MenuMgr::getInstance( ).setCurrentMenu( MenuType::ORDER_MENU );
		break;
	case 6:
		//转到导出菜单
		MenuMgr::getInstance( ).setCurrentMenu( MenuType::EXPORT_MENU );
		break;
	}
	return true;
}




//供应商管理
void VendorMenu::display( ) const {
	system( "clear" );
	cout << "\n\t	供应商管理\n\n";
	cout << "\t	1. 供应商列表\n";
	cout << "\t	2. 按供应商名称查询\n";
	cout << "\t	3. 添加供应商\n";
	cout << "\t	0. 返回上一级\n\n";

	cout << "\t 请选择（0-3）：";
}

bool VendorMenu::doChoice( int choice ) {
	switch ( choice ) {	
	case 1:
		// 待实现
		break;
	case 2:
		// 待实现
		break;
	case 3:
		// 待实现
		break;
	default:
		//返回上一级
		MenuMgr::getInstance( ).setCurrentMenu( MenuType::MAIN_MENU );
	}
	return true;
}


//供应商产品管理
void ProductMenu::display( ) const {
	system( "clear" );
	cout << "\n\t	供应商商品管理\n\n";
	cout << "\t	1. 按供应商查询商品列表\n";
	cout << "\t	2. 按商品名称查询供应商列表\n";
	cout << "\t	3. 添加供应商商品\n";
	cout << "\t	0. 返回上一级\n\n";

	cout << "\t 请选择（0-3）：";
}


bool ProductMenu::doChoice( int choice ) {
	switch ( choice ) {
	case 1:
		// 待实现
		break;
	case 2:
		// 待实现
		break;
	case 3:
		// 待实现
		break;
	default:
		//返回上一级
		MenuMgr::getInstance( ).setCurrentMenu( MenuType::MAIN_MENU );
	}
	return true;
}

//采购项管理
void PurchaseMenu::display( ) const {
	system( "clear" );
	cout << "\n\t	采购项管理\n\n";
	cout << "\t	1. 采购项列表\n";
	cout << "\t	2. 新增采购项\n";
	cout << "\t	0. 返回上一级\n\n";

	cout << "\t 请选择（0-2）：";
}

bool PurchaseMenu::doChoice( int choice ) {
	switch ( choice ) {
	case 1:
		// 待实现
		break;
	case 2:
		// 待实现
		break;
	case 3:
		// 待实现
		break;
	case 0:
		//返回上一级
		MenuMgr::getInstance( ).setCurrentMenu( MenuType::MAIN_MENU );
	}
	return true;
}

//询价管理
void InquiryMenu::display( ) const {
	system( "clear" );
	cout << "\n\t	询价管理\n\n";
	cout << "\t	1. 按名称筛选供应商\n";
	cout << "\t	2. 按商品名筛选供应商\n";
	cout << "\t	3. 新增询价\n";
	cout << "\t	4. 询价比较\n";
	cout << "\t	0. 返回上一级\n\n";

	cout << "\t 请选择（0-4）：";
}

bool InquiryMenu::doChoice( int choice ) {
	switch ( choice ) {
	case 1:
		// 待实现
		break;
	case 2:
		// 待实现
		break;
	case 3:
		// 待实现
		break;
	case 4:
		// 待实现
		break;
	default:
		//返回上一级
		MenuMgr::getInstance( ).setCurrentMenu( MenuType::MAIN_MENU );
	}
	return true;
}

//订单管理
void OrderMenu::display( ) const {
	system( "clear" );
	cout << "\n\t	订单管理\n\n";
	cout << "\t	1. 新增订单\n";
	cout << "\t	2. 查询订单\n";
	cout << "\t	3. 跟踪订单\n";
	cout << "\t	0. 返回上一级\n\n";

	cout << "\t 请选择（0-3）：";
}

bool OrderMenu::doChoice( int choice ) {
	switch ( choice ) {
	case 1:
		// 待实现
		break;
	case 2:
		// 待实现
		break;
	case 3:
		// 待实现
		break;
	case 4:
		// 待实现
		break;
	default:
		//返回上一级
		MenuMgr::getInstance( ).setCurrentMenu( MenuType::MAIN_MENU );
	}
	return true;
}

//信息导出
void ExportMenu::display( ) const {
	system( "clear" );
	cout << "\n\t	信息导出\n\n";
	cout << "\t	1. XXX\n";
	cout << "\t	2. YYY\n";
	cout << "\t	3. ZZZ\n";
	cout << "\t	0. 返回上一级\n\n";

	cout << "\t 请选择（0-3）：";
}

bool ExportMenu::doChoice( int choice ) {
	switch ( choice ) {
	case 1:
		// 待实现
		break;
	case 2:
		// 待实现
		break;
	case 3:
		// 待实现
		break;
	default:
		//返回上一级
		MenuMgr::getInstance( ).setCurrentMenu( MenuType::MAIN_MENU );
	}
	return true;
}
