//
// Created by blast on 11/14/21.
//

#ifndef RS_MONITOR_CPUDISPLAY_H
#define RS_MONITOR_CPUDISPLAY_H

#include <QWidget>
#include <QGridLayout>
#include "../interface/CPUObject.h"



QT_BEGIN_NAMESPACE
namespace Ui { class CPUDisplay; }
QT_END_NAMESPACE

class CPUDisplay : public QWidget {
Q_OBJECT

public:
    explicit CPUDisplay(QWidget *parent = nullptr);
    QLayout *getLayout();
    ~CPUDisplay() override;

private:
    Ui::CPUDisplay *ui;
    CPUObject *cpuObj;
    QGridLayout *layout;
};


#endif //RS_MONITOR_CPUDISPLAY_H
