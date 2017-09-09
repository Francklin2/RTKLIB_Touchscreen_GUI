#ifndef CLAVIER_H
#define CLAVIER_H

#include <QDialog>

namespace Ui {
class Clavier;
}

class Clavier : public QDialog
{
    Q_OBJECT

public:
    explicit Clavier(QString ancientexte,QString nomchamp = QString(""),QWidget *parent = 0);
    ~Clavier();

private:
    Ui::Clavier *ui;
    bool MAJ = false;

public slots:
    void A();
    void Z();
    void E();
    void R();
    void T();
    void Y();
    void U();
    void I();
    void O();
    void P();
    void Q();
    void S();
    void D();
    void F();
    void G();
    void H();
    void J();
    void K();
    void L();
    void M();
    void W();
    void X();
    void C();
    void V();
    void B();
    void N();
    void Space();
    void Back();
    void Maj();
    void Gauche();
    void Droite();
    void Virg();
    void PVirg();
    void P2();
    void PExcl();
    void Under();
    void ChevG();
    void ChevD();
    void PInt();
    void Point();
    void Slash();
    void ASlash();
    void _9();
    void _8();
    void _7();
    void _6();
    void _5();
    void _4();
    void _3();
    void _2();
    void _1();
    void _0();
    void Moins();
    void Plus();
    void Div();
    void Ast();

    void Cancel();
    void OK();

signals:
    void Texte(QString);

};

#endif // CLAVIER_H
