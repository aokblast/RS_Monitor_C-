//
// Created by blast on 11/14/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>


MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainWindow), cpuD(new CPUDisplay(this)) {
    ui->setupUi(this);
    ui->cpuFrame->setLayout(cpuD->getLayout());

}

MainWindow::~MainWindow() {
    delete cpuD;
    delete ui;
}