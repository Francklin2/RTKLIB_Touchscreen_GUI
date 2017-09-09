#include "choixstr2str.h"
#include "ui_choixstr2str.h"
#include "optionsstr2str.h"
#include <QFile>
#include <QInputDialog>
#include <iostream>
#include "clavier.h"

ChoixStr2Str::ChoixStr2Str(int _save_load, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChoixStr2Str)
{
    ui->setupUi(this);
    save_load=_save_load;

    this->setWindowFlags(Qt::Window);
    this->showFullScreen();
    this->setWindowFlags(Qt::WindowStaysOnTopHint);

    if(save_load==0) ui->WindowTitleEdit->setText(QString("CHOOSE SAVE SLOT"));
    else ui->WindowTitleEdit->setText(QString("CHOOSE LOAD SLOT"));

    QObject::connect(ui->Base1Button,SIGNAL(clicked()),this,SLOT(SelectBase1()));
    QObject::connect(ui->Base2Button,SIGNAL(clicked()),this,SLOT(SelectBase2()));
    QObject::connect(ui->Base3Button,SIGNAL(clicked()),this,SLOT(SelectBase3()));
    QObject::connect(ui->Base4Button,SIGNAL(clicked()),this,SLOT(SelectBase4()));
    QObject::connect(ui->Base5Button,SIGNAL(clicked()),this,SLOT(SelectBase5()));
    QObject::connect(ui->Base6Button,SIGNAL(clicked()),this,SLOT(SelectBase6()));
    QObject::connect(ui->Base7Button,SIGNAL(clicked()),this,SLOT(SelectBase7()));
    QObject::connect(ui->Base8Button,SIGNAL(clicked()),this,SLOT(SelectBase8()));
    QObject::connect(ui->Base9Button,SIGNAL(clicked()),this,SLOT(SelectBase9()));
    QObject::connect(ui->Base10Button,SIGNAL(clicked()),this,SLOT(SelectBase10()));
    QObject::connect(ui->Base11Button,SIGNAL(clicked()),this,SLOT(SelectBase11()));
    QObject::connect(ui->Base12Button,SIGNAL(clicked()),this,SLOT(SelectBase12()));

    QObject::connect(ui->ReturnButton,SIGNAL(clicked()),this,SLOT(Retour()));

    QFile baseName(QString("../RTKBASE/data/BaseNames"));
    baseName.open(QIODevice::ReadOnly | QIODevice::Text);
    QString line;
    QStringList list;
    QTextStream flux(&baseName);
    while(! flux.atEnd())
    {
        line = flux.readLine();
        qDebug()<<line;
        list<<line;
    }
    baseName.close();

    ui->Base1Button->setText(list[0].simplified());
    ui->Base2Button->setText(list[1].simplified());
    ui->Base3Button->setText(list[2].simplified());
    ui->Base4Button->setText(list[3].simplified());
    ui->Base5Button->setText(list[4].simplified());
    ui->Base6Button->setText(list[5].simplified());
    ui->Base7Button->setText(list[6].simplified());
    ui->Base8Button->setText(list[7].simplified());
    ui->Base9Button->setText(list[8].simplified());
    ui->Base10Button->setText(list[9].simplified());
    ui->Base11Button->setText(list[10].simplified());
    ui->Base12Button->setText(list[11].simplified());
}

ChoixStr2Str::~ChoixStr2Str()
{
    delete ui;
}

void ChoixStr2Str::SaveBase(QString baseFile)
{
    QFile old(baseFile);
    old.remove();
    QFile temp("../RTKBASE/BaseFiles/temp.bas");
    temp.rename("../RTKBASE/BaseFiles/temp.bas",baseFile);
    temp.close();
    this->close();
}

void ChoixStr2Str::LoadBase(QString baseFile)
{
    emit Charge(baseFile);
    this->close();
}

void ChoixStr2Str::SelectBase1()
{
    if(save_load==0) DemandeNom(1,ui->Base1Button->text());
    else LoadBase(QString("../RTKBASE/BaseFiles/Base1.bas"));
}

