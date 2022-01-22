//
// Created by blast on 11/15/21.
//

#ifndef RS_MONITOR_DISKCOMPONENT_H
#define RS_MONITOR_DISKCOMPONENT_H

#include <QWidget>
#include "../interface/DiskInfo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DiskComponent; }
QT_END_NAMESPACE

class DiskComponent : public QWidget {
Q_OBJECT

public:
    explicit DiskComponent(DiskInfo::VolumnInfo &_volumn, QWidget *parent = nullptr);

    ~DiskComponent() override;

private:
    Ui::DiskComponent *ui;
    DiskInfo::VolumnInfo &volumn;
    std::string getUsagePercentage();
};


#endif //RS_MONITOR_DISKCOMPONENT_H
