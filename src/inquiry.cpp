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
    MSG("���ۼ۸� = �۸�-�۸�*��Ӧ���Ǽ�*��Ӧ���Ǽ�Ȩ��-�۸�*ѯ�۹����Ǽ�*ѯ���Ǽ�Ȩ��");
    MSG("�����빩Ӧ���Ǽ�Ȩ�أ�����ֵ0.02����");
    cin >> vendor_weight;
    MSG("������ѯ���Ǽ�Ȩ�أ�����ֵ0.01����");
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
        return "�ۺϹ�Ӧ���Ǽ�ѯ���Ǽ��ͼ۸��� �����Ƽ���Ӧ�̣�"+res_pair[0].first;
    }

    MSG("---------------------------finished----------------------------");

}