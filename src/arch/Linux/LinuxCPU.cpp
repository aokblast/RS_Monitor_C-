//
// Created by blast on 11/7/21.
//

#include "LinuxCPU.h"
#include <fstream>
#include <sstream>
#include <thread>
#include <unistd.h>


LinuxCPU::LinuxCPU() {

    std::ifstream fs("/proc/cpuinfo");
    std::string line;
    auto &cpu = getCpu();

    while(std::getline(fs, line)){
        if(line.compare(0, 10, "model name") == 0){

            cpu.setModelName(line.substr(line.find(':') + 2));
            break;
        }
    }

    auto &cores = cpu.getCores();
    cores.resize(sysconf(_SC_NPROCESSORS_ONLN));

    update();
}

void LinuxCPU::update() {
    std::vector<CoreData> before, after;

    auto &cores = getCpu().getCores();

    readCoreData(before);

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    readCoreData(after);

    for(int i = 0; i < cores.size(); ++i){
        unsigned long total = after[i + 1] - before[i + 1];
        cores[i].setUsage(100.0 * (total - (after[i + 1].data[CoreData::IDLE_TAB] - before[i + 1].data[CoreData::IDLE_TAB])) / (total));
    }


    readCpuFreq(cores);
}

void LinuxCPU::readCoreData(std::vector<CoreData> &datas) {
    std::ifstream is("/proc/stat");
    std::string line;
    while(std::getline(is, line)){
        if(line.compare(0, 3, "cpu"))break;
        std::istringstream parseCore(line);
        datas.emplace_back(CoreData());
        auto &newCoreInfo = datas.back();
        parseCore >> newCoreInfo.cpuID;
        int i = 0;
        while(parseCore >> newCoreInfo.data[i++]);
    }
}

void LinuxCPU::readCpuFreq(std::vector<CPUInfo::CoreInfo> &cores) {
    std::string baseDir = "/sys/devices/system/cpu/cpu", tail = "/cpufreq/scaling_cur_freq";
    for(int i = 0; i < cores.size(); ++i){
        std::ifstream f((baseDir + std::to_string(i) + tail));
        unsigned long freq;
        f >> freq;
        cores[i].setFreq(freq / 1000.0);
    }
}

unsigned long LinuxCPU::CoreData::operator-(const CoreData &c) const {
    unsigned long res = 0;
    for(int i = 0; i < 10; ++i){
        res += data[i] - c.data[i];
    }
    return res;
}