#include "optionsstr2str.h"
#include "ui_optionsstr2str.h"
#include "affichestr2str.h"
#include <QTextStream>
#include <QFile>
#include <iostream>
#include "choixstr2str.h"
#include "clavier.h"
#include "mylineedit.h"

#include <QInputDialog>


int PositionMode;
int i;
char LongManual;
char LatManual;
char AltiManual;

QString Outbaudext;
QString OutSerialPortext;
QString OutFormatext;
QString OutFilePathtext;
QString Inbaudext;
QString InSerialPortext;
QString InFormatext;
QString RtcmMsgext;



OptionsStr2str::OptionsStr2str(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionsStr2str)
{
    ui->setupUi(this);
    this->showFullScreen();
    QObject::connect(ui->pushButtonDefault1,SIGNAL(clicked()),this,SLOT(OuvreDefault1()));
    QObject::connect(ui->radioButtonPositionAuto,SIGNAL(checked() ),this,SLOT(on_radioButtonPositionAuto_clicked(bool checked)()) );
    QObject::connect(ui->radioButtonPositionManual,SIGNAL(checked() ),this,SLOT(on_radioButtonPositionManual_clicked(bool checked)()) );


    QObject::connect(ui->radioButtonPositionAuto,SIGNAL(checked() ),this,SLOT(AfficheOptionString()));

    QObject::connect(ui->pushButtonLoad,SIGNAL(clicked()),this,SLOT(LoadBase()));
    QObject::connect(ui->pushButtonSave,SIGNAL(clicked()),this,SLOT(SaveBase()));



 // Set défault Base position mode (if not set it crashes at server start

    ui->radioButtonPositionAuto->setChecked(true);
 if (ui->radioButtonPositionAuto->isChecked())
 {
    PositionMode=1;
 }

   /* Load base position in files to display in ui
      Open, read line by line and then close file*/
{
int i=1;
QStringList list;
QString fileName = "sauvegardepourbaseManual.txt";
QFile fichier1(fileName);
fichier1.open(QIODevice::ReadOnly | QIODevice::Text);
//---------verifier ouverture fichier......
QTextStream flux(&fichier1);
QString ligne;
while(! flux.atEnd())
{
   ligne = flux.readLine();
   //traitement de la ligne
   qDebug()<<ligne;
   list<<ligne;
   i=i+1;
}

//  Display manual position
   ui->LatManualLine->setText(QString(list[0]));
   ui->LongManualLine->setText(QString(list[1]));
   ui->AltiManualLine->setText(QString(list[2]));

fichier1.close();

    }
{


/*Open, read line by line and then close file*/
int i=1;
QStringList list;
QString fileName = "sauvegardepourbase.txt";
QFile fichier1(fileName);
fichier1.open(QIODevice::ReadOnly | QIODevice::Text);
//---------verifier ouverture fichier......
QTextStream flux(&fichier1);
QString ligne;

while(! flux.atEnd())
{
ligne = flux.readLine();
//traitement de la ligne
qDebug()<<ligne;
list<<ligne;
i=i+1;
}

//  Display manual position
ui->LatAutoLine->setText(QString(list[0]));
ui->LongAutoLine->setText(QString(list[1]));
ui->AltiAutoLine->setText(QString(list[2]));

fichier1.close();

}


 // String displayed in the ui at startup

{

     QString LongAuto = ui->LongAutoLine->text();
     QString LatAuto = ui->LatAutoLine->text();
     QString AltiAuto = ui->AltiAutoLine->text();

     QString LongManual = ui->LongManualLine->text();
     QString LatManual = ui->LatManualLine->text();
     QString AltiManual = ui->AltiManualLine->text();




 QString Outbaud = ui->OutBaudRatecomboBox ->currentText();
 Outbaudext = Outbaud;
 QString OutSerialPort = ui->OutSerialPortcomboBox ->currentText();
 OutSerialPortext = OutSerialPort;
 QString OutFormat = ui->OutFormatcomboBox ->currentText();
 OutFormatext = OutFormat;
 QString OutFilePath = ui->OutFilePathcomboBox ->currentText();
 OutFilePathtext = OutFilePath;
 QString Inbaud = ui->InBaudratecomboBox ->currentText();
 Inbaudext = Inbaud;
 QString InSerialPort = ui->InSerialPortcomboBox ->currentText();
 InSerialPortext = InSerialPort;
 QString InFormat = ui->InFormatcomboBox ->currentText();
 InFormatext = InFormat;
 QString RtcmMsg = ui->RtcmMsgcomboBox ->currentText();
 RtcmMsgext = RtcmMsg;



   QString DisplayRtkrcvStr= ("-in ");
   DisplayRtkrcvStr.append(&InSerialPortext);
   DisplayRtkrcvStr.append(":");
   DisplayRtkrcvStr.append(&Inbaudext);
   DisplayRtkrcvStr.append(":8:n:1:#");
   DisplayRtkrcvStr.append(&InFormatext);
   DisplayRtkrcvStr.append(" -out ");
   DisplayRtkrcvStr.append(&OutSerialPortext);
   DisplayRtkrcvStr.append(":");
   DisplayRtkrcvStr.append(&Outbaudext);
   DisplayRtkrcvStr.append(":8:n:1:#");
   DisplayRtkrcvStr.append(&OutFormatext);
   DisplayRtkrcvStr.append(" -msg ");
   DisplayRtkrcvStr.append(&RtcmMsgext);
   DisplayRtkrcvStr.append(" -p ");

   if (PositionMode==1)
   {
   DisplayRtkrcvStr.append(&LatAuto);
   DisplayRtkrcvStr.append(" ");
   DisplayRtkrcvStr.append(&LongAuto);
   DisplayRtkrcvStr.append(" ");
   DisplayRtkrcvStr.append(&AltiAuto);

   }
   if (PositionMode==2)
   {
   DisplayRtkrcvStr.append(&LatManual);
   DisplayRtkrcvStr.append(" ");
   DisplayRtkrcvStr.append(&LongManual);
   DisplayRtkrcvStr.append(" ");
   DisplayRtkrcvStr.append(&AltiManual);
   }


   ui->RtkrcvOptionstextBrowser->setText(DisplayRtkrcvStr);

}

 //début test !
 ui->LatManualLine->setCursorPosition(0);
 //QObject::connect(ui->LatManualLine,SIGNAL(cursorPositionChanged(int,int)),this,SLOT(AppelleClavier(QLineEdit* ui->LatManualLine)));
 //QObject::connect(ui->LongManualLine,SIGNAL(cursorPositionChanged(int,int)),this,SLOT(AppelleClavier(QLineEdit* ui->LongManualLine)));
 //QObject::connect(ui->AltiManualLine,SIGNAL(cursorPositionChanged(int,int)),this,SLOT(AppelleClavier(QLineEdit* ui->AltiManualLine)));
 //AppelleClavier(ui->LatManualLine);
 //AppelleClavier(ui->LongManualLine);
 //AppelleClavier(ui->AltiManualLine);
 //fin test !

}

