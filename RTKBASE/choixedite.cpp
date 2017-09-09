#include "choixedite.h"
#include "ui_choixedite.h"
#include "editeconfig.h"
#include "gestionconfig.h"
#include "choixconfig.h"
#include <QFile>
#include <QDebug>
#include <QString>
#include <QInputDialog>
#include <iostream>
#include "clavier.h"

ChoixEdite::ChoixEdite(QString _modeleFile, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChoixEdite)
{
    ui->setupUi(this);

    modeleFile = _modeleFile;

    this->setWindowFlags(Qt::Window);
    this->showFullScreen();

    QObject::connect(ui->Custom1Button,SIGNAL(clicked()),this,SLOT(SelectConfig1()));
    QObject::connect(ui->Custom2Button,SIGNAL(clicked()),this,SLOT(SelectConfig2()));
    QObject::connect(ui->Custom3Button,SIGNAL(clicked()),this,SLOT(SelectConfig3()));
    QObject::connect(ui->Custom4Button,SIGNAL(clicked()),this,SLOT(SelectConfig4()));
    QObject::connect(ui->Custom5Button,SIGNAL(clicked()),this,SLOT(SelectConfig5()));
    QObject::connect(ui->Custom6Button,SIGNAL(clicked()),this,SLOT(SelectConfig6()));
    QObject::connect(ui->Custom7Button,SIGNAL(clicked()),this,SLOT(SelectConfig7()));
    QObject::connect(ui->Custom8Button,SIGNAL(clicked()),this,SLOT(SelectConfig8()));
    QObject::connect(ui->Custom9Button,SIGNAL(clicked()),this,SLOT(SelectConfig9()));
    QObject::connect(ui->Custom10Button,SIGNAL(clicked()),this,SLOT(SelectConfig10()));
    QObject::connect(ui->Custom11Button,SIGNAL(clicked()),this,SLOT(SelectConfig11()));
    QObject::connect(ui->Custom12Button,SIGNAL(clicked()),this,SLOT(SelectConfig12()));
    QObject::connect(ui->ReturnButton,SIGNAL(clicked()),this,SLOT(Retour()));


    QFile configName(QString("../RTKBASE/data/ConfigNames"));
    configName.open(QIODevice::ReadOnly | QIODevice::Text);
    QString line;
    QStringList list;
    QTextStream flux(&configName);
    while(! flux.atEnd())
    {
        line = flux.readLine();
        qDebug()<<line;
        list<<line;
    }
    configName.close();
    ui->Custom1Button->setText(list[0].simplified());
    ui->Custom2Button->setText(list[1].simplified());
    ui->Custom3Button->setText(list[2].simplified());
    ui->Custom4Button->setText(list[3].simplified());
    ui->Custom5Button->setText(list[4].simplified());
    ui->Custom6Button->setText(list[5].simplified());
    ui->Custom7Button->setText(list[6].simplified());
    ui->Custom8Button->setText(list[7].simplified());
    ui->Custom9Button->setText(list[8].simplified());
    ui->Custom10Button->setText(list[9].simplified());
    ui->Custom11Button->setText(list[10].simplified());
    ui->Custom12Button->setText(list[11].simplified());
}

ChoixEdite::~ChoixEdite()
{
    delete ui;
}

void ChoixEdite::OuvrirEditeur(QString configFile)
{
    EditeConfig *FenetreEditeConfig = new EditeConfig(modeleFile, configFile);
    QObject::connect(FenetreEditeConfig,SIGNAL(DemandeRetour()),this,SLOT(Affiche()));
    QObject::connect(FenetreEditeConfig,SIGNAL(DemandeFerme()),this,SLOT(FermeTout()));
    this->hide();
    FenetreEditeConfig->exec();
}

void ChoixEdite::SelectConfig1()
{
    DemandeNom(1,ui->Custom1Button->text());
}

void ChoixEdite::SelectConfig2()
{
    DemandeNom(2,ui->Custom2Button->text());
}

void ChoixEdite::SelectConfig3()
{
    DemandeNom(3,ui->Custom3Button->text());
}

void ChoixEdite::SelectConfig4()
{
    DemandeNom(4,ui->Custom4Button->text());
}

void ChoixEdite::SelectConfig5()
{
    DemandeNom(5,ui->Custom5Button->text());
}

