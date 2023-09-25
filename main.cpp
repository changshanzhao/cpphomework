
#include <memory>
using namespace std;
#include "include/App.h"

int main()
{
    // 使用shared_ptr,可防止遗忘delete，同时确保在堆区分配对象
    shared_ptr<App> app = make_shared<App>( );
    app->init( );
    app->run( );
    app->term( );
}
