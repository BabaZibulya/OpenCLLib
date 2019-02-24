#pragma once
#include <vector>
#include <string>
#include <ostream>

#include "CLTypes.h"

class CLPlatform
{
public:
    /*
    #define CL_PLATFORM_PROFILE                         0x0900
    #define CL_PLATFORM_VERSION                         0x0901
    #define CL_PLATFORM_NAME                            0x0902
    #define CL_PLATFORM_VENDOR                          0x0903
    #define CL_PLATFORM_EXTENSIONS                      0x0904
    */
    struct PlatformInfo {
        const std::string profile, version, name, vendor, extensions;
        PlatformInfo() = delete;
        friend std::ostream& operator<< (std::ostream& ostream, const PlatformInfo& platformInfo);
    };
    PlatformInfo getPlatformInfo() const;
    std::string getPlatformInfoDetail(unsigned int detailInd);

    const cl_platform_id platformId;
private:
    explicit CLPlatform(cl_platform_id platformId);
    friend CLPlatform platformFromId(cl_platform_id platformId);
};
