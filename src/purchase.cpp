#include "../include/purchase.h"
#include "../include/FileExample.h"


Purchase::Purchase(std::string formatInfo) {
    FileExample example;
    example.splitByDelimiter(formatInfo, ',');

    for(int i = 0 ;i < purchasePropertyCount; i++)
    {
        id = example.stringList[static_cast<int>(PurchaseArrayOffSet::ID)];
        type = example.stringList[static_cast<int>(PurchaseArrayOffSet::TYPE)];
        request = example.stringList[static_cast<int>(PurchaseArrayOffSet::REQUEST)];
        num = example.stringList[static_cast<int>(PurchaseArrayOffSet::NUM)];
        name = example.stringList[static_cast<int>(PurchaseArrayOffSet::NAME)];
    }

    msg = formatInfo;
}

void Purchase::showPurchaseInfo() {
    MSG(msg);
}