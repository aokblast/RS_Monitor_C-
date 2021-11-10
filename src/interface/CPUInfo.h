//
// Created by blast on 11/7/21.
//

#ifndef RS_MONITOR_CPUINFO_H
#define RS_MONITOR_CPUINFO_H
#include "ResourceObject.h"
#include <string>
#include <vector>

class CPUInfo{
public:
    class CoreInfo{
    public:
        void setFreq(double _freq);
        double getFreq();
        void setUsage(double _usage);
        double getUsage();

    private:
        double freq;
        double usage;
    };

    void setModelName(const std::string &_modelName);
    const std::string &getModelName();
    std::vector<CoreInfo> &getCores();


private:
    std::string modelName;
    std::vector<CoreInfo> cores;
};




#endif //RS_MONITOR_CPUINFO_H
