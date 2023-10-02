#include <algorithm>
#include "../include/inquiry.h"
#include "../include/FileExample.h"
#include "../include/Data.h"
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
// 主观价格 = 价格-价格*供应商星级*0.02-价格*询价过程星级*0.01
bool comparePairs(const std::pair<std::string, float>& pair1, const std::pair<std::string, float>& pair2) {
    return pair1.second < pair2.second;
}
std::string Inquiry::best_choice(std::string ID)
{
    int findTarget = 0;
    std::vector<pair<std::string, float>> res_pair;
    MSG("---------------------------checked----------------------------");
    for(Inquiry tmp : data.appInquiry)
    {
        if(tmp.compareID(ID)){
            tmp.showInquiryInfo();
            for(Vendor v_t : data.appVendor)
            {
                if(v_t.compareName(tmp.v_name))
                {
                    res_pair.push_back(make_pair(tmp.v_name, \
                    std::atoi(tmp.money.c_str()) \
                    -std::atoi(v_t.get_level().c_str())*0.02 \
                    -std::atoi(tmp.level.c_str())*0.01));
                    findTarget++;
                    break;
                }
            }
        }
    }

    if(findTarget == 0){
        return "Do not find any target";
    }
    else
    {
        std::sort(res_pair.begin(), res_pair.end(), comparePairs);
        return res_pair[0].first;
    }

    MSG("---------------------------finished----------------------------");

}