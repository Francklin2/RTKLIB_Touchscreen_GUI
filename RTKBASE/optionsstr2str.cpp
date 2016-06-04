#include "optionsstr2str.h"
#include "ui_optionsstr2str.h"
#include "affichestr2str.h"

#include <QTextStream>
#include <QFile>

  int PositionMode;



int i;
char LongManual;
char LongManualLine;
char LatManual;
char AltiManual;


//char LatManualLine;
//char CoordManual;

OptionsStr2str::OptionsStr2str(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionsStr2str)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButtonDefault1,SIGNAL(clicked()),this,SLOT(OuvreDefault1()));
    QObject::connect(ui->pushButtonDefault2,SIGNAL(clicked()),this,SLOT(OuvreDefault2()));


}

OptionsStr2str::~OptionsStr2str()
{
    delete ui;
}






void OptionsStr2str::OuvreDefault1()
{
    arga={"carlepremierargtoujorsleprog","-in","serial://ttyACM0:115200:8:n:1:#ubx","-msg","1004,1019,1012,1020,1006,1008"};


    AfficheStr2str affichesolutionsStr2str(arga);
    this->hide();
    affichesolutionsStr2str.exec();
}

void OptionsStr2str::OuvreDefault2()
{


    //arga={"carlepremierargtoujorsleprog","-in","serial://ttyACM0:115200:8:n:1:#ubx","-out","serial://ttyUSB0:38400:8:n:1:#RTCM3","-msg","1004,1019,1012,1020,1006,1008"};

    arga={"carlepremierargtoujorsleprog","-in","serial://ttyACM0:115200:8:n:1:#ubx","-out","serial://ttyUSB0:38400:8:n:1:#RTCM3","-msg","1004,1019,1012,1020,1006,1008","-p","48.2","12.2","120.23"};

    // crash arga={"carlepremierargtoujorsleprog","-in","serial://ttyACM0:115200:8:n:1:#ubx","-out","serial://ttyUSB0:38400:8:n:1:#RTCM3","-msg","1004,1019,1012,1020,1006,1008", "-p","48,12,120"};
    // crash arga={"carlepremierargtoujorsleprog","-in","serial://ttyACM0:115200:8:n:1:#ubx","-out","serial://ttyUSB0:38400:8:n:1:#RTCM3","-msg","1004,1019,1012,1020,1006,1008", "-p","48 12 120"};
    /* essayer avec:
    arga={"carlepremierargtoujorsleprog","-in","serial://ttyACM0:115200:8:n:1:#ubx","-out","serial://ttyUSB0:38400:8:n:1:#RTCM3","-msg","1004,1019,1012,1020,1006,1008", "-p","48", " 12", " 120"};*/

    AfficheStr2str affichesolutionsStr2str(arga);
    this->hide();
    affichesolutionsStr2str.exec();



}




void OptionsStr2str::on_LongManualLine_textChanged()
{

}


void OptionsStr2str::on_LatManualLine_textChanged()
{

}

void OptionsStr2str::on_AltiManualLine_textChanged()
{

}


void OptionsStr2str::on_radioButtonPositionAuto_clicked()
{


    PositionMode=1;

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

   ui->LongManualLine->setText(QString(list[0]));
   ui->LatManualLine->setText(QString(list[1]));
   ui->AltiManualLine->setText(QString(list[2]));

fichier1.close();




}

void OptionsStr2str::on_radioButtonPositionManual_clicked()
{

     PositionMode=2;



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

    ui->LongManualLine->setText(QString(list[0]));
    ui->LatManualLine->setText(QString(list[1]));
    ui->AltiManualLine->setText(QString(list[2]));

 fichier1.close();

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

// QTextStream filestream(&CoordManual);




QTextStream out1(&CoordManual);
 if(i>1)
{
   out1<<LongManual<<endl;
   out1<<LatManual<<endl;
   out1<<AltiManual<<endl;
}

//  out1 << &CoordManual;


CoordManual.close();



}
