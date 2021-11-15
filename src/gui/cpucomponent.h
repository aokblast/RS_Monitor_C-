//
// Created by blast on 11/14/21.
//

#ifndef RS_MONITOR_CPUCOMPONENT_H
#define RS_MONITOR_CPUCOMPONENT_H

#include <QWidget>
#include "../interface/CPUObject.h"


QT_BEGIN_NAMESPACE
namespace Ui { class CpuComponent; }
QT_END_NAMESPACE

class CpuComponent : public QWidget {
Q_OBJECT

public:
    explicit CpuComponent(CPUInfo::CoreInfo &_core, int id, QWidget *parent = nullptr);
    ~CpuComponent() override;

private:
    Ui::CpuComponent *ui;
    CPUInfo::CoreInfo &core;
};


#endif //RS_MONITOR_CPUCOMPONENT_H
