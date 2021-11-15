//
// Created by blast on 11/15/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_RamDisplay.h" resolved

#include "ramdisplay.h"
#include "ui_ramdisplay.h"
#include <QVBoxLayout>
#include "../arch/Linux/LinuxRam.h"

RamDisplay::RamDisplay(QWidget *parent) :
        QWidget(parent), ui(new Ui::RamDisplay), ramobj(new LinuxRam) {
    ui->setupUi(this);
    ui->ramUsageBar->setValue(1.0 * ramobj->getUsage() / ramobj->getTotal() * 100.0);
    ui->ramUsgaeText->setText(QString::fromStdString(std::to_string(ramobj->getUsage() / 1024 / 1024 / 1024) + "/" + std::to_string(ramobj->getTotal() / 1024 / 1024 / 1024) + "GB"));
}

RamDisplay::~RamDisplay() {
    delete ramobj;
    delete ui;
}

