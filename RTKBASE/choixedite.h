#ifndef CHOIXEDITE_H
#define CHOIXEDITE_H

#include <QDialog>

namespace Ui {
class ChoixEdite;
}

class ChoixEdite : public QDialog
{
    Q_OBJECT

public:
    explicit ChoixEdite(QString _configFile = QString(""), QWidget *parent = 0);
    ~ChoixEdite();

private:
    Ui::ChoixEdite *ui;
    QString modeleFile;
    int numSauve;
    void DemandeNom(int num, QString name);
    void OuvrirEditeur(QString configFile);
    void MAJNoms();

public slots:
    void SelectConfig1();
    void SelectConfig2();
    void SelectConfig3();
    void SelectConfig4();
    void SelectConfig5();
    void SelectConfig6();
    void SelectConfig7();
    void SelectConfig8();
    void SelectConfig9();
    void SelectConfig10();
    void SelectConfig11();
    void SelectConfig12();
    void Retour();
    void Affiche();
    void FermeTout();
    void SauveNom(QString newname);

signals:
    void DemandeRetour();
    void DemandeFerme();
};

#endif // CHOIXEDITE_H
