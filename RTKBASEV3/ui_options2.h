/********************************************************************************
** Form generated from reading UI file 'options2.ui'
**
** Created: Mon May 16 01:18:50 2016
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONS2_H
#define UI_OPTIONS2_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Options2
{
public:
    QPushButton *satStatusButton;
    QPushButton *CoordonneesButton;
    QPushButton *NavidataButton;
    QPushButton *StreamButton;
    QPushButton *StopButton;
    QPushButton *CoordonneesButton2;

    void setupUi(QDialog *Options2)
    {
        if (Options2->objectName().isEmpty())
            Options2->setObjectName(QString::fromUtf8("Options2"));
        Options2->setWindowModality(Qt::NonModal);
        Options2->resize(800, 155);
        Options2->setModal(true);
        satStatusButton = new QPushButton(Options2);
        satStatusButton->setObjectName(QString::fromUtf8("satStatusButton"));
        satStatusButton->setGeometry(QRect(250, 10, 111, 121));
        CoordonneesButton = new QPushButton(Options2);
        CoordonneesButton->setObjectName(QString::fromUtf8("CoordonneesButton"));
        CoordonneesButton->setGeometry(QRect(10, 10, 111, 121));
        NavidataButton = new QPushButton(Options2);
        NavidataButton->setObjectName(QString::fromUtf8("NavidataButton"));
        NavidataButton->setGeometry(QRect(490, 10, 111, 121));
        StreamButton = new QPushButton(Options2);
        StreamButton->setObjectName(QString::fromUtf8("StreamButton"));
        StreamButton->setGeometry(QRect(370, 10, 111, 121));
        StreamButton->setAutoDefault(false);
        StreamButton->setDefault(true);
        StopButton = new QPushButton(Options2);
        StopButton->setObjectName(QString::fromUtf8("StopButton"));
        StopButton->setGeometry(QRect(650, 10, 111, 121));
        CoordonneesButton2 = new QPushButton(Options2);
        CoordonneesButton2->setObjectName(QString::fromUtf8("CoordonneesButton2"));
        CoordonneesButton2->setGeometry(QRect(130, 10, 111, 121));

        retranslateUi(Options2);

        QMetaObject::connectSlotsByName(Options2);
    } // setupUi

    void retranslateUi(QDialog *Options2)
    {
        Options2->setWindowTitle(QApplication::translate("Options2", "Options Choice", 0, QApplication::UnicodeUTF8));
        satStatusButton->setText(QApplication::translate("Options2", "Satellites", 0, QApplication::UnicodeUTF8));
        CoordonneesButton->setText(QApplication::translate("Options2", "Coord", 0, QApplication::UnicodeUTF8));
        NavidataButton->setText(QApplication::translate("Options2", "Evolution Pos", 0, QApplication::UnicodeUTF8));
        StreamButton->setText(QApplication::translate("Options2", "Stream", 0, QApplication::UnicodeUTF8));
        StopButton->setText(QApplication::translate("Options2", "Stop", 0, QApplication::UnicodeUTF8));
        CoordonneesButton2->setText(QApplication::translate("Options2", "Coord2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Options2: public Ui_Options2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONS2_H
