/********************************************************************************
** Form generated from reading UI file 'optionsstr2str.ui'
**
** Created: Sun May 22 00:27:28 2016
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONSSTR2STR_H
#define UI_OPTIONSSTR2STR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_OptionsStr2str
{
public:
    QRadioButton *RTCM2radioButton;
    QRadioButton *RTCM3radioButton;
    QRadioButton *NOVradioButton;
    QRadioButton *OEM3radioButton;
    QRadioButton *UBXradioButton;
    QRadioButton *SS2radioButton;
    QRadioButton *HEMISradioButton;
    QRadioButton *STQradioButton;
    QRadioButton *JAVADradioButton;
    QRadioButton *NVSradioButton;
    QRadioButton *BINEXradioButton;
    QRadioButton *RTCM3OutradioButton;
    QLineEdit *InStreamlineEdit;
    QLineEdit *InStreamlineEdit_2;
    QPushButton *pushButtonDefault1;
    QPushButton *pushButtonDefault2;
    QTextEdit *textEditDefault2;
    QTextEdit *textEditDefault1;

    void setupUi(QDialog *OptionsStr2str)
    {
        if (OptionsStr2str->objectName().isEmpty())
            OptionsStr2str->setObjectName(QString::fromUtf8("OptionsStr2str"));
        OptionsStr2str->resize(800, 398);
        RTCM2radioButton = new QRadioButton(OptionsStr2str);
        RTCM2radioButton->setObjectName(QString::fromUtf8("RTCM2radioButton"));
        RTCM2radioButton->setGeometry(QRect(20, 40, 117, 22));
        RTCM3radioButton = new QRadioButton(OptionsStr2str);
        RTCM3radioButton->setObjectName(QString::fromUtf8("RTCM3radioButton"));
        RTCM3radioButton->setGeometry(QRect(20, 70, 117, 22));
        NOVradioButton = new QRadioButton(OptionsStr2str);
        NOVradioButton->setObjectName(QString::fromUtf8("NOVradioButton"));
        NOVradioButton->setGeometry(QRect(20, 100, 117, 22));
        OEM3radioButton = new QRadioButton(OptionsStr2str);
        OEM3radioButton->setObjectName(QString::fromUtf8("OEM3radioButton"));
        OEM3radioButton->setGeometry(QRect(20, 130, 117, 22));
        UBXradioButton = new QRadioButton(OptionsStr2str);
        UBXradioButton->setObjectName(QString::fromUtf8("UBXradioButton"));
        UBXradioButton->setGeometry(QRect(20, 160, 117, 22));
        SS2radioButton = new QRadioButton(OptionsStr2str);
        SS2radioButton->setObjectName(QString::fromUtf8("SS2radioButton"));
        SS2radioButton->setGeometry(QRect(130, 160, 117, 22));
        HEMISradioButton = new QRadioButton(OptionsStr2str);
        HEMISradioButton->setObjectName(QString::fromUtf8("HEMISradioButton"));
        HEMISradioButton->setGeometry(QRect(130, 40, 117, 22));
        STQradioButton = new QRadioButton(OptionsStr2str);
        STQradioButton->setObjectName(QString::fromUtf8("STQradioButton"));
        STQradioButton->setGeometry(QRect(20, 190, 117, 22));
        JAVADradioButton = new QRadioButton(OptionsStr2str);
        JAVADradioButton->setObjectName(QString::fromUtf8("JAVADradioButton"));
        JAVADradioButton->setGeometry(QRect(130, 70, 117, 22));
        NVSradioButton = new QRadioButton(OptionsStr2str);
        NVSradioButton->setObjectName(QString::fromUtf8("NVSradioButton"));
        NVSradioButton->setGeometry(QRect(130, 100, 117, 22));
        BINEXradioButton = new QRadioButton(OptionsStr2str);
        BINEXradioButton->setObjectName(QString::fromUtf8("BINEXradioButton"));
        BINEXradioButton->setGeometry(QRect(130, 130, 117, 22));
        RTCM3OutradioButton = new QRadioButton(OptionsStr2str);
        RTCM3OutradioButton->setObjectName(QString::fromUtf8("RTCM3OutradioButton"));
        RTCM3OutradioButton->setGeometry(QRect(270, 40, 117, 22));
        InStreamlineEdit = new QLineEdit(OptionsStr2str);
        InStreamlineEdit->setObjectName(QString::fromUtf8("InStreamlineEdit"));
        InStreamlineEdit->setGeometry(QRect(60, 14, 113, 27));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        InStreamlineEdit->setFont(font);
        InStreamlineEdit->setAlignment(Qt::AlignCenter);
        InStreamlineEdit_2 = new QLineEdit(OptionsStr2str);
        InStreamlineEdit_2->setObjectName(QString::fromUtf8("InStreamlineEdit_2"));
        InStreamlineEdit_2->setGeometry(QRect(240, 14, 113, 27));
        InStreamlineEdit_2->setFont(font);
        InStreamlineEdit_2->setAlignment(Qt::AlignCenter);
        pushButtonDefault1 = new QPushButton(OptionsStr2str);
        pushButtonDefault1->setObjectName(QString::fromUtf8("pushButtonDefault1"));
        pushButtonDefault1->setGeometry(QRect(660, 220, 99, 51));
        pushButtonDefault2 = new QPushButton(OptionsStr2str);
        pushButtonDefault2->setObjectName(QString::fromUtf8("pushButtonDefault2"));
        pushButtonDefault2->setGeometry(QRect(660, 280, 99, 51));
        textEditDefault2 = new QTextEdit(OptionsStr2str);
        textEditDefault2->setObjectName(QString::fromUtf8("textEditDefault2"));
        textEditDefault2->setGeometry(QRect(20, 280, 611, 51));
        textEditDefault1 = new QTextEdit(OptionsStr2str);
        textEditDefault1->setObjectName(QString::fromUtf8("textEditDefault1"));
        textEditDefault1->setGeometry(QRect(20, 230, 611, 31));

        retranslateUi(OptionsStr2str);

        QMetaObject::connectSlotsByName(OptionsStr2str);
    } // setupUi

    void retranslateUi(QDialog *OptionsStr2str)
    {
        OptionsStr2str->setWindowTitle(QApplication::translate("OptionsStr2str", "Dialog", 0, QApplication::UnicodeUTF8));
        RTCM2radioButton->setText(QApplication::translate("OptionsStr2str", "RTCM2", 0, QApplication::UnicodeUTF8));
        RTCM3radioButton->setText(QApplication::translate("OptionsStr2str", "RTCM3", 0, QApplication::UnicodeUTF8));
        NOVradioButton->setText(QApplication::translate("OptionsStr2str", "Nov", 0, QApplication::UnicodeUTF8));
        OEM3radioButton->setText(QApplication::translate("OptionsStr2str", "Oem3", 0, QApplication::UnicodeUTF8));
        UBXradioButton->setText(QApplication::translate("OptionsStr2str", "Ubx", 0, QApplication::UnicodeUTF8));
        SS2radioButton->setText(QApplication::translate("OptionsStr2str", "Ss2", 0, QApplication::UnicodeUTF8));
        HEMISradioButton->setText(QApplication::translate("OptionsStr2str", "Hemis", 0, QApplication::UnicodeUTF8));
        STQradioButton->setText(QApplication::translate("OptionsStr2str", "Stq", 0, QApplication::UnicodeUTF8));
        JAVADradioButton->setText(QApplication::translate("OptionsStr2str", "Javad", 0, QApplication::UnicodeUTF8));
        NVSradioButton->setText(QApplication::translate("OptionsStr2str", "Nvs", 0, QApplication::UnicodeUTF8));
        BINEXradioButton->setText(QApplication::translate("OptionsStr2str", "Binex", 0, QApplication::UnicodeUTF8));
        RTCM3OutradioButton->setText(QApplication::translate("OptionsStr2str", "RTCM3", 0, QApplication::UnicodeUTF8));
        InStreamlineEdit->setText(QApplication::translate("OptionsStr2str", "in stream", 0, QApplication::UnicodeUTF8));
        InStreamlineEdit_2->setText(QApplication::translate("OptionsStr2str", "out stream", 0, QApplication::UnicodeUTF8));
        pushButtonDefault1->setText(QApplication::translate("OptionsStr2str", "default 1", 0, QApplication::UnicodeUTF8));
        pushButtonDefault2->setText(QApplication::translate("OptionsStr2str", "default 2", 0, QApplication::UnicodeUTF8));
        textEditDefault2->setHtml(QApplication::translate("OptionsStr2str", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">&quot;-in&quot;,&quot;serial://ttyACM0:115200:8:n:1:#ubx&quot;,&quot;-out&quot;,&quot;serial://ttyUSB0:57600:8:n:1:#RTCM3&quot;,&quot;-msg&quot;,&quot;1004,1019,1012,1020,1006,1008&quot;</p></body></html>", 0, QApplication::UnicodeUTF8));
        textEditDefault1->setHtml(QApplication::translate("OptionsStr2str", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">&quot;-in&quot;,&quot;serial://ttyACM0:115200:8:n:1:#ubx&quot;,&quot;-msg&quot;,&quot;1004,1019,1012,1020,1006,1008&quot;</p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OptionsStr2str: public Ui_OptionsStr2str {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONSSTR2STR_H
