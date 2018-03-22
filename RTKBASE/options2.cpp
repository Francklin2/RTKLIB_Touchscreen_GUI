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


#include "options2.h"
#include "ui_options2.h"
#include "affichesolutions.h"
#include <stdlib.h>
#include<iostream>

using namespace std;

Options2::Options2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Options2)
{
    ui->setupUi(this);

    QObject::connect(ui->CoordonneesButton,SIGNAL(clicked()),this,SLOT(emitSat()));
    QObject::connect(ui->satStatusButton,SIGNAL(clicked()),this,SLOT(emitSat1()));
    QObject::connect(ui->NavidataButton,SIGNAL(clicked()),this,SLOT(emitSat2()));
    QObject::connect(ui->StreamButton,SIGNAL(clicked()),this,SLOT(emitSat5()));
    QObject::connect(ui->StopButton,SIGNAL(clicked()),this,SLOT(emitSat4()));
    QObject::connect(ui->CoordonneesButton2,SIGNAL(clicked()),this,SLOT(emitSat6()));

}

Options2::~Options2()
{
    delete ui;
}


void Options2::emitSat()
{
    emit Options2emit(2);
    this->close();
}

void Options2::emitSat1()
{
    emit Options2emit(1);
    this->close();
}

void Options2::emitSat2()
{
    emit Options2emit(3);
    this->close();
}

void Options2::emitSat4()
{
    emit Options2emit(4);
    this->close();
}

void Options2::emitSat5()
{
    emit Options2emit(5);
    this->close();
}

void Options2::emitSat6()
{
    emit Options2emit(6);
    this->close();
}
