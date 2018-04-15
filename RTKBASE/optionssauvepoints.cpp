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


#include "optionssauvepoints.h"
#include "ui_optionssauvepoints.h"

#include <QFileDialog>
#include <QTextStream>
#include <QFile>

optionssauvepoints::optionssauvepoints(QString filePath,QString pointName, int nummeas, float cyclen, int oldpoint,QString EPSG,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::optionssauvepoints)
{
    ui->setupUi(this);

    ui->FilepathLine->setText(filePath);
    ui->PointnameLine->setText(pointName);
    ui->NummeasBox->setEditText(QString::number(nummeas));
    ui->CyclenBox->setEditText(QString::number(cyclen));
    ui->OldpointBox->setCurrentIndex(oldpoint);
    ui->EPSG_comboBox->setCurrentText(EPSG);

    QObject::connect(ui->CancelButton,SIGNAL(clicked()),this,SLOT(Cancel()));
    QObject::connect(ui->SaveButton,SIGNAL(clicked()),this,SLOT(Save()));

    QObject::connect(ui->FilepathButton,SIGNAL(clicked()),this,SLOT(ChoixFilepath()));
}

optionssauvepoints::~optionssauvepoints()
{
    delete ui;
}

void optionssauvepoints::Cancel()
{
    this->close();
}

void optionssauvepoints::Save()
{
    QStringList options = QStringList();
    options<<ui->FilepathLine->text();
    options<<ui->PointnameLine->text();
    options<<ui->NummeasBox->currentText();
    options<<ui->CyclenBox->currentText();
    options<<QString::number(ui->OldpointBox->currentIndex());
    options<<ui->EPSG_comboBox->currentText();
    emit SaveOptions(options);

    QFile sauveOptionFile(QString("../RTKBASE/data/SauveOptions"));
    QTextStream flux(&sauveOptionFile);
    sauveOptionFile.open(QFile::ReadWrite|QFile::Truncate);
    flux<<qSetFieldWidth(20)<<left<<"filepath"<<qSetFieldWidth(0)<<"="<<ui->FilepathLine->text()<<endl;
    flux<<qSetFieldWidth(20)<<left<<"pointname"<<qSetFieldWidth(0)<<"="<<ui->PointnameLine->text()<<endl;
    flux<<qSetFieldWidth(20)<<left<<"nummeas"<<qSetFieldWidth(0)<<"="<<ui->NummeasBox->currentText()<<endl;
    flux<<qSetFieldWidth(20)<<left<<"cyclen"<<qSetFieldWidth(0)<<"="<<ui->CyclenBox->currentText()<<endl;
    flux<<qSetFieldWidth(20)<<left<<"oldpoint"<<qSetFieldWidth(0)<<"="<<ui->OldpointBox->currentIndex()<<endl;
    flux<<qSetFieldWidth(20)<<left<<"EPSG"<<qSetFieldWidth(0)<<"="<<ui->EPSG_comboBox->currentText()<<endl;
    sauveOptionFile.close();
    this->close();
}

void optionssauvepoints::ChoixFilepath()
{
    QString filePath = QFileDialog::getSaveFileName(this,tr("Measure File"),"../RTKBASE/PointsFiles",tr("Text Files (*.txt);;All Files (*)"));
    if (filePath!="") ui->FilepathLine->setText(filePath);

}
