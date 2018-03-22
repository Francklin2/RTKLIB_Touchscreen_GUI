/********************************************************************************
** Form generated from reading UI file 'mylineedit.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYLINEEDIT_H
#define UI_MYLINEEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyLineEdit
{
public:

    void setupUi(QWidget *MyLineEdit)
    {
        if (MyLineEdit->objectName().isEmpty())
            MyLineEdit->setObjectName(QStringLiteral("MyLineEdit"));
        MyLineEdit->resize(400, 300);

        retranslateUi(MyLineEdit);

        QMetaObject::connectSlotsByName(MyLineEdit);
    } // setupUi

    void retranslateUi(QWidget *MyLineEdit)
    {
        MyLineEdit->setWindowTitle(QApplication::translate("MyLineEdit", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class MyLineEdit: public Ui_MyLineEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYLINEEDIT_H
