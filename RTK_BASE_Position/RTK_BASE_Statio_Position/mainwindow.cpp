#include <QApplication>



#include "ui_mainwindow.h"

#include "processing.h"
#include "mymessagehandler.h"

#include <mydialog.h>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    //this->showFullScreen();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_run_clicked()
{
   // this->hide();
/*
    MyDialog mDialog;
    mDialog.setModal(true);
    mDialog.exec();
*/
    mDialog=new MyDialog(this);
    mDialog->show();


}
