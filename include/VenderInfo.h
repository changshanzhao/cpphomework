#ifndef _VENDERINFO_H_
#define _VENDERINFO_H_

#include <string>
#include "FileExample.h"
class VenderInfo
{
public:
    VenderInfo() = delete;
    VenderInfo(std::string info);

private:
    std::string venderInfo;
};

#endif