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
	cout << "\n\t	���˵�\n\n";	
	cout << "\t	1. ��Ӧ�̹���\n";
	cout << "\t	2. ��Ӧ�̲�Ʒ����\n";
	cout << "\t	3. �ɹ������\n";
	cout << "\t	4. ѯ�۹���\n";
	cout << "\t	5. ��������\n";
	cout << "\t	6. ��Ϣ����\n";
	cout << "\t	0. �˳�\n\n";

	cout << "\t ��ѡ��0-6����";
}

bool MainMenu::doChoice( int choice ) {
	switch ( choice ) {
    case 0:
        cout<<"\n\t��ӭ�´���ʹ��!\n"<<endl;
        system("pause");
        return false;  //�˳���ֹ
	case 1:
		//ת����Ӧ�̹���˵�
		MenuMgr::getInstance( ).setCurrentMenu( MenuType::VENDOR_MENU );
		break;
	case 2:
		//ת����Ӧ����Ʒ�˵�
		MenuMgr::getInstance( ).setCurrentMenu( MenuType::PRODUCT_MENU );
		break;
	case 3:
		//ת���ɹ���˵�
		MenuMgr::getInstance( ).setCurrentMenu( MenuType::PURCHASE_MENU );
		break;
	case 4:
		//ת��ѯ�۲˵�
		MenuMgr::getInstance( ).setCurrentMenu( MenuType::INQUIRY_MENU );
		break;
	case 5:
		//ת�������˵�
		MenuMgr::getInstance( ).setCurrentMenu( MenuType::ORDER_MENU );
		break;
	case 6:
		//ת�������˵�
		MenuMgr::getInstance( ).setCurrentMenu( MenuType::EXPORT_MENU );
		break;
    default:
        system("cls");
	}
	return true;
}




//��Ӧ�̹���
void VendorMenu::display( ) const {
	cout << "\n\t	��Ӧ�̹���\n\n";
	cout << "\t	1. ��Ӧ���б�\n";
	cout << "\t	2. ����Ӧ�����Ʋ�ѯ\n";
	cout << "\t	3. ��ӹ�Ӧ��\n";
	cout << "\t	0. ������һ��\n\n";

	cout << "\t ��ѡ��0-3����";
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
        std::cout << "���빩Ӧ������:> ";
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
        MSG("�����빩Ӧ����Ϣ��һ��һ��Ϣ��Ŀ:> ");
        std::vector<string> listInfo;
        for(int i = 0; i < vendorPropertyCount; i++)
        {
            string sig;
            std::cin >> sig;
            if(sig.empty()){
                i--;
                MSG("��Ϣ�Ƿ���:>");
                MSG(sig);
            }

            listInfo.push_back(sig);
        }
        MSG("����¼�룡");
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
		//������һ��
		MenuMgr::getInstance( ).setCurrentMenu( MenuType::MAIN_MENU );
    default:
        system("cls");
	}
	return true;
}


//��Ӧ�̲�Ʒ����
void ProductMenu::display( ) const {
	cout << "\n\t	��Ӧ����Ʒ����\n\n";
	cout << "\t	1. ����Ӧ�̲�ѯ��Ʒ�б�\n";
	cout << "\t	2. ����Ʒ���Ʋ�ѯ��Ӧ���б�\n";
	cout << "\t	3. ��ӹ�Ӧ����Ʒ\n";
	cout << "\t	0. ������һ��\n\n";

	cout << "\t ��ѡ��0-3����";
}


