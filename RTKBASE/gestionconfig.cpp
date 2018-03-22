// RTKBASE is a GUI interface for RTKLIB made for the Raspberry pî and a touchscreen
//   Copyright (C) 2016
//   David ENSG PPMD-2016 (first rtkbase release)
//   Francklin N'guyen van <francklin2@wanadoo.fr>
//   Sylvain Poulain <sylvain.poulain@giscan.com>
//   Vladimir ENSG PPMD-2017 (editable configuration)
//   Saif Aati ENSG PPMD-2018 (post processing)
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.


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
