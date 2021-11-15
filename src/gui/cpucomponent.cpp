//
// Created by blast on 11/14/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_CpuComponent.h" resolved

#include "cpucomponent.h"
#include "ui_cpucomponent.h"
#include <QString>


CpuComponent::CpuComponent(CPUInfo::CoreInfo &_core, int id, QWidget *parent) :
        QWidget(parent), ui(new Ui::CpuComponent), core(_core) {
    char buf[100];
    ui->setupUi(this);
    ui->coreID->setText(QString::fromStdString(std::to_string(id)));
    ui->usageProgress->setValue(core.getUsage());
    sprintf(buf, "%.3lf", core.getUsage());
    ui->usageNum->setText(QString::fromStdString(std::string(buf) + "%"));
    sprintf(buf, "%.3lf", core.getFreq());
    ui->freq->setText(QString::fromStdString(std::string(buf) + "Mhz"));
}

CpuComponent::~CpuComponent() {
    delete ui;
}

