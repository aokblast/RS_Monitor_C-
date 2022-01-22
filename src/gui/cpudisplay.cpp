//
// Created by blast on 11/14/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_cpudisplay.h" resolved

#include "cpudisplay.h"
#include "ui_cpudisplay.h"
#include "../arch/Linux/LinuxCPU.h"
#include "cpucomponent.h"


#include <QTextBrowser>
#include <cmath>

CPUDisplay::CPUDisplay(QWidget *parent) :
        QWidget(parent), ui(new Ui::CPUDisplay), cpuObj(new LinuxCPU()),  layout(new QGridLayout(parent)){
    ui->setupUi(this);
    int id = 0;
    auto &cores = cpuObj->getCpu().getCores();
    int sq = sqrt(cores.size());

    for(auto &core : cores)
        layout->addWidget(new CpuComponent(core, id++), id / sq, id % sq);

}

QLayout *CPUDisplay::getLayout() {
    return layout;
}

CPUDisplay::~CPUDisplay() {
    delete cpuObj;
    delete layout;
    delete ui;
}