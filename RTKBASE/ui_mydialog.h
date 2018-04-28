/********************************************************************************
** Form generated from reading UI file 'mydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYDIALOG_H
#define UI_MYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include "mycombobox.h"

QT_BEGIN_NAMESPACE

class Ui_MyDialog
{
public:
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QPushButton *pushButton_run_rnx2rtk_process_RGP;
    QLineEdit *LLH_Lat_lineEdit;
    QLineEdit *LLH_Alt_lineEdit;
    QLineEdit *LLH_Lon_lineEdit;
    QLineEdit *ECEF_x_lineEdit;
    QLineEdit *ECEF_z_lineEdit;
    QLineEdit *ECEF_y_lineEdit;
    QLineEdit *lineEdit_2;
    QProgressBar *progressBar;
    QLineEdit *InfoProcess_lineEdit;
    QLineEdit *InfoCapture_lineEdit;
    QPushButton *AutoPostP_pushButton;
    QTextBrowser *Capture_textBrowser;
    QLineEdit *lineEdit_6;
    QTextBrowser *textBrowser_2;
    QPushButton *Stop_AutoPP_pushButton;
    QLineEdit *InfoBaseAuto_lineEdit;
    QTextBrowser *InfotextBrowser;
    QLineEdit *InfoServer;
    QLineEdit *lineEdit_16;
    QWidget *tab_3;
    QLineEdit *lineEdit;
    QComboBox *Radius_dmax;
    QComboBox *MinStation;
    QLineEdit *lineEdit_3;
    QPushButton *Save_options_pushButton;
    QLineEdit *lineEdit_4;
    QComboBox *CaptureTime;
    QLineEdit *lineEdit_5;
    QComboBox *WaitingTime;
    QLineEdit *lineEdit_15;
    QLineEdit *lineEdit_10;
    MyComboBox *InBaudratecomboBox2;
    QLineEdit *lineEdit_11;
    MyComboBox *RtcmMsgcomboBox2;
    MyComboBox *InFormatcomboBox2;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_12;
    MyComboBox *OutBaudRatecomboBox2;
    QLineEdit *lineEdit_13;
    MyComboBox *InSerialPortcomboBox2;
    MyComboBox *OutFormatcomboBox2;
    QLineEdit *lineEdit_14;
    MyComboBox *OutSerialPortcomboBox2;
    QComboBox *Autostartbase_comboBox;
    QLineEdit *lineEdit_17;
    QLineEdit *lineEdit_18;
    QComboBox *Choose_server;
    QWidget *tab;
    QTextBrowser *textBrowser;
    QPushButton *testlog_pushButton;
    QPushButton *teststart_pushButton;
    QPushButton *teststop_pushButton;

    void setupUi(QDialog *MyDialog)
    {
        if (MyDialog->objectName().isEmpty())
            MyDialog->setObjectName(QStringLiteral("MyDialog"));
        MyDialog->resize(800, 480);
        MyDialog->setMaximumSize(QSize(895, 16777215));
        tabWidget = new QTabWidget(MyDialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 20, 781, 451));
        QFont font;
        font.setPointSize(11);
        font.setBold(false);
        font.setWeight(50);
        tabWidget->setFont(font);
        tab_1 = new QWidget();
        tab_1->setObjectName(QStringLiteral("tab_1"));
        QFont font1;
        font1.setPointSize(11);
        tab_1->setFont(font1);
        pushButton_run_rnx2rtk_process_RGP = new QPushButton(tab_1);
        pushButton_run_rnx2rtk_process_RGP->setObjectName(QStringLiteral("pushButton_run_rnx2rtk_process_RGP"));
        pushButton_run_rnx2rtk_process_RGP->setGeometry(QRect(10, 10, 131, 61));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        pushButton_run_rnx2rtk_process_RGP->setFont(font2);
        pushButton_run_rnx2rtk_process_RGP->setStyleSheet(QLatin1String("background-color: rgb(238, 238, 236);border-style: solid;\n"
"border-color: black;\n"
"border-width: 1px;\n"
"border-radius: 10px;"));
        LLH_Lat_lineEdit = new QLineEdit(tab_1);
        LLH_Lat_lineEdit->setObjectName(QStringLiteral("LLH_Lat_lineEdit"));
        LLH_Lat_lineEdit->setGeometry(QRect(620, 50, 141, 25));
        LLH_Lat_lineEdit->setMaxLength(17);
        LLH_Lat_lineEdit->setFrame(true);
        LLH_Alt_lineEdit = new QLineEdit(tab_1);
        LLH_Alt_lineEdit->setObjectName(QStringLiteral("LLH_Alt_lineEdit"));
        LLH_Alt_lineEdit->setGeometry(QRect(622, 110, 141, 25));
        LLH_Alt_lineEdit->setMaxLength(17);
        LLH_Lon_lineEdit = new QLineEdit(tab_1);
        LLH_Lon_lineEdit->setObjectName(QStringLiteral("LLH_Lon_lineEdit"));
        LLH_Lon_lineEdit->setGeometry(QRect(622, 80, 141, 25));
        LLH_Lon_lineEdit->setMaxLength(17);
        ECEF_x_lineEdit = new QLineEdit(tab_1);
        ECEF_x_lineEdit->setObjectName(QStringLiteral("ECEF_x_lineEdit"));
        ECEF_x_lineEdit->setGeometry(QRect(460, 50, 151, 25));
        ECEF_x_lineEdit->setReadOnly(false);
        ECEF_z_lineEdit = new QLineEdit(tab_1);
        ECEF_z_lineEdit->setObjectName(QStringLiteral("ECEF_z_lineEdit"));
        ECEF_z_lineEdit->setGeometry(QRect(460, 110, 151, 25));
        ECEF_y_lineEdit = new QLineEdit(tab_1);
        ECEF_y_lineEdit->setObjectName(QStringLiteral("ECEF_y_lineEdit"));
        ECEF_y_lineEdit->setGeometry(QRect(460, 80, 151, 25));
        lineEdit_2 = new QLineEdit(tab_1);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(470, 10, 281, 25));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        lineEdit_2->setFont(font3);
        lineEdit_2->setStyleSheet(QLatin1String("border-style: solid;\n"
"border-color: black;\n"
"border-width: 1px;\n"
"border-radius: 10px;"));
        lineEdit_2->setAlignment(Qt::AlignCenter);
        progressBar = new QProgressBar(tab_1);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(650, 380, 118, 23));
        progressBar->setValue(0);
        InfoProcess_lineEdit = new QLineEdit(tab_1);
        InfoProcess_lineEdit->setObjectName(QStringLiteral("InfoProcess_lineEdit"));
        InfoProcess_lineEdit->setGeometry(QRect(10, 120, 281, 25));
        InfoCapture_lineEdit = new QLineEdit(tab_1);
        InfoCapture_lineEdit->setObjectName(QStringLiteral("InfoCapture_lineEdit"));
        InfoCapture_lineEdit->setGeometry(QRect(10, 90, 281, 25));
        AutoPostP_pushButton = new QPushButton(tab_1);
        AutoPostP_pushButton->setObjectName(QStringLiteral("AutoPostP_pushButton"));
        AutoPostP_pushButton->setGeometry(QRect(150, 10, 141, 61));
        AutoPostP_pushButton->setFont(font2);
        AutoPostP_pushButton->setStyleSheet(QLatin1String("background-color: rgb(238, 238, 236);\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 1px;\n"
"border-radius: 10px;"));
        Capture_textBrowser = new QTextBrowser(tab_1);
        Capture_textBrowser->setObjectName(QStringLiteral("Capture_textBrowser"));
        Capture_textBrowser->setGeometry(QRect(150, 150, 481, 31));
        lineEdit_6 = new QLineEdit(tab_1);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(10, 150, 131, 31));
        lineEdit_6->setFont(font2);
        textBrowser_2 = new QTextBrowser(tab_1);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(20, 380, 591, 31));
        textBrowser_2->setFont(font2);
        Stop_AutoPP_pushButton = new QPushButton(tab_1);
        Stop_AutoPP_pushButton->setObjectName(QStringLiteral("Stop_AutoPP_pushButton"));
        Stop_AutoPP_pushButton->setGeometry(QRect(300, 10, 81, 41));
        Stop_AutoPP_pushButton->setFont(font3);
        Stop_AutoPP_pushButton->setStyleSheet(QLatin1String("background-color: rgb(238, 238, 236);\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 1px;\n"
"border-radius: 10px;"));
        InfoBaseAuto_lineEdit = new QLineEdit(tab_1);
        InfoBaseAuto_lineEdit->setObjectName(QStringLiteral("InfoBaseAuto_lineEdit"));
        InfoBaseAuto_lineEdit->setGeometry(QRect(320, 120, 111, 25));
        InfoBaseAuto_lineEdit->setFont(font1);
        InfotextBrowser = new QTextBrowser(tab_1);
        InfotextBrowser->setObjectName(QStringLiteral("InfotextBrowser"));
        InfotextBrowser->setGeometry(QRect(20, 190, 741, 181));
        InfotextBrowser->setFont(font2);
        InfoServer = new QLineEdit(tab_1);
        InfoServer->setObjectName(QStringLiteral("InfoServer"));
        InfoServer->setGeometry(QRect(310, 90, 131, 25));
        InfoServer->setFont(font1);
        lineEdit_16 = new QLineEdit(tab_1);
        lineEdit_16->setObjectName(QStringLiteral("lineEdit_16"));
        lineEdit_16->setGeometry(QRect(310, 60, 131, 31));
        lineEdit_16->setFont(font2);
        lineEdit_16->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(tab_1, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        lineEdit = new QLineEdit(tab_3);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(30, 50, 241, 25));
        Radius_dmax = new QComboBox(tab_3);
        Radius_dmax->setObjectName(QStringLiteral("Radius_dmax"));
        Radius_dmax->setGeometry(QRect(290, 50, 61, 25));
        MinStation = new QComboBox(tab_3);
        MinStation->setObjectName(QStringLiteral("MinStation"));
        MinStation->setGeometry(QRect(190, 90, 51, 25));
        lineEdit_3 = new QLineEdit(tab_3);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(30, 90, 141, 25));
        Save_options_pushButton = new QPushButton(tab_3);
        Save_options_pushButton->setObjectName(QStringLiteral("Save_options_pushButton"));
        Save_options_pushButton->setGeometry(QRect(640, 10, 121, 51));
        Save_options_pushButton->setFont(font2);
        Save_options_pushButton->setStyleSheet(QLatin1String("background-color: rgb(238, 238, 236);\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 1px;\n"
"border-radius: 10px;"));
        lineEdit_4 = new QLineEdit(tab_3);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(30, 130, 141, 25));
        CaptureTime = new QComboBox(tab_3);
        CaptureTime->setObjectName(QStringLiteral("CaptureTime"));
        CaptureTime->setGeometry(QRect(190, 130, 71, 25));
        lineEdit_5 = new QLineEdit(tab_3);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(30, 170, 211, 25));
        WaitingTime = new QComboBox(tab_3);
        WaitingTime->setObjectName(QStringLiteral("WaitingTime"));
        WaitingTime->setGeometry(QRect(250, 170, 61, 25));
        lineEdit_15 = new QLineEdit(tab_3);
        lineEdit_15->setObjectName(QStringLiteral("lineEdit_15"));
        lineEdit_15->setGeometry(QRect(420, 342, 321, 20));
        lineEdit_15->setFont(font2);
        lineEdit_15->setAlignment(Qt::AlignCenter);
        lineEdit_15->setReadOnly(true);
        lineEdit_10 = new QLineEdit(tab_3);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(40, 293, 151, 21));
        lineEdit_10->setFont(font2);
        lineEdit_10->setAlignment(Qt::AlignCenter);
        lineEdit_10->setReadOnly(true);
        InBaudratecomboBox2 = new MyComboBox(tab_3);
        InBaudratecomboBox2->setObjectName(QStringLiteral("InBaudratecomboBox2"));
        InBaudratecomboBox2->setGeometry(QRect(200, 312, 81, 32));
        InBaudratecomboBox2->setFont(font2);
        InBaudratecomboBox2->setEditable(true);
        lineEdit_11 = new QLineEdit(tab_3);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));
        lineEdit_11->setGeometry(QRect(200, 293, 81, 21));
        lineEdit_11->setFont(font2);
        lineEdit_11->setAlignment(Qt::AlignCenter);
        lineEdit_11->setReadOnly(true);
        RtcmMsgcomboBox2 = new MyComboBox(tab_3);
        RtcmMsgcomboBox2->setObjectName(QStringLiteral("RtcmMsgcomboBox2"));
        RtcmMsgcomboBox2->setGeometry(QRect(420, 360, 321, 32));
        RtcmMsgcomboBox2->setFont(font2);
        RtcmMsgcomboBox2->setEditable(true);
        InFormatcomboBox2 = new MyComboBox(tab_3);
        InFormatcomboBox2->setObjectName(QStringLiteral("InFormatcomboBox2"));
        InFormatcomboBox2->setGeometry(QRect(290, 312, 81, 32));
        InFormatcomboBox2->setFont(font2);
        InFormatcomboBox2->setEditable(true);
        lineEdit_7 = new QLineEdit(tab_3);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(670, 283, 71, 21));
        lineEdit_7->setFont(font2);
        lineEdit_7->setAlignment(Qt::AlignCenter);
        lineEdit_7->setReadOnly(true);
        lineEdit_8 = new QLineEdit(tab_3);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(420, 283, 151, 21));
        lineEdit_8->setFont(font2);
        lineEdit_8->setAlignment(Qt::AlignCenter);
        lineEdit_8->setReadOnly(true);
        lineEdit_9 = new QLineEdit(tab_3);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(290, 293, 81, 21));
        lineEdit_9->setFont(font2);
        lineEdit_9->setAlignment(Qt::AlignCenter);
        lineEdit_9->setReadOnly(true);
        lineEdit_12 = new QLineEdit(tab_3);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));
        lineEdit_12->setGeometry(QRect(110, 250, 201, 21));
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        lineEdit_12->setFont(font4);
        lineEdit_12->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;"));
        lineEdit_12->setAlignment(Qt::AlignCenter);
        lineEdit_12->setReadOnly(true);
        OutBaudRatecomboBox2 = new MyComboBox(tab_3);
        OutBaudRatecomboBox2->setObjectName(QStringLiteral("OutBaudRatecomboBox2"));
        OutBaudRatecomboBox2->setGeometry(QRect(580, 302, 81, 32));
        OutBaudRatecomboBox2->setFont(font2);
        OutBaudRatecomboBox2->setEditable(true);
        lineEdit_13 = new QLineEdit(tab_3);
        lineEdit_13->setObjectName(QStringLiteral("lineEdit_13"));
        lineEdit_13->setGeometry(QRect(580, 283, 81, 21));
        lineEdit_13->setFont(font2);
        lineEdit_13->setAlignment(Qt::AlignCenter);
        lineEdit_13->setReadOnly(true);
        InSerialPortcomboBox2 = new MyComboBox(tab_3);
        InSerialPortcomboBox2->setObjectName(QStringLiteral("InSerialPortcomboBox2"));
        InSerialPortcomboBox2->setGeometry(QRect(40, 312, 151, 32));
        InSerialPortcomboBox2->setFont(font2);
        InSerialPortcomboBox2->setEditable(true);
        OutFormatcomboBox2 = new MyComboBox(tab_3);
        OutFormatcomboBox2->setObjectName(QStringLiteral("OutFormatcomboBox2"));
        OutFormatcomboBox2->setGeometry(QRect(670, 302, 71, 32));
        OutFormatcomboBox2->setFont(font2);
        OutFormatcomboBox2->setEditable(true);
        lineEdit_14 = new QLineEdit(tab_3);
        lineEdit_14->setObjectName(QStringLiteral("lineEdit_14"));
        lineEdit_14->setGeometry(QRect(480, 250, 201, 21));
        lineEdit_14->setFont(font4);
        lineEdit_14->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;"));
        lineEdit_14->setAlignment(Qt::AlignCenter);
        lineEdit_14->setReadOnly(true);
        OutSerialPortcomboBox2 = new MyComboBox(tab_3);
        OutSerialPortcomboBox2->setObjectName(QStringLiteral("OutSerialPortcomboBox2"));
        OutSerialPortcomboBox2->setGeometry(QRect(420, 302, 151, 32));
        OutSerialPortcomboBox2->setFont(font2);
        OutSerialPortcomboBox2->setEditable(true);
        Autostartbase_comboBox = new QComboBox(tab_3);
        Autostartbase_comboBox->setObjectName(QStringLiteral("Autostartbase_comboBox"));
        Autostartbase_comboBox->setGeometry(QRect(250, 210, 61, 25));
        lineEdit_17 = new QLineEdit(tab_3);
        lineEdit_17->setObjectName(QStringLiteral("lineEdit_17"));
        lineEdit_17->setGeometry(QRect(30, 210, 201, 25));
        lineEdit_18 = new QLineEdit(tab_3);
        lineEdit_18->setObjectName(QStringLiteral("lineEdit_18"));
        lineEdit_18->setGeometry(QRect(30, 10, 201, 25));
        Choose_server = new QComboBox(tab_3);
        Choose_server->setObjectName(QStringLiteral("Choose_server"));
        Choose_server->setGeometry(QRect(250, 10, 161, 25));
        tabWidget->addTab(tab_3, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        textBrowser = new QTextBrowser(tab);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(20, 60, 741, 341));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy);
        testlog_pushButton = new QPushButton(tab);
        testlog_pushButton->setObjectName(QStringLiteral("testlog_pushButton"));
        testlog_pushButton->setGeometry(QRect(300, 20, 141, 25));
        teststart_pushButton = new QPushButton(tab);
        teststart_pushButton->setObjectName(QStringLiteral("teststart_pushButton"));
        teststart_pushButton->setGeometry(QRect(460, 20, 141, 25));
        teststop_pushButton = new QPushButton(tab);
        teststop_pushButton->setObjectName(QStringLiteral("teststop_pushButton"));
        teststop_pushButton->setGeometry(QRect(620, 20, 141, 25));
        tabWidget->addTab(tab, QString());

        retranslateUi(MyDialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MyDialog);
    } // setupUi

    void retranslateUi(QDialog *MyDialog)
    {
        MyDialog->setWindowTitle(QApplication::translate("MyDialog", "Dialog", Q_NULLPTR));
        pushButton_run_rnx2rtk_process_RGP->setText(QApplication::translate("MyDialog", " START  \n"
"Post Processing  \n"
"on recorded file", Q_NULLPTR));
        lineEdit_2->setText(QApplication::translate("MyDialog", "POST PROCESSING RESULTS", Q_NULLPTR));
        InfoProcess_lineEdit->setText(QString());
        AutoPostP_pushButton->setText(QApplication::translate("MyDialog", "START  \n"
" Logging data and  \n"
"Post processing", Q_NULLPTR));
        lineEdit_6->setText(QApplication::translate("MyDialog", "STR2STR output:", Q_NULLPTR));
        Stop_AutoPP_pushButton->setText(QApplication::translate("MyDialog", "CLOSE", Q_NULLPTR));
        lineEdit_16->setText(QApplication::translate("MyDialog", "CORS data from", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("MyDialog", "AUTOMATIC POST PROCESSING", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("MyDialog", "Search stations in a Km radius of", Q_NULLPTR));
        Radius_dmax->clear();
        Radius_dmax->insertItems(0, QStringList()
         << QApplication::translate("MyDialog", "10", Q_NULLPTR)
         << QApplication::translate("MyDialog", "20", Q_NULLPTR)
         << QApplication::translate("MyDialog", "30", Q_NULLPTR)
         << QApplication::translate("MyDialog", "40", Q_NULLPTR)
         << QApplication::translate("MyDialog", "50", Q_NULLPTR)
         << QApplication::translate("MyDialog", "60", Q_NULLPTR)
         << QApplication::translate("MyDialog", "70", Q_NULLPTR)
         << QApplication::translate("MyDialog", "80", Q_NULLPTR)
         << QApplication::translate("MyDialog", "90", Q_NULLPTR)
         << QApplication::translate("MyDialog", "100", Q_NULLPTR)
         << QApplication::translate("MyDialog", "120", Q_NULLPTR)
         << QApplication::translate("MyDialog", "150", Q_NULLPTR)
         << QApplication::translate("MyDialog", "200", Q_NULLPTR)
         << QApplication::translate("MyDialog", "300", Q_NULLPTR)
         << QApplication::translate("MyDialog", "400", Q_NULLPTR)
         << QApplication::translate("MyDialog", "500", Q_NULLPTR)
         << QApplication::translate("MyDialog", "1000", Q_NULLPTR)
         << QApplication::translate("MyDialog", "6000", Q_NULLPTR)
        );
        MinStation->clear();
        MinStation->insertItems(0, QStringList()
         << QApplication::translate("MyDialog", "1", Q_NULLPTR)
         << QApplication::translate("MyDialog", "2", Q_NULLPTR)
         << QApplication::translate("MyDialog", "3", Q_NULLPTR)
         << QApplication::translate("MyDialog", "4", Q_NULLPTR)
         << QApplication::translate("MyDialog", "5", Q_NULLPTR)
         << QApplication::translate("MyDialog", "6", Q_NULLPTR)
        );
        lineEdit_3->setText(QApplication::translate("MyDialog", "Nb of station to use", Q_NULLPTR));
        Save_options_pushButton->setText(QApplication::translate("MyDialog", "SAVE OPTIONS", Q_NULLPTR));
        lineEdit_4->setText(QApplication::translate("MyDialog", "Capture time in mn", Q_NULLPTR));
        CaptureTime->clear();
        CaptureTime->insertItems(0, QStringList()
         << QApplication::translate("MyDialog", "31", Q_NULLPTR)
         << QApplication::translate("MyDialog", "45", Q_NULLPTR)
         << QApplication::translate("MyDialog", "60", Q_NULLPTR)
         << QApplication::translate("MyDialog", "90", Q_NULLPTR)
         << QApplication::translate("MyDialog", "120", Q_NULLPTR)
         << QApplication::translate("MyDialog", "240", Q_NULLPTR)
         << QApplication::translate("MyDialog", "360", Q_NULLPTR)
         << QApplication::translate("MyDialog", "480", Q_NULLPTR)
         << QApplication::translate("MyDialog", "540", Q_NULLPTR)
         << QApplication::translate("MyDialog", "720", Q_NULLPTR)
         << QApplication::translate("MyDialog", "1440", Q_NULLPTR)
        );
        lineEdit_5->setText(QApplication::translate("MyDialog", "Wait before processing in mn", Q_NULLPTR));
        WaitingTime->clear();
        WaitingTime->insertItems(0, QStringList()
         << QApplication::translate("MyDialog", "0", Q_NULLPTR)
         << QApplication::translate("MyDialog", "1", Q_NULLPTR)
         << QApplication::translate("MyDialog", "15", Q_NULLPTR)
         << QApplication::translate("MyDialog", "30", Q_NULLPTR)
         << QApplication::translate("MyDialog", "45", Q_NULLPTR)
         << QApplication::translate("MyDialog", "60", Q_NULLPTR)
        );
        lineEdit_15->setText(QApplication::translate("MyDialog", "RTCM MESSAGES", Q_NULLPTR));
        lineEdit_10->setText(QApplication::translate("MyDialog", "INPUT PORT", Q_NULLPTR));
        InBaudratecomboBox2->clear();
        InBaudratecomboBox2->insertItems(0, QStringList()
         << QApplication::translate("MyDialog", "115200", Q_NULLPTR)
         << QApplication::translate("MyDialog", "57600", Q_NULLPTR)
         << QApplication::translate("MyDialog", "38400", Q_NULLPTR)
         << QApplication::translate("MyDialog", "9600", Q_NULLPTR)
        );
        lineEdit_11->setText(QApplication::translate("MyDialog", "BAUDS", Q_NULLPTR));
        RtcmMsgcomboBox2->clear();
        RtcmMsgcomboBox2->insertItems(0, QStringList()
         << QApplication::translate("MyDialog", "1004,1006,1008,1012,1019,1020", Q_NULLPTR)
        );
        InFormatcomboBox2->clear();
        InFormatcomboBox2->insertItems(0, QStringList()
         << QApplication::translate("MyDialog", "ubx", Q_NULLPTR)
         << QApplication::translate("MyDialog", "nvs", Q_NULLPTR)
         << QApplication::translate("MyDialog", "oem3", Q_NULLPTR)
         << QApplication::translate("MyDialog", "nov", Q_NULLPTR)
         << QApplication::translate("MyDialog", "ss2", Q_NULLPTR)
         << QApplication::translate("MyDialog", "hemis", Q_NULLPTR)
         << QApplication::translate("MyDialog", "stq", Q_NULLPTR)
         << QApplication::translate("MyDialog", "javad", Q_NULLPTR)
         << QApplication::translate("MyDialog", "binex", Q_NULLPTR)
         << QApplication::translate("MyDialog", "rtcm2", Q_NULLPTR)
         << QApplication::translate("MyDialog", "rtcm3", Q_NULLPTR)
        );
        lineEdit_7->setText(QApplication::translate("MyDialog", "FORMAT", Q_NULLPTR));
        lineEdit_8->setText(QApplication::translate("MyDialog", "OUTPUT PORT", Q_NULLPTR));
        lineEdit_9->setText(QApplication::translate("MyDialog", "FORMAT", Q_NULLPTR));
        lineEdit_12->setText(QApplication::translate("MyDialog", "LOG INPUT", Q_NULLPTR));
        OutBaudRatecomboBox2->clear();
        OutBaudRatecomboBox2->insertItems(0, QStringList()
         << QApplication::translate("MyDialog", "57600", Q_NULLPTR)
         << QApplication::translate("MyDialog", "9600", Q_NULLPTR)
         << QApplication::translate("MyDialog", "38400", Q_NULLPTR)
         << QApplication::translate("MyDialog", "115200", Q_NULLPTR)
        );
        lineEdit_13->setText(QApplication::translate("MyDialog", "BAUDS", Q_NULLPTR));
        InSerialPortcomboBox2->clear();
        InSerialPortcomboBox2->insertItems(0, QStringList()
         << QApplication::translate("MyDialog", "serial://ttyACM0", Q_NULLPTR)
         << QApplication::translate("MyDialog", "serial://AMA0", Q_NULLPTR)
         << QApplication::translate("MyDialog", "serial://USB0", Q_NULLPTR)
        );
        OutFormatcomboBox2->clear();
        OutFormatcomboBox2->insertItems(0, QStringList()
         << QApplication::translate("MyDialog", "rtcm3", Q_NULLPTR)
         << QApplication::translate("MyDialog", "rtcm2", Q_NULLPTR)
        );
        lineEdit_14->setText(QApplication::translate("MyDialog", "BASE OUTPUT ", Q_NULLPTR));
        OutSerialPortcomboBox2->clear();
        OutSerialPortcomboBox2->insertItems(0, QStringList()
         << QApplication::translate("MyDialog", "serial://ttyUSB0", Q_NULLPTR)
         << QApplication::translate("MyDialog", "serial://ttyAMA0", Q_NULLPTR)
         << QApplication::translate("MyDialog", "serial://ttyACM0", Q_NULLPTR)
         << QApplication::translate("MyDialog", "File", Q_NULLPTR)
        );
        Autostartbase_comboBox->clear();
        Autostartbase_comboBox->insertItems(0, QStringList()
         << QApplication::translate("MyDialog", "off", Q_NULLPTR)
         << QApplication::translate("MyDialog", "on", Q_NULLPTR)
        );
        lineEdit_17->setText(QApplication::translate("MyDialog", "Autostart base with results", Q_NULLPTR));
        lineEdit_18->setText(QApplication::translate("MyDialog", "Use CORS data from server:", Q_NULLPTR));
        Choose_server->clear();
        Choose_server->insertItems(0, QStringList()
         << QApplication::translate("MyDialog", "rgpdata.ign.fr", Q_NULLPTR)
         << QApplication::translate("MyDialog", "geodesy.noaa.gov", Q_NULLPTR)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MyDialog", "CONFIGURATION", Q_NULLPTR));
        testlog_pushButton->setText(QApplication::translate("MyDialog", "manual start log", Q_NULLPTR));
        teststart_pushButton->setText(QApplication::translate("MyDialog", "manual start base", Q_NULLPTR));
        teststop_pushButton->setText(QApplication::translate("MyDialog", "stop str2str", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MyDialog", "DEBUG", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MyDialog: public Ui_MyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYDIALOG_H
