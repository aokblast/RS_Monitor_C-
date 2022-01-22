//
// Created by blast on 11/15/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_DiskComponent.h" resolved

#include "diskcomponent.h"
#include "ui_diskcomponent.h"
#include "../interface/DiskObject.h"
#include <iostream>
#include <sstream>
#include <iomanip>

DiskComponent::DiskComponent(DiskInfo::VolumnInfo &_volumn, QWidget *parent) :
        QWidget(parent), ui(new Ui::DiskComponent), volumn(_volumn) {
    ui->setupUi(this);
    ui->volumnName->setText(QString::fromStdString(volumn.getVolumnName()));
    ui->volumnUsageText->setText(QString::fromStdString(getUsagePercentage()));
    ui->volumnUsageBar->setValue(100 * volumn.getUsage() / volumn.getTotal());
}

DiskComponent::~DiskComponent() {
    delete ui;
}

std::string DiskComponent::getUsagePercentage() {
    std::stringstream ss;
    ss << std::setprecision(3);
    ss << (volumn.getUsage() / DiskObject::byteToGbyte) << "/" << (volumn.getTotal() / DiskObject::byteToGbyte) << "GB";
    return ss.str();
}
