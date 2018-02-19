#include <QDebug>
#include <QMessageBox>

#include "rnx2rtkp.h"
#include "station.h"
#include <fstream>
#include <QGraphicsTextItem>

#include "mydialog.h"
#include "ui_mydialog.h"

#include "mainwindow.h"
#include "processing.h"
#include "mymessagehandler.h"

#include <QTextStream>
#include <QFile>
#include <iostream>
#include <QTimer>


MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);

    QObject::connect(ui->AutoPostP_pushButton,SIGNAL(clicked()),this,SLOT(Start_AutoPP()));
    QObject::connect(ui->Stop_AutoPP_pushButton,SIGNAL(clicked()),this,SLOT(Close_Window()));
    QObject::connect(ui->Save_options_pushButton,SIGNAL(clicked()),this,SLOT(Save_Options()));


    // Open configuration file to read max radius for station and nb of station
        {
        int i=1;
        QStringList list;
        QString fileName = "sauvegardeoptionAutoPPbase.txt";
        QFile readoption(fileName);
        readoption.open(QIODevice::ReadOnly | QIODevice::Text);
        //---------verifier ouverture fichier......
        QTextStream flux(&readoption);
        QString ligne;
        while(! flux.atEnd())
        {
           ligne = flux.readLine();
           //traitement de la ligne
           qDebug()<<ligne;
           list<<ligne;
           i=i+1;
        }

              ui->Radius_dmax->setCurrentText(QString(list[0]));
              ui->MinStation->setCurrentText(QString(list[1]));
              ui->CaptureTime->setCurrentText(QString(list[2]));
              ui->WaitingTime->setCurrentText(QString(list[3]));
              ui->InSerialPortcomboBox2->setCurrentText(QString(list[4]));
              ui->InBaudratecomboBox2->setCurrentText(QString(list[5]));
              ui->InFormatcomboBox2->setCurrentText(QString(list[6]));
              ui->Autostartbase_comboBox->setCurrentText(QString(list[7]));
              ui->OutSerialPortcomboBox2->setCurrentText(QString(list[8]));
              ui->OutBaudRatecomboBox2->setCurrentText(QString(list[9]));
              ui->OutFormatcomboBox2->setCurrentText(QString(list[10]));
              ui->RtcmMsgcomboBox2->setCurrentText(QString(list[11]));


              ui->InfoCapture_lineEdit->setText(QString("Log "+list[2]+"mn and wait "+list[3]+"mn before process"));
              ui->InfoProcess_lineEdit->setText(QString(list[1])+" stations in a "+(list[0])+"Km radius will be used");

        readoption.close();

    }


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