OptionsStr2str::~OptionsStr2str()
{
    delete ui;
}






void OptionsStr2str::OuvreDefault1()
{

    QString Outbaud = ui->OutBaudRatecomboBox ->currentText();
    Outbaudext = Outbaud;
    QString OutSerialPort = ui->OutSerialPortcomboBox ->currentText();
    OutSerialPortext = OutSerialPort;
    QString OutFormat = ui->OutFormatcomboBox ->currentText();
    OutFormatext = OutFormat;
    QString OutFilePath = ui->OutFilePathcomboBox ->currentText();
    OutFilePathtext = OutFilePath;
    QString Inbaud = ui->InBaudratecomboBox ->currentText();
    Inbaudext = Inbaud;
    QString InSerialPort = ui->InSerialPortcomboBox ->currentText();
    InSerialPortext = InSerialPort;
    QString InFormat = ui->InFormatcomboBox ->currentText();
    InFormatext = InFormat;
    QString RtcmMsg = ui->RtcmMsgcomboBox ->currentText();
    RtcmMsgext = RtcmMsg;



    if (OutSerialPort =="File")

        arga={"carlep,remierargtoujorsleprog","-in","serial://ttyACM0:115200:8:n:1:#ubx","-out","../RTKBASE/PointsFiles/rover.ubx"};
  else
        arga={"carlep,remierargtoujorsleprog","-in","serial://ttyACM0:115200:8:n:1:#ubx","-out","serial://ttyUSB0:38400:8:n:1:#rtcm3","-p","48.2","2.2","120.23","-msg","1004,1019,1012,1020,1006,1008"};


  //  std::vector<std::string>  arga={"carlep,remierargtoujorsleprog","-in","serial://",InSerialPort,":",Inbaud,":8:n:1:#",InFormat,",-out","serial://",OutSerialPort,":",Outbaud,":8:n:1:#",OutFormat,"-p","48.2","2.2","120.23","-msg","1004,1019,1012,1020,1006,1008"};
    //   arga={""};
    //arga={"carlepremierargtoujorsleprog","-in","serial://ttyACM0:115200:8:n:1:#ubx","-out","serial://ttyUSB0:38400:8:n:1:#RTCM3","-msg",""1004,1019,1012,1020,1006,1008""};
    // crash arga={"carlepremierargtoujorsleprog","-in","serial://ttyACM0:115200:8:n:1:#ubx","-out","serial://ttyUSB0:38400:8:n:1:#RTCM3","-msg","1004,1019,1012,1020,1006,1008", "-p","48,12,120"};
    // crash arga={"carlepremierargtoujorsleprog","-in","serial://ttyACM0:115200:8:n:1:#ubx","-out","serial://ttyUSB0:38400:8:n:1:#RTCM3","-msg","1004,1019,1012,1020,1006,1008", "-p","48 12 120"};
    /* essayer avec:
    arga={"carlepremierargtoujorsleprog","-in","serial://ttyACM0:115200:8:n:1:#ubx","-out","serial://ttyUSB0:38400:8:n:1:#RTCM3","-msg","1004,1019,1012,1020,1006,1008", "-p","48", " 12", " 120"};*/

    AfficheStr2str affichesolutionsStr2str(arga);
    this->hide();
    affichesolutionsStr2str.exec();


}






