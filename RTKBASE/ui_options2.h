/********************************************************************************
** Form generated from reading UI file 'options2.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONS2_H
#define UI_OPTIONS2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

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
            Options2->setObjectName(QStringLiteral("Options2"));
        Options2->setWindowModality(Qt::NonModal);
        Options2->resize(800, 155);
        Options2->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
""));
        Options2->setModal(true);
        satStatusButton = new QPushButton(Options2);
        satStatusButton->setObjectName(QStringLiteral("satStatusButton"));
        satStatusButton->setGeometry(QRect(250, 10, 111, 121));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        satStatusButton->setFont(font);
        satStatusButton->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        CoordonneesButton = new QPushButton(Options2);
        CoordonneesButton->setObjectName(QStringLiteral("CoordonneesButton"));
        CoordonneesButton->setGeometry(QRect(10, 10, 111, 121));
        CoordonneesButton->setFont(font);
        CoordonneesButton->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        NavidataButton = new QPushButton(Options2);
        NavidataButton->setObjectName(QStringLiteral("NavidataButton"));
        NavidataButton->setGeometry(QRect(490, 10, 141, 121));
        NavidataButton->setFont(font);
        NavidataButton->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        StreamButton = new QPushButton(Options2);
        StreamButton->setObjectName(QStringLiteral("StreamButton"));
        StreamButton->setGeometry(QRect(370, 10, 111, 121));
        StreamButton->setFont(font);
        StreamButton->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        StreamButton->setAutoDefault(false);
        StopButton = new QPushButton(Options2);
        StopButton->setObjectName(QStringLiteral("StopButton"));
        StopButton->setGeometry(QRect(650, 10, 111, 121));
        StopButton->setFont(font);
        StopButton->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        CoordonneesButton2 = new QPushButton(Options2);
        CoordonneesButton2->setObjectName(QStringLiteral("CoordonneesButton2"));
        CoordonneesButton2->setGeometry(QRect(130, 10, 111, 121));
        CoordonneesButton2->setFont(font);
        CoordonneesButton2->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));

        retranslateUi(Options2);

        StreamButton->setDefault(true);


        QMetaObject::connectSlotsByName(Options2);
    } // setupUi

    void retranslateUi(QDialog *Options2)
    {
        Options2->setWindowTitle(QApplication::translate("Options2", "Options Choice", Q_NULLPTR));
        satStatusButton->setText(QApplication::translate("Options2", "SATELLITES", Q_NULLPTR));
        CoordonneesButton->setText(QApplication::translate("Options2", "STATUS", Q_NULLPTR));
        NavidataButton->setText(QApplication::translate("Options2", "EVOLUTION", Q_NULLPTR));
        StreamButton->setText(QApplication::translate("Options2", "STREAM", Q_NULLPTR));
        StopButton->setText(QApplication::translate("Options2", "STOP", Q_NULLPTR));
        CoordonneesButton2->setText(QApplication::translate("Options2", "POSITION", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Options2: public Ui_Options2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONS2_H
