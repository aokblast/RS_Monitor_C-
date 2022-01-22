//
// Created by blast on 11/7/21.
//

#ifndef RS_MONITOR_DISKOBJECT_H
#define RS_MONITOR_DISKOBJECT_H
#include "DiskInfo.h"
#include "ResourceObject.h"

class DiskObject : public ResourceObject{
public:
    virtual void update() = 0;
    std::vector<DiskInfo> &getDisks();
    constexpr inline static double byteToGbyte = 1.0 * 1024 * 1024 * 1024;
    constexpr inline static double byteToMbyte = 1.0 * 1024 * 1024;
    constexpr inline static double byteToKbyte = 1.0 * 1024;
    constexpr inline static double gbyteToByte = 1.0 / 1024 / 1024 / 1024;
    constexpr inline static double mbyteToByte = 1.0 / 1024 / 1024;
    constexpr inline static double kbyteToByte = 1.0 / 1024;
private:
    std::vector<DiskInfo> disks;
};


#endif //RS_MONITOR_DISKOBJECT_H
