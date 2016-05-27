#include "optionsstr2str.h"
#include "ui_optionsstr2str.h"
#include "affichestr2str.h"

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
