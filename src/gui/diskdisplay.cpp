//
// Created by blast on 11/15/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_DiskDisplay.h" resolved

#include "diskdisplay.h"
#include "ui_diskdisplay.h"
#include "diskcomponent.h"
#include "../arch/Linux/LinuxDisk.h"
DiskDisplay::DiskDisplay(QWidget *parent) :
        QWidget(parent), ui(new Ui::DiskDisplay), layout(new QVBoxLayout(parent)), diskobj(new LinuxDisk()) {
    ui->setupUi(this);
    int id = 0;
    for(auto &disk : diskobj->getDisks()){
        for(auto &volumn : disk.getVolumns()){
            layout->addWidget(new DiskComponent(volumn));
        }
    }
}

QLayout *DiskDisplay::getLayout() {
    return layout;
}

DiskDisplay::~DiskDisplay() {
    delete layout;
    delete diskobj;
    delete ui;
}

