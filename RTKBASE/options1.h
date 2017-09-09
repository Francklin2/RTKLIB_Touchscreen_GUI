#ifndef OPTIONS1_H
#define OPTIONS1_H

#include <QDialog>
extern int choixcalcul; // A supprimer et modifier les ouvrir...() -> rajouter dans le constructeur
                        // de AfficheSolutions le chemin vers le fichier config correspondant


namespace Ui {
class Options1;
}


class Options1 : public QDialog
{
    Q_OBJECT

public:
    explicit Options1(QWidget *parent = 0);
    ~Options1();




private:
    Ui::Options1 *ui;
    QString m_fileName1="";


public slots:
    //void AfficheHistoHeureSyst(int
    void ouvreSingle();
    void ouvreSBAS();
    void ouvreDGPS();
    void ouvrePPP();
    void ouvreRTKstatic();
    void ouvreRTKkinematic();




};


#endif // OPTIONS1_H
