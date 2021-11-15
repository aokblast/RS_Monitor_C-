//
// Created by blast on 11/7/21.
//

#ifndef RS_MONITOR_LINUXCPU_H
#define RS_MONITOR_LINUXCPU_H
#include <string>
#include "../../interface/CPUObject.h"

class LinuxCPU : public CPUObject{
public:
    LinuxCPU();
    void update();

private:

    struct CoreData{
        static const size_t IDLE_TAB = 3;
        std::string cpuID;
        unsigned long data[10];
        unsigned long operator-(const CoreData &c) const;
    };

    void readCoreData(std::vector<CoreData> &datas);
    void readCpuFreq(std::vector<CPUInfo::CoreInfo> &cores);

};



#endif //RS_MONITOR_LINUXCPU_H
