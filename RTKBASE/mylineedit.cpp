#include "mylineedit.h"
#include "ui_mylineedit.h"
#include "clavier.h"
#include <QFocusEvent>

MyLineEdit::MyLineEdit(QWidget *parent)
 : QLineEdit(parent)
{}

MyLineEdit::~MyLineEdit()
{}

void MyLineEdit::focusInEvent(QFocusEvent *e)
{
    if (e->reason() == Qt::MouseFocusReason)
        {
        Clavier *NouveauClavier = new Clavier(this->text(),QString(""));
        QObject::connect(NouveauClavier,SIGNAL(Texte(QString)),this,SLOT(setText(QString)));
        NouveauClavier->setWindowFlags(Qt::FramelessWindowHint);
        NouveauClavier->setModal(true);
        NouveauClavier->exec();
        }
    QLineEdit::focusInEvent(e);
}

