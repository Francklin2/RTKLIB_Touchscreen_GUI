#include <QDebug>
#include <QMessageBox>

#include "rnx2rtkp.h"
#include "station.h"

#include "mydialog.h"
#include "ui_mydialog.h"

#include "mainwindow.h"
#include "processing.h"
#include "mymessagehandler.h"

// QString Radmax;
// QString Radmax = "50";
// QString Radmax = Radmax5;

 QString Radmax = "40";
// QString Radmax;




MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);

    // QObject::connect(ui->pushButton_run_rnx2rtk_process_RGP,SIGNAL(clicked()),this,SLOT(on_pushButton_run_rnx2rtk_process_RGP_clicked()));

//   QString Dmax_Radius = ui->Radius_dmax->currentText();
//   Radmax = Dmax_Radius;

   //  Radmax5 = ui->Radius_dmax->currentText();


}
//QString Radmax = "40";

// QString Radmax = Radmax5;

MyDialog::~MyDialog()
{
    delete ui;


}

void MyDialog::on_pushButton_run_rnx2rtk_process_RGP_clicked()
{


   // QString Dmax_Radius = ui->Radius_dmax->currentText();
   // QString Radmax = Dmax_Radius;

   // QString Dmax_Radius = ui->Radius_dmax->currentText();
   // Radmax = Dmax_Radius;



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





    extern QString Sol_x_ECEF;
    QString X_ECEF = QString("ECEF X: ").append(Sol_x_ECEF);
    extern QString Sol_y_ECEF;
     QString Y_ECEF = QString("ECEF Y: ").append(Sol_y_ECEF);
     extern QString Sol_z_ECEF;
    QString Z_ECEF = QString("ECEF Z: ").append(Sol_z_ECEF);


    extern QString Sol_x_LLH;
    QString X_LLH = QString("Lat: ").append(Sol_x_LLH);
    extern QString Sol_y_LLH;
     QString Y_LLH = QString("Lon: ").append(Sol_y_LLH);
     extern QString Sol_z_LLH;
    QString Z_LLH = QString("Alt: ").append(Sol_z_LLH);



   ui->ECEF_x_lineEdit->setText(X_ECEF);
   ui->ECEF_y_lineEdit->setText(Y_ECEF);
   ui->ECEF_z_lineEdit->setText(Z_ECEF);

   ui->LLH_Lat_lineEdit->setText(X_LLH);
   ui->LLH_Lon_lineEdit->setText(Y_LLH);
   ui->LLH_Alt_lineEdit->setText(Z_LLH);

}

void MyDialog::on_progressBar_valueChanged(int value)
{
    ui->progressBar->setValue(value);
}
