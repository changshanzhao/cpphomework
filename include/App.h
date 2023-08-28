//
// Created by Lenovo on 2023/8/28.
//

#ifndef HOMEWORK_APP_H
#define HOMEWORK_APP_H

class App {
public:
    virtual ~App( ) = default;
    virtual void init( );	//初始化工作
    virtual void run( );	//运行
    virtual void term( );	//清理工作
};

#endif //HOMEWORK_APP_H
