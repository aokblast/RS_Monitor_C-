//
// Created by blast on 11/14/21.
//

#ifndef RS_MONITOR_CPULAYOUT_H
#define RS_MONITOR_CPULAYOUT_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class CPULayout; }
QT_END_NAMESPACE

class CPULayout : public QWidget {
Q_OBJECT

public:
    explicit CPULayout(QWidget *parent = nullptr);

    ~CPULayout() override;

private:
    Ui::CPULayout *ui;
};


#endif //RS_MONITOR_CPULAYOUT_H
