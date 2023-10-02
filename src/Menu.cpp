// Menu.cpp
#include <iostream>
using namespace std;
#include "../include/Menu.h"
#include "../include/MenuMgr.h"

int Menu::selectMenuItem( ) {
	int choice = 0;
    std::fflush(stdin);
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
    // system( "cls" );
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
        cout<<"\n\t欢迎下次再使用!\n"<<endl;
        system("pause");
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
    default:
        system("cls");
	}
	return true;
}




//供应商管理
void VendorMenu::display( ) const {
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
		data.showAppVendor();
		break;
	case 2:
    {
        int findTol = 0;
        string checkedName;
        std::cout << "输入供应商名称:> ";
        std::cin >> checkedName;
        std::cout << "---------checked-----------" << std::endl;
        for (Vendor vendor: data.appVendor) {
            if (vendor.compareName(checkedName)) {
                vendor.showVendorInfo();
                findTol++;
            }
        }
        if(findTol == 0){
            MSG("Can not find any targeted!");
        }
        std::cout << "---------finished!-----------" << std::endl;
        break;
    }
	case 3:
    {
        MSG("请输入供应商信息，一行一信息项目:> ");
        std::vector<string> listInfo;
        for(int i = 0; i < vendorPropertyCount; i++)
        {
            string sig;
            std::cin >> sig;
            if(sig.empty()){
                i--;
                MSG("信息非法！:>");
                MSG(sig);
            }

            listInfo.push_back(sig);
        }
        MSG("结束录入！");
        // fflusher in ALL Compilers
        char c;
        while ((c = getchar()) != '\n');
        data.appVendor.push_back(Vendor(
                listInfo[static_cast<int>(VendorArrayOffset::NAME)],
                listInfo[static_cast<int>(VendorArrayOffset::ADDR)],
                listInfo[static_cast<int>(VendorArrayOffset::TYPE)],
                listInfo[static_cast<int>(VendorArrayOffset::PEO)],
                listInfo[static_cast<int>(VendorArrayOffset::PEO_PHONE)],
                listInfo[static_cast<int>(VendorArrayOffset::POS)],
                listInfo[static_cast<int>(VendorArrayOffset::LEVEL)]
                ));
        data.showAppVendor();
    }break;
	case 0:
		//返回上一级
		MenuMgr::getInstance( ).setCurrentMenu( MenuType::MAIN_MENU );
    default:
        system("cls");
	}
	return true;
}


//供应商产品管理
void ProductMenu::display( ) const {
	cout << "\n\t	供应商商品管理\n\n";
	cout << "\t	1. 按供应商查询商品列表\n";
	cout << "\t	2. 按商品名称查询供应商列表\n";
	cout << "\t	3. 添加供应商商品\n";
	cout << "\t	0. 返回上一级\n\n";

	cout << "\t 请选择（0-3）：";
}


bool ProductMenu::doChoice( int choice ) {
	switch ( choice ) {
	case 1: {
        int findTarget = 0;
        std::string vendorName;
        MSG("输入供应商名称:> ");
        std::cin >>vendorName;
        MSG("---------------------------checked----------------------------");
        for(Product tmp : data.appProduct)
        {
            if(tmp.compareVName(vendorName)){
                tmp.showProductInfo();
                findTarget++;
            }
        }
        if(findTarget == 0){
            MSG("Do not find any target");
        }
        MSG("---------------------------finished----------------------------");
    }
		break;
	case 2:
    {
        int findTarget = 0;
        std::string productName;
        MSG("输入商品名称:> ");
        std::cin >>productName;
        MSG("---------------------------checked----------------------------");
        for(Product tmp : data.appProduct)
        {
            if(tmp.comparePName(productName)){
                tmp.showProductInfo();
                findTarget++;
            }
        }
        if(findTarget == 0){
            MSG("Do not find any target");
        }
        MSG("---------------------------finished----------------------------");
    }
		break;
	case 3:
    {
        MSG("请输入商品信息，一行一信息项目:> ");
        std::vector<string> listInfo;
        for(int i = 0; i < productPropertyCount; i++)
        {
            string sig;
            std::cin >> sig;
            if(sig.empty()){
                i--;
                MSG("信息非法！:>");
                MSG(sig);
            }
            listInfo.push_back(sig);
        }
        MSG("结束录入！");
        getchar();
        data.appProduct.push_back
        (
                Product
                (
                        listInfo[static_cast<int>(ProductArrayOffSet::V_NAME)],
                        listInfo[static_cast<int>(ProductArrayOffSet::P_NAME)],
                        listInfo[static_cast<int>(ProductArrayOffSet::TYPE)],
                        listInfo[static_cast<int>(ProductArrayOffSet::INFO)]
                )
        );
    }
    break;
	case 0:
		//返回上一级
		MenuMgr::getInstance( ).setCurrentMenu( MenuType::MAIN_MENU );
    default:
        system("cls");
	}
	return true;
}

