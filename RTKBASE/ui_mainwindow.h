/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

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
    QLabel *Rtkliblabel;
    QLabel *ensglabel;
    QLabel *ensgIconlabel;
    QPushButton *HelpButton;
    QPushButton *PowerOFFButton;
    QLineEdit *lineEdit;
    QPushButton *RTK_BASE_position;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 480);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        RoverButton = new QPushButton(centralWidget);
        RoverButton->setObjectName(QStringLiteral("RoverButton"));
        RoverButton->setGeometry(QRect(20, 100, 261, 171));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        RoverButton->setFont(font);
        RoverButton->setStyleSheet(QLatin1String("border-radius: 20px;\n"
"border: 1px solid black;"));
        BasestationButton = new QPushButton(centralWidget);
        BasestationButton->setObjectName(QStringLiteral("BasestationButton"));
        BasestationButton->setGeometry(QRect(310, 100, 271, 171));
        BasestationButton->setFont(font);
        BasestationButton->setStyleSheet(QLatin1String("border-radius: 20px;\n"
"border: 1px solid black;"));
        TimeEdit = new QLineEdit(centralWidget);
        TimeEdit->setObjectName(QStringLiteral("TimeEdit"));
        TimeEdit->setEnabled(false);
        TimeEdit->setGeometry(QRect(290, -1, 71, 27));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        TimeEdit->setFont(font1);
        TimeEdit->setAlignment(Qt::AlignCenter);
        TimeRetourEdit = new QLineEdit(centralWidget);
        TimeRetourEdit->setObjectName(QStringLiteral("TimeRetourEdit"));
        TimeRetourEdit->setEnabled(false);
        TimeRetourEdit->setGeometry(QRect(380, -1, 171, 27));
        TimeRetourEdit->setFont(font1);
        TimeRetourEdit->setAcceptDrops(true);
        TimeRetourEdit->setAlignment(Qt::AlignCenter);
        QuitterButton = new QPushButton(centralWidget);
        QuitterButton->setObjectName(QStringLiteral("QuitterButton"));
        QuitterButton->setGeometry(QRect(610, 145, 151, 81));
        QuitterButton->setFont(font1);
        QuitterButton->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        Rtkliblabel = new QLabel(centralWidget);
        Rtkliblabel->setObjectName(QStringLiteral("Rtkliblabel"));
        Rtkliblabel->setGeometry(QRect(10, 280, 81, 71));
        ensglabel = new QLabel(centralWidget);
        ensglabel->setObjectName(QStringLiteral("ensglabel"));
        ensglabel->setGeometry(QRect(10, 337, 71, 81));
        ensgIconlabel = new QLabel(centralWidget);
        ensgIconlabel->setObjectName(QStringLiteral("ensgIconlabel"));
        ensgIconlabel->setGeometry(QRect(353, 38, 111, 61));
        HelpButton = new QPushButton(centralWidget);
        HelpButton->setObjectName(QStringLiteral("HelpButton"));
        HelpButton->setGeometry(QRect(610, 240, 151, 81));
        HelpButton->setFont(font1);
        HelpButton->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        PowerOFFButton = new QPushButton(centralWidget);
        PowerOFFButton->setObjectName(QStringLiteral("PowerOFFButton"));
        PowerOFFButton->setGeometry(QRect(610, 55, 151, 81));
        PowerOFFButton->setFont(font1);
        PowerOFFButton->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(90, 30, 211, 51));
        QFont font2;
        font2.setPointSize(25);
        font2.setBold(true);
        font2.setWeight(75);
        lineEdit->setFont(font2);
        lineEdit->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;"));
        lineEdit->setAlignment(Qt::AlignCenter);
        RTK_BASE_position = new QPushButton(centralWidget);
        RTK_BASE_position->setObjectName(QStringLiteral("RTK_BASE_position"));
        RTK_BASE_position->setGeometry(QRect(320, 270, 251, 51));
        MainWindow->setCentralWidget(centralWidget);
        RoverButton->raise();
        BasestationButton->raise();
        TimeRetourEdit->raise();
        QuitterButton->raise();
        Rtkliblabel->raise();
        ensglabel->raise();
        ensgIconlabel->raise();
        HelpButton->raise();
        PowerOFFButton->raise();
        TimeEdit->raise();
        lineEdit->raise();
        RTK_BASE_position->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "RTKLIB for Raspberry", 0));
        RoverButton->setText(QApplication::translate("MainWindow", "ROVER", 0));
        BasestationButton->setText(QApplication::translate("MainWindow", "BASESTATION", 0));
        TimeEdit->setText(QApplication::translate("MainWindow", "TIME:", 0));
        TimeRetourEdit->setText(QString());
        QuitterButton->setText(QApplication::translate("MainWindow", "CLOSE GUI", 0));
        Rtkliblabel->setText(QString());
        ensglabel->setText(QString());
        ensgIconlabel->setText(QString());
        HelpButton->setText(QApplication::translate("MainWindow", "HELP", 0));
        PowerOFFButton->setText(QApplication::translate("MainWindow", "POWER OFF", 0));
        lineEdit->setText(QApplication::translate("MainWindow", "RTKLIB", 0));
        RTK_BASE_position->setText(QApplication::translate("MainWindow", " Post Processing RTK_BASE position \n"
"  using CORS stations ", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