void OptionsStr2str::on_radioButtonPositionAuto_clicked()
{
    PositionMode=1;

    // String displayed in the ui at startup

   {

        QString LongAuto = ui->LongAutoLine->text();
        QString LatAuto = ui->LatAutoLine->text();
        QString AltiAuto = ui->AltiAutoLine->text();

        QString LongManual = ui->LongManualLine->text();
        QString LatManual = ui->LatManualLine->text();
        QString AltiManual = ui->AltiManualLine->text();




    QString Outbaud = ui->OutBaudRatecomboBox ->currentText();
    Outbaudext = Outbaud;
    QString OutSerialPort = ui->OutSerialPortcomboBox ->currentText();
    OutSerialPortext = OutSerialPort;
    QString OutFormat = ui->OutFormatcomboBox ->currentText();
    OutFormatext = OutFormat;
    QString Inbaud = ui->InBaudratecomboBox ->currentText();
    Inbaudext = Inbaud;
    QString InSerialPort = ui->InSerialPortcomboBox ->currentText();
    InSerialPortext = InSerialPort;
    QString InFormat = ui->InFormatcomboBox ->currentText();
    InFormatext = InFormat;
    QString RtcmMsg = ui->RtcmMsgcomboBox ->currentText();
    RtcmMsgext = RtcmMsg;



      QString DisplayRtkrcvStr= ("-in ");
      DisplayRtkrcvStr.append(&InSerialPortext);
      DisplayRtkrcvStr.append(":");
      DisplayRtkrcvStr.append(&Inbaudext);
      DisplayRtkrcvStr.append(":8:n:1:#");
      DisplayRtkrcvStr.append(&InFormatext);
      DisplayRtkrcvStr.append(" -out ");
      DisplayRtkrcvStr.append(&OutSerialPortext);
      DisplayRtkrcvStr.append(":");
      DisplayRtkrcvStr.append(&Outbaudext);
      DisplayRtkrcvStr.append(":8:n:1:#");
      DisplayRtkrcvStr.append(&OutFormatext);
      DisplayRtkrcvStr.append(" -msg ");
      DisplayRtkrcvStr.append(&RtcmMsgext);
      DisplayRtkrcvStr.append(" -p ");

 //Display auto position
      DisplayRtkrcvStr.append(&LatAuto);
      DisplayRtkrcvStr.append(" ");
      DisplayRtkrcvStr.append(&LongAuto);
      DisplayRtkrcvStr.append(" ");
      DisplayRtkrcvStr.append(&AltiAuto);




      ui->RtkrcvOptionstextBrowser->setText(DisplayRtkrcvStr);

}



}



