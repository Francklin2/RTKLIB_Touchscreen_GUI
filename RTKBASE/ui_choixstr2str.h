/********************************************************************************
** Form generated from reading UI file 'choixstr2str.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOIXSTR2STR_H
#define UI_CHOIXSTR2STR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ChoixStr2Str
{
public:
    QPushButton *ReturnButton;
    QPushButton *Base7Button;
    QPushButton *Base8Button;
    QPushButton *Base2Button;
    QPushButton *Base6Button;
    QPushButton *Base10Button;
    QPushButton *Base12Button;
    QPushButton *Base11Button;
    QPushButton *Base9Button;
    QPushButton *Base1Button;
    QPushButton *Base3Button;
    QPushButton *Base4Button;
    QPushButton *Base5Button;
    QLineEdit *WindowTitleEdit;

    void setupUi(QDialog *ChoixStr2Str)
    {
        if (ChoixStr2Str->objectName().isEmpty())
            ChoixStr2Str->setObjectName(QStringLiteral("ChoixStr2Str"));
        ChoixStr2Str->resize(800, 360);
        ReturnButton = new QPushButton(ChoixStr2Str);
        ReturnButton->setObjectName(QStringLiteral("ReturnButton"));
        ReturnButton->setGeometry(QRect(14, 310, 780, 40));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        ReturnButton->setFont(font);
        ReturnButton->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        Base7Button = new QPushButton(ChoixStr2Str);
        Base7Button->setObjectName(QStringLiteral("Base7Button"));
        Base7Button->setGeometry(QRect(14, 190, 120, 110));
        Base7Button->setFont(font);
        Base7Button->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        Base8Button = new QPushButton(ChoixStr2Str);
        Base8Button->setObjectName(QStringLiteral("Base8Button"));
        Base8Button->setGeometry(QRect(146, 189, 120, 111));
        Base8Button->setFont(font);
        Base8Button->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        Base2Button = new QPushButton(ChoixStr2Str);
        Base2Button->setObjectName(QStringLiteral("Base2Button"));
        Base2Button->setGeometry(QRect(146, 70, 120, 110));
        Base2Button->setFont(font);
        Base2Button->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        Base6Button = new QPushButton(ChoixStr2Str);
        Base6Button->setObjectName(QStringLiteral("Base6Button"));
        Base6Button->setGeometry(QRect(674, 70, 120, 110));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        Base6Button->setFont(font1);
        Base6Button->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        Base10Button = new QPushButton(ChoixStr2Str);
        Base10Button->setObjectName(QStringLiteral("Base10Button"));
        Base10Button->setGeometry(QRect(410, 190, 120, 110));
        Base10Button->setFont(font);
        Base10Button->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        Base12Button = new QPushButton(ChoixStr2Str);
        Base12Button->setObjectName(QStringLiteral("Base12Button"));
        Base12Button->setGeometry(QRect(674, 190, 120, 110));
        Base12Button->setFont(font1);
        Base12Button->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        Base11Button = new QPushButton(ChoixStr2Str);
        Base11Button->setObjectName(QStringLiteral("Base11Button"));
        Base11Button->setGeometry(QRect(542, 190, 120, 110));
        Base11Button->setFont(font);
        Base11Button->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        Base9Button = new QPushButton(ChoixStr2Str);
        Base9Button->setObjectName(QStringLiteral("Base9Button"));
        Base9Button->setGeometry(QRect(278, 190, 120, 110));
        Base9Button->setFont(font);
        Base9Button->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        Base1Button = new QPushButton(ChoixStr2Str);
        Base1Button->setObjectName(QStringLiteral("Base1Button"));
        Base1Button->setGeometry(QRect(14, 70, 120, 110));
        Base1Button->setFont(font);
        Base1Button->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        Base3Button = new QPushButton(ChoixStr2Str);
        Base3Button->setObjectName(QStringLiteral("Base3Button"));
        Base3Button->setGeometry(QRect(278, 70, 120, 110));
        Base3Button->setFont(font);
        Base3Button->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        Base4Button = new QPushButton(ChoixStr2Str);
        Base4Button->setObjectName(QStringLiteral("Base4Button"));
        Base4Button->setGeometry(QRect(410, 70, 120, 110));
        Base4Button->setFont(font);
        Base4Button->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        Base5Button = new QPushButton(ChoixStr2Str);
        Base5Button->setObjectName(QStringLiteral("Base5Button"));
        Base5Button->setGeometry(QRect(542, 70, 120, 110));
        Base5Button->setFont(font);
        Base5Button->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
"background-color: rgb(230, 230, 230);"));
        WindowTitleEdit = new QLineEdit(ChoixStr2Str);
        WindowTitleEdit->setObjectName(QStringLiteral("WindowTitleEdit"));
        WindowTitleEdit->setGeometry(QRect(260, 15, 280, 40));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        WindowTitleEdit->setFont(font2);
        WindowTitleEdit->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"border: 1px solid black;\n"
""));
        WindowTitleEdit->setAlignment(Qt::AlignCenter);
        WindowTitleEdit->setReadOnly(true);

        retranslateUi(ChoixStr2Str);

        QMetaObject::connectSlotsByName(ChoixStr2Str);
    } // setupUi

    void retranslateUi(QDialog *ChoixStr2Str)
    {
        ChoixStr2Str->setWindowTitle(QApplication::translate("ChoixStr2Str", "Dialog", Q_NULLPTR));
        ReturnButton->setText(QApplication::translate("ChoixStr2Str", "RETURN", Q_NULLPTR));
        Base7Button->setText(QApplication::translate("ChoixStr2Str", "BASE 7", Q_NULLPTR));
        Base8Button->setText(QApplication::translate("ChoixStr2Str", "BASE 8", Q_NULLPTR));
        Base2Button->setText(QApplication::translate("ChoixStr2Str", "BASE  2", Q_NULLPTR));
        Base6Button->setText(QApplication::translate("ChoixStr2Str", "BASE 6", Q_NULLPTR));
        Base10Button->setText(QApplication::translate("ChoixStr2Str", "BASE 10", Q_NULLPTR));
        Base12Button->setText(QApplication::translate("ChoixStr2Str", "BASE 12", Q_NULLPTR));
        Base11Button->setText(QApplication::translate("ChoixStr2Str", "BASE 11", Q_NULLPTR));
        Base9Button->setText(QApplication::translate("ChoixStr2Str", "BASE 9", Q_NULLPTR));
        Base1Button->setText(QApplication::translate("ChoixStr2Str", "BASE  1", Q_NULLPTR));
        Base3Button->setText(QApplication::translate("ChoixStr2Str", "BASE 3", Q_NULLPTR));
        Base4Button->setText(QApplication::translate("ChoixStr2Str", "BASE 4", Q_NULLPTR));
        Base5Button->setText(QApplication::translate("ChoixStr2Str", "BASE 5", Q_NULLPTR));
        WindowTitleEdit->setText(QApplication::translate("ChoixStr2Str", "BASE", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChoixStr2Str: public Ui_ChoixStr2Str {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOIXSTR2STR_H
