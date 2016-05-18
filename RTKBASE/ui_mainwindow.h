/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon May 16 01:18:50 2016
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *RoverButton;
    QPushButton *BasestationButton;
    QLineEdit *TimeEdit;
    QLineEdit *TimeRetourEdit;
    QPushButton *QuitterButton;
    QTextEdit *textEdit;
    QLabel *Rtkliblabel;
    QLabel *ensglabel;
    QLabel *ensgIconlabel;
    QPushButton *HelpButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 480);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        RoverButton = new QPushButton(centralWidget);
        RoverButton->setObjectName(QString::fromUtf8("RoverButton"));
        RoverButton->setGeometry(QRect(20, 100, 261, 171));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        RoverButton->setFont(font);
        BasestationButton = new QPushButton(centralWidget);
        BasestationButton->setObjectName(QString::fromUtf8("BasestationButton"));
        BasestationButton->setGeometry(QRect(320, 100, 251, 171));
        BasestationButton->setFont(font);
        TimeEdit = new QLineEdit(centralWidget);
        TimeEdit->setObjectName(QString::fromUtf8("TimeEdit"));
        TimeEdit->setEnabled(false);
        TimeEdit->setGeometry(QRect(310, -1, 61, 27));
        TimeRetourEdit = new QLineEdit(centralWidget);
        TimeRetourEdit->setObjectName(QString::fromUtf8("TimeRetourEdit"));
        TimeRetourEdit->setEnabled(false);
        TimeRetourEdit->setGeometry(QRect(380, -1, 131, 27));
        TimeRetourEdit->setAcceptDrops(true);
        QuitterButton = new QPushButton(centralWidget);
        QuitterButton->setObjectName(QString::fromUtf8("QuitterButton"));
        QuitterButton->setGeometry(QRect(660, 120, 91, 81));
        QuitterButton->setFont(font);
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(100, 40, 211, 41));
        Rtkliblabel = new QLabel(centralWidget);
        Rtkliblabel->setObjectName(QString::fromUtf8("Rtkliblabel"));
        Rtkliblabel->setGeometry(QRect(10, 280, 81, 71));
        ensglabel = new QLabel(centralWidget);
        ensglabel->setObjectName(QString::fromUtf8("ensglabel"));
        ensglabel->setGeometry(QRect(10, 337, 71, 81));
        ensgIconlabel = new QLabel(centralWidget);
        ensgIconlabel->setObjectName(QString::fromUtf8("ensgIconlabel"));
        ensgIconlabel->setGeometry(QRect(353, 38, 111, 61));
        HelpButton = new QPushButton(centralWidget);
        HelpButton->setObjectName(QString::fromUtf8("HelpButton"));
        HelpButton->setGeometry(QRect(660, 205, 91, 51));
        HelpButton->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 30));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "RTKLIB for Raspberry", 0, QApplication::UnicodeUTF8));
        RoverButton->setText(QApplication::translate("MainWindow", "ROVER", 0, QApplication::UnicodeUTF8));
        BasestationButton->setText(QApplication::translate("MainWindow", "BASESTATION", 0, QApplication::UnicodeUTF8));
        TimeEdit->setText(QApplication::translate("MainWindow", "Time:", 0, QApplication::UnicodeUTF8));
        TimeRetourEdit->setText(QString());
        QuitterButton->setText(QApplication::translate("MainWindow", "CLOSE", 0, QApplication::UnicodeUTF8));
        textEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Oxygen-Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:16pt; font-weight:600; text-decoration: underline;\">RTKLIB</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        Rtkliblabel->setText(QString());
        ensglabel->setText(QString());
        ensgIconlabel->setText(QString());
        HelpButton->setText(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
