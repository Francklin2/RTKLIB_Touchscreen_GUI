/********************************************************************************
** Form generated from reading UI file 'mydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYDIALOG_H
#define UI_MYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_MyDialog
{
public:
    QPushButton *pushButton_run_rnx2rtk_process_RGP;
    QTextBrowser *textBrowser;
    QProgressBar *progressBar;

    void setupUi(QDialog *MyDialog)
    {
        if (MyDialog->objectName().isEmpty())
            MyDialog->setObjectName(QStringLiteral("MyDialog"));
        MyDialog->resize(640, 392);
        pushButton_run_rnx2rtk_process_RGP = new QPushButton(MyDialog);
        pushButton_run_rnx2rtk_process_RGP->setObjectName(QStringLiteral("pushButton_run_rnx2rtk_process_RGP"));
        pushButton_run_rnx2rtk_process_RGP->setGeometry(QRect(140, 10, 291, 61));
        textBrowser = new QTextBrowser(MyDialog);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(30, 80, 581, 271));
        progressBar = new QProgressBar(MyDialog);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(520, 360, 118, 23));
        progressBar->setValue(0);

        retranslateUi(MyDialog);

        QMetaObject::connectSlotsByName(MyDialog);
    } // setupUi

    void retranslateUi(QDialog *MyDialog)
    {
        MyDialog->setWindowTitle(QApplication::translate("MyDialog", "Dialog", 0));
        pushButton_run_rnx2rtk_process_RGP->setText(QApplication::translate("MyDialog", " Post Processing RTK_BASE position \n"
"  using CORS stations ", 0));
    } // retranslateUi

};

namespace Ui {
    class MyDialog: public Ui_MyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYDIALOG_H
