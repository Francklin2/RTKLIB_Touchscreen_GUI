#include "gestionconfig.h"
#include "ui_gestionconfig.h"
#include "choixedite.h"
#include "choixconfig.h"

GestionConfig::GestionConfig(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GestionConfig)
{
    ui->setupUi(this);

    QObject::connect(ui->EditButton,SIGNAL(clicked()),this,SLOT(OuvreChoixEdit()));
    QObject::connect(ui->NewButton,SIGNAL(clicked()),this,SLOT(OuvreChoixNouveau()));
    QObject::connect(ui->ReturnButton,SIGNAL(clicked()),this,SLOT(Retour()));
}

GestionConfig::~GestionConfig()
{
    delete ui;
}

void GestionConfig::OuvreChoixNouveau()
{
    ChoixConfig *FenetreChoixConfigNouveau = new ChoixConfig(1);
    QObject::connect(FenetreChoixConfigNouveau,SIGNAL(DemandeRetour()),this,SLOT(Affiche()));
    QObject::connect(FenetreChoixConfigNouveau,SIGNAL(DemandeFerme()),this,SLOT(Retour()));
    this->hide();
    //FenetreChoixConfigNouveau->setModal(true);
    FenetreChoixConfigNouveau->exec();
}

void GestionConfig::OuvreChoixEdit()
{
    ChoixEdite *FenetreChoixEdit = new ChoixEdite(QString(""));
    QObject::connect(FenetreChoixEdit,SIGNAL(DemandeRetour()),this,SLOT(Affiche()));
    QObject::connect(FenetreChoixEdit,SIGNAL(DemandeFerme()),this,SLOT(Retour()));
    this->hide();
    //FenetreChoixEdit.setModal(true);
    FenetreChoixEdit->exec();
}

void GestionConfig::Retour()
{
    emit DemandeMAJ();
    this->close();
}


void GestionConfig::Affiche()
{
    this->show();
}
