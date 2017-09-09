/********************************************************************************
** Form generated from reading UI file 'affichestr2str.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AFFICHESTR2STR_H
#define UI_AFFICHESTR2STR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_AfficheStr2str
{
public:
    QLineEdit *lineEdit;
    QPushButton *FermeStr2strpushButton;
    QLineEdit *Msg1lineEdit;
    QLineEdit *Msg2lineEdit;
    QLineEdit *Msg3lineEdit;
    QLineEdit *Msg4lineEdit;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *AfficheStr2str)
    {
        if (AfficheStr2str->objectName().isEmpty())
            AfficheStr2str->setObjectName(QStringLiteral("AfficheStr2str"));
        AfficheStr2str->setEnabled(true);
        AfficheStr2str->resize(800, 480);
        lineEdit = new QLineEdit(AfficheStr2str);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(250, 10, 271, 41));
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
        FermeStr2strpushButton = new QPushButton(AfficheStr2str);
        FermeStr2strpushButton->setObjectName(QStringLiteral("FermeStr2strpushButton"));
        FermeStr2strpushButton->setEnabled(true);
        FermeStr2strpushButton->setGeometry(QRect(650, 330, 99, 91));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setWeight(75);
        FermeStr2strpushButton->setFont(font1);
        FermeStr2strpushButton->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        Msg1lineEdit = new QLineEdit(AfficheStr2str);
        Msg1lineEdit->setObjectName(QStringLiteral("Msg1lineEdit"));
        Msg1lineEdit->setGeometry(QRect(50, 110, 701, 27));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        Msg1lineEdit->setFont(font2);
        Msg2lineEdit = new QLineEdit(AfficheStr2str);
        Msg2lineEdit->setObjectName(QStringLiteral("Msg2lineEdit"));
        Msg2lineEdit->setGeometry(QRect(50, 150, 701, 27));
        Msg2lineEdit->setFont(font2);
        Msg3lineEdit = new QLineEdit(AfficheStr2str);
        Msg3lineEdit->setObjectName(QStringLiteral("Msg3lineEdit"));
        Msg3lineEdit->setGeometry(QRect(50, 190, 701, 27));
        Msg3lineEdit->setFont(font2);
        Msg4lineEdit = new QLineEdit(AfficheStr2str);
        Msg4lineEdit->setObjectName(QStringLiteral("Msg4lineEdit"));
        Msg4lineEdit->setGeometry(QRect(50, 70, 701, 27));
        Msg4lineEdit->setFont(font2);
        textBrowser = new QTextBrowser(AfficheStr2str);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(50, 230, 381, 241));
        textBrowser->setFont(font2);

        retranslateUi(AfficheStr2str);

        QMetaObject::connectSlotsByName(AfficheStr2str);
    } // setupUi

    void retranslateUi(QDialog *AfficheStr2str)
    {
        AfficheStr2str->setWindowTitle(QApplication::translate("AfficheStr2str", "Base Station Status", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("AfficheStr2str", "BASE STATION STATUS", Q_NULLPTR));
        FermeStr2strpushButton->setText(QApplication::translate("AfficheStr2str", "CLOSE", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AfficheStr2str: public Ui_AfficheStr2str {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AFFICHESTR2STR_H
