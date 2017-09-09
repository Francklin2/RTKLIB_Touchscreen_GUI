#include "choixconfig.h"
#include "ui_choixconfig.h"
#include "affichesolutions.h"
#include "choixedite.h"
#include "gestionconfig.h"
#include <iostream>

ChoixConfig::ChoixConfig(int _rover_edit, QWidget *parent):
    QDialog(parent),
    ui(new Ui::ChoixConfig)
{
    ui->setupUi(this);
    rover_edit=_rover_edit;

    this->setWindowFlags(Qt::Window);
    this->showFullScreen();

    if(rover_edit==0) ui->WindowTitleEdit->setText(QString("CONFIGURATION CHOICE"));
    else ui->WindowTitleEdit->setText(QString("MODELE CHOICE"));

    QObject::connect(ui->SingleButton,SIGNAL(clicked()),this,SLOT(ouvreSingle()));
    QObject::connect(ui->SBASButton,SIGNAL(clicked()),this,SLOT(ouvreSBAS()));
    QObject::connect(ui->DGPSButton,SIGNAL(clicked()),this,SLOT(ouvreDGPS()));
    QObject::connect(ui->PPPButton,SIGNAL(clicked()),this,SLOT(ouvrePPP()));
    QObject::connect(ui->RTKButton,SIGNAL(clicked()),this,SLOT(ouvreRTKstatic()));
    QObject::connect(ui->RTKButton_2,SIGNAL(clicked()),this,SLOT(ouvreRTKkinematic()));

    QObject::connect(ui->Custom1Button,SIGNAL(clicked()),this,SLOT(OuvreConfig1()));
    QObject::connect(ui->Custom2Button,SIGNAL(clicked()),this,SLOT(OuvreConfig2()));
    QObject::connect(ui->Custom3Button,SIGNAL(clicked()),this,SLOT(OuvreConfig3()));
    QObject::connect(ui->Custom4Button,SIGNAL(clicked()),this,SLOT(OuvreConfig4()));
    QObject::connect(ui->Custom5Button,SIGNAL(clicked()),this,SLOT(OuvreConfig5()));
    QObject::connect(ui->Custom6Button,SIGNAL(clicked()),this,SLOT(OuvreConfig6()));
    QObject::connect(ui->Custom7Button,SIGNAL(clicked()),this,SLOT(OuvreConfig7()));
    QObject::connect(ui->Custom8Button,SIGNAL(clicked()),this,SLOT(OuvreConfig8()));
    QObject::connect(ui->Custom9Button,SIGNAL(clicked()),this,SLOT(OuvreConfig9()));
    QObject::connect(ui->Custom10Button,SIGNAL(clicked()),this,SLOT(OuvreConfig10()));
    QObject::connect(ui->Custom11Button,SIGNAL(clicked()),this,SLOT(OuvreConfig11()));
    QObject::connect(ui->Custom12Button,SIGNAL(clicked()),this,SLOT(OuvreConfig12()));

    QObject::connect(ui->ReturnButton,SIGNAL(clicked()),this,SLOT(Retour()));

    if(rover_edit==0)
    {
        ui->EditeButton->show();
        QObject::connect(ui->EditeButton,SIGNAL(clicked()),this,SLOT(OuvreEdit()));
    }
    else
    {
        ui->EditeButton->hide();
    }

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

ChoixConfig::~ChoixConfig()
{
    delete ui;
}

void ChoixConfig::OuvreAfficheSolutions(QString configFile)
{
    AfficheSolutions SingleRoverSolutions(configFile);
    this->close();
    SingleRoverSolutions.showFullScreen();// NE FONCTIONNE PAS, NE CHANGE RIEN...
    SingleRoverSolutions.exec();
}

void ChoixConfig::OuvreChoixEdit(QString modeleFile)
{
    ChoixEdite *FenetreChoixEdit = new ChoixEdite(modeleFile);
    QObject::connect(FenetreChoixEdit,SIGNAL(DemandeRetour()),this,SLOT(Affiche()));
    QObject::connect(FenetreChoixEdit,SIGNAL(DemandeFerme()),this,SLOT(FermeTout()));
    this->hide();
    FenetreChoixEdit->setWindowFlags(Qt::FramelessWindowHint);
    FenetreChoixEdit->exec();
}

void ChoixConfig::ouvreSingle()
{
    if(rover_edit==0) OuvreAfficheSolutions(QString("../RTKBASE/ConfFiles/Single.ubx"));
    else OuvreChoixEdit(QString("../RTKBASE/ConfFiles/Single.ubx"));
}

void ChoixConfig::ouvreSBAS()
{
    if(rover_edit==0) OuvreAfficheSolutions(QString("../RTKBASE/ConfFiles/SBAS.ubx"));
    else OuvreChoixEdit(QString("../RTKBASE/ConfFiles/SBAS.ubx"));
}

void ChoixConfig::ouvreDGPS()
{
    if(rover_edit==0) OuvreAfficheSolutions(QString("../RTKBASE/ConfFiles/DGPS.ubx"));
    else OuvreChoixEdit(QString("../RTKBASE/ConfFiles/DGPS.ubx"));
}

void ChoixConfig::ouvrePPP()
{
    if(rover_edit==0) OuvreAfficheSolutions(QString("../RTKBASE/ConfFiles/PPP-Static.ubx"));
    else OuvreChoixEdit(QString("../RTKBASE/ConfFiles/PPP-Static.ubx"));
}

void ChoixConfig::ouvreRTKstatic()
{
    if(rover_edit==0) OuvreAfficheSolutions(QString("../RTKBASE/ConfFiles/RTK-Static.ubx"));
    else OuvreChoixEdit(QString("../RTKBASE/ConfFiles/RTK-Static.ubx"));
}

void ChoixConfig::ouvreRTKkinematic()
{
    if(rover_edit==0) OuvreAfficheSolutions(QString("../RTKBASE/ConfFiles/RTK-Kinematic.ubx"));
    else OuvreChoixEdit(QString("../RTKBASE/ConfFiles/RTK-Kinematic.ubx"));
}

void ChoixConfig::OuvreConfig1()
{
    if(rover_edit==0) OuvreAfficheSolutions(QString("../RTKBASE/ConfFiles/Custom1.ubx"));
    else OuvreChoixEdit(QString("../RTKBASE/ConfFiles/Custom1.ubx"));
}

void ChoixConfig::OuvreConfig2()
{
    if(rover_edit==0) OuvreAfficheSolutions(QString("../RTKBASE/ConfFiles/Custom2.ubx"));
    else OuvreChoixEdit(QString("../RTKBASE/ConfFiles/Custom2.ubx"));
}

void ChoixConfig::OuvreConfig3()
{
    if(rover_edit==0) OuvreAfficheSolutions(QString("../RTKBASE/ConfFiles/Custom3.ubx"));
    else OuvreChoixEdit(QString("../RTKBASE/ConfFiles/Custom3.ubx"));
}

void ChoixConfig::OuvreConfig4()
{
    if(rover_edit==0) OuvreAfficheSolutions(QString("../RTKBASE/ConfFiles/Custom4.ubx"));
    else OuvreChoixEdit(QString("../RTKBASE/ConfFiles/Custom4.ubx"));
}

void ChoixConfig::OuvreConfig5()
{
    if(rover_edit==0) OuvreAfficheSolutions(QString("../RTKBASE/ConfFiles/Custom5.ubx"));
    else OuvreChoixEdit(QString("../RTKBASE/ConfFiles/Custom5.ubx"));
}

void ChoixConfig::OuvreConfig6()
{
    if(rover_edit==0) OuvreAfficheSolutions(QString("../RTKBASE/ConfFiles/Custom6.ubx"));
    else OuvreChoixEdit(QString("../RTKBASE/ConfFiles/Custom6.ubx"));
}

void ChoixConfig::OuvreConfig7()
{
    if(rover_edit==0) OuvreAfficheSolutions(QString("../RTKBASE/ConfFiles/Custom7.ubx"));
    else OuvreChoixEdit(QString("../RTKBASE/ConfFiles/Custom7.ubx"));
}

void ChoixConfig::OuvreConfig8()
{
    if(rover_edit==0) OuvreAfficheSolutions(QString("../RTKBASE/ConfFiles/Custom8.ubx"));
    else OuvreChoixEdit(QString("../RTKBASE/ConfFiles/Custom8.ubx"));
}

void ChoixConfig::OuvreConfig9()
{
    if(rover_edit==0) OuvreAfficheSolutions(QString("../RTKBASE/ConfFiles/Custom9.ubx"));
    else OuvreChoixEdit(QString("../RTKBASE/ConfFiles/Custom9.ubx"));
}

void ChoixConfig::OuvreConfig10()
{
    if(rover_edit==0) OuvreAfficheSolutions(QString("../RTKBASE/ConfFiles/Custom10.ubx"));
    else OuvreChoixEdit(QString("../RTKBASE/ConfFiles/Custom10.ubx"));
}

void ChoixConfig::OuvreConfig11()
{
    if(rover_edit==0) OuvreAfficheSolutions(QString("../RTKBASE/ConfFiles/Custom11.ubx"));
    else OuvreChoixEdit(QString("../RTKBASE/ConfFiles/Custom11.ubx"));
}

void ChoixConfig::OuvreConfig12()
{
    if(rover_edit==0) OuvreAfficheSolutions(QString("../RTKBASE/ConfFiles/Custom12.ubx"));
    else OuvreChoixEdit(QString("../RTKBASE/ConfFiles/Custom12.ubx"));
}

void ChoixConfig::OuvreEdit()
{
    GestionConfig *FenetreGestionConfig=new GestionConfig();
    QObject::connect(FenetreGestionConfig,SIGNAL(DemandeMAJ()),this,SLOT(FermeTout()));
    FenetreGestionConfig->setModal(true);
    FenetreGestionConfig->setWindowFlags(Qt::FramelessWindowHint);
    FenetreGestionConfig->exec();
}

void ChoixConfig::Retour()
{
    if(rover_edit!=0)
    {
        /*GestionConfig *FenetreGestionConfig=new GestionConfig();
        FenetreGestionConfig->setModal(true);
        FenetreGestionConfig->setWindowFlags(Qt::FramelessWindowHint);
        FenetreGestionConfig->exec();*/
        emit DemandeRetour();
    }
    this->close();
}

void ChoixConfig::MAJNoms()
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

void ChoixConfig::Affiche()
{
    this->show();
    MAJNoms();
}

void ChoixConfig::FermeTout()
{
    if(rover_edit==0) MAJNoms();
    else
    {
        emit DemandeFerme();
        this->close();
    }
}
