//
// Created by blast on 11/14/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_CPULayout.h" resolved

#include "cpulayout.h"
#include "ui_CPULayout.h"


CPULayout::CPULayout(QWidget *parent) :
        QWidget(parent), ui(new Ui::CPULayout) {
    ui->setupUi(this);
}

CPULayout::~CPULayout() {
    delete ui;
}

