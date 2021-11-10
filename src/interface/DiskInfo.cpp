//
// Created by blast on 11/7/21.
//

#include "DiskInfo.h"

unsigned long DiskInfo::VolumnInfo::getTotal() {
    return blkSize * totalBlk;
}

unsigned long DiskInfo::VolumnInfo::getUsage() {
    return (totalBlk - freeBlk) * blkSize;
}

unsigned long DiskInfo::VolumnInfo::getFree() {
    return freeBlk * blkSize;
}

void DiskInfo::VolumnInfo::setBlkSize(unsigned long _blkSize) {
    blkSize = _blkSize;
}

void DiskInfo::VolumnInfo::setFreeBlk(unsigned long _freeBlk) {
    freeBlk = _freeBlk;
}

void DiskInfo::VolumnInfo::setTotalBlk(unsigned long _totalBlk) {
    totalBlk = _totalBlk;
}

void DiskInfo::VolumnInfo::setVolumnName(const std::string &_volumnName) {
    volumnName = _volumnName;
}

const std::string &DiskInfo::VolumnInfo::getVolumnName() {
    return volumnName;
}

void DiskInfo::VolumnInfo::setMountPoint(const std::string &_mountPoint) {
    mountPoint = _mountPoint;
}

const std::string &DiskInfo::VolumnInfo::getMountPoint() {
    return mountPoint;
}

const std::string &DiskInfo::getDiskName() {
    return diskName;
}

void DiskInfo::setDiskName(const std::string &_diskName) {
    diskName = _diskName;
}

std::vector<DiskInfo::VolumnInfo> &DiskInfo::getVolumns() {
    return volumns;
}