void OptionsStr2str::on_radioButtonPositionManual_clicked()
{
    PositionMode=2;


    // String displayed in the ui at startup

   {

        QString LongAuto = ui->LongAutoLine->text();
        QString LatAuto = ui->LatAutoLine->text();
        QString AltiAuto = ui->AltiAutoLine->text();

        QString LongManual = ui->LongManualLine->text();
        QString LatManual = ui->LatManualLine->text();
        QString AltiManual = ui->AltiManualLine->text();




    QString Outbaud = ui->OutBaudRatecomboBox ->currentText();
    Outbaudext = Outbaud;
    QString OutSerialPort = ui->OutSerialPortcomboBox ->currentText();
    OutSerialPortext = OutSerialPort;
    QString OutFormat = ui->OutFormatcomboBox ->currentText();
    OutFormatext = OutFormat;
    QString Inbaud = ui->InBaudratecomboBox ->currentText();
    Inbaudext = Inbaud;
    QString InSerialPort = ui->InSerialPortcomboBox ->currentText();
    InSerialPortext = InSerialPort;
    QString InFormat = ui->InFormatcomboBox ->currentText();
    InFormatext = InFormat;
    QString RtcmMsg = ui->RtcmMsgcomboBox ->currentText();
    RtcmMsgext = RtcmMsg;



      QString DisplayRtkrcvStr= ("-in ");
      DisplayRtkrcvStr.append(&InSerialPortext);
      DisplayRtkrcvStr.append(":");
      DisplayRtkrcvStr.append(&Inbaudext);
      DisplayRtkrcvStr.append(":8:n:1:#");
      DisplayRtkrcvStr.append(&InFormatext);
      DisplayRtkrcvStr.append(" -out ");
      DisplayRtkrcvStr.append(&OutSerialPortext);
      DisplayRtkrcvStr.append(":");
      DisplayRtkrcvStr.append(&Outbaudext);
      DisplayRtkrcvStr.append(":8:n:1:#");
      DisplayRtkrcvStr.append(&OutFormatext);
      DisplayRtkrcvStr.append(" -msg ");
      DisplayRtkrcvStr.append(&RtcmMsgext);
      DisplayRtkrcvStr.append(" -p ");


// Disolay manual position
      DisplayRtkrcvStr.append(&LatManual);
      DisplayRtkrcvStr.append(" ");
      DisplayRtkrcvStr.append(&LongManual);
      DisplayRtkrcvStr.append(" ");
      DisplayRtkrcvStr.append(&AltiManual);



      ui->RtkrcvOptionstextBrowser->setText(DisplayRtkrcvStr);

}


}