void ChoixEdite::SelectConfig6()
{
    DemandeNom(6,ui->Custom6Button->text());
}

void ChoixEdite::SelectConfig7()
{
    DemandeNom(7,ui->Custom7Button->text());
}

void ChoixEdite::SelectConfig8()
{
    DemandeNom(8,ui->Custom8Button->text());
}

void ChoixEdite::SelectConfig9()
{
    DemandeNom(9,ui->Custom9Button->text());
}

void ChoixEdite::SelectConfig10()
{
    DemandeNom(10,ui->Custom10Button->text());
}

void ChoixEdite::SelectConfig11()
{
    DemandeNom(11,ui->Custom11Button->text());
}

void ChoixEdite::SelectConfig12()
{
    DemandeNom(12,ui->Custom12Button->text());
}

void ChoixEdite::Retour()
{
    if(modeleFile==QString(""))
    {
        /*GestionConfig *FenetreGestionConfig=new GestionConfig();
        FenetreGestionConfig->setModal(true);
        FenetreGestionConfig->setWindowFlags(Qt::FramelessWindowHint);
        FenetreGestionConfig->exec();*/

    }
    else
    {
        /*ChoixConfig FenetreChoixConfigNouveau(1);
        FenetreChoixConfigNouveau.exec();*/
    }
    emit DemandeRetour();
    this->close();
}

void ChoixEdite::DemandeNom(int num, QString name)
{
    numSauve=num;
    Clavier *NouveauClavier = new Clavier(name,QString("New Configuration Name :"));
    QObject::connect(NouveauClavier,SIGNAL(Texte(QString)),this,SLOT(SauveNom(QString)));
    NouveauClavier->setWindowFlags(Qt::FramelessWindowHint);
    NouveauClavier->setModal(true);
    NouveauClavier->exec();
    /*bool ok;
    QString newName = QInputDialog::getText(this,tr("Blabla"),tr("New Configuration Name :"),QLineEdit::Normal,
                                            name,&ok,Qt::WindowFlags(Qt::FramelessWindowHint));
    if(ok)*/
}

void ChoixEdite::SauveNom(QString newName)
{
    QFile oldConfigName(QString("../RTKBASE/data/ConfigNames"));
    oldConfigName.open(QIODevice::ReadWrite | QIODevice::Text);
    QString line;
    QStringList list;
    QTextStream flux(&oldConfigName);
    while(! flux.atEnd())
    {
        line = flux.readLine();
        qDebug()<<line;
        list<<line;
    }
    oldConfigName.close();
    oldConfigName.remove();
    list[numSauve-1]=newName;
    QFile newConfigName(QString("../RTKBASE/data/ConfigNames"));
    newConfigName.open(QIODevice::ReadWrite | QIODevice::Text);
    QTextStream flux2(&newConfigName);
    for(int i=0;i<list.length();i++)
    {
        flux2<<list[i]<<endl;
    }
    newConfigName.close();
    OuvrirEditeur(QString("../RTKBASE/ConfFiles/Custom").append(QString::number(numSauve)).append(".ubx"));
}

void ChoixEdite::Affiche()
{
    this->show();
    MAJNoms();
}

void ChoixEdite::MAJNoms()
{
    QFile configName(QString("../RTKBASE/data/ConfigNames"));
    configName.open(QIODevice::ReadOnly | QIODevice::Text);
    QString line;
    QStringList list;
    QTextStream flux(&configName);
    while(! flux.atEnd())
    {
        line = flux.readLine();
        qDebug()<<line;
        list<<line;
    }
    configName.close();
    ui->Custom1Button->setText(list[0].simplified());
    ui->Custom2Button->setText(list[1].simplified());
    ui->Custom3Button->setText(list[2].simplified());
    ui->Custom4Button->setText(list[3].simplified());
    ui->Custom5Button->setText(list[4].simplified());
    ui->Custom6Button->setText(list[5].simplified());
    ui->Custom7Button->setText(list[6].simplified());
    ui->Custom8Button->setText(list[7].simplified());
    ui->Custom9Button->setText(list[8].simplified());
    ui->Custom10Button->setText(list[9].simplified());
    ui->Custom11Button->setText(list[10].simplified());
    ui->Custom12Button->setText(list[11].simplified());
}

void ChoixEdite::FermeTout()
{
    emit DemandeFerme();
    this->close();
}
