//
// Created by ³Â¹ÚºÀ on 2023/8/28.
//

#ifndef HOMEWORK_DATA_H
#define HOMEWORK_DATA_H
#include "inquiry.h"
#include "product.h"
#include "purchase.h"
#include "vendor.h"
#include "order.h"
#include "Utils.h"

enum class DataSectionOffSet{
    VENDOR,
    PRODUCT,
    PURCHASE,
    INQUIRY,
    ORDER
};


class Data {
public:
    std::vector<Vendor> appVendor;
    std::vector<Product> appProduct;
    std::vector<Purchase> appPurchase;
    std::vector<Inquiry> appInquiry;
    std::vector<Order> appOrder;

    void exportLists(DataSectionOffSet which);

    void showAppVendor();
    void showAppProduct();
    void showAppPurchase();

};

extern Data data;


#endif //HOMEWORK_DATA_H
