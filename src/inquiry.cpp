#include "../include/inquiry.h"
#include "../include/FileExample.h"
Inquiry::Inquiry(std::string formatInfo) {
    FileExample example;
    example.splitByDelimiter(formatInfo, ',');
    if (example.stringList.size() == 9) {
        id = example.stringList[static_cast<int>(InquiryArrayOffSet::ID)];
        info = example.stringList[static_cast<int>(InquiryArrayOffSet::INFO)];
        v_name = example.stringList[static_cast<int>(InquiryArrayOffSet::V_NAME)];
        product = example.stringList[static_cast<int>(InquiryArrayOffSet::PRODUCT)];
        type = example.stringList[static_cast<int>(InquiryArrayOffSet::TYPE)];
        money = example.stringList[static_cast<int>(InquiryArrayOffSet::MONEY)];
        m_info = example.stringList[static_cast<int>(InquiryArrayOffSet::MONEY)];
        evaluate = example.stringList[static_cast<int>(InquiryArrayOffSet::EVALUATE)];
        level = example.stringList[static_cast<int>(InquiryArrayOffSet::LEVEL)];
    }

    msg = formatInfo;
}