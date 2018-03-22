/********************************************************************************
** Form generated from reading UI file 'options1.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONS1_H
#define UI_OPTIONS1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

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
            Options1->setObjectName(QStringLiteral("Options1"));
        Options1->resize(800, 152);
        Options1->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
""));
        SingleButton = new QPushButton(Options1);
        SingleButton->setObjectName(QStringLiteral("SingleButton"));
        SingleButton->setGeometry(QRect(10, 20, 121, 111));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        SingleButton->setFont(font);
        SingleButton->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        PPPButton = new QPushButton(Options1);
        PPPButton->setObjectName(QStringLiteral("PPPButton"));
        PPPButton->setGeometry(QRect(400, 20, 121, 111));
        PPPButton->setFont(font);
        PPPButton->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        DGPSButton = new QPushButton(Options1);
        DGPSButton->setObjectName(QStringLiteral("DGPSButton"));
        DGPSButton->setGeometry(QRect(270, 20, 121, 111));
        DGPSButton->setFont(font);
        DGPSButton->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        RTKButton = new QPushButton(Options1);
        RTKButton->setObjectName(QStringLiteral("RTKButton"));
        RTKButton->setGeometry(QRect(530, 20, 121, 111));
        RTKButton->setFont(font);
        RTKButton->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        RTKButton_2 = new QPushButton(Options1);
        RTKButton_2->setObjectName(QStringLiteral("RTKButton_2"));
        RTKButton_2->setGeometry(QRect(660, 20, 131, 111));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        RTKButton_2->setFont(font1);
        RTKButton_2->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        SBASButton = new QPushButton(Options1);
        SBASButton->setObjectName(QStringLiteral("SBASButton"));
        SBASButton->setGeometry(QRect(140, 20, 121, 111));
        SBASButton->setFont(font);
        SBASButton->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));

        retranslateUi(Options1);

        QMetaObject::connectSlotsByName(Options1);
    } // setupUi

    void retranslateUi(QDialog *Options1)
    {
        Options1->setWindowTitle(QApplication::translate("Options1", "Dialog", 0));
        SingleButton->setText(QApplication::translate("Options1", "SINGLE", 0));
        PPPButton->setText(QApplication::translate("Options1", "PPP STATIC", 0));
        DGPSButton->setText(QApplication::translate("Options1", "DGPS", 0));
        RTKButton->setText(QApplication::translate("Options1", "RTK STATIC", 0));
        RTKButton_2->setText(QApplication::translate("Options1", "RTK KINEMATIC", 0));
        SBASButton->setText(QApplication::translate("Options1", "SBAS", 0));
    } // retranslateUi

};

namespace Ui {
    class Options1: public Ui_Options1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONS1_H
