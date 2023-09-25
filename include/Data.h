
#ifndef HOMEWORK_DATA_H
#define HOMEWORK_DATA_H
#include "inquiry.h"
#include "product.h"
#include "purchase.h"
#include "vendor.h"
#include "order.h"
#include "Utils.h"
#include "../include/FileExample.h"

enum class DataSectionOffSet{
    VENDOR,
    PRODUCT,
    PURCHASE,
    INQUIRY,
    ORDER
};


class Data {
public:
    void exportLists(DataSectionOffSet which);
    void showAppVendor();
//    void showAppProduct();
    void showAppPurchase();
    void init();
    std::vector<Vendor> appVendor;
    std::vector<Product> appProduct;
    std::vector<Purchase> appPurchase;
    std::vector<Inquiry> appInquiry;
    std::vector<Order> appOrder;

};

extern Data data;


#endif //HOMEWORK_DATA_H
