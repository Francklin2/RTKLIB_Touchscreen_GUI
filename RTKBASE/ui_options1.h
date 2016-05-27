/********************************************************************************
** Form generated from reading UI file 'options1.ui'
**
** Created: Thu May 26 23:29:45 2016
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONS1_H
#define UI_OPTIONS1_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Options1
{
public:
    QPushButton *SingleButton;
    QPushButton *PPPButton;
    QPushButton *DGPSButton;
    QPushButton *RTKButton;
    QPushButton *RTKButton_2;
    QPushButton *SBASButton;

    void setupUi(QDialog *Options1)
    {
        if (Options1->objectName().isEmpty())
            Options1->setObjectName(QString::fromUtf8("Options1"));
        Options1->resize(800, 152);
        SingleButton = new QPushButton(Options1);
        SingleButton->setObjectName(QString::fromUtf8("SingleButton"));
        SingleButton->setGeometry(QRect(10, 20, 121, 111));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        SingleButton->setFont(font);
        PPPButton = new QPushButton(Options1);
        PPPButton->setObjectName(QString::fromUtf8("PPPButton"));
        PPPButton->setGeometry(QRect(400, 20, 121, 111));
        PPPButton->setFont(font);
        DGPSButton = new QPushButton(Options1);
        DGPSButton->setObjectName(QString::fromUtf8("DGPSButton"));
        DGPSButton->setGeometry(QRect(270, 20, 121, 111));
        DGPSButton->setFont(font);
        RTKButton = new QPushButton(Options1);
        RTKButton->setObjectName(QString::fromUtf8("RTKButton"));
        RTKButton->setGeometry(QRect(530, 20, 121, 111));
        RTKButton->setFont(font);
        RTKButton_2 = new QPushButton(Options1);
        RTKButton_2->setObjectName(QString::fromUtf8("RTKButton_2"));
        RTKButton_2->setGeometry(QRect(660, 20, 131, 111));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        RTKButton_2->setFont(font1);
        SBASButton = new QPushButton(Options1);
        SBASButton->setObjectName(QString::fromUtf8("SBASButton"));
        SBASButton->setGeometry(QRect(140, 22, 121, 111));
        SBASButton->setFont(font);

        retranslateUi(Options1);

        QMetaObject::connectSlotsByName(Options1);
    } // setupUi

    void retranslateUi(QDialog *Options1)
    {
        Options1->setWindowTitle(QApplication::translate("Options1", "Dialog", 0, QApplication::UnicodeUTF8));
        SingleButton->setText(QApplication::translate("Options1", "SINGLE", 0, QApplication::UnicodeUTF8));
        PPPButton->setText(QApplication::translate("Options1", "PPP STATIC", 0, QApplication::UnicodeUTF8));
        DGPSButton->setText(QApplication::translate("Options1", "DGPS", 0, QApplication::UnicodeUTF8));
        RTKButton->setText(QApplication::translate("Options1", "RTK STATIC", 0, QApplication::UnicodeUTF8));
        RTKButton_2->setText(QApplication::translate("Options1", "RTK KINEMATIC", 0, QApplication::UnicodeUTF8));
        SBASButton->setText(QApplication::translate("Options1", "SBAS", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Options1: public Ui_Options1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONS1_H