void MyDialog::Save_Options()
{

  /*Save options for auto post processing The options will be used in Automatic post processing Mode*/

     QString RadiusMaxStation = ui->Radius_dmax->currentText();
     QString MinStat = ui->MinStation->currentText();
     QString Capture_Time = ui->CaptureTime->currentText();
     QString Wait_Time = ui->WaitingTime->currentText();
     QString InputPort = ui->InSerialPortcomboBox2->currentText();
     QString InputBaud = ui->InBaudratecomboBox2->currentText();
     QString InFormat = ui->InFormatcomboBox2->currentText();
     QString Autostartbase =ui->Autostartbase_comboBox->currentText();
     QString Outport =ui->OutSerialPortcomboBox2->currentText();
     QString OutBaud =ui->OutBaudRatecomboBox2->currentText();
     QString OutFormat =ui->OutFormatcomboBox2->currentText();
     QString RTCMmsg =ui->RtcmMsgcomboBox2->currentText();


     std::ofstream q("sauvegardeoptionAutoPPbase.txt");
       QFile optionAutoPPbase("sauvegardeoptionAutoPPbase.txt");
       optionAutoPPbase.open(QIODevice::Append | QIODevice::Text);
       QTextStream out1(&optionAutoPPbase);
    {
       out1<<RadiusMaxStation<<endl;
       out1<<MinStat<<endl;
       out1<<Capture_Time<<endl;
       out1<<Wait_Time<<endl;
       out1<<InputPort<<endl;
       out1<<InputBaud<<endl;
       out1<<InFormat<<endl;
       out1<<Autostartbase<<endl;
       out1<<Outport<<endl;
       out1<<OutBaud<<endl;
       out1<<OutFormat<<endl;
       out1<<RTCMmsg<<endl;


       ui->InfoProcess_lineEdit->setText(QString(MinStat)+" stations in a "+(RadiusMaxStation)+"Km radius will be used");
       ui->InfoCapture_lineEdit->setText(QString("Log "+Capture_Time+"mn and wait "+Wait_Time+"mn before process"));

       }



    optionAutoPPbase.close();

}


 void MyDialog::Start_AutoPP()
 {

     // Open configuration file to use for auto processing

         int i=1;
         QStringList list;
         QString fileName = "sauvegardeoptionAutoPPbase.txt";
         QFile readoption(fileName);
         readoption.open(QIODevice::ReadOnly | QIODevice::Text);
         //---------verifier ouverture fichier......
         QTextStream flux(&readoption);
         QString ligne;
         while(! flux.atEnd())
         {
            ligne = flux.readLine();
            //traitement de la ligne
            qDebug()<<ligne;
            list<<ligne;
            i=i+1;
         }


          QString Capttime = (list[2]);
          int Capttime2 = Capttime.toInt();
          int CaptureTimer = Capttime2*60000;

          QString Waittime = (list[3]);
          int Waittime2 = Waittime.toInt();
          int WaitTimer = Waittime2*60000;

        QString InputPort2 = (list[4]);
        QString InputBaud2 = (list[5]);
        QString InputFormat2 = (list[6]);
        QString Autostart_Base = (list[7]);
        QString OutPort2 = (list[8]);
        QString OutBaud2 = (list[9]);
        QString OutFormat2 = (list[10]);
        QString RTCMmsg2 = (list[11]);





         readoption.close();




        // Launch str2str

     string InSerialPortstr = InputPort2.toStdString();
     string Inbaudstr= InputBaud2.toStdString();
     string InFormatstr = InputFormat2.toStdString();
     string OutSerialPortstr = OutPort2.toStdString();
     string Outbaudstr = OutBaud2.toStdString();
     string OutFormatstr = OutFormat2.toStdString();
     string RtcmMsgstr = RTCMmsg2.toStdString();
     string latstr = Sol_x_LLH.toStdString();
     string lonstr = Sol_y_LLH.toStdString();
     string hstr = Sol_z_LLH.toStdString();


     string OutFilePathstr = "../RTKBASE/PointsFiles/rover.ubx";


                              arga={"carlepremierargesttoujorsleprog","-in","serial://ttyACM0:115200:8:n:1:#ubx","-out","../RTKBASE/PointsFiles/rover.ubx"};

    std::vector<std::string> args1={"carlepremierargesttoujorsleprog","-in",InSerialPortstr+":"+Inbaudstr+":8:n:1:#"+InFormatstr,"-out",OutFilePathstr};

    args=args1;



 /*Str2str.c opening options*/
 int sizeArgs=args.size();
 QVector<QString> qstr(sizeArgs);

  for (int i=0; i<sizeArgs;i++)
 {
     qstr[i] = QString::fromStdString(args[i]);
 }

 ui->Capture_textBrowser->setText(QString("CURRENT STR2STR OPTIONS"));

 for (int i=1; i<sizeArgs;i++)
 {
     ui->Capture_textBrowser->append(qstr[i]);
 }

   m_tstr2str->setArgcArgvStr2str(args);
   m_tstr2str->start();
   m_readfile->start();

  QObject::connect(m_readfile,SIGNAL(emitdonneesStr2str(QStringList)),this,SLOT(recupdonneesStr2str(QStringList))); //ok
 // QObject::connect(ui->Stop_AutoPP_pushButton,SIGNAL(clicked()),this,SLOT(FermeStr2str2()));
 QObject::connect(this,SIGNAL(closeSignal(int)),m_tstr2str,SLOT(close(int)));
 QObject::connect(m_tstr2str,SIGNAL(etatFermetureThreadStr2str(bool)),this,SLOT(finThread2(bool)));

ui->textBrowser_2->setText(QString("RECORDING RAW DATA FROM GNSS"));



  QTimer::singleShot(CaptureTimer, this, SLOT(FermeStr2str2()));        // Close str2str and logging
  QTimer::singleShot(CaptureTimer+WaitTimer, this, SLOT(on_pushButton_run_rnx2rtk_process_RGP_clicked())); // Wait and start post processing




  if (Autostart_Base == "on")        // Check to start againstr2str in base mode with position results
  {

      // Launch str2str

                               arga={"carlepremierargesttoujorsleprog","-in","serial://ttyACM0:115200:8:n:1:#ubx","-out","serial://ttyUSB0:38400:8:n:1:#rtcm3","-p","48.2","2.2","120.23","-msg","1004,1019,1012,1020,1006,1008"};
     std::vector<std::string> args1={"carlepremierargesttoujorsleprog","-in",InSerialPortstr+":"+Inbaudstr+":8:n:1:#"+InFormatstr,"-out",OutSerialPortstr+":"+Outbaudstr+":8:n:1:#"+OutFormatstr,"-msg",RtcmMsgstr,"-p",latstr,lonstr,hstr};


  args=args1;

// }

/*Str2str.c opening options*/
int sizeArgs=args.size();
QVector<QString> qstr(sizeArgs);

for (int i=0; i<sizeArgs;i++)
{
   qstr[i] = QString::fromStdString(args[i]);
}

ui->Capture_textBrowser->setText(QString("CURRENT STR2STR OPTIONS"));

for (int i=1; i<sizeArgs;i++)
{
   ui->Capture_textBrowser->append(qstr[i]);
}


 m_tstr2str->setArgcArgvStr2str(args);
 m_tstr2str->start();
 m_readfile->start();

QObject::connect(m_readfile,SIGNAL(emitdonneesStr2str(QStringList)),this,SLOT(recupdonneesStr2str(QStringList))); //ok
// QObject::connect(ui->Stop_AutoPP_pushButton,SIGNAL(clicked()),this,SLOT(FermeStr2str2()));
QObject::connect(this,SIGNAL(closeSignal(int)),m_tstr2str,SLOT(close(int)));
QObject::connect(m_tstr2str,SIGNAL(etatFermetureThreadStr2str(bool)),this,SLOT(finThread2(bool)));




  }


 }

 void MyDialog::FermeStr2str2()
 {
     emit closeSignal(1);
     ui->textBrowser_2->setText(QString("CLOSING IN PROGRESS"));

 }


 void MyDialog::finThread2(bool a)
 {
     if (a==true)
     {
         m_readfile->terminate();
         m_tstr2str->terminate();
       //  this->close();
     }
 }

 void MyDialog::recupdonneesStr2str(QStringList i)
 {

     {

ui->Capture_textBrowser->setText(QString("RECORDING RAW DATA FROM GNSS"));

}

     {
     ui->Capture_textBrowser->setText((i[0]));
     }

}


 void MyDialog::Close_Window()
 {
     emit closeSignal(1);
     ui->textBrowser_2->setText(QString("CLOSING IN PROGRESS"));
     m_readfile->terminate();
     m_tstr2str->terminate();
     this->close();

 }
