//
// Created by blast on 11/7/21.
//

#include "RamObject.h"

void RamObject::setFree(unsigned long _free) {
    free = _free;
}

void RamObject::setTotal(unsigned long _total) {
    total = _total;
}

unsigned long RamObject::getTotal() {
    return total;
}

unsigned long RamObject::getFree() {
    return free;
}

unsigned long RamObject::getUsage() {
    return total - free;
}