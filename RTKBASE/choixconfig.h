#ifndef CHOIXCONFIG_H
#define CHOIXCONFIG_H

#include <QDialog>

namespace Ui {
class ChoixConfig;
}

class ChoixConfig : public QDialog
{
    Q_OBJECT

public:
    explicit ChoixConfig( int _rover_edit = 0, QWidget *parent = 0);
    ~ChoixConfig();

private:
    Ui::ChoixConfig *ui;
    int rover_edit;
    void OuvreAfficheSolutions(QString configFile);
    void OuvreChoixEdit(QString modeleFile);

public slots:
    //void AfficheHistoHeureSyst(int
    void ouvreSingle();
    void ouvreSBAS();
    void ouvreDGPS();
    void ouvrePPP();
    void ouvreRTKstatic();
    void ouvreRTKkinematic();
    void OuvreConfig1();
    void OuvreConfig2();
    void OuvreConfig3();
    void OuvreConfig4();
    void OuvreConfig5();
    void OuvreConfig6();
    void OuvreConfig7();
    void OuvreConfig8();
    void OuvreConfig9();
    void OuvreConfig10();
    void OuvreConfig11();
    void OuvreConfig12();
    void OuvreEdit();
    void Retour();
    void MAJNoms();
    void Affiche();
    void FermeTout();

signals:
    void DemandeRetour();
    void DemandeFerme();

};

#endif // CHOIXCONFIG_H
