#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<log.h>
//#define LogPt

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
static int sb;
void MainWindow::on_pushButton_clicked()
{
LogPt("sb is %d %d\n",sb,sb);
    sb++;
}
