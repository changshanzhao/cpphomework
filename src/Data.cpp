#include "../include/Data.h"

const std::string VENDORPATH = std::string("../source/vendor.txt");
const std::string PRODUCTPATH = std::string("../source/product.txt");
const std::string  PURCHASEPATH = std::string("../source/purchase.txt");
const std::string  INQUIRYEPATH = std::string("../source/inquiry.txt");
const std::string  ORDERPATH = std::string("../source/order.txt");

void Data::showAppVendor()
{
    LINE;
    for(Vendor tmp: appVendor)
    {
        tmp.showVendorInfo();
    }
    LINE;
}

void Data::showAppProduct()
{
    LINE;
    for(Product tmp : appProduct){
        tmp.showProductInfo();
    }
    LINE;
}

void Data::showAppPurchase() {
    LINE;
    for(Purchase tmp : appPurchase){
        tmp.showPurchaseInfo();
    }
    LINE;
}

void Data::exportLists(DataSectionOffSet which)
{

    switch (which)
    {
        case DataSectionOffSet::VENDOR:
        {
            ofstream outFile(VENDORPATH, ios_base::out);
            for (int i = 0; i < appVendor.size(); i++)
            {
                outFile << appVendor[i].backMsg() << std::string("\n");
            }

        }break;
        case DataSectionOffSet::PRODUCT:
        {
            ofstream outFile(PRODUCTPATH, ios_base::out);
            for (int i = 0; i < appProduct.size(); i++)
            {
                outFile << appProduct[i].backMsg() << std::string("\n");
            }
        }break;
        case DataSectionOffSet::PURCHASE:
        {
            ofstream outFile(PURCHASEPATH, ios_base::out);
            for (int i = 0; i < appPurchase.size(); i++)
            {
                outFile << appPurchase[i].backMsg() << std::string("\n");
            }

        }
        break;
        case DataSectionOffSet::INQUIRY:
        {
            ofstream outFile(INQUIRYEPATH, ios_base::out);
            for (int i = 0; i < appInquiry.size(); i++) {
                outFile << appInquiry[i].backMsg() << std::string("\n");
            }
        }break;
        case DataSectionOffSet::ORDER:
        {
            ofstream outFile(ORDERPATH, ios_base::out);
            for (int i = 0; i < appOrder.size(); i++) {
                outFile << appOrder[i].backMsg() << std::string("\n");
            }
        }break;
    }
}