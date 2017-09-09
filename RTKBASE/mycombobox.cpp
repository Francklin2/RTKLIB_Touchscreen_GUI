#include "mycombobox.h"
#include "ui_mycombobox.h"
#include <QFocusEvent>
#include "clavier.h"

MyComboBox::MyComboBox(QWidget *parent) :
    QComboBox(parent)
{
    QObject::connect(this,SIGNAL(activated(int)),this,SLOT(ActiveClavier()));
}

MyComboBox::~MyComboBox()
{}

/*void MyComboBox::focusInEvent(QFocusEvent *e)
{
    if (e->reason() == Qt::MouseFocusReason)
        {
        Clavier *NouveauClavier = new Clavier(this->currentText(),QString(""));
        QObject::connect(NouveauClavier,SIGNAL(Texte(QString)),this,SLOT(setEditText(QString)));
        NouveauClavier->setWindowFlags(Qt::FramelessWindowHint);
        NouveauClavier->setModal(true);
        NouveauClavier->exec();
        }
    QComboBox::focusInEvent(e);
}*/

void MyComboBox::ActiveClavier()
{
    Clavier *NouveauClavier = new Clavier(this->currentText(),QString(""));
    QObject::connect(NouveauClavier,SIGNAL(Texte(QString)),this,SLOT(setEditText(QString)));
    NouveauClavier->setWindowFlags(Qt::FramelessWindowHint);
    NouveauClavier->setModal(true);
    NouveauClavier->exec();
}