//采购项管理
void PurchaseMenu::display( ) const {
	cout << "\n\t	采购项管理\n\n";
	cout << "\t	1. 采购项列表\n";
	cout << "\t	2. 新增采购项\n";
	cout << "\t	0. 返回上一级\n\n";
	cout << "\t 请选择（0-2）：";
}

bool PurchaseMenu::doChoice( int choice ) {
	switch ( choice ) {
	case 1:
        data.showAppPurchase();
		break;
	case 2:
    {
        MSG("请输入采购信息，一行一信息项目:> ");
        std::vector<string> listInfo;
        for(int i = 0; i < purchasePropertyCount; i++)
        {
            string sig;
            std::cin >> sig;
            if(sig.empty()){
                i--;
                MSG("信息非法！:>");
                MSG(sig);
            }
            listInfo.push_back(sig);
        }
        MSG("结束录入！");
        getchar();
        data.appPurchase.push_back(
             Purchase
             (
                     listInfo[static_cast<int>(PurchaseArrayOffSet::ID)],
                     listInfo[static_cast<int>(PurchaseArrayOffSet::NAME)],
                     listInfo[static_cast<int>(PurchaseArrayOffSet::NUM)],
                     listInfo[static_cast<int>(PurchaseArrayOffSet::TYPE)],
                     listInfo[static_cast<int>(PurchaseArrayOffSet::REQUEST)]

             )
        );
    }break;
	case 0:
		//返回上一级
		MenuMgr::getInstance( ).setCurrentMenu( MenuType::MAIN_MENU );
    default:
        system("cls");
	}
	return true;
}

//询价管理
void InquiryMenu::display( ) const {
	cout << "\n\t	询价管理\n\n";
	cout << "\t	1. 按名称筛选供应商\n";
	cout << "\t	2. 按商品名筛选供应商\n";
	cout << "\t	3. 新增询价\n";
	cout << "\t	4. 询价比较\n";
    cout << "\t	5. 智能推荐供应商\n";
	cout << "\t	0. 返回上一级\n\n";

	cout << "\t 请选择（0-5）：";
}

bool InquiryMenu::doChoice( int choice ) {
	switch ( choice ) {
	case 1:
    {
        int findTarget = 0;
        std::string VendorName;
        MSG("输入名称:> ");
        std::cin >> VendorName;
        MSG("---------------------------checked----------------------------");
        for(Inquiry tmp : data.appInquiry)
        {
            if(tmp.compareVName(VendorName)){
                tmp.showInquiryInfo();
                findTarget++;
            }
        }
        if(findTarget == 0){
            MSG("Do not find any target");
        }
        MSG("---------------------------finished----------------------------");
    }
		break;
	case 2:
    {
        int findTarget = 0;
        std::string productName;
        MSG("输入商品名称:> ");
        std::cin >>productName;
        MSG("---------------------------checked----------------------------");
        for(Inquiry tmp : data.appInquiry)
        {
            if(tmp.compareProductName(productName)){
                tmp.showInquiryInfo();
                findTarget++;
            }
        }
        if(findTarget == 0){
            MSG("Do not find any target");
        }
        MSG("---------------------------finished----------------------------");
    }
		break;
	case 3:
    {
        MSG("请输入询价信息，一行一信息项目:> ");
        std::vector<string> listInfo;
        for(int i = 0; i < inquiryPropertyCount; i++)
        {
            string sig;
            std::cin >> sig;
            if(sig.empty()){
                i--;
                MSG("信息非法！:>");
                MSG(sig);
            }
            listInfo.push_back(sig);
        }
        MSG("结束录入！");
        getchar();
        data.appInquiry.push_back(
                Inquiry(
                        listInfo[static_cast<int>(InquiryArrayOffSet::ID)],
                        listInfo[static_cast<int>(InquiryArrayOffSet::V_NAME)],
                        listInfo[static_cast<int>(InquiryArrayOffSet::PRODUCT)],
                        listInfo[static_cast<int>(InquiryArrayOffSet::TYPE)],
                        listInfo[static_cast<int>(InquiryArrayOffSet::INFO)],
                        listInfo[static_cast<int>(InquiryArrayOffSet::MONEY)],
                        listInfo[static_cast<int>(InquiryArrayOffSet::M_INFO)],
                        listInfo[static_cast<int>(InquiryArrayOffSet::EVALUATE)],
                        listInfo[static_cast<int>(InquiryArrayOffSet::LEVEL)]
                        )
        );
    }
		break;
	case 4:
    {
        int findTarget = 0;
        std::string ID;
        MSG("输入ID:> ");
        std::cin >> ID;
        MSG("---------------------------checked----------------------------");
        for(Inquiry tmp : data.appInquiry)
        {
            if(tmp.compareID(ID)){
                tmp.showInquiryInfo();
                findTarget++;
            }
        }
        if(findTarget == 0){
            MSG("Do not find any target");
        }
        MSG("---------------------------finished----------------------------");
    }
		break;
    case 5:
    {
        std::string ID;
        MSG("输入ID:> ");
        std::cin >> ID;
        MSG(Inquiry::best_choice(ID));

    }
        break;
	case 0:
		//返回上一级
		MenuMgr::getInstance( ).setCurrentMenu( MenuType::MAIN_MENU );
    default:
        system("cls");
	}
	return true;
}

