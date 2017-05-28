#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include<QtCore>
#include "log.h"
#include<stdio.h>
 Log* lg;
 void my_log(const char* buf)
 {
     puts(buf);
    QFile f;
//    QString str =buf;
    f.setFileName("xx.log");
    f.open(QIODevice::Append);
    f.write(buf);
 }
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    lg = new Log();
    lg->flagsEnable(LogALLON);
//    lg->flagsDisable(LogFunc);
    lg->setCallback(my_log);

    MainWindow w;
    w.show();

    return a.exec();
}
