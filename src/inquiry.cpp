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

bool comparePairs(const std::pair<std::string, float>& pair1, const std::pair<std::string, float>& pair2) {
    return pair1.second < pair2.second;
}
std::string Inquiry::best_choice(std::string ID)
{
    int findTarget = 0;
    float vendor_weight = 0;
    float inquiry_weight = 0;
    std::vector<pair<std::string, float>> res_pair;
    MSG("---------------------------checked----------------------------");
    MSG("主观价格 = 价格-价格*供应商星级*供应商星级权重-价格*询价过程星级*询价星级权重");
    MSG("请输入供应商星级权重（建议值0.02）：");
    cin >> vendor_weight;
    MSG("请输入询价星级权重（建议值0.01）：");
    cin >> inquiry_weight;
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
                    -std::atoi(v_t.get_level().c_str())*vendor_weight \
                    -std::atoi(tmp.level.c_str())*inquiry_weight));
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
        return "综合供应商星级询价星级和价格考虑 智能推荐供应商："+res_pair[0].first;
    }

    MSG("---------------------------finished----------------------------");

}