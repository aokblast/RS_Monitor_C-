//
// Created by blast on 11/7/21.
//

#include "LinuxDisk.h"
#include <dirent.h>
#include <string>
#include <algorithm>
#include <sys/statvfs.h>
#include <fstream>
#include <unordered_map>
#include <sstream>
#include <iostream>


LinuxDisk::LinuxDisk() {
    std::string blockDirName = "/sys/block", devName;
    DIR *blockDir = opendir(blockDirName.c_str()), *diskDir;
    struct dirent *diskEntry, *volumnEntry;
    std::unordered_map<std::string, std::string> mountInfo;
    getMountInfo(mountInfo);

    auto &disks = getDisks();

    while((diskEntry = readdir(blockDir)) != nullptr){
        if(diskEntry->d_name[0] != '.'){

            std::string diskDirName = blockDirName + "/" + diskEntry->d_name;

            disks.emplace_back(DiskInfo());

            auto &newDisk = disks.back();
            newDisk.setDiskName(diskEntry->d_name);

            diskDir = opendir(diskDirName.c_str());
            auto &volumns = newDisk.getVolumns();

            while((volumnEntry = readdir(diskDir)) != nullptr){
                devName = std::string("/dev/") + volumnEntry->d_name;
                auto hasPrefix = std::mismatch(diskEntry->d_name, diskEntry->d_name + diskDirName.size() - blockDirName.size() - 1, volumnEntry->d_name);
                if(hasPrefix.first == diskEntry->d_name + diskDirName.size() - blockDirName.size() - 1 && mountInfo.find(devName) != mountInfo.end()){

                    volumns.emplace_back(DiskInfo::VolumnInfo());
                    auto &volumn = volumns.back();
                    volumn.setVolumnName(volumnEntry->d_name);
                    volumn.setMountPoint(mountInfo[devName]);

                }
            }

            closedir(diskDir);
        }
    }
    closedir(blockDir);


    update();
}

void LinuxDisk::update() {
    struct statvfs buffer;
    //std::vector<std::vector<DiskInfo::VolumnInfo>::iterator> erroVec;

    for(auto &disk : getDisks()){

        for(auto &volumn : disk.getVolumns()){
            int ret = statvfs(volumn.getMountPoint().c_str(), &buffer);

            volumn.setBlkSize(buffer.f_frsize);
            volumn.setTotalBlk(buffer.f_blocks);
            volumn.setFreeBlk(buffer.f_bfree);
        }

    }
}

void LinuxDisk::getMountInfo(std::unordered_map<std::string, std::string> &m) {
    std::ifstream mountFile("/proc/mounts");
    std::string line, deviceName, mountPoint;

    while(std::getline(mountFile, line)){
        std::istringstream is(line);
        is >> deviceName >> mountPoint;
        m[deviceName] = mountPoint;

    }
}