void ChoixStr2Str::SelectBase2()
{
    if(save_load==0) DemandeNom(2,ui->Base2Button->text());
    else LoadBase(QString("../RTKBASE/BaseFiles/Base2.bas"));
}

void ChoixStr2Str::SelectBase3()
{
    if(save_load==0) DemandeNom(3,ui->Base3Button->text());
    else LoadBase(QString("../RTKBASE/BaseFiles/Base3.bas"));
}

void ChoixStr2Str::SelectBase4()
{
    if(save_load==0) DemandeNom(4,ui->Base4Button->text());
    else LoadBase(QString("../RTKBASE/BaseFiles/Base4.bas"));
}

void ChoixStr2Str::SelectBase5()
{
    if(save_load==0) DemandeNom(5,ui->Base5Button->text());
    else LoadBase(QString("../RTKBASE/BaseFiles/Base5.bas"));
}

void ChoixStr2Str::SelectBase6()
{
    if(save_load==0) DemandeNom(6,ui->Base6Button->text());
    else LoadBase(QString("../RTKBASE/BaseFiles/Base6.bas"));
}

void ChoixStr2Str::SelectBase7()
{
    if(save_load==0) DemandeNom(7,ui->Base7Button->text());
    else LoadBase(QString("../RTKBASE/BaseFiles/Base7.bas"));
}

void ChoixStr2Str::SelectBase8()
{
    if(save_load==0) DemandeNom(8,ui->Base8Button->text());
    else LoadBase(QString("../RTKBASE/BaseFiles/Base8.bas"));
}

void ChoixStr2Str::SelectBase9()
{
    if(save_load==0) DemandeNom(9,ui->Base9Button->text());
    else LoadBase(QString("../RTKBASE/BaseFiles/Base9.bas"));
}

void ChoixStr2Str::SelectBase10()
{
    if(save_load==0) DemandeNom(10,ui->Base10Button->text());
    else LoadBase(QString("../RTKBASE/BaseFiles/Base10.bas"));
}

void ChoixStr2Str::SelectBase11()
{
    if(save_load==0) DemandeNom(11,ui->Base11Button->text());
    else LoadBase(QString("../RTKBASE/BaseFiles/Base11.bas"));
}

void ChoixStr2Str::SelectBase12()
{
    if(save_load==0) DemandeNom(12,ui->Base12Button->text());
    else LoadBase(QString("../RTKBASE/BaseFiles/Base12.bas"));
}

void ChoixStr2Str::Retour()
{
    this->close();
}

void ChoixStr2Str::DemandeNom(int num, QString name)
{
    numSauve=num;
    Clavier *NouveauClavier = new Clavier(name,QString("New Base Name :"));
    QObject::connect(NouveauClavier,SIGNAL(Texte(QString)),this,SLOT(SauveNom(QString)));
    NouveauClavier->setWindowFlags(Qt::FramelessWindowHint);
    NouveauClavier->setModal(true);
    NouveauClavier->exec();
}
void ChoixStr2Str::SauveNom(QString newName)
{
    QFile oldBaseName(QString("../RTKBASE/data/BaseNames"));
    oldBaseName.open(QIODevice::ReadWrite | QIODevice::Text);
    QString line;
    QStringList list;
    QTextStream flux(&oldBaseName);
    while(! flux.atEnd())
    {
        line = flux.readLine();
        qDebug()<<line;
        list<<line;
    }
    oldBaseName.close();
    oldBaseName.remove();
    list[numSauve-1]=newName;
    QFile newBaseName(QString("../RTKBASE/data/BaseNames"));
    newBaseName.open(QIODevice::ReadWrite | QIODevice::Text);
    QTextStream flux2(&newBaseName);
    for(int i=0;i<list.length();i++)
    {
        flux2<<list[i]<<endl;
    }
    newBaseName.close();
    SaveBase(QString("../RTKBASE/BaseFiles/Base").append(QString::number(numSauve)).append(".bas"));
}
