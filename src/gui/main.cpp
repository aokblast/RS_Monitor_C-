//
// Created by blast on 11/14/21.
//

#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}