//
// Created by Lenovo on 2023/8/28.
//

#include <iostream>
using namespace std;
#include "../include/Menu.h"
#include "../include/MenuMgr.h"
#include "../include/MenuType.h"

int Menu::selectMenuItem( ) {
    int choice = 0;
    cin >> choice;
    return choice;
}

void MainMenu::display( ) const {
    system( "cls" );
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
    }
    return true;
}

//��Ӧ�̹���
void VendorMenu::display( ) const {
    system( "cls" );
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
            // ��ʵ��
            break;
        case 2:
            // ��ʵ��
            break;
        case 3:
            // ��ʵ��
            break;
        default:
            //������һ��
            MenuMgr::getInstance( ).setCurrentMenu( MenuType::MAIN_MENU );
    }
    return true;
}


//��Ӧ�̲�Ʒ����
void ProductMenu::display( ) const {
    system( "cls" );
    cout << "\n\t	��Ӧ����Ʒ����\n\n";
    cout << "\t	1. ����Ӧ�̲�ѯ��Ʒ�б�\n";
    cout << "\t	2. ����Ʒ���Ʋ�ѯ��Ӧ���б�\n";
    cout << "\t	3. ��ӹ�Ӧ����Ʒ\n";
    cout << "\t	0. ������һ��\n\n";

    cout << "\t ��ѡ��0-3����";
}


bool ProductMenu::doChoice( int choice ) {
    switch ( choice ) {
        case 1:
            // ��ʵ��
            break;
        case 2:
            // ��ʵ��
            break;
        case 3:
            // ��ʵ��
            break;
        default:
            //������һ��
            MenuMgr::getInstance( ).setCurrentMenu( MenuType::MAIN_MENU );
    }
    return true;
}

//�ɹ������
void PurchaseMenu::display( ) const {
    system( "cls" );
    cout << "\n\t	�ɹ������\n\n";
    cout << "\t	1. �ɹ����б�\n";
    cout << "\t	2. �����ɹ���\n";
    cout << "\t	0. ������һ��\n\n";

    cout << "\t ��ѡ��0-2����";
}

bool PurchaseMenu::doChoice( int choice ) {
    switch ( choice ) {
        case 1:
            // ��ʵ��
            break;
        case 2:
            // ��ʵ��
            break;
        case 3:
            // ��ʵ��
            break;
        case 0:
            //������һ��
            MenuMgr::getInstance( ).setCurrentMenu( MenuType::MAIN_MENU );
    }
    return true;
}

//ѯ�۹���
void InquiryMenu::display( ) const {
    system( "cls" );
    cout << "\n\t	ѯ�۹���\n\n";
    cout << "\t	1. ������ɸѡ��Ӧ��\n";
    cout << "\t	2. ����Ʒ��ɸѡ��Ӧ��\n";
    cout << "\t	3. ����ѯ��\n";
    cout << "\t	4. ѯ�۱Ƚ�\n";
    cout << "\t	0. ������һ��\n\n";

    cout << "\t ��ѡ��0-4����";
}

bool InquiryMenu::doChoice( int choice ) {
    switch ( choice ) {
        case 1:
            // ��ʵ��
            break;
        case 2:
            // ��ʵ��
            break;
        case 3:
            // ��ʵ��
            break;
        case 4:
            // ��ʵ��
            break;
        default:
            //������һ��
            MenuMgr::getInstance( ).setCurrentMenu( MenuType::MAIN_MENU );
    }
    return true;
}

//��������
void OrderMenu::display( ) const {
    system( "cls" );
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
            // ��ʵ��
            break;
        case 2:
            // ��ʵ��
            break;
        case 3:
            // ��ʵ��
            break;
        case 4:
            // ��ʵ��
            break;
        default:
            //������һ��
            MenuMgr::getInstance( ).setCurrentMenu( MenuType::MAIN_MENU );
    }
    return true;
}

//��Ϣ����
void ExportMenu::display( ) const {
    system( "cls" );
    cout << "\n\t	��Ϣ����\n\n";
    cout << "\t	1. XXX\n";
    cout << "\t	2. YYY\n";
    cout << "\t	3. ZZZ\n";
    cout << "\t	0. ������һ��\n\n";

    cout << "\t ��ѡ��0-3����";
}

bool ExportMenu::doChoice( int choice ) {
    switch ( choice ) {
        case 1:
            // ��ʵ��
            break;
        case 2:
            // ��ʵ��
            break;
        case 3:
            // ��ʵ��
            break;
        default:
            //������һ��
            MenuMgr::getInstance( ).setCurrentMenu( MenuType::MAIN_MENU );
    }
    return true;
}