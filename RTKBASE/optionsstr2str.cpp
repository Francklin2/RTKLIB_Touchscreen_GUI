#include "optionsstr2str.h"
#include "ui_optionsstr2str.h"
#include "affichestr2str.h"

#include <QTextStream>
#include <QFile>

int i;
char LongManual;
//char LongManualLine;
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
    //QLineEdit *LongManualLine = new QLineEdit("0");

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




void OptionsStr2str::on_LongManualLine_editingFinished()
{
    QString LongManual = "ui->LongManualLine->text()";
}

void OptionsStr2str::on_LatManualLine_editingFinished()
{
    QString LatManual = ui->LatManualLine->text();
}

void OptionsStr2str::on_AltiManualLine_editingFinished()
{

}


void OptionsStr2str::on_radioButton_toggled(bool checked)
{

    /*Save Manual position. This position will be used in Manual Base Mode*/


    QFile CoordManual("sauvegardepourbaseManual.txt");

    if (!CoordManual.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

   // QTextStream filestream(&CoordManual);

    QStringList list;



    QTextStream out1(&CoordManual);
    if(i>1)
    {
        out1<<list[LongManual]<<endl;
        out1<<list[LatManual]<<endl;
        out1<<list[AltiManual]<<endl;
    }

      out1 << &CoordManual;


    CoordManual.close();

}



