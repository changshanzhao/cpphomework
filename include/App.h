//
// Created by Lenovo on 2023/8/28.
//

#ifndef HOMEWORK_APP_H
#define HOMEWORK_APP_H
#include "inquiry.h"
#include "product.h"
#include "purchase.h"
#include "vendor.h"
#include "order.h"
#include "Data.h"
#include "Utils.h"
class App {
public:
    virtual ~App( ) = default;
    virtual void init( );	//��ʼ������
    virtual void run( );	//����
    virtual void term( );	//������

};

#endif //HOMEWORK_APP_H
