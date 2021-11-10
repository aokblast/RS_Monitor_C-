//
// Created by blast on 11/7/21.
//

#ifndef RS_MONITOR_CPUOBJECT_H
#define RS_MONITOR_CPUOBJECT_H
#include "CPUInfo.h"
#include "ResourceObject.h"
#include <vector>

class CPUObject : public ResourceObject{
public:
    virtual void update() = 0;
    CPUInfo &getCpu();

private:
    CPUInfo cpu;
};


#endif //RS_MONITOR_CPUOBJECT_H
