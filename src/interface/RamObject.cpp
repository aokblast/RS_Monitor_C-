//
// Created by blast on 11/7/21.
//

#include "RamObject.h"

void RamObject::setUsage(unsigned long _usage) {
    used = _usage;
}

void RamObject::setTotal(unsigned long _total) {
    total = _total;
}

unsigned long RamObject::getTotal() {
    return total;
}

unsigned long RamObject::getFree() {
    return total - used;
}

unsigned long RamObject::getUsage() {
    return used;
}