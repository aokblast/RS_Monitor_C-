//
// Created by blast on 11/7/21.
//

#include "LinuxRam.h"
#include <sys/sysinfo.h>

LinuxRam::LinuxRam() {
    update();
}

void LinuxRam::update() {
    struct sysinfo sys;
    sysinfo(&sys);
    setTotal(sys.totalram);
    setFree(sys.freeram);
}
