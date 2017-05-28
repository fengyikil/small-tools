#include "mainwindow.h"
#include "ui_mainwindow.h"

//void my_log(char* buf)
//{
//    puts(buf);
//}

 extern Log* lg;
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
LogPt(lg," sb is %d %d\n",sb,sb);
//    lg->print();
    sb++;
}