void OptionsStr2str::on_pushButtonManual_clicked()
{

    /*Open, read line by line and then close file*/
int i=1;
QStringList list;
QString fileName = "sauvegardepourbaseManual.txt";
QFile fichier1(fileName);
fichier1.open(QIODevice::ReadOnly | QIODevice::Text);
//---------verifier ouverture fichier......
QTextStream flux(&fichier1);
QString ligne;
while(! flux.atEnd())
{
   ligne = flux.readLine();
   //traitement de la ligne
   qDebug()<<ligne;
   list<<ligne;
   i=i+1;
}

fichier1.close();


/*Save Manual position. This position will be used in Manual Base Mode*/

 QString LongManual = ui->LongManualLine->text();
 QString LatManual = ui->LatManualLine->text();
 QString AltiManual = ui->AltiManualLine->text();

QFile CoordManual("sauvegardepourbaseManual.txt");

if (!CoordManual.open(QIODevice::WriteOnly | QIODevice::Text))
   return;


QTextStream out1(&CoordManual);
 if(i>1)
{
   out1<<LatManual<<endl;
   out1<<LongManual<<endl;
   out1<<AltiManual<<endl;
}



CoordManual.close();



// String displayed in the ui


if (PositionMode==1)
 {

QString Outbaud = ui->OutBaudRatecomboBox ->currentText();
Outbaudext = Outbaud;
QString OutSerialPort = ui->OutSerialPortcomboBox ->currentText();
OutSerialPortext = OutSerialPort;
QString OutFormat = ui->OutFormatcomboBox ->currentText();
OutFormatext = OutFormat;
QString Inbaud = ui->InBaudratecomboBox ->currentText();
Inbaudext = Inbaud;
QString InSerialPort = ui->InSerialPortcomboBox ->currentText();
InSerialPortext = InSerialPort;
QString InFormat = ui->InFormatcomboBox ->currentText();
InFormatext = InFormat;
QString RtcmMsg = ui->RtcmMsgcomboBox ->currentText();
RtcmMsgext = RtcmMsg;

QString LongAuto = ui->LongAutoLine->text();
QString LatAuto = ui->LatAutoLine->text();
QString AltiAuto = ui->AltiAutoLine->text();



  QString DisplayRtkrcvStr= ("-in ");
  DisplayRtkrcvStr.append(&InSerialPortext);
  DisplayRtkrcvStr.append(":");
  DisplayRtkrcvStr.append(&Inbaudext);
  DisplayRtkrcvStr.append(":8:n:1:#");
  DisplayRtkrcvStr.append(&InFormatext);
  DisplayRtkrcvStr.append(" -out ");
  DisplayRtkrcvStr.append(&OutSerialPortext);
  DisplayRtkrcvStr.append(":");
  DisplayRtkrcvStr.append(&Outbaudext);
  DisplayRtkrcvStr.append(":8:n:1:#");
  DisplayRtkrcvStr.append(&OutFormatext);
  DisplayRtkrcvStr.append(" -msg ");
  DisplayRtkrcvStr.append(&RtcmMsgext);
  DisplayRtkrcvStr.append(" -p ");

//Display auto position
  DisplayRtkrcvStr.append(&LatAuto);
  DisplayRtkrcvStr.append(" ");
  DisplayRtkrcvStr.append(&LongAuto);
  DisplayRtkrcvStr.append(" ");
  DisplayRtkrcvStr.append(&AltiAuto);

  ui->RtkrcvOptionstextBrowser->setText(DisplayRtkrcvStr);

 }
if (PositionMode==2)
 {

QString Outbaud = ui->OutBaudRatecomboBox ->currentText();
Outbaudext = Outbaud;
QString OutSerialPort = ui->OutSerialPortcomboBox ->currentText();
OutSerialPortext = OutSerialPort;
QString OutFormat = ui->OutFormatcomboBox ->currentText();
OutFormatext = OutFormat;
QString Inbaud = ui->InBaudratecomboBox ->currentText();
Inbaudext = Inbaud;
QString InSerialPort = ui->InSerialPortcomboBox ->currentText();
InSerialPortext = InSerialPort;
QString InFormat = ui->InFormatcomboBox ->currentText();
InFormatext = InFormat;
QString RtcmMsg = ui->RtcmMsgcomboBox ->currentText();
RtcmMsgext = RtcmMsg;

QString LongManual = ui->LongManualLine->text();
QString LatManual = ui->LatManualLine->text();
QString AltiManual = ui->AltiManualLine->text();



  QString DisplayRtkrcvStr= ("-in ");
  DisplayRtkrcvStr.append(&InSerialPortext);
  DisplayRtkrcvStr.append(":");
  DisplayRtkrcvStr.append(&Inbaudext);
  DisplayRtkrcvStr.append(":8:n:1:#");
  DisplayRtkrcvStr.append(&InFormatext);
  DisplayRtkrcvStr.append(" -out ");
  DisplayRtkrcvStr.append(&OutSerialPortext);
  DisplayRtkrcvStr.append(":");
  DisplayRtkrcvStr.append(&Outbaudext);
  DisplayRtkrcvStr.append(":8:n:1:#");
  DisplayRtkrcvStr.append(&OutFormatext);
  DisplayRtkrcvStr.append(" -msg ");
  DisplayRtkrcvStr.append(&RtcmMsgext);
  DisplayRtkrcvStr.append(" -p ");

// Disolay manual position
  DisplayRtkrcvStr.append(&LatManual);
  DisplayRtkrcvStr.append(" ");
  DisplayRtkrcvStr.append(&LongManual);
  DisplayRtkrcvStr.append(" ");
  DisplayRtkrcvStr.append(&AltiManual);

  ui->RtkrcvOptionstextBrowser->setText(DisplayRtkrcvStr);

 }



}


