/********************************************************************************
** Form generated from reading UI file 'optionsstr2str.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONSSTR2STR_H
#define UI_OPTIONSSTR2STR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include "mycombobox.h"
#include "mylineedit.h"

QT_BEGIN_NAMESPACE

class Ui_OptionsStr2str
{
public:
    QPushButton *pushButtonDefault1;
    QTabWidget *tabWidget;
    QWidget *tab;
    QRadioButton *radioButtonPositionAuto;
    QRadioButton *radioButtonPositionManual;
    QPushButton *pushButtonManual;
    MyLineEdit *LatManualLine;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit;
    MyLineEdit *LongManualLine;
    MyLineEdit *AltiManualLine;
    QLineEdit *lineEdit_12;
    QLineEdit *lineEdit_13;
    QLineEdit *lineEdit_14;
    MyLineEdit *LatAutoLine;
    MyLineEdit *LongAutoLine;
    MyLineEdit *AltiAutoLine;
    QWidget *tab_2;
    MyComboBox *OutBaudRatecomboBox;
    MyComboBox *OutSerialPortcomboBox;
    MyComboBox *OutFormatcomboBox;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    MyComboBox *InSerialPortcomboBox;
    MyComboBox *InBaudratecomboBox;
    MyComboBox *InFormatcomboBox;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_15;
    MyComboBox *RtcmMsgcomboBox;
    QPushButton *UpdateOptionspushButton;
    QLineEdit *lineEdit_17;
    MyComboBox *OutFilePathcomboBox;
    QTextBrowser *RtkrcvOptionstextBrowser;
    QLineEdit *lineEdit_16;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonLoad;

    void setupUi(QDialog *OptionsStr2str)
    {
        if (OptionsStr2str->objectName().isEmpty())
            OptionsStr2str->setObjectName(QStringLiteral("OptionsStr2str"));
        OptionsStr2str->resize(800, 398);
        pushButtonDefault1 = new QPushButton(OptionsStr2str);
        pushButtonDefault1->setObjectName(QStringLiteral("pushButtonDefault1"));
        pushButtonDefault1->setGeometry(QRect(660, 310, 121, 71));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        pushButtonDefault1->setFont(font);
        pushButtonDefault1->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        tabWidget = new QTabWidget(OptionsStr2str);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(30, 50, 731, 251));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        radioButtonPositionAuto = new QRadioButton(tab);
        radioButtonPositionAuto->setObjectName(QStringLiteral("radioButtonPositionAuto"));
        radioButtonPositionAuto->setGeometry(QRect(20, 20, 121, 22));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        radioButtonPositionAuto->setFont(font1);
        radioButtonPositionAuto->setCheckable(true);
        radioButtonPositionAuto->setChecked(false);
        radioButtonPositionAuto->setAutoRepeat(false);
        radioButtonPositionManual = new QRadioButton(tab);
        radioButtonPositionManual->setObjectName(QStringLiteral("radioButtonPositionManual"));
        radioButtonPositionManual->setGeometry(QRect(440, 20, 151, 22));
        radioButtonPositionManual->setFont(font1);
        pushButtonManual = new QPushButton(tab);
        pushButtonManual->setObjectName(QStringLiteral("pushButtonManual"));
        pushButtonManual->setGeometry(QRect(620, 90, 81, 51));
        pushButtonManual->setFont(font);
        pushButtonManual->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);\n"
""));
        LatManualLine = new MyLineEdit(tab);
        LatManualLine->setObjectName(QStringLiteral("LatManualLine"));
        LatManualLine->setGeometry(QRect(490, 60, 113, 32));
        LatManualLine->setFont(font1);
        LatManualLine->setAlignment(Qt::AlignCenter);
        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(370, 100, 111, 32));
        lineEdit_2->setFont(font1);
        lineEdit_2->setAlignment(Qt::AlignCenter);
        lineEdit_2->setReadOnly(true);
        lineEdit_3 = new QLineEdit(tab);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(370, 140, 111, 32));
        lineEdit_3->setFont(font1);
        lineEdit_3->setAlignment(Qt::AlignCenter);
        lineEdit_3->setReadOnly(true);
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(370, 60, 111, 32));
        lineEdit->setFont(font1);
        lineEdit->setAlignment(Qt::AlignCenter);
        lineEdit->setReadOnly(true);
        LongManualLine = new MyLineEdit(tab);
        LongManualLine->setObjectName(QStringLiteral("LongManualLine"));
        LongManualLine->setGeometry(QRect(490, 100, 111, 32));
        LongManualLine->setFont(font1);
        LongManualLine->setAlignment(Qt::AlignCenter);
        AltiManualLine = new MyLineEdit(tab);
        AltiManualLine->setObjectName(QStringLiteral("AltiManualLine"));
        AltiManualLine->setGeometry(QRect(490, 140, 111, 32));
        AltiManualLine->setFont(font1);
        AltiManualLine->setAlignment(Qt::AlignCenter);
        lineEdit_12 = new QLineEdit(tab);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));
        lineEdit_12->setEnabled(true);
        lineEdit_12->setGeometry(QRect(10, 60, 111, 32));
        lineEdit_12->setFont(font1);
        lineEdit_12->setAlignment(Qt::AlignCenter);
        lineEdit_12->setReadOnly(true);
        lineEdit_13 = new QLineEdit(tab);
        lineEdit_13->setObjectName(QStringLiteral("lineEdit_13"));
        lineEdit_13->setGeometry(QRect(12, 140, 111, 32));
        lineEdit_13->setFont(font1);
        lineEdit_13->setAlignment(Qt::AlignCenter);
        lineEdit_13->setReadOnly(true);
        lineEdit_14 = new QLineEdit(tab);
        lineEdit_14->setObjectName(QStringLiteral("lineEdit_14"));
        lineEdit_14->setGeometry(QRect(10, 100, 111, 32));
        lineEdit_14->setFont(font1);
        lineEdit_14->setAlignment(Qt::AlignCenter);
        lineEdit_14->setReadOnly(true);
        LatAutoLine = new MyLineEdit(tab);
        LatAutoLine->setObjectName(QStringLiteral("LatAutoLine"));
        LatAutoLine->setGeometry(QRect(130, 60, 111, 32));
        LatAutoLine->setFont(font1);
        LatAutoLine->setAlignment(Qt::AlignCenter);
        LongAutoLine = new MyLineEdit(tab);
        LongAutoLine->setObjectName(QStringLiteral("LongAutoLine"));
        LongAutoLine->setGeometry(QRect(130, 100, 113, 32));
        LongAutoLine->setFont(font1);
        LongAutoLine->setAlignment(Qt::AlignCenter);
        AltiAutoLine = new MyLineEdit(tab);
        AltiAutoLine->setObjectName(QStringLiteral("AltiAutoLine"));
        AltiAutoLine->setGeometry(QRect(130, 140, 111, 32));
        AltiAutoLine->setFont(font1);
        AltiAutoLine->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        OutBaudRatecomboBox = new MyComboBox(tab_2);
        OutBaudRatecomboBox->setObjectName(QStringLiteral("OutBaudRatecomboBox"));
        OutBaudRatecomboBox->setGeometry(QRect(550, 70, 81, 32));
        OutBaudRatecomboBox->setFont(font1);
        OutBaudRatecomboBox->setEditable(true);
        OutSerialPortcomboBox = new MyComboBox(tab_2);
        OutSerialPortcomboBox->setObjectName(QStringLiteral("OutSerialPortcomboBox"));
        OutSerialPortcomboBox->setGeometry(QRect(390, 70, 151, 32));
        OutSerialPortcomboBox->setFont(font1);
        OutSerialPortcomboBox->setEditable(true);
        OutFormatcomboBox = new MyComboBox(tab_2);
        OutFormatcomboBox->setObjectName(QStringLiteral("OutFormatcomboBox"));
        OutFormatcomboBox->setGeometry(QRect(640, 70, 71, 32));
        OutFormatcomboBox->setFont(font1);
        OutFormatcomboBox->setEditable(true);
        lineEdit_4 = new QLineEdit(tab_2);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(390, 51, 151, 21));
        lineEdit_4->setFont(font1);
        lineEdit_4->setAlignment(Qt::AlignCenter);
        lineEdit_4->setReadOnly(true);
        lineEdit_5 = new QLineEdit(tab_2);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(550, 51, 81, 21));
        lineEdit_5->setFont(font1);
        lineEdit_5->setAlignment(Qt::AlignCenter);
        lineEdit_5->setReadOnly(true);
        lineEdit_6 = new QLineEdit(tab_2);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(640, 51, 71, 21));
        lineEdit_6->setFont(font1);
        lineEdit_6->setAlignment(Qt::AlignCenter);
        lineEdit_6->setReadOnly(true);
        lineEdit_7 = new QLineEdit(tab_2);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(460, 10, 201, 32));
        lineEdit_7->setFont(font);
        lineEdit_7->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;"));
        lineEdit_7->setAlignment(Qt::AlignCenter);
        lineEdit_7->setReadOnly(true);
        lineEdit_8 = new QLineEdit(tab_2);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(80, 10, 201, 32));
        lineEdit_8->setFont(font);
        lineEdit_8->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;"));
        lineEdit_8->setAlignment(Qt::AlignCenter);
        lineEdit_8->setReadOnly(true);
        InSerialPortcomboBox = new MyComboBox(tab_2);
        InSerialPortcomboBox->setObjectName(QStringLiteral("InSerialPortcomboBox"));
        InSerialPortcomboBox->setGeometry(QRect(10, 80, 151, 32));
        InSerialPortcomboBox->setFont(font1);
        InSerialPortcomboBox->setEditable(true);
        InBaudratecomboBox = new MyComboBox(tab_2);
        InBaudratecomboBox->setObjectName(QStringLiteral("InBaudratecomboBox"));
        InBaudratecomboBox->setGeometry(QRect(170, 80, 81, 32));
        InBaudratecomboBox->setFont(font1);
        InBaudratecomboBox->setEditable(true);
        InFormatcomboBox = new MyComboBox(tab_2);
        InFormatcomboBox->setObjectName(QStringLiteral("InFormatcomboBox"));
        InFormatcomboBox->setGeometry(QRect(260, 80, 81, 32));
        InFormatcomboBox->setFont(font1);
        InFormatcomboBox->setEditable(true);
        lineEdit_9 = new QLineEdit(tab_2);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(260, 61, 81, 21));
        lineEdit_9->setFont(font1);
        lineEdit_9->setAlignment(Qt::AlignCenter);
        lineEdit_9->setReadOnly(true);
        lineEdit_10 = new QLineEdit(tab_2);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(10, 61, 151, 21));
        lineEdit_10->setFont(font1);
        lineEdit_10->setAlignment(Qt::AlignCenter);
        lineEdit_10->setReadOnly(true);
        lineEdit_11 = new QLineEdit(tab_2);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));
        lineEdit_11->setGeometry(QRect(170, 61, 81, 21));
        lineEdit_11->setFont(font1);
        lineEdit_11->setAlignment(Qt::AlignCenter);
        lineEdit_11->setReadOnly(true);
        lineEdit_15 = new QLineEdit(tab_2);
        lineEdit_15->setObjectName(QStringLiteral("lineEdit_15"));
        lineEdit_15->setGeometry(QRect(390, 110, 321, 20));
        lineEdit_15->setFont(font1);
        lineEdit_15->setAlignment(Qt::AlignCenter);
        lineEdit_15->setReadOnly(true);
        RtcmMsgcomboBox = new MyComboBox(tab_2);
        RtcmMsgcomboBox->setObjectName(QStringLiteral("RtcmMsgcomboBox"));
        RtcmMsgcomboBox->setGeometry(QRect(390, 128, 321, 32));
        RtcmMsgcomboBox->setFont(font1);
        RtcmMsgcomboBox->setEditable(true);
        UpdateOptionspushButton = new QPushButton(tab_2);
        UpdateOptionspushButton->setObjectName(QStringLiteral("UpdateOptionspushButton"));
        UpdateOptionspushButton->setGeometry(QRect(50, 160, 271, 34));
        UpdateOptionspushButton->setFont(font1);
        UpdateOptionspushButton->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        lineEdit_17 = new QLineEdit(tab_2);
        lineEdit_17->setObjectName(QStringLiteral("lineEdit_17"));
        lineEdit_17->setGeometry(QRect(390, 162, 321, 20));
        lineEdit_17->setFont(font1);
        lineEdit_17->setAlignment(Qt::AlignCenter);
        lineEdit_17->setReadOnly(true);
        OutFilePathcomboBox = new MyComboBox(tab_2);
        OutFilePathcomboBox->setObjectName(QStringLiteral("OutFilePathcomboBox"));
        OutFilePathcomboBox->setGeometry(QRect(390, 180, 321, 32));
        OutFilePathcomboBox->setFont(font1);
        OutFilePathcomboBox->setEditable(true);
        tabWidget->addTab(tab_2, QString());
        RtkrcvOptionstextBrowser = new QTextBrowser(OptionsStr2str);
        RtkrcvOptionstextBrowser->setObjectName(QStringLiteral("RtkrcvOptionstextBrowser"));
        RtkrcvOptionstextBrowser->setGeometry(QRect(30, 310, 591, 81));
        RtkrcvOptionstextBrowser->setFont(font1);
        RtkrcvOptionstextBrowser->setStyleSheet(QStringLiteral("border: 1px solid grey;"));
        lineEdit_16 = new QLineEdit(OptionsStr2str);
        lineEdit_16->setObjectName(QStringLiteral("lineEdit_16"));
        lineEdit_16->setGeometry(QRect(222, 10, 281, 32));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        lineEdit_16->setFont(font2);
        lineEdit_16->setFocusPolicy(Qt::WheelFocus);
        lineEdit_16->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;"));
        lineEdit_16->setAlignment(Qt::AlignCenter);
        pushButtonSave = new QPushButton(OptionsStr2str);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        pushButtonSave->setGeometry(QRect(600, 10, 91, 61));
        pushButtonSave->setFont(font);
        pushButtonSave->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);\n"
""));
        pushButtonLoad = new QPushButton(OptionsStr2str);
        pushButtonLoad->setObjectName(QStringLiteral("pushButtonLoad"));
        pushButtonLoad->setGeometry(QRect(700, 10, 91, 61));
        pushButtonLoad->setFont(font);
        pushButtonLoad->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);\n"
""));

        retranslateUi(OptionsStr2str);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(OptionsStr2str);
    } // setupUi

    void retranslateUi(QDialog *OptionsStr2str)
    {
        OptionsStr2str->setWindowTitle(QApplication::translate("OptionsStr2str", "Dialog", 0));
        pushButtonDefault1->setText(QApplication::translate("OptionsStr2str", "START BASE", 0));
        radioButtonPositionAuto->setText(QApplication::translate("OptionsStr2str", "AU&TOMATIC ", 0));
        radioButtonPositionManual->setText(QApplication::translate("OptionsStr2str", "&MANUAL INPUT", 0));
        pushButtonManual->setText(QApplication::translate("OptionsStr2str", "WRITE", 0));
        LatManualLine->setText(QApplication::translate("OptionsStr2str", "01.00", 0));
        lineEdit_2->setText(QApplication::translate("OptionsStr2str", "      LONGITUDE :", 0));
        lineEdit_3->setText(QApplication::translate("OptionsStr2str", "ALTITUDE :", 0));
        lineEdit->setText(QApplication::translate("OptionsStr2str", "LATITUDE :", 0));
        LongManualLine->setText(QApplication::translate("OptionsStr2str", "01,00", 0));
        AltiManualLine->setText(QApplication::translate("OptionsStr2str", "1.00", 0));
        lineEdit_12->setText(QApplication::translate("OptionsStr2str", "LATITUDE :", 0));
        lineEdit_13->setText(QApplication::translate("OptionsStr2str", "ALTITUDE :", 0));
        lineEdit_14->setText(QApplication::translate("OptionsStr2str", "      LONGITUDE :", 0));
        LatAutoLine->setText(QApplication::translate("OptionsStr2str", "01,00", 0));
        LongAutoLine->setText(QApplication::translate("OptionsStr2str", "01.00", 0));
        AltiAutoLine->setText(QApplication::translate("OptionsStr2str", "1.00", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("OptionsStr2str", "BASE POSITION", 0));
        OutBaudRatecomboBox->clear();
        OutBaudRatecomboBox->insertItems(0, QStringList()
         << QApplication::translate("OptionsStr2str", "57600", 0)
         << QApplication::translate("OptionsStr2str", "9600", 0)
         << QApplication::translate("OptionsStr2str", "38400", 0)
         << QApplication::translate("OptionsStr2str", "115200", 0)
        );
        OutSerialPortcomboBox->clear();
        OutSerialPortcomboBox->insertItems(0, QStringList()
         << QApplication::translate("OptionsStr2str", "serial://ttyUSB0", 0)
         << QApplication::translate("OptionsStr2str", "serial://ttyAMA0", 0)
         << QApplication::translate("OptionsStr2str", "serial://ttyACM0", 0)
         << QApplication::translate("OptionsStr2str", "File", 0)
        );
        OutFormatcomboBox->clear();
        OutFormatcomboBox->insertItems(0, QStringList()
         << QApplication::translate("OptionsStr2str", "rtcm3", 0)
         << QApplication::translate("OptionsStr2str", "rtcm2", 0)
        );
        lineEdit_4->setText(QApplication::translate("OptionsStr2str", "OUTPUT PORT", 0));
        lineEdit_5->setText(QApplication::translate("OptionsStr2str", "BAUDS", 0));
        lineEdit_6->setText(QApplication::translate("OptionsStr2str", "FORMAT", 0));
        lineEdit_7->setText(QApplication::translate("OptionsStr2str", "OUTPUT STREAM", 0));
        lineEdit_8->setText(QApplication::translate("OptionsStr2str", "INPUT STREAM", 0));
        InSerialPortcomboBox->clear();
        InSerialPortcomboBox->insertItems(0, QStringList()
         << QApplication::translate("OptionsStr2str", "serial://ttyACM0", 0)
         << QApplication::translate("OptionsStr2str", "serial://AMA0", 0)
         << QApplication::translate("OptionsStr2str", "serial://USB0", 0)
        );
        InBaudratecomboBox->clear();
        InBaudratecomboBox->insertItems(0, QStringList()
         << QApplication::translate("OptionsStr2str", "115200", 0)
         << QApplication::translate("OptionsStr2str", "57600", 0)
         << QApplication::translate("OptionsStr2str", "38400", 0)
         << QApplication::translate("OptionsStr2str", "9600", 0)
        );
        InFormatcomboBox->clear();
        InFormatcomboBox->insertItems(0, QStringList()
         << QApplication::translate("OptionsStr2str", "ubx", 0)
         << QApplication::translate("OptionsStr2str", "nvs", 0)
         << QApplication::translate("OptionsStr2str", "oem3", 0)
         << QApplication::translate("OptionsStr2str", "nov", 0)
         << QApplication::translate("OptionsStr2str", "ss2", 0)
         << QApplication::translate("OptionsStr2str", "hemis", 0)
         << QApplication::translate("OptionsStr2str", "stq", 0)
         << QApplication::translate("OptionsStr2str", "javad", 0)
         << QApplication::translate("OptionsStr2str", "binex", 0)
         << QApplication::translate("OptionsStr2str", "rtcm2", 0)
         << QApplication::translate("OptionsStr2str", "rtcm3", 0)
        );
        lineEdit_9->setText(QApplication::translate("OptionsStr2str", "FORMAT", 0));
        lineEdit_10->setText(QApplication::translate("OptionsStr2str", "INPUT PORT", 0));
        lineEdit_11->setText(QApplication::translate("OptionsStr2str", "BAUDS", 0));
        lineEdit_15->setText(QApplication::translate("OptionsStr2str", "RTCM MESSAGES", 0));
        RtcmMsgcomboBox->clear();
        RtcmMsgcomboBox->insertItems(0, QStringList()
         << QApplication::translate("OptionsStr2str", "1004,1006,1008,1012,1019,1020", 0)
        );
        UpdateOptionspushButton->setText(QApplication::translate("OptionsStr2str", "UPDATE STREAM  CONFIGURATION", 0));
        lineEdit_17->setText(QApplication::translate("OptionsStr2str", "FILE PATH FOR RAW DATA", 0));
        OutFilePathcomboBox->clear();
        OutFilePathcomboBox->insertItems(0, QStringList()
         << QApplication::translate("OptionsStr2str", "../RTKBASE/PointsFiles/rover.ubx", 0)
         << QApplication::translate("OptionsStr2str", "/home/pi/rover.ubx", 0)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("OptionsStr2str", "CONFIGURATION", 0));
        lineEdit_16->setText(QApplication::translate("OptionsStr2str", "BASE CONFIGURATION", 0));
        pushButtonSave->setText(QApplication::translate("OptionsStr2str", "Save", 0));
        pushButtonLoad->setText(QApplication::translate("OptionsStr2str", "Load", 0));
    } // retranslateUi

};

namespace Ui {
    class OptionsStr2str: public Ui_OptionsStr2str {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONSSTR2STR_H
