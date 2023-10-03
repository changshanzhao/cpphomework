//
// Created by Lenovo on 2023/8/28.
//

#ifndef HOMEWORK_MENU_H
#define HOMEWORK_MENU_H

#include "Utils.h"
#include "Data.h"
// ����˵�
class Menu {
public:
    virtual ~Menu( ) = default;
    virtual bool process();
    virtual void confirmExit();//ȷ���˳�
protected:
    virtual void display( ) const = 0;
    virtual int  selectMenuItem( );
    virtual bool doChoice( int choice ) = 0;
    static bool exported; // ��¼�Ƿ�ִ�й���������
};

//���˵�
class MainMenu :public Menu {
protected:
    virtual void display( ) const;
    virtual bool doChoice( int choice );
};
//��Ӧ�̹���˵�
class VendorMenu :public Menu {
protected:
    virtual void display( ) const;
    virtual bool doChoice( int choice );

};
//��Ӧ����Ʒ�˵�
class ProductMenu :public Menu {
protected:
    virtual void display( ) const;
    virtual bool doChoice( int choice );

};
//�ɹ���˵�
class PurchaseMenu :public Menu {
protected:
    virtual void display( ) const;
    virtual bool doChoice( int choice );
};
//ѯ�۲˵�
class InquiryMenu :public Menu {
protected:
    virtual void display( ) const;
    virtual bool doChoice( int choice );
};
//�����˵�
class OrderMenu :public Menu {
protected:
    virtual void display( ) const;
    virtual bool doChoice( int choice );
};
//�����˵�
class ExportMenu :public Menu {
protected:
    virtual void display( ) const;
    virtual bool doChoice( int choice );
};
#endif //HOMEWORK_MENU_H
