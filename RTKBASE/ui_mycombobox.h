/********************************************************************************
** Form generated from reading UI file 'mycombobox.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYCOMBOBOX_H
#define UI_MYCOMBOBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyComboBox
{
public:

    void setupUi(QWidget *MyComboBox)
    {
        if (MyComboBox->objectName().isEmpty())
            MyComboBox->setObjectName(QStringLiteral("MyComboBox"));
        MyComboBox->resize(400, 300);

        retranslateUi(MyComboBox);

        QMetaObject::connectSlotsByName(MyComboBox);
    } // setupUi

    void retranslateUi(QWidget *MyComboBox)
    {
        MyComboBox->setWindowTitle(QApplication::translate("MyComboBox", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MyComboBox: public Ui_MyComboBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCOMBOBOX_H
