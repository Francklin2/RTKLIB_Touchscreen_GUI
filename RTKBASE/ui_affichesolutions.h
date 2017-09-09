/********************************************************************************
** Form generated from reading UI file 'affichesolutions.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AFFICHESOLUTIONS_H
#define UI_AFFICHESOLUTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_AfficheSolutions
{
public:
    QGraphicsView *AfficheSolutionsgraphicsView;
    QLineEdit *lineEditStatut;
    QLineEdit *lineEditPositionXYZ;
    QLineEdit *lineEditPositionX;
    QLineEdit *lineEditPositionY;
    QLineEdit *lineEditPositionZ;
    QLineEdit *lineEditPositionH;
    QLineEdit *lineEditPositionLat;
    QLineEdit *lineEditPositionLong;
    QLineEdit *lineEditPositionLLH;
    QLineEdit *lineEditRunningTime;
    QLineEdit *lineEditTimeToRun;
    QLineEdit *lineEditPositioningMode;
    QLineEdit *lineEditModePosition;
    QLineEdit *lineEditSatellites;
    QLineEdit *lineEditSatRover;
    QLineEdit *lineEditStream;
    QProgressBar *progressBarSatellites;
    QPushButton *PushButtonSauvegarde;
    QLineEdit *lineEditSolutionStatus1;
    QLineEdit *lineEditSolutionStatus2;
    QCustomPlot *widget;
    QLineEdit *MessageUserlineEdit;
    QLineEdit *lineEditSatBase;
    QLineEdit *lineEditSatValides;
    QPushButton *pushButtonXYZ;
    QPushButton *pushButtonLLH;
    QPushButton *pushButtonSat1;
    QPushButton *pushButtonSat2;
    QPushButton *pushButtonSat3;
    QLineEdit *lineEditPosEvol;
    QPushButton *PushButtonSauveOptions;
    QLineEdit *lineEditTimeGPS;
    QLineEdit *lineEditGPSTime;
    QLineEdit *lineEditTimeSYS;
    QLineEdit *lineEditSYSTime;
    QPushButton *pushButtonSetSYSTime;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *AfficheSolutions)
    {
        if (AfficheSolutions->objectName().isEmpty())
            AfficheSolutions->setObjectName(QStringLiteral("AfficheSolutions"));
        AfficheSolutions->resize(800, 480);
        AfficheSolutionsgraphicsView = new QGraphicsView(AfficheSolutions);
        AfficheSolutionsgraphicsView->setObjectName(QStringLiteral("AfficheSolutionsgraphicsView"));
        AfficheSolutionsgraphicsView->setEnabled(true);
        AfficheSolutionsgraphicsView->setGeometry(QRect(10, 20, 781, 431));
        AfficheSolutionsgraphicsView->setAutoFillBackground(false);
        QBrush brush(QColor(0, 0, 0, 0));
        brush.setStyle(Qt::NoBrush);
        AfficheSolutionsgraphicsView->setBackgroundBrush(brush);
        QBrush brush1(QColor(0, 0, 0, 0));
        brush1.setStyle(Qt::NoBrush);
        AfficheSolutionsgraphicsView->setForegroundBrush(brush1);
        lineEditStatut = new QLineEdit(AfficheSolutions);
        lineEditStatut->setObjectName(QStringLiteral("lineEditStatut"));
        lineEditStatut->setEnabled(true);
        lineEditStatut->setGeometry(QRect(242, 30, 251, 31));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        lineEditStatut->setFont(font);
        lineEditStatut->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
""));
        lineEditStatut->setAlignment(Qt::AlignCenter);
        lineEditStatut->setDragEnabled(false);
        lineEditStatut->setReadOnly(true);
        lineEditPositionXYZ = new QLineEdit(AfficheSolutions);
        lineEditPositionXYZ->setObjectName(QStringLiteral("lineEditPositionXYZ"));
        lineEditPositionXYZ->setEnabled(true);
        lineEditPositionXYZ->setGeometry(QRect(50, 160, 113, 27));
        lineEditPositionXYZ->setDragEnabled(false);
        lineEditPositionXYZ->setReadOnly(true);
        lineEditPositionX = new QLineEdit(AfficheSolutions);
        lineEditPositionX->setObjectName(QStringLiteral("lineEditPositionX"));
        lineEditPositionX->setEnabled(true);
        lineEditPositionX->setGeometry(QRect(180, 160, 191, 27));
        lineEditPositionX->setDragEnabled(false);
        lineEditPositionX->setReadOnly(true);
        lineEditPositionY = new QLineEdit(AfficheSolutions);
        lineEditPositionY->setObjectName(QStringLiteral("lineEditPositionY"));
        lineEditPositionY->setEnabled(true);
        lineEditPositionY->setGeometry(QRect(180, 200, 191, 27));
        lineEditPositionY->setDragEnabled(false);
        lineEditPositionY->setReadOnly(true);
        lineEditPositionZ = new QLineEdit(AfficheSolutions);
        lineEditPositionZ->setObjectName(QStringLiteral("lineEditPositionZ"));
        lineEditPositionZ->setEnabled(true);
        lineEditPositionZ->setGeometry(QRect(180, 240, 191, 27));
        lineEditPositionZ->setDragEnabled(false);
        lineEditPositionZ->setReadOnly(true);
        lineEditPositionH = new QLineEdit(AfficheSolutions);
        lineEditPositionH->setObjectName(QStringLiteral("lineEditPositionH"));
        lineEditPositionH->setEnabled(true);
        lineEditPositionH->setGeometry(QRect(180, 360, 191, 27));
        lineEditPositionH->setDragEnabled(false);
        lineEditPositionH->setReadOnly(true);
        lineEditPositionLat = new QLineEdit(AfficheSolutions);
        lineEditPositionLat->setObjectName(QStringLiteral("lineEditPositionLat"));
        lineEditPositionLat->setEnabled(true);
        lineEditPositionLat->setGeometry(QRect(180, 280, 191, 27));
        lineEditPositionLat->setDragEnabled(false);
        lineEditPositionLat->setReadOnly(true);
        lineEditPositionLong = new QLineEdit(AfficheSolutions);
        lineEditPositionLong->setObjectName(QStringLiteral("lineEditPositionLong"));
        lineEditPositionLong->setEnabled(true);
        lineEditPositionLong->setGeometry(QRect(180, 320, 191, 27));
        lineEditPositionLong->setDragEnabled(false);
        lineEditPositionLong->setReadOnly(true);
        lineEditPositionLLH = new QLineEdit(AfficheSolutions);
        lineEditPositionLLH->setObjectName(QStringLiteral("lineEditPositionLLH"));
        lineEditPositionLLH->setEnabled(true);
        lineEditPositionLLH->setGeometry(QRect(50, 280, 113, 27));
        lineEditPositionLLH->setDragEnabled(false);
        lineEditPositionLLH->setReadOnly(true);
        lineEditRunningTime = new QLineEdit(AfficheSolutions);
        lineEditRunningTime->setObjectName(QStringLiteral("lineEditRunningTime"));
        lineEditRunningTime->setEnabled(true);
        lineEditRunningTime->setGeometry(QRect(40, 80, 91, 27));
        lineEditRunningTime->setDragEnabled(false);
        lineEditRunningTime->setReadOnly(true);
        lineEditTimeToRun = new QLineEdit(AfficheSolutions);
        lineEditTimeToRun->setObjectName(QStringLiteral("lineEditTimeToRun"));
        lineEditTimeToRun->setEnabled(true);
        lineEditTimeToRun->setGeometry(QRect(140, 80, 71, 27));
        lineEditTimeToRun->setMaxLength(8);
        lineEditTimeToRun->setAlignment(Qt::AlignCenter);
        lineEditTimeToRun->setDragEnabled(false);
        lineEditTimeToRun->setReadOnly(true);
        lineEditPositioningMode = new QLineEdit(AfficheSolutions);
        lineEditPositioningMode->setObjectName(QStringLiteral("lineEditPositioningMode"));
        lineEditPositioningMode->setEnabled(true);
        lineEditPositioningMode->setGeometry(QRect(60, 120, 81, 27));
        lineEditPositioningMode->setDragEnabled(false);
        lineEditPositioningMode->setReadOnly(true);
        lineEditModePosition = new QLineEdit(AfficheSolutions);
        lineEditModePosition->setObjectName(QStringLiteral("lineEditModePosition"));
        lineEditModePosition->setEnabled(true);
        lineEditModePosition->setGeometry(QRect(150, 120, 131, 27));
        lineEditModePosition->setStyleSheet(QStringLiteral(""));
        lineEditModePosition->setDragEnabled(false);
        lineEditModePosition->setReadOnly(true);
        lineEditSatellites = new QLineEdit(AfficheSolutions);
        lineEditSatellites->setObjectName(QStringLiteral("lineEditSatellites"));
        lineEditSatellites->setEnabled(true);
        lineEditSatellites->setGeometry(QRect(240, 30, 251, 31));
        lineEditSatellites->setFont(font);
        lineEditSatellites->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
""));
        lineEditSatellites->setAlignment(Qt::AlignCenter);
        lineEditSatellites->setDragEnabled(false);
        lineEditSatellites->setReadOnly(true);
        lineEditSatRover = new QLineEdit(AfficheSolutions);
        lineEditSatRover->setObjectName(QStringLiteral("lineEditSatRover"));
        lineEditSatRover->setEnabled(true);
        lineEditSatRover->setGeometry(QRect(390, 160, 311, 27));
        lineEditSatRover->setDragEnabled(false);
        lineEditSatRover->setReadOnly(true);
        lineEditStream = new QLineEdit(AfficheSolutions);
        lineEditStream->setObjectName(QStringLiteral("lineEditStream"));
        lineEditStream->setEnabled(true);
        lineEditStream->setGeometry(QRect(240, 30, 251, 31));
        lineEditStream->setFont(font);
        lineEditStream->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
""));
        lineEditStream->setAlignment(Qt::AlignCenter);
        lineEditStream->setDragEnabled(false);
        lineEditStream->setReadOnly(true);
        progressBarSatellites = new QProgressBar(AfficheSolutions);
        progressBarSatellites->setObjectName(QStringLiteral("progressBarSatellites"));
        progressBarSatellites->setGeometry(QRect(40, 32, 191, 23));
        progressBarSatellites->setMaximum(32);
        progressBarSatellites->setValue(0);
        PushButtonSauvegarde = new QPushButton(AfficheSolutions);
        PushButtonSauvegarde->setObjectName(QStringLiteral("PushButtonSauvegarde"));
        PushButtonSauvegarde->setGeometry(QRect(650, 380, 131, 51));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        PushButtonSauvegarde->setFont(font1);
        PushButtonSauvegarde->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        lineEditSolutionStatus1 = new QLineEdit(AfficheSolutions);
        lineEditSolutionStatus1->setObjectName(QStringLiteral("lineEditSolutionStatus1"));
        lineEditSolutionStatus1->setEnabled(true);
        lineEditSolutionStatus1->setGeometry(QRect(310, 120, 111, 27));
        lineEditSolutionStatus1->setDragEnabled(false);
        lineEditSolutionStatus1->setReadOnly(true);
        lineEditSolutionStatus2 = new QLineEdit(AfficheSolutions);
        lineEditSolutionStatus2->setObjectName(QStringLiteral("lineEditSolutionStatus2"));
        lineEditSolutionStatus2->setEnabled(true);
        lineEditSolutionStatus2->setGeometry(QRect(430, 120, 111, 27));
        lineEditSolutionStatus2->setDragEnabled(false);
        lineEditSolutionStatus2->setReadOnly(true);
        widget = new QCustomPlot(AfficheSolutions);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 70, 701, 371));
        MessageUserlineEdit = new QLineEdit(AfficheSolutions);
        MessageUserlineEdit->setObjectName(QStringLiteral("MessageUserlineEdit"));
        MessageUserlineEdit->setGeometry(QRect(50, 400, 551, 27));
        lineEditSatBase = new QLineEdit(AfficheSolutions);
        lineEditSatBase->setObjectName(QStringLiteral("lineEditSatBase"));
        lineEditSatBase->setEnabled(true);
        lineEditSatBase->setGeometry(QRect(390, 200, 311, 27));
        lineEditSatBase->setDragEnabled(false);
        lineEditSatBase->setReadOnly(true);
        lineEditSatValides = new QLineEdit(AfficheSolutions);
        lineEditSatValides->setObjectName(QStringLiteral("lineEditSatValides"));
        lineEditSatValides->setEnabled(true);
        lineEditSatValides->setGeometry(QRect(390, 240, 311, 27));
        lineEditSatValides->setDragEnabled(false);
        lineEditSatValides->setReadOnly(true);
        pushButtonXYZ = new QPushButton(AfficheSolutions);
        buttonGroup = new QButtonGroup(AfficheSolutions);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(pushButtonXYZ);
        pushButtonXYZ->setObjectName(QStringLiteral("pushButtonXYZ"));
        pushButtonXYZ->setGeometry(QRect(670, 20, 71, 51));
        pushButtonXYZ->setFont(font1);
        pushButtonXYZ->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        pushButtonLLH = new QPushButton(AfficheSolutions);
        buttonGroup->addButton(pushButtonLLH);
        pushButtonLLH->setObjectName(QStringLiteral("pushButtonLLH"));
        pushButtonLLH->setGeometry(QRect(570, 20, 71, 51));
        pushButtonLLH->setFont(font1);
        pushButtonLLH->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        pushButtonSat1 = new QPushButton(AfficheSolutions);
        pushButtonSat1->setObjectName(QStringLiteral("pushButtonSat1"));
        pushButtonSat1->setGeometry(QRect(510, 30, 81, 61));
        pushButtonSat1->setFont(font1);
        pushButtonSat1->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        pushButtonSat2 = new QPushButton(AfficheSolutions);
        pushButtonSat2->setObjectName(QStringLiteral("pushButtonSat2"));
        pushButtonSat2->setGeometry(QRect(600, 30, 91, 61));
        pushButtonSat2->setFont(font1);
        pushButtonSat2->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        pushButtonSat3 = new QPushButton(AfficheSolutions);
        pushButtonSat3->setObjectName(QStringLiteral("pushButtonSat3"));
        pushButtonSat3->setGeometry(QRect(700, 30, 81, 61));
        pushButtonSat3->setFont(font1);
        pushButtonSat3->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        lineEditPosEvol = new QLineEdit(AfficheSolutions);
        lineEditPosEvol->setObjectName(QStringLiteral("lineEditPosEvol"));
        lineEditPosEvol->setEnabled(true);
        lineEditPosEvol->setGeometry(QRect(240, 30, 251, 31));
        lineEditPosEvol->setFont(font);
        lineEditPosEvol->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
""));
        lineEditPosEvol->setAlignment(Qt::AlignCenter);
        lineEditPosEvol->setDragEnabled(false);
        lineEditPosEvol->setReadOnly(true);
        PushButtonSauveOptions = new QPushButton(AfficheSolutions);
        PushButtonSauveOptions->setObjectName(QStringLiteral("PushButtonSauveOptions"));
        PushButtonSauveOptions->setGeometry(QRect(650, 320, 131, 51));
        PushButtonSauveOptions->setFont(font1);
        PushButtonSauveOptions->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        lineEditTimeGPS = new QLineEdit(AfficheSolutions);
        lineEditTimeGPS->setObjectName(QStringLiteral("lineEditTimeGPS"));
        lineEditTimeGPS->setEnabled(true);
        lineEditTimeGPS->setGeometry(QRect(320, 80, 151, 27));
        lineEditTimeGPS->setMaxLength(19);
        lineEditTimeGPS->setAlignment(Qt::AlignCenter);
        lineEditTimeGPS->setDragEnabled(false);
        lineEditTimeGPS->setReadOnly(true);
        lineEditGPSTime = new QLineEdit(AfficheSolutions);
        lineEditGPSTime->setObjectName(QStringLiteral("lineEditGPSTime"));
        lineEditGPSTime->setEnabled(true);
        lineEditGPSTime->setGeometry(QRect(230, 80, 81, 27));
        lineEditGPSTime->setDragEnabled(false);
        lineEditGPSTime->setReadOnly(true);
        lineEditTimeSYS = new QLineEdit(AfficheSolutions);
        lineEditTimeSYS->setObjectName(QStringLiteral("lineEditTimeSYS"));
        lineEditTimeSYS->setEnabled(true);
        lineEditTimeSYS->setGeometry(QRect(600, 80, 161, 27));
        lineEditTimeSYS->setMaxLength(20);
        lineEditTimeSYS->setAlignment(Qt::AlignCenter);
        lineEditTimeSYS->setDragEnabled(false);
        lineEditTimeSYS->setReadOnly(true);
        lineEditSYSTime = new QLineEdit(AfficheSolutions);
        lineEditSYSTime->setObjectName(QStringLiteral("lineEditSYSTime"));
        lineEditSYSTime->setEnabled(true);
        lineEditSYSTime->setGeometry(QRect(490, 80, 101, 27));
        lineEditSYSTime->setDragEnabled(false);
        lineEditSYSTime->setReadOnly(true);
        pushButtonSetSYSTime = new QPushButton(AfficheSolutions);
        pushButtonSetSYSTime->setObjectName(QStringLiteral("pushButtonSetSYSTime"));
        pushButtonSetSYSTime->setGeometry(QRect(560, 120, 221, 31));
        pushButtonSetSYSTime->setFont(font1);
        pushButtonSetSYSTime->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        lineEditPosEvol->raise();
        widget->raise();
        lineEditPositionXYZ->raise();
        lineEditPositionX->raise();
        lineEditPositionY->raise();
        lineEditPositionZ->raise();
        lineEditPositionH->raise();
        lineEditPositionLat->raise();
        lineEditPositionLong->raise();
        lineEditPositionLLH->raise();
        lineEditSatRover->raise();
        MessageUserlineEdit->raise();
        lineEditSatBase->raise();
        lineEditSatValides->raise();
        AfficheSolutionsgraphicsView->raise();
        lineEditSatellites->raise();
        lineEditStatut->raise();
        lineEditStream->raise();
        pushButtonLLH->raise();
        pushButtonXYZ->raise();
        PushButtonSauvegarde->raise();
        pushButtonSat1->raise();
        pushButtonSat2->raise();
        pushButtonSat3->raise();
        progressBarSatellites->raise();
        PushButtonSauveOptions->raise();
        lineEditTimeGPS->raise();
        lineEditGPSTime->raise();
        lineEditTimeSYS->raise();
        lineEditSYSTime->raise();
        lineEditRunningTime->raise();
        lineEditTimeToRun->raise();
        lineEditPositioningMode->raise();
        lineEditSolutionStatus1->raise();
        lineEditSolutionStatus2->raise();
        lineEditModePosition->raise();
        pushButtonSetSYSTime->raise();

        retranslateUi(AfficheSolutions);

        QMetaObject::connectSlotsByName(AfficheSolutions);
    } // setupUi

    void retranslateUi(QDialog *AfficheSolutions)
    {
        AfficheSolutions->setWindowTitle(QApplication::translate("AfficheSolutions", "Rover Solutions", Q_NULLPTR));
        lineEditStatut->setText(QApplication::translate("AfficheSolutions", "STATUS", Q_NULLPTR));
        lineEditPositionXYZ->setText(QApplication::translate("AfficheSolutions", "Rover Single:", Q_NULLPTR));
        lineEditPositionX->setText(QString());
        lineEditPositionY->setText(QString());
        lineEditPositionZ->setText(QString());
        lineEditPositionH->setText(QString());
        lineEditPositionLat->setText(QString());
        lineEditPositionLong->setText(QString());
        lineEditPositionLLH->setText(QApplication::translate("AfficheSolutions", "Rover Fixed:", Q_NULLPTR));
        lineEditRunningTime->setText(QApplication::translate("AfficheSolutions", "Time to run:", Q_NULLPTR));
        lineEditTimeToRun->setText(QString());
        lineEditPositioningMode->setText(QApplication::translate("AfficheSolutions", "Pos Mode:", Q_NULLPTR));
        lineEditModePosition->setText(QString());
        lineEditSatellites->setText(QApplication::translate("AfficheSolutions", " SATELLITES", Q_NULLPTR));
        lineEditSatRover->setText(QString());
        lineEditStream->setText(QApplication::translate("AfficheSolutions", "STREAM", Q_NULLPTR));
        PushButtonSauvegarde->setText(QApplication::translate("AfficheSolutions", "SAVE POSITION", Q_NULLPTR));
        lineEditSolutionStatus1->setText(QApplication::translate("AfficheSolutions", "Solution status:", Q_NULLPTR));
        lineEditSolutionStatus2->setText(QString());
        lineEditSatBase->setText(QString());
        lineEditSatValides->setText(QApplication::translate("AfficheSolutions", "Valides Satellites", Q_NULLPTR));
        pushButtonXYZ->setText(QApplication::translate("AfficheSolutions", "XYZ", Q_NULLPTR));
        pushButtonLLH->setText(QApplication::translate("AfficheSolutions", "LLH", Q_NULLPTR));
        pushButtonSat1->setText(QApplication::translate("AfficheSolutions", "GENERAL", Q_NULLPTR));
        pushButtonSat2->setText(QApplication::translate("AfficheSolutions", "ELEVATION", Q_NULLPTR));
        pushButtonSat3->setText(QApplication::translate("AfficheSolutions", "AZIMUTH", Q_NULLPTR));
        lineEditPosEvol->setText(QApplication::translate("AfficheSolutions", "EVOLUTION", Q_NULLPTR));
        PushButtonSauveOptions->setText(QApplication::translate("AfficheSolutions", "SAVE OPTIONS", Q_NULLPTR));
        lineEditTimeGPS->setText(QString());
        lineEditGPSTime->setText(QApplication::translate("AfficheSolutions", "GPS Time :", Q_NULLPTR));
        lineEditTimeSYS->setText(QApplication::translate("AfficheSolutions", "System Time :", Q_NULLPTR));
        lineEditSYSTime->setText(QApplication::translate("AfficheSolutions", "System Time :", Q_NULLPTR));
        pushButtonSetSYSTime->setText(QApplication::translate("AfficheSolutions", "Set system time with GPS", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AfficheSolutions: public Ui_AfficheSolutions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AFFICHESOLUTIONS_H
