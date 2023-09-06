//
// Created by Lenovo on 2023/8/28.
//

#ifndef HOMEWORK_MENUFACTORY_H
#define HOMEWORK_MENUFACTORY_H
#include "MenuType.h"

//²Ëµ¥¹¤³§
class Menu;
class MenuFactory {
public:
    virtual ~MenuFactory( ) = default;
    virtual Menu * createMenu( MenuType menuType )  = 0;
};

class MyMenuFactory :public MenuFactory {
public:
    virtual Menu * createMenu( MenuType menuType ) ;
};
#endif //HOMEWORK_MENUFACTORY_H
