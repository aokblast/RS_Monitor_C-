//
// Created by blast on 11/14/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    cpuD = new CPUDisplay(ui->cpuFrame);
    ramD = new RamDisplay(ui->ramFrame);
    diskD = new DiskDisplay(ui->diskFrame);
}

MainWindow::~MainWindow() {
    delete cpuD;
    delete ramD;
    delete diskD;
    delete ui;
}