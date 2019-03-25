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


#include "optionsstartatboot.h"
#include "ui_optionsstartatboot.h"

#include <QFileDialog>
#include <QTextStream>
#include <QFile>
#include <fstream>

QString Startup_Mode;
QString Mode_at_Boot;
QString Rover_Config;


optionsstartatboot::optionsstartatboot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::optionsstartatboot)
{
    ui->setupUi(this);

    QObject::connect(ui->CancelButton,SIGNAL(clicked()),this,SLOT(Cancel()));
    QObject::connect(ui->SaveButton,SIGNAL(clicked()),this,SLOT(Save()));

    // Open startup options configuration file

        {
        int i=1;
        QStringList list;
        QString fileName = "saveoptionstartatboot.txt";
        QFile readoption(fileName);
        readoption.open(QIODevice::ReadOnly | QIODevice::Text);
        //---------verifier ouverture fichier......
        QTextStream flux(&readoption);
        QString ligne;
        while(! flux.atEnd())
        {
           ligne = flux.readLine();
           //traitement de la ligne
           list<<ligne;
           i=i+1;
       }


    Startup_Mode = list[0];
    Mode_at_Boot = list[1];
    Rover_Config = list[2];

    readoption.close();
    }

int StartupIndex;
int ModeIndex;
int RoverIndex;

if(Startup_Mode=="OFF"){StartupIndex=0;}
if(Startup_Mode=="ON"){StartupIndex=1;}
if(Mode_at_Boot=="ROVER"){ModeIndex=0;}
if(Mode_at_Boot=="BASE"){ModeIndex=1;}
if(Rover_Config=="SINGLE"){RoverIndex=0;}
if(Rover_Config=="SBAS"){RoverIndex=1;}
if(Rover_Config=="DGPS"){RoverIndex=2;}
if(Rover_Config=="PPP STATIC"){RoverIndex=3;}
if(Rover_Config=="RTK STATIC"){RoverIndex=4;}
if(Rover_Config=="RTK KINE"){RoverIndex=5;}
if(Rover_Config=="CUSTOM 1"){RoverIndex=6;}


ui->Startatboot_comboBox->setCurrentIndex(StartupIndex);
ui->ChooseMode_comboBox->setCurrentIndex(ModeIndex);
ui->RoverMode_comboBox->setCurrentIndex(RoverIndex);

}

optionsstartatboot::~optionsstartatboot()
{
    delete ui;
}


void optionsstartatboot::Cancel()
{
    this->close();
}

void optionsstartatboot::Save()
{

    /* Save options for auto start mode at boot */

      Startup_Mode = ui->Startatboot_comboBox->currentText();
       Mode_at_Boot = ui->ChooseMode_comboBox->currentText();
       Rover_Config = ui->RoverMode_comboBox->currentText();



       std::ofstream q("saveoptionstartatboot.txt");
         QFile optionstartatboot("saveoptionstartatboot.txt");
         optionstartatboot.open(QIODevice::Append | QIODevice::Text);
         QTextStream outboot(&optionstartatboot);
      {
         outboot<<Startup_Mode<<endl;
         outboot<<Mode_at_Boot<<endl;
         outboot<<Rover_Config<<endl;




         }



      optionstartatboot.close();






}
