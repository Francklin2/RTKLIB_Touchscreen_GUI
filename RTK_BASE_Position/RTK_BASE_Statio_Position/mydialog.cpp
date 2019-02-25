#include <QDebug>
#include <QMessageBox>

#include "mydialog.h"
#include "ui_mydialog.h"

#include "mainwindow.h"
#include "processing.h"
#include "mymessagehandler.h"



MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);
}

MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::on_pushButton_run_rnx2rtk_process_RGP_clicked()
{
    on_progressBar_valueChanged(3);
    ui->textBrowser->setText("Please wait ... calculation in progress...");
    qInstallMessageHandler(myMessageHandler);

    processing();
    on_progressBar_valueChanged(90);

    QFile file_("../work/Log_file.txt");
    if (!file_.open(QIODevice::ReadOnly))
        QMessageBox::information(0,"info",file_.errorString());

    QTextStream in(&file_);
    ui->textBrowser->setText(in.readAll());
    on_progressBar_valueChanged(100);

}

void MyDialog::on_progressBar_valueChanged(int value)
{
    ui->progressBar->setValue(value);
}
