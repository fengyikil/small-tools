#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include<QtCore>
#include "log.h"
#include<stdio.h>
 void my_log1(const char* buf)
 {
     puts(buf);
    QFile f;
//    QString str =buf;
    f.setFileName("xx1.log");
    f.open(QIODevice::Append);
    f.write(buf);
 }

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    logEnableflags(LogALLON);
    logDisableflags(LogFunc);
    logsetCallback(my_log1);

    MainWindow w;
    w.show();

    return a.exec();
}
