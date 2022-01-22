//
// Created by blast on 11/15/21.
//

#ifndef RS_MONITOR_DISKDISPLAY_H
#define RS_MONITOR_DISKDISPLAY_H

#include <QWidget>
#include <QVBoxLayout>
#include "../interface/DiskObject.h"


QT_BEGIN_NAMESPACE
namespace Ui { class DiskDisplay; }
QT_END_NAMESPACE

class DiskDisplay : public QWidget {
Q_OBJECT

public:
    explicit DiskDisplay(QWidget *parent = nullptr);
    QLayout *getLayout();
    ~DiskDisplay() override;

private:
    Ui::DiskDisplay *ui;
    QVBoxLayout *layout;
    DiskObject *diskobj;
};


#endif //RS_MONITOR_DISKDISPLAY_H
