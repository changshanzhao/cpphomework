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

bool Menu::exported = false;// ��¼�Ƿ�ִ�й���������

//�˳�����ȷ��
void Menu::confirmExit() {
    cout << "\n\t��ǰδ�������Ƿ񵼳����ģ���Y/N��: ";
    char choice;
    cin >> choice;
    if (choice == 'Y' || choice == 'y') {
        data.exportLists(DataSectionOffSet::VENDOR);
        data.exportLists(DataSectionOffSet::PRODUCT);
        data.exportLists(DataSectionOffSet::PURCHASE);
        data.exportLists(DataSectionOffSet::INQUIRY);
        data.exportLists(DataSectionOffSet::ORDER);
        cout << "\n\t�ѱ�����ġ�" << endl;
    } else {
        cout << "\n\tδ������ġ�" << endl;
    }
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



bool MainMenu::doChoice(int choice) {
    switch (choice) {
    case 0:
        if(!exported)confirmExit();
        cout << "\n\t��ӭ�´���ʹ��!\n" << endl;
        system("pause");
        return false;  // �˳���ֹ
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
    cout << "\t	4. ����Ӧ������ɾ��\n";
	cout << "\t	0. ������һ��\n\n";

	cout << "\t ��ѡ��0-4����";
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
        std::vector<string> listInfo;
        for(int i = 0; i < vendorPropertyCount; i++)
        {
            string prompt;
            switch(i)
            {
                case static_cast<int>(VendorArrayOffset::NAME):
                    prompt = "�����빩Ӧ������: ";
                    break;
                case static_cast<int>(VendorArrayOffset::ADDR):
                    prompt = "�������ַ: ";
                    break;
                case static_cast<int>(VendorArrayOffset::TYPE):
                    prompt = "��������ҵ����: ";
                    break;
                case static_cast<int>(VendorArrayOffset::PEO):
                    prompt = "��������ϵ��: ";
                    break;
                case static_cast<int>(VendorArrayOffset::PEO_PHONE):
                    prompt = "��������ϵ�˵绰: ";
                    break;
                case static_cast<int>(VendorArrayOffset::POS):
                    prompt = "��������ϵ��ְ��: ";
                    break;
                case static_cast<int>(VendorArrayOffset::LEVEL):
                    prompt = "�����빩Ӧ�������Ǽ�: ";
                    break;
                default:
                    //Ԥ��
                    break;
            }
            MSG(prompt);//������ʾ
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
    case 4:
    {
        string checkedName;
        std::cout << "����Ҫɾ���Ĺ�Ӧ������:> ";
        std::cin >> checkedName;

        auto it = data.appVendor.begin();// ������
        bool  found = false;// ����Ƿ��ҵ�

        while (it != data.appVendor.end()) {
            if (it->compareName(checkedName)) {
                it = data.appVendor.erase(it);
                std::cout << "��ɾ����Ӧ�̣�" << std::endl;
                found = true;
            } else {
                ++it;
            }
        }

        if (!found) {
            std::cout << "�Ҳ���Ҫɾ���Ĺ�Ӧ�̣�" << std::endl;
        }
        break;
    }
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
    cout << "\t	4. ����Ʒ����ɾ����Ӧ����Ʒ\n";
    cout << "\t	5. ����Ӧ������ɾ����Ӧ����Ʒ\n";
	cout << "\t	0. ������һ��\n\n";

	cout << "\t ��ѡ��0-5����";
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
        std::vector<string> listInfo;
        for(int i = 0; i < productPropertyCount; i++)
        {
            string prompt;
            switch(i)
            {
                case static_cast<int>(ProductArrayOffSet::V_NAME):
                    prompt = "�����빩Ӧ������: ";
                    break;
                case static_cast<int>(ProductArrayOffSet::P_NAME):
                    prompt = "�������Ʒ����: ";
                    break;
                case static_cast<int>(ProductArrayOffSet::TYPE):
                    prompt = "���������ͺ�: ";
                    break;
                case static_cast<int>(ProductArrayOffSet::INFO):
                    prompt = "�������Ʒ˵��: ";
                    break;
                default:
                    //Ԥ��
                    break;
            }

            MSG(prompt);//������ʾ
            
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
    case 4:
    {
        string checkedName;
        std::cout << "����Ҫɾ������Ʒ����:> ";
        std::cin >> checkedName;

        auto it = data.appProduct.begin();// ������
        bool found = false;// ����Ƿ��ҵ�

        while (it != data.appProduct.end()) {
            if (it->comparePName(checkedName)) {
                it = data.appProduct.erase(it);
                std::cout << "��ɾ����Ʒ��" << std::endl;
                found = true;
            } else {
                ++it;
            }
        }

        if (!found) {
            std::cout << "�Ҳ���Ҫɾ������Ʒ��" << std::endl;
        }
        break;
    }
    case 5:
    {
        string checkedName;
        std::cout << "����Ҫɾ���Ĺ�Ӧ������:> ";
        std::cin >> checkedName;

        auto it = data.appProduct.begin();// ������
        bool found = false;// ����Ƿ��ҵ�

        while (it != data.appProduct.end()) {
            if (it->compareVName(checkedName)) {
                it = data.appProduct.erase(it);
                std::cout << "��ɾ����Ӧ����Ʒ��" << std::endl;
                found = true;
            } else {
                ++it;
            }
        }

        if (!found) {
            std::cout << "�Ҳ���Ҫɾ���Ĺ�Ӧ����Ʒ��" << std::endl;
        }
        break;
    }
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
    cout << "\t	3. ���ɹ�������ɾ��\n";
	cout << "\t	0. ������һ��\n\n";
	cout << "\t ��ѡ��0-3����";
}

bool PurchaseMenu::doChoice( int choice ) {
	switch ( choice ) {
	case 1:
        data.showAppPurchase();
		break;
	case 2:
    {
        std::vector<string> listInfo;
        for(int i = 0; i < purchasePropertyCount; i++)
        {
            string prompt;
            switch(i)
            {
                case static_cast<int>(PurchaseArrayOffSet::ID):
                    prompt = "������ɹ��ڲ����: ";
                    break;
                case static_cast<int>(PurchaseArrayOffSet::NAME):
                    prompt = "������ɹ����ڲ���: ";
                    break;
                case static_cast<int>(PurchaseArrayOffSet::NUM):
                    prompt = "����������: ";
                    break;
                case static_cast<int>(PurchaseArrayOffSet::TYPE):
                    prompt = "���������ͺ�: ";
                    break;
                case static_cast<int>(PurchaseArrayOffSet::REQUEST):
                    prompt = "������ɹ�Ҫ��: ";
                    break;
                default:
                    //Ԥ��
                    break;
            }
            MSG(prompt);//������ʾ

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
    case 3:
    {
        string checkedName;
        std::cout << "����Ҫɾ���Ĳɹ�������:> ";
        std::cin >> checkedName;

        auto it = data.appPurchase.begin();// ������
        bool found = false;// �Ƿ��ҵ�

        while (it != data.appPurchase.end()) {
            if (it->compareName(checkedName)) {
                it = data.appPurchase.erase(it);
                std::cout << "��ɾ���ɹ��" << std::endl;
                found = true;
                break; // ɾ��һ���ɹ�����˳�ѭ��
            } else {
                ++it;
            }
        }

        if (!found) {
            std::cout << "�Ҳ���Ҫɾ���Ĳɹ��" << std::endl;
        }
        break;
    }
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
        std::vector<string> listInfo;
        for(int i = 0; i < inquiryPropertyCount; i++)
        {
            string prompt;
            switch(i)
            {
                case static_cast<int>(InquiryArrayOffSet::ID):
                    prompt = "������ɹ��ڲ����: ";
                    break;
                case static_cast<int>(InquiryArrayOffSet::V_NAME):
                    prompt = "�����빩Ӧ��: ";
                    break;
                case static_cast<int>(InquiryArrayOffSet::PRODUCT):
                    prompt = "�������Ʒ����: ";
                    break;
                case static_cast<int>(InquiryArrayOffSet::TYPE):
                    prompt = "���������ͺ�: ";
                    break;
                case static_cast<int>(InquiryArrayOffSet::INFO):
                    prompt = "�������Ʒ˵��: ";
                    break;
                case static_cast<int>(InquiryArrayOffSet::MONEY):
                    prompt = "�����뱨��: ";
                    break;
                case static_cast<int>(InquiryArrayOffSet::M_INFO):
                    prompt = "�����뱨��˵��: ";
                    break;
                case static_cast<int>(InquiryArrayOffSet::EVALUATE):
                    prompt = "������ѯ�۹�������: ";
                    break;
                case static_cast<int>(InquiryArrayOffSet::LEVEL):
                    prompt = "������ѯ�۹����Ǽ�: ";
                    break;
                default:
                    //Ԥ��
                    break;
            }

            MSG(prompt);//������ʾ
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
        MSG("������ƷID:> ");
        std::cin >> ID;
        MSG("\n"+Inquiry::best_choice(ID));
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
    cout << "\t	4. �������ڲ�����ɾ��\n";
    cout << "\t	5. ��ɶ���\n";
	cout << "\t	0. ������һ��\n\n";

	cout << "\t ��ѡ��0-5����";
}

bool OrderMenu::doChoice( int choice ) {
	switch ( choice ) {
	case 1:
    {
        std::vector<string> listInfo;
        for(int i = 0; i < orderPropertyCount-1; i++)
        {
            string prompt;
            switch(i)
            {
                case static_cast<int>(OrderArrayOffSet::ID):
                    prompt = "������ɹ��ڲ����: ";
                    break;
                case static_cast<int>(OrderArrayOffSet::V_NAME):
                    prompt = "�����빩Ӧ��: ";
                    break;
                case static_cast<int>(OrderArrayOffSet::PRODUCT):
                    prompt = "�������Ʒ����: ";
                    break;
                case static_cast<int>(OrderArrayOffSet::TYPE):
                    prompt = "���������ͺ�: ";
                    break;
                case static_cast<int>(OrderArrayOffSet::MONEY):
                    prompt = "�����뵥��: ";
                    break;
                case static_cast<int>(OrderArrayOffSet::UNIT):
                    prompt = "�����������λ: ";
                    break;
                case static_cast<int>(OrderArrayOffSet::NUM):
                    prompt = "����������: ";
                    break;
                //case static_cast<int>(OrderArrayOffSet::TOTAL_MONEY):
                   // prompt = "�������ܼ�: ";
                   // break;
                case static_cast<int>(OrderArrayOffSet::REQUEST):
                    prompt = "�����붩��Ҫ��: ";
                    break;
                default:
                    //Ԥ��
                    break;
            }

            MSG(prompt);//������ʾ

            string sig;
            if(i == static_cast<int>(OrderArrayOffSet::TOTAL_MONEY)){
                sig = std::to_string(std::stod(listInfo[static_cast<int>(OrderArrayOffSet::MONEY)])\
                * std::stod(listInfo[static_cast<int>(OrderArrayOffSet::NUM)]));}
            else{std::cin >> sig;}
            if(sig.empty()){
                i--;
                MSG("��Ϣ�Ƿ���:>");
                MSG(sig);
            }
            listInfo.push_back(sig);
        }
        string sig = "δ���";
        listInfo.push_back(sig);
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
              listInfo[static_cast<int>(OrderArrayOffSet::REQUEST)],
              listInfo[static_cast<int>(OrderArrayOffSet::CONDITION)]
            )
        );
    }
		break;
    //��ѯ����
	case 2:
    {
        int findTarget = 0;
        std::string ID;
        MSG("�����ڲ����:> ");
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
    //���ٶ���
	case 3:
    {
        int findTarget = 0;
        std::string ID;
        MSG("�����ڲ����:> ");
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
    //�������ڲ�����ɾ��
    case 4:
    {
        string checkedName;
        std::cout << "����Ҫɾ���Ķ����ڲ�����:> ";
        std::cin >> checkedName;

        auto it = data.appOrder.begin();// ������
        bool found = false; // ����Ƿ��ҵ�����
        while (it != data.appOrder.end()) {
            if (it->compareID(checkedName)) {
                it = data.appOrder.erase(it);
                std::cout << "��ɾ��������" << std::endl;
                found = true;
            } else {
                ++it;
            }
        }

        if (!found) {
            std::cout << "�Ҳ���Ҫɾ���Ķ�����" << std::endl;
        }
        break;
    }
    case 5: {
        string checkedName;
        std::cout << "����Ҫ��ɵĶ����ڲ�����:> ";
        std::cin >> checkedName;

        auto it = data.appOrder.begin();// ������
        bool found = false; // ����Ƿ��ҵ�����
        while (it != data.appOrder.end()) {
            if (it->compareID(checkedName)) {
                it->setCondition("�����");
                found = true;
                break;
            } else {
                ++it;
            }
        }

        if (!found) {
            std::cout << "�Ҳ���Ҫ��ɵĶ�����" << std::endl;
        }else{
            std::cout << "����ɶ�����" << std::endl;
        }
        break;
    }
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
    cout << "\t	6. �����б�\n";
	cout << "\t	0. ������һ��\n\n";

	cout << "\t ��ѡ��0-6����";
}

bool ExportMenu::doChoice( int choice ) {

	switch ( choice ) {
	case 1:
		data.exportLists(DataSectionOffSet::VENDOR);
        Menu::exported = true;
        cout<<"\n\t�ѵ�����Ӧ���б�"<<endl;
		break;
	case 2:
        data.exportLists(DataSectionOffSet::PRODUCT);
        Menu::exported = true;
        cout<<"\n\t�ѵ�����Ʒ�б�"<<endl;
		break;
	case 3:
        data.exportLists(DataSectionOffSet::PURCHASE);
        Menu::exported = true;
        cout<<"\n\t�ѵ����ɹ����б�"<<endl;
		break;
    case 4:
        data.exportLists(DataSectionOffSet::INQUIRY);
        Menu::exported = true;
        cout<<"\n\t�ѵ���ѯ���б�"<<endl;
        break;
    case 5:
        data.exportLists(DataSectionOffSet::ORDER);
        cout << "\n\t�ѵ��������б�" << endl;
        Menu::exported = true;
        break;
    case 6:
        data.exportLists(DataSectionOffSet::VENDOR);
        data.exportLists(DataSectionOffSet::PRODUCT);
        data.exportLists(DataSectionOffSet::PURCHASE);
        data.exportLists(DataSectionOffSet::INQUIRY);
        data.exportLists(DataSectionOffSet::ORDER);
        cout<<"\n\t�ѵ��������б�"<<endl;
        Menu::exported = true;
        break;
	case 0:
		//������һ��
		MenuMgr::getInstance( ).setCurrentMenu( MenuType::MAIN_MENU );
    default:
        system("cls");
	}
	return true;
}
