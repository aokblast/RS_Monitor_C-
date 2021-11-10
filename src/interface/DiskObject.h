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

private:
    std::vector<DiskInfo> disks;
};


#endif //RS_MONITOR_DISKOBJECT_H
