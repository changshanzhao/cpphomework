cmake_minimum_required(VERSION 3.16)
project(homework)

set(CMAKE_CXX_STANDARD 11)

add_executable(homework main.cpp src/App.cpp include/App.h include/MenuType.h include/MenuFactory.h src/MenuFactory.cpp src/MenuMgr.cpp include/MenuMgr.h src/Menu.cpp include/Menu.h include/FileExample.h include/vendor.h src/vendor.cpp include/product.h include/purchase.h include/inquiry.h include/order.h)