bool ProductMenu::doChoice( int choice ) {
	switch ( choice ) {
	case 1: {
        int findTarget = 0;
        std::string vendorName;
        MSG("���빩Ӧ������:> ");
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
        MSG("������Ʒ����:> ");
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
        MSG("��������Ʒ��Ϣ��һ��һ��Ϣ��Ŀ:> ");
        std::vector<string> listInfo;
        for(int i = 0; i < productPropertyCount; i++)
        {
            string sig;
            std::cin >> sig;
            if(sig.empty()){
                i--;
                MSG("��Ϣ�Ƿ���:>");
                MSG(sig);
            }
            listInfo.push_back(sig);
        }
        MSG("����¼�룡");
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
		//������һ��
		MenuMgr::getInstance( ).setCurrentMenu( MenuType::MAIN_MENU );
    default:
        system("cls");
	}
	return true;
}

//�ɹ������
void PurchaseMenu::display( ) const {
	cout << "\n\t	�ɹ������\n\n";
	cout << "\t	1. �ɹ����б�\n";
	cout << "\t	2. �����ɹ���\n";
	cout << "\t	0. ������һ��\n\n";
	cout << "\t ��ѡ��0-2����";
}

bool PurchaseMenu::doChoice( int choice ) {
	switch ( choice ) {
	case 1:
        data.showAppPurchase();
		break;
	case 2:
    {
        MSG("������ɹ���Ϣ��һ��һ��Ϣ��Ŀ:> ");
        std::vector<string> listInfo;
        for(int i = 0; i < purchasePropertyCount; i++)
        {
            string sig;
            std::cin >> sig;
            if(sig.empty()){
                i--;
                MSG("��Ϣ�Ƿ���:>");
                MSG(sig);
            }
            listInfo.push_back(sig);
        }
        MSG("����¼�룡");
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
		//������һ��
		MenuMgr::getInstance( ).setCurrentMenu( MenuType::MAIN_MENU );
    default:
        system("cls");
	}
	return true;
}

//ѯ�۹���
void InquiryMenu::display( ) const {
	cout << "\n\t	ѯ�۹���\n\n";
	cout << "\t	1. ������ɸѡ��Ӧ��\n";
	cout << "\t	2. ����Ʒ��ɸѡ��Ӧ��\n";
	cout << "\t	3. ����ѯ��\n";
	cout << "\t	4. ѯ�۱Ƚ�\n";
    cout << "\t	5. �����Ƽ���Ӧ��\n";
	cout << "\t	0. ������һ��\n\n";

	cout << "\t ��ѡ��0-5����";
}

bool InquiryMenu::doChoice( int choice ) {
	switch ( choice ) {
	case 1:
    {
        int findTarget = 0;
        std::string VendorName;
        MSG("��������:> ");
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
        MSG("������Ʒ����:> ");
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
        MSG("������ѯ����Ϣ��һ��һ��Ϣ��Ŀ:> ");
        std::vector<string> listInfo;
        for(int i = 0; i < inquiryPropertyCount; i++)
        {
            string sig;
            std::cin >> sig;
            if(sig.empty()){
                i--;
                MSG("��Ϣ�Ƿ���:>");
                MSG(sig);
            }
            listInfo.push_back(sig);
        }
        MSG("����¼�룡");
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
        MSG("����ID:> ");
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
        MSG("����ID:> ");
        std::cin >> ID;
        MSG(Inquiry::best_choice(ID));

    }
        break;
	case 0:
		//������һ��
		MenuMgr::getInstance( ).setCurrentMenu( MenuType::MAIN_MENU );
    default:
        system("cls");
	}
	return true;
}

//��������
void OrderMenu::display( ) const {
	cout << "\n\t	��������\n\n";
	cout << "\t	1. ��������\n";
	cout << "\t	2. ��ѯ����\n";
	cout << "\t	3. ���ٶ���\n";
	cout << "\t	0. ������һ��\n\n";

	cout << "\t ��ѡ��0-3����";
}

bool OrderMenu::doChoice( int choice ) {
	switch ( choice ) {
	case 1:
    {
        MSG("�����붩����Ϣ��һ��һ��Ϣ��Ŀ:> ");
        std::vector<string> listInfo;
        for(int i = 0; i < orderPropertyCount; i++)
        {
            string sig;
            std::cin >> sig;
            if(sig.empty()){
                i--;
                MSG("��Ϣ�Ƿ���:>");
                MSG(sig);
            }
            listInfo.push_back(sig);
        }
        MSG("����¼�룡");
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
        MSG("����ID:> ");
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
        MSG("����ID:> ");
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
		//������һ��
		MenuMgr::getInstance( ).setCurrentMenu( MenuType::MAIN_MENU );
    default:
        system("cls");
	}
	return true;
}

//��Ϣ����
void ExportMenu::display( ) const {
	cout << "\n\t	��Ϣ����\n\n";
	cout << "\t	1. ��Ӧ���б�\n";
	cout << "\t	2. ��Ʒ�б�\n";
	cout << "\t	3. �ɼ����б�\n";
    cout << "\t	4. ѯ���б�\n";
    cout << "\t	5. �����б�\n";
	cout << "\t	0. ������һ��\n\n";

	cout << "\t ��ѡ��0-3����";
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
		//������һ��
		MenuMgr::getInstance( ).setCurrentMenu( MenuType::MAIN_MENU );
    default:
        system("cls");
	}
	return true;
}
