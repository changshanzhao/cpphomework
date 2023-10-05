#include <algorithm>
#include "../include/order.h"
#include "../include/FileExample.h"

Order::Order(std::string formatInfo)
{
    FileExample example;
    example.splitByDelimiter(formatInfo, ',');
    if (example.stringList.size() == 10) {
        id = example.stringList[static_cast<int>(OrderArrayOffSet::ID)];
        unit = example.stringList[static_cast<int>(OrderArrayOffSet::UNIT)];
        v_name = example.stringList[static_cast<int>(OrderArrayOffSet::V_NAME)];
        product = example.stringList[static_cast<int>(OrderArrayOffSet::PRODUCT)];
        type = example.stringList[static_cast<int>(OrderArrayOffSet::TYPE)];
        money = example.stringList[static_cast<int>(OrderArrayOffSet::MONEY)];
        num = example.stringList[static_cast<int>(OrderArrayOffSet::NUM)];
        total_money = example.stringList[static_cast<int>(OrderArrayOffSet::TOTAL_MONEY)];
        request = example.stringList[static_cast<int>(OrderArrayOffSet::REQUEST)];
        condition = example.stringList[static_cast<int>(OrderArrayOffSet::CONDITION)];
    }
    msg = formatInfo;
}

