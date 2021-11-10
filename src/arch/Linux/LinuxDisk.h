//
// Created by blast on 11/7/21.
//

#ifndef RS_MONITOR_LINUXDISK_H
#define RS_MONITOR_LINUXDISK_H
#include "../../interface/DiskObject.h"
#include <unordered_map>

class LinuxDisk : public DiskObject{
public:

    LinuxDisk();
    void update();

private:
    void getMountInfo(std::unordered_map<std::string, std::string> &m);

};


#endif //RS_MONITOR_LINUXDISK_H