void OptionsStr2str::on_UpdateOptionspushButton_clicked()
{


    // String displayed in the ui


        QString LongAuto = ui->LongAutoLine->text();
        QString LatAuto = ui->LatAutoLine->text();
        QString AltiAuto = ui->AltiAutoLine->text();

        QString LongManual = ui->LongManualLine->text();
        QString LatManual = ui->LatManualLine->text();
        QString AltiManual = ui->AltiManualLine->text();




    QString Outbaud = ui->OutBaudRatecomboBox ->currentText();
    Outbaudext = Outbaud;
    QString OutSerialPort = ui->OutSerialPortcomboBox ->currentText();
    OutSerialPortext = OutSerialPort;
    QString OutFormat = ui->OutFormatcomboBox ->currentText();
    OutFormatext = OutFormat;
    QString OutFilePath = ui->OutFilePathcomboBox ->currentText();
    OutFilePathtext = OutFilePath;
    QString Inbaud = ui->InBaudratecomboBox ->currentText();
    Inbaudext = Inbaud;
    QString InSerialPort = ui->InSerialPortcomboBox ->currentText();
    InSerialPortext = InSerialPort;
    QString InFormat = ui->InFormatcomboBox ->currentText();
    InFormatext = InFormat;
    QString RtcmMsg = ui->RtcmMsgcomboBox ->currentText();
    RtcmMsgext = RtcmMsg;



      QString DisplayRtkrcvStr= ("-in ");
      DisplayRtkrcvStr.append(&InSerialPortext);
      DisplayRtkrcvStr.append(":");
      DisplayRtkrcvStr.append(&Inbaudext);
      DisplayRtkrcvStr.append(":8:n:1:#");
      DisplayRtkrcvStr.append(&InFormatext);
      DisplayRtkrcvStr.append(" -out ");


      if ( (PositionMode==1) and (OutSerialPortext!="File") )
    {
         DisplayRtkrcvStr.append(&OutSerialPortext);
         DisplayRtkrcvStr.append(":");
         DisplayRtkrcvStr.append(&Outbaudext);
         DisplayRtkrcvStr.append(":8:n:1:#");
         DisplayRtkrcvStr.append(&OutFormatext);
         DisplayRtkrcvStr.append(" -msg ");
         DisplayRtkrcvStr.append(&RtcmMsgext);
         DisplayRtkrcvStr.append(" -p ");
         DisplayRtkrcvStr.append(&LatAuto);
         DisplayRtkrcvStr.append(" ");
         DisplayRtkrcvStr.append(&LongAuto);
         DisplayRtkrcvStr.append(" ");
         DisplayRtkrcvStr.append(&AltiAuto);
      }

      if ( (PositionMode==2) and (OutSerialPortext!="File") )
      {
          DisplayRtkrcvStr.append(&OutSerialPortext);
          DisplayRtkrcvStr.append(":");
          DisplayRtkrcvStr.append(&Outbaudext);
          DisplayRtkrcvStr.append(":8:n:1:#");
          DisplayRtkrcvStr.append(&OutFormatext);
          DisplayRtkrcvStr.append(" -msg ");
          DisplayRtkrcvStr.append(&RtcmMsgext);
          DisplayRtkrcvStr.append(" -p ");
          DisplayRtkrcvStr.append(&LatManual);
          DisplayRtkrcvStr.append(" ");
         DisplayRtkrcvStr.append(&LongManual);
         DisplayRtkrcvStr.append(" ");
         DisplayRtkrcvStr.append(&AltiManual);
      }
      if ( (PositionMode==1 and OutSerialPortext=="File") or (PositionMode==2 and OutSerialPortext=="File") )       {
      {
          DisplayRtkrcvStr.append(&OutFilePath);
      }

   }
      ui->RtkrcvOptionstextBrowser->setText(DisplayRtkrcvStr);

}

