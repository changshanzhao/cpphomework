//
// Created by Lenovo on 2023/8/28.
//

#ifndef HOMEWORK_MENUMGR_H
#define HOMEWORK_MENUMGR_H
#include <memory>
#include <vector>
#include "MenuType.h"
// ������MenuMgr
class Menu;
class MenuMgr {
public:
    static MenuMgr & getInstance( );
protected:
    MenuMgr( );
    MenuMgr( const MenuMgr & ) = delete;	//��ֹ����
    MenuMgr( MenuMgr && ) = delete;			//��ֹת�ƿ���
    MenuMgr & operator=( const MenuMgr & ) = delete;	//��ֹ��ֵ
public:
    // ��ǰ��˵��� getter/setter
    Menu * currentMenu( ) const			{ return mCurrentMenu; }
    ~MenuMgr();
    void   setCurrentMenu( MenuType menuType )
    {
        system("cls");
        mCurrentMenu = mVctMenus[ (int)menuType ];
    }
private:
    std::vector<Menu *>	mVctMenus = {}; //ȫ���˵�����
    Menu * mCurrentMenu = nullptr;	//��˵�
};
#endif //HOMEWORK_MENUMGR_H
