
#include <memory>
using namespace std;
#include "include/App.h"

int main()
{
    // ʹ��shared_ptr,�ɷ�ֹ����delete��ͬʱȷ���ڶ����������
    shared_ptr<App> app = make_shared<App>( );
    app->init( );
    app->run( );
    app->term( );
}
