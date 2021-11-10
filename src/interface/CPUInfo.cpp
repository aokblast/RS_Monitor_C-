//
// Created by blast on 11/7/21.
//

#include "CPUInfo.h"

using CoreInfo = CPUInfo::CoreInfo;

void CoreInfo::setFreq(double _freq) {
    freq = _freq;
}

double CoreInfo::getFreq() {
    return freq;
}

void CoreInfo::setUsage(double _usage) {
    usage = _usage;
}

double CoreInfo::getUsage() {
    return usage;
}

void CPUInfo::setModelName(const std::string &_modelName) {
    modelName = _modelName;
}

const std::string &CPUInfo::getModelName() {
    return modelName;
}

std::vector<CoreInfo> &CPUInfo::getCores() {
    return cores;
}

