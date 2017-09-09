#ifndef AFFICHESOLUTIONS_H
#define AFFICHESOLUTIONS_H

#include <QDialog>
#include <magraphicsscene.h>
#include "magraphicsscene.h"
#include "options1.h"
#include "options2.h"
#include "MainThread.h"



namespace Ui {
class AfficheSolutions;
}

class AfficheSolutions : public QDialog
{
    Q_OBJECT

public:
    explicit AfficheSolutions(QString _configFile = QString(""), QWidget *parent = 0); //ajouter un paramètre : chemin du fichier config
    ~AfficheSolutions();



private:
    Ui::AfficheSolutions *ui;
    void SatStatus();
    MaGraphicsScene SatStatusSingleRover;
    Options2 Options2Rover;
    MainThread* m_t=new MainThread;
    QVector <QPointF> points;
    int m_compteur=0;
    QString configFile="";
    int m_choix=1;
    int m_UnitChoice=1;
    int m_SatChoice=1;





public slots:
    void OuvreOptions2();
    void choixVue(int);
    void ChoixVueSats();
    void ChoixVueStatus();
    void ChoixVueDoneesCom();
    void ChoixVueObserv();
    void ChoixVueNavidata();
    void ChoixVueStream();
    void FermeTout();
    void initAffichage();
    void recupedonneesStatus(QStringList);
    void recupedonneesSatellites(QStringList,int);
    void recupedonneesStream(QStringList,int);
    void affichePointNbr(QString);
    void finThread(bool);
    void unitchoice1();
    void unitchoice2();
    void satchoice1();
    void satchoice2();
    void satchoice3();
    void sauvegardeoptions();
//    void setSYSTime();


signals:
    void typeAffichageEmit(int);
    //void emitsave(int);


};

#endif // AFFICHESOLUTIONS_H
