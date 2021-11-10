//
// Created by blast on 11/7/21.
//

#ifndef RS_MONITOR_LINUXRAM_H
#define RS_MONITOR_LINUXRAM_H
#include "../../interface/RamObject.h"


class LinuxRam : public RamObject{
public:
    void update();
    LinuxRam();
};


#endif //RS_MONITOR_LINUXRAM_H
