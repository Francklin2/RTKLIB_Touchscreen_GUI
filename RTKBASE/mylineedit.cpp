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


#include "mylineedit.h"
#include "ui_mylineedit.h"
#include "clavier.h"
#include <QFocusEvent>

MyLineEdit::MyLineEdit(QWidget *parent)
 : QLineEdit(parent)
{}

MyLineEdit::~MyLineEdit()
{}

void MyLineEdit::focusInEvent(QFocusEvent *e)
{
    if (e->reason() == Qt::MouseFocusReason)
        {
        Clavier *NouveauClavier = new Clavier(this->text(),QString(""));
        QObject::connect(NouveauClavier,SIGNAL(Texte(QString)),this,SLOT(setText(QString)));
        NouveauClavier->setWindowFlags(Qt::FramelessWindowHint);
        NouveauClavier->setModal(true);
        NouveauClavier->exec();
        }
    QLineEdit::focusInEvent(e);
}

