#include "optionssauvepoints.h"
#include "ui_optionssauvepoints.h"

#include <QFileDialog>
#include <QTextStream>
#include <QFile>

optionssauvepoints::optionssauvepoints(QString filePath,QString pointName, int nummeas, float cyclen, int oldpoint,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::optionssauvepoints)
{
    ui->setupUi(this);

    ui->FilepathLine->setText(filePath);
    ui->PointnameLine->setText(pointName);
    ui->NummeasBox->setEditText(QString::number(nummeas));
    ui->CyclenBox->setEditText(QString::number(cyclen));
    ui->OldpointBox->setCurrentIndex(oldpoint);


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
    emit SaveOptions(options);

    QFile sauveOptionFile(QString("../RTKBASE/data/SauveOptions"));
    QTextStream flux(&sauveOptionFile);
    sauveOptionFile.open(QFile::ReadWrite|QFile::Truncate);
    flux<<qSetFieldWidth(20)<<left<<"filepath"<<qSetFieldWidth(0)<<"="<<ui->FilepathLine->text()<<endl;
    flux<<qSetFieldWidth(20)<<left<<"pointname"<<qSetFieldWidth(0)<<"="<<ui->PointnameLine->text()<<endl;
    flux<<qSetFieldWidth(20)<<left<<"nummeas"<<qSetFieldWidth(0)<<"="<<ui->NummeasBox->currentText()<<endl;
    flux<<qSetFieldWidth(20)<<left<<"cyclen"<<qSetFieldWidth(0)<<"="<<ui->CyclenBox->currentText()<<endl;
    flux<<qSetFieldWidth(20)<<left<<"oldpoint"<<qSetFieldWidth(0)<<"="<<ui->OldpointBox->currentIndex()<<endl;
    sauveOptionFile.close();
    this->close();
}

void optionssauvepoints::ChoixFilepath()
{
    QString filePath = QFileDialog::getSaveFileName(this,tr("Measure File"),"../RTKBASE/PointsFiles",tr("Text Files (*.txt);;All Files (*)"));
    if (filePath!="") ui->FilepathLine->setText(filePath);

}
