/********************************************************************************
** Form generated from reading UI file 'optionssauvepoints.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONSSAUVEPOINTS_H
#define UI_OPTIONSSAUVEPOINTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include "mylineedit.h"

QT_BEGIN_NAMESPACE

class Ui_optionssauvepoints
{
public:
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QComboBox *NummeasBox;
    QLabel *label_6;
    QComboBox *CyclenBox;
    QLabel *label_7;
    QComboBox *OldpointBox;
    MyLineEdit *FilepathLine;
    QPushButton *FilepathButton;
    MyLineEdit *PointnameLine;
    QLineEdit *lineEdit;
    QPushButton *CancelButton;
    QPushButton *SaveButton;

    void setupUi(QDialog *optionssauvepoints)
    {
        if (optionssauvepoints->objectName().isEmpty())
            optionssauvepoints->setObjectName(QStringLiteral("optionssauvepoints"));
        optionssauvepoints->resize(500, 330);
        label_3 = new QLabel(optionssauvepoints);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 70, 211, 40));
        label_4 = new QLabel(optionssauvepoints);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 120, 91, 40));
        label_5 = new QLabel(optionssauvepoints);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 170, 151, 40));
        NummeasBox = new QComboBox(optionssauvepoints);
        NummeasBox->setObjectName(QStringLiteral("NummeasBox"));
        NummeasBox->setGeometry(QRect(160, 170, 71, 40));
        NummeasBox->setEditable(true);
        NummeasBox->setFrame(true);
        label_6 = new QLabel(optionssauvepoints);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(250, 170, 111, 40));
        CyclenBox = new QComboBox(optionssauvepoints);
        CyclenBox->setObjectName(QStringLiteral("CyclenBox"));
        CyclenBox->setGeometry(QRect(360, 170, 131, 40));
        CyclenBox->setEditable(true);
        CyclenBox->setFrame(true);
        label_7 = new QLabel(optionssauvepoints);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 220, 81, 40));
        OldpointBox = new QComboBox(optionssauvepoints);
        OldpointBox->setObjectName(QStringLiteral("OldpointBox"));
        OldpointBox->setGeometry(QRect(120, 220, 371, 40));
        OldpointBox->setFrame(true);
        FilepathLine = new MyLineEdit(optionssauvepoints);
        FilepathLine->setObjectName(QStringLiteral("FilepathLine"));
        FilepathLine->setGeometry(QRect(230, 70, 211, 41));
        FilepathButton = new QPushButton(optionssauvepoints);
        FilepathButton->setObjectName(QStringLiteral("FilepathButton"));
        FilepathButton->setGeometry(QRect(450, 70, 40, 40));
        PointnameLine = new MyLineEdit(optionssauvepoints);
        PointnameLine->setObjectName(QStringLiteral("PointnameLine"));
        PointnameLine->setGeometry(QRect(120, 120, 371, 41));
        lineEdit = new QLineEdit(optionssauvepoints);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(120, 10, 270, 40));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        lineEdit->setFont(font);
        lineEdit->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
""));
        lineEdit->setAlignment(Qt::AlignCenter);
        lineEdit->setReadOnly(true);
        CancelButton = new QPushButton(optionssauvepoints);
        CancelButton->setObjectName(QStringLiteral("CancelButton"));
        CancelButton->setGeometry(QRect(10, 280, 230, 41));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        CancelButton->setFont(font1);
        CancelButton->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        SaveButton = new QPushButton(optionssauvepoints);
        SaveButton->setObjectName(QStringLiteral("SaveButton"));
        SaveButton->setGeometry(QRect(260, 280, 230, 41));
        SaveButton->setFont(font1);
        SaveButton->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));

        retranslateUi(optionssauvepoints);

        NummeasBox->setCurrentIndex(0);
        CyclenBox->setCurrentIndex(0);
        OldpointBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(optionssauvepoints);
    } // setupUi

    void retranslateUi(QDialog *optionssauvepoints)
    {
        optionssauvepoints->setWindowTitle(QApplication::translate("optionssauvepoints", "Dialog", Q_NULLPTR));
        label_3->setText(QApplication::translate("optionssauvepoints", "File Path (default : keep empty)", Q_NULLPTR));
        label_4->setText(QApplication::translate("optionssauvepoints", "Point Name", Q_NULLPTR));
        label_5->setText(QApplication::translate("optionssauvepoints", "Number of Measures", Q_NULLPTR));
        NummeasBox->clear();
        NummeasBox->insertItems(0, QStringList()
         << QApplication::translate("optionssauvepoints", "1", Q_NULLPTR)
         << QApplication::translate("optionssauvepoints", "2", Q_NULLPTR)
         << QApplication::translate("optionssauvepoints", "3", Q_NULLPTR)
         << QApplication::translate("optionssauvepoints", "4", Q_NULLPTR)
         << QApplication::translate("optionssauvepoints", "5", Q_NULLPTR)
         << QApplication::translate("optionssauvepoints", "10", Q_NULLPTR)
         << QApplication::translate("optionssauvepoints", "20", Q_NULLPTR)
         << QApplication::translate("optionssauvepoints", "30", Q_NULLPTR)
         << QApplication::translate("optionssauvepoints", "60", Q_NULLPTR)
         << QApplication::translate("optionssauvepoints", "120", Q_NULLPTR)
         << QApplication::translate("optionssauvepoints", "300", Q_NULLPTR)
         << QApplication::translate("optionssauvepoints", "600", Q_NULLPTR)
         << QApplication::translate("optionssauvepoints", "1200", Q_NULLPTR)
         << QApplication::translate("optionssauvepoints", "3600", Q_NULLPTR)
        );
        label_6->setText(QApplication::translate("optionssauvepoints", "Cycle lenght (s)", Q_NULLPTR));
        CyclenBox->clear();
        CyclenBox->insertItems(0, QStringList()
         << QApplication::translate("optionssauvepoints", "1", Q_NULLPTR)
         << QApplication::translate("optionssauvepoints", "2", Q_NULLPTR)
         << QApplication::translate("optionssauvepoints", "3", Q_NULLPTR)
         << QApplication::translate("optionssauvepoints", "4", Q_NULLPTR)
         << QApplication::translate("optionssauvepoints", "5", Q_NULLPTR)
         << QApplication::translate("optionssauvepoints", "10", Q_NULLPTR)
         << QApplication::translate("optionssauvepoints", "15", Q_NULLPTR)
         << QApplication::translate("optionssauvepoints", "20", Q_NULLPTR)
         << QApplication::translate("optionssauvepoints", "30", Q_NULLPTR)
         << QApplication::translate("optionssauvepoints", "60", Q_NULLPTR)
        );
        label_7->setText(QApplication::translate("optionssauvepoints", "Old points", Q_NULLPTR));
        OldpointBox->clear();
        OldpointBox->insertItems(0, QStringList()
         << QApplication::translate("optionssauvepoints", "Remove Old Measures from the File", Q_NULLPTR)
         << QApplication::translate("optionssauvepoints", "Add the New Measures after the Old Content", Q_NULLPTR)
        );
        FilepathButton->setText(QApplication::translate("optionssauvepoints", "...", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("optionssauvepoints", "SAVE POINT OPTIONS", Q_NULLPTR));
        CancelButton->setText(QApplication::translate("optionssauvepoints", "CANCEL", Q_NULLPTR));
        SaveButton->setText(QApplication::translate("optionssauvepoints", "SAVE", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class optionssauvepoints: public Ui_optionssauvepoints {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONSSAUVEPOINTS_H
