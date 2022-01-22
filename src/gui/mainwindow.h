//
// Created by blast on 11/14/21.
//

#ifndef RS_MONITOR_MAINWINDOW_H
#define RS_MONITOR_MAINWINDOW_H

#include <QWidget>
#include "cpudisplay.h"
#include "ramdisplay.h"
#include "diskdisplay.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
    CPUDisplay *cpuD;
    RamDisplay *ramD;
    DiskDisplay *diskD;
};


#endif //RS_MONITOR_MAINWINDOW_H