void OptionsStr2str::SaveBase()
{
    /*
     * mettre les différentes indications dans un fichier "temp.bas"
     */
    QFile temp("../RTKBASE/BaseFiles/temp.bas");
    temp.open(QFile::ReadWrite|QFile::Truncate);
    QTextStream flux(&temp);
    /*flux<<qSetFieldWidth(20)<<left<<"auto-lat"<<qSetFieldWidth(0)<<"="<<ui->LatAutoLine->text()<<endl;
    flux<<qSetFieldWidth(20)<<left<<"auto-long"<<qSetFieldWidth(0)<<"="<<ui->LongAutoLine->text()<<endl;
    flux<<qSetFieldWidth(20)<<left<<"auto-alt"<<qSetFieldWidth(0)<<"="<<ui->AltiAutoLine->text()<<endl;*/
    flux<<qSetFieldWidth(20)<<left<<"manual-lat"<<qSetFieldWidth(0)<<"="<<ui->LatManualLine->text()<<endl;
    flux<<qSetFieldWidth(20)<<left<<"manual-long"<<qSetFieldWidth(0)<<"="<<ui->LongManualLine->text()<<endl;
    flux<<qSetFieldWidth(20)<<left<<"manual-alt"<<qSetFieldWidth(0)<<"="<<ui->AltiManualLine->text()<<endl;
    flux<<qSetFieldWidth(20)<<left<<"inpstr-port"<<qSetFieldWidth(0)<<"="<<ui->InSerialPortcomboBox->currentText()<<endl;
    flux<<qSetFieldWidth(20)<<left<<"inpstr-baud"<<qSetFieldWidth(0)<<"="<<ui->InBaudratecomboBox->currentText()<<endl;
    flux<<qSetFieldWidth(20)<<left<<"inpstr-format"<<qSetFieldWidth(0)<<"="<<ui->InFormatcomboBox->currentText()<<endl;
    flux<<qSetFieldWidth(20)<<left<<"outstr-port"<<qSetFieldWidth(0)<<"="<<ui->OutSerialPortcomboBox->currentText()<<endl;
    flux<<qSetFieldWidth(20)<<left<<"outstr-baud"<<qSetFieldWidth(0)<<"="<<ui->OutBaudRatecomboBox->currentText()<<endl;
    flux<<qSetFieldWidth(20)<<left<<"outstr-format"<<qSetFieldWidth(0)<<"="<<ui->OutFormatcomboBox->currentText()<<endl;
    flux<<qSetFieldWidth(20)<<left<<"rtcm-msg"<<qSetFieldWidth(0)<<"="<<ui->RtcmMsgcomboBox->currentText()<<endl;
    temp.close();

    ChoixStr2Str *SaveChoixStr2Str = new ChoixStr2Str(0);
    SaveChoixStr2Str->setWindowFlags(Qt::FramelessWindowHint);
    SaveChoixStr2Str->setModal(true);
    SaveChoixStr2Str->exec();
}

