#include <iostream>
#include "./src/interface/CPUObject.h"
#include "./src/arch/Linux/LinuxCPU.h"
#include <unistd.h>


int main() {
    CPUObject *cpu = new LinuxCPU();

    while(1){
        auto &cores = cpu->getCpu().getCores();

        for(auto &c : cores){
            std::cout << c.getFreq() << " " << c.getUsage() << '\n';
        }
        std::cout << '\n';
        cpu->update();

    }

    delete cpu;

}
