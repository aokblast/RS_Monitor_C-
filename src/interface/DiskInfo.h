//
// Created by blast on 11/7/21.
//

#ifndef RS_MONITOR_DISKINFO_H
#define RS_MONITOR_DISKINFO_H
#include <vector>
#include <string>

class DiskInfo {
public:
    class VolumnInfo{
    public:
        void setBlkSize(unsigned long _blkSize);
        void setTotalBlk(unsigned long _totalBlk);
        void setFreeBlk(unsigned long _freeBlk);
        unsigned long getUsage();
        unsigned long getTotal();
        unsigned long getFree();

        void setVolumnName(const std::string &_volumnName);
        const std::string &getVolumnName();
        void setMountPoint(const std::string &_mountPoint);
        const std::string &getMountPoint();

    private:
        std::string volumnName;
        std::string mountPoint;
        unsigned long blkSize;
        unsigned long totalBlk;
        unsigned long freeBlk;
    };

    void setDiskName(const std::string &_diskName);
    const std::string &getDiskName();
    std::vector<VolumnInfo> &getVolumns();

private:
    std::vector<VolumnInfo> volumns;
    std::string diskName;
};



#endif //RS_MONITOR_DISKINFO_H
