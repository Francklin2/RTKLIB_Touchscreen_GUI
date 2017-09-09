#include "options1.h"
#include "ui_options1.h"
#include <QDialog>
#include "affichesolutions.h"

#include "affichestr2str.h"
#include "optionsstr2str.h"

int choixcalcul;    // A mettre dans la classe et le remplir dans les ouvrir...() -> rajouter dans le constructeur
                    // de AfficheSolutions

Options1::Options1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Options1)
{
    ui->setupUi(this);
    QObject::connect(ui->SingleButton,SIGNAL(clicked()),this,SLOT(ouvreSingle()));
    QObject::connect(ui->SBASButton,SIGNAL(clicked()),this,SLOT(ouvreSBAS()));
    QObject::connect(ui->DGPSButton,SIGNAL(clicked()),this,SLOT(ouvreDGPS()));
    QObject::connect(ui->PPPButton,SIGNAL(clicked()),this,SLOT(ouvrePPP()));
    QObject::connect(ui->RTKButton,SIGNAL(clicked()),this,SLOT(ouvreRTKstatic()));
    QObject::connect(ui->RTKButton_2,SIGNAL(clicked()),this,SLOT(ouvreRTKkinematic()));



}

Options1::~Options1()
{
    delete ui;
}


void Options1::ouvreSingle()
{
     choixcalcul=1;

       AfficheSolutions *SingleRoverSolutions=new AfficheSolutions();
       this->hide();
       SingleRoverSolutions->showFullScreen();// NE FONCTIONNE PAS, NE CHANGE RIEN...
       SingleRoverSolutions->exec();
}

void Options1::ouvreSBAS()
{
    choixcalcul=2;


    AfficheSolutions *SingleRoverSolutions=new AfficheSolutions();
    this->hide();
    SingleRoverSolutions->showFullScreen();// NE FONCTIONNE PAS, NE CHANGE RIEN...
    SingleRoverSolutions->exec();   
}

void Options1::ouvreDGPS()
{
    choixcalcul=3;


       AfficheSolutions *SingleRoverSolutions=new AfficheSolutions();
       this->hide();
       SingleRoverSolutions->showFullScreen();// NE FONCTIONNE PAS, NE CHANGE RIEN...
       SingleRoverSolutions->exec();
}

void Options1::ouvrePPP()
{
    choixcalcul=4;


       AfficheSolutions *SingleRoverSolutions=new AfficheSolutions();
       this->hide();
       SingleRoverSolutions->showFullScreen();// NE FONCTIONNE PAS, NE CHANGE RIEN...
       SingleRoverSolutions->exec();
}

void Options1::ouvreRTKstatic()
{
    choixcalcul=5;

       AfficheSolutions *SingleRoverSolutions=new AfficheSolutions();
       this->hide();
       SingleRoverSolutions->showFullScreen();// NE FONCTIONNE PAS, NE CHANGE RIEN...
       SingleRoverSolutions->exec();
}

void Options1::ouvreRTKkinematic()
{
    choixcalcul=6;

       AfficheSolutions *SingleRoverSolutions=new AfficheSolutions();
       this->hide();
       SingleRoverSolutions->showFullScreen();// NE FONCTIONNE PAS, NE CHANGE RIEN...
       SingleRoverSolutions->exec();
}