void OptionsStr2str::LoadBase()
{
    ChoixStr2Str *LoadChoixStr2Str = new ChoixStr2Str(1);
    QObject::connect(LoadChoixStr2Str,SIGNAL(Charge(QString)),this,SLOT(Charge(QString)));
    LoadChoixStr2Str->setWindowFlags(Qt::FramelessWindowHint);
    LoadChoixStr2Str->setModal(true);
    LoadChoixStr2Str->exec();
}

void OptionsStr2str::Charge(QString _baseFile)
{

    QFile baseFile(_baseFile);
    QTextStream flux(&baseFile);
    baseFile.open(QIODevice::ReadOnly | QIODevice::Truncate);
    QString line;
    QStringList liste;
    while(!flux.atEnd())
    {
        line = flux.readLine();
        qDebug()<<line;
        liste<<line;
    }
    baseFile.close();

    for(int i=0;i<liste.length();i++)
    {
        QStringList decomp = liste[i].remove("=").split(" ",QString::SkipEmptyParts);
        /*if(decomp[0]=="auto-lat") ui->LatAutoLine->setText(decomp[1]);
        else if(decomp[0]=="auto-long") ui->LongAutoLine->setText(decomp[1]);
        else if(decomp[0]=="auto-alt") ui->AltiAutoLine->setText(decomp[1]);
        else*/ if(decomp[0]=="manual-lat")  ui->LatManualLine->setText(decomp[1]);
        else if(decomp[0]=="manual-long") ui->LongManualLine->setText(decomp[1]);
        else if(decomp[0]=="manual-alt") ui->AltiManualLine->setText(decomp[1]);
        else if(decomp[0]=="inpstr-port") ui->InSerialPortcomboBox->setEditText(decomp[1]);
        else if(decomp[0]=="inpstr-baud") ui->InBaudratecomboBox->setEditText(decomp[1]);
        else if(decomp[0]=="inpstr-format") ui->InFormatcomboBox->setEditText(decomp[1]);
        else if(decomp[0]=="outstr-port") ui->OutSerialPortcomboBox->setEditText(decomp[1]);
        else if(decomp[0]=="outstr-baud") ui->OutBaudRatecomboBox->setEditText(decomp[1]);
        else if(decomp[0]=="outstr-format") ui->OutFormatcomboBox->setEditText(decomp[1]);
        else if(decomp[0]=="rtcm-msg") ui->RtcmMsgcomboBox->setEditText(decomp[1]);
        else std::cout<<"Le paramètre <"<<decomp[0].toStdString()<<"> n'a pas été reconnu"<<std::endl;
    }
    on_UpdateOptionspushButton_clicked();
}

void OptionsStr2str::AppelleClavier(MyLineEdit *line)
{
    line->setCursorPosition(0);
    Clavier *NouveauClavier = new Clavier(line->text());
    QObject::connect(line,SIGNAL(focussed(bool)),NouveauClavier,SLOT(exec()));
    QObject::connect(NouveauClavier,SIGNAL(Texte(QString)),line,SLOT(setText(QString)));
    NouveauClavier->setWindowFlags(Qt::FramelessWindowHint);
    NouveauClavier->setModal(true);
}

