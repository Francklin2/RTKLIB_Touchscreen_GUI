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
