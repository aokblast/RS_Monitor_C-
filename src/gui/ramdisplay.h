//
// Created by blast on 11/15/21.
//

#ifndef RS_MONITOR_RAMDISPLAY_H
#define RS_MONITOR_RAMDISPLAY_H

#include <QWidget>
#include "../interface/RamObject.h"

QT_BEGIN_NAMESPACE
namespace Ui { class RamDisplay; }
QT_END_NAMESPACE

class RamDisplay : public QWidget {
Q_OBJECT

public:
    explicit RamDisplay(QWidget *parent = nullptr);

    ~RamDisplay() override;

private:
    Ui::RamDisplay *ui;
    RamObject *ramobj;
};


#endif //RS_MONITOR_RAMDISPLAY_H