//订单管理
void OrderMenu::display( ) const {
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
    {
        MSG("请输入订单信息，一行一信息项目:> ");
        std::vector<string> listInfo;
        for(int i = 0; i < orderPropertyCount; i++)
        {
            string sig;
            std::cin >> sig;
            if(sig.empty()){
                i--;
                MSG("信息非法！:>");
                MSG(sig);
            }
            listInfo.push_back(sig);
        }
        MSG("结束录入！");
        getchar();
        data.appOrder.push_back(
            Order(
              listInfo[static_cast<int>(OrderArrayOffSet::ID)],
              listInfo[static_cast<int>(OrderArrayOffSet::V_NAME)],
              listInfo[static_cast<int>(OrderArrayOffSet::PRODUCT)],
              listInfo[static_cast<int>(OrderArrayOffSet::TYPE)],
              listInfo[static_cast<int>(OrderArrayOffSet::MONEY)],
              listInfo[static_cast<int>(OrderArrayOffSet::UNIT)],
              listInfo[static_cast<int>(OrderArrayOffSet::NUM)],
              listInfo[static_cast<int>(OrderArrayOffSet::TOTAL_MONEY)],
              listInfo[static_cast<int>(OrderArrayOffSet::REQUEST)]
            )
        );
    }
		break;
	case 2:
    {
        int findTarget = 0;
        std::string ID;
        MSG("输入ID:> ");
        std::cin >> ID;
        MSG("---------------------------checked----------------------------");
        for(Order tmp : data.appOrder)
        {
            if(tmp.compareID(ID)){
                tmp.showOrderQuery();
                findTarget++;
            }
        }
        if(findTarget == 0){
            MSG("Do not find any target");
        }
        MSG("---------------------------finished----------------------------");
    }
		break;
	case 3:
    {
        int findTarget = 0;
        std::string ID;
        MSG("输入ID:> ");
        std::cin >> ID;
        MSG("---------------------------checked----------------------------");
        for(Order tmp : data.appOrder)
        {
            if(tmp.compareID(ID)){
                tmp.showOrderInfo();
                findTarget++;
            }
        }
        if(findTarget == 0){
            MSG("Do not find any target");
        }
        MSG("---------------------------finished----------------------------");
    }
		break;
	case 0:
		//返回上一级
		MenuMgr::getInstance( ).setCurrentMenu( MenuType::MAIN_MENU );
    default:
        system("cls");
	}
	return true;
}

//信息导出
void ExportMenu::display( ) const {
	cout << "\n\t	信息导出\n\n";
	cout << "\t	1. 供应商列表\n";
	cout << "\t	2. 商品列表\n";
	cout << "\t	3. 采集单列表\n";
    cout << "\t	4. 询价列表\n";
    cout << "\t	5. 订单列表\n";
	cout << "\t	0. 返回上一级\n\n";

	cout << "\t 请选择（0-3）：";
}

bool ExportMenu::doChoice( int choice ) {
	switch ( choice ) {
	case 1:
		data.exportLists(DataSectionOffSet::VENDOR);
		break;
	case 2:
        data.exportLists(DataSectionOffSet::PRODUCT);
		break;
	case 3:
        data.exportLists(DataSectionOffSet::PURCHASE);
		break;
    case 4:
            data.exportLists(DataSectionOffSet::INQUIRY);
            break;
    case 5:
            data.exportLists(DataSectionOffSet::ORDER);
            break;
	case 0:
		//返回上一级
		MenuMgr::getInstance( ).setCurrentMenu( MenuType::MAIN_MENU );
    default:
        system("cls");
	}
	return true;
}
