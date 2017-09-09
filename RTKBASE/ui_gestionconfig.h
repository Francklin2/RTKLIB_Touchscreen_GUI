/********************************************************************************
** Form generated from reading UI file 'gestionconfig.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTIONCONFIG_H
#define UI_GESTIONCONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_GestionConfig
{
public:
    QPushButton *EditButton;
    QPushButton *ReturnButton;
    QPushButton *NewButton;

    void setupUi(QDialog *GestionConfig)
    {
        if (GestionConfig->objectName().isEmpty())
            GestionConfig->setObjectName(QStringLiteral("GestionConfig"));
        GestionConfig->resize(800, 150);
        EditButton = new QPushButton(GestionConfig);
        EditButton->setObjectName(QStringLiteral("EditButton"));
        EditButton->setGeometry(QRect(320, 20, 250, 110));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        EditButton->setFont(font);
        EditButton->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        ReturnButton = new QPushButton(GestionConfig);
        ReturnButton->setObjectName(QStringLiteral("ReturnButton"));
        ReturnButton->setGeometry(QRect(650, 20, 120, 110));
        ReturnButton->setFont(font);
        ReturnButton->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        NewButton = new QPushButton(GestionConfig);
        NewButton->setObjectName(QStringLiteral("NewButton"));
        NewButton->setGeometry(QRect(30, 20, 250, 110));
        NewButton->setFont(font);
        NewButton->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));

        retranslateUi(GestionConfig);

        QMetaObject::connectSlotsByName(GestionConfig);
    } // setupUi

    void retranslateUi(QDialog *GestionConfig)
    {
        GestionConfig->setWindowTitle(QApplication::translate("GestionConfig", "Dialog", Q_NULLPTR));
        EditButton->setText(QApplication::translate("GestionConfig", "EDIT CONFIGURATION", Q_NULLPTR));
        ReturnButton->setText(QApplication::translate("GestionConfig", "Return", Q_NULLPTR));
        NewButton->setText(QApplication::translate("GestionConfig", "NEW CONFIGURATION", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GestionConfig: public Ui_GestionConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTIONCONFIG_H
