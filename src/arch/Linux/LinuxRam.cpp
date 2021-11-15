//
// Created by blast on 11/7/21.
//

#include "LinuxRam.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

LinuxRam::LinuxRam() {
    update();
}

void LinuxRam::update() {
    std::ifstream memInfo("/proc/meminfo");
    std::string line, tmp;
    unsigned long val;
    std::getline(memInfo, line);
    std::istringstream ss1(line);
    ss1 >> tmp >> val;
    setTotal(val * 1024UL);
    std::getline(memInfo, line);
    std::getline(memInfo, line);
    std::istringstream ss2(line);
    ss2 >> tmp >> val;
    setUsage(getTotal() - val * 1024UL);
}
