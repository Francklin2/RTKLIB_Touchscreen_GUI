#include <QVector>
#include<QTime>
#include <QInputDialog>
#include <QThread>
#include<iostream>
#include<stdlib.h>
#include "threadheuresysteme.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

ThreadHeureSysteme ::ThreadHeureSysteme(QObject* parent):
QThread(parent)
{
        // start démarre effectivement le nouveau thread et appelle sa méthode run()
        start();
//        QObject::connect(MainWindow,SIGNAL(recustopthreadheure(bool)),this,SLOT(fermethread()));
}

ThreadHeureSysteme::~ThreadHeureSysteme()
{
     exit();
     wait();
     // nettoyage
}

void ThreadHeureSysteme::run()
{
    while(1)
    {
    int heures = QTime::currentTime().hour();    // problème, heure statique, passer par des threads
    int minutes = QTime::currentTime().minute();
    int secondes = QTime::currentTime().second(); // initialement "unsigned int"
    long int horaire=0;
    horaire= (heures*3600)+(minutes*60)+secondes;
    //cout<<"il est "<<heures<<"heures et "<<minutes<<"minutes "<<secondes<<std::endl;  // le thread fonctionne mais prend-il beaucoup de CPU...?
    emit heureretournee(horaire); //----------------définir le signal à envoyer et où? vers le MainWindow et QLineEdit
    sleep(1);   // pause d'une seconde
    }
    exec();
}

/*void ThreadHeureSysteme::fermethread()
{
    exit();
}
*/

// ---------------------détruire le signal?-----------------------------------
/*
void ThreadHeureSysteme::heureretournee(int a)
{
    cout<<"signal fonctionne et renvoie"<<a<<endl;
}*/

//int ThreadHeureSysteme::exec()
//{
  //  while(1)
    //{
    //unsigned int heures = QTime::currentTime().hour();    // problème, heure statique, passer par des threads
    //unsigned int minutes = QTime::currentTime().minute();
    //unsigned int secondes = QTime::currentTime().second();
    //cout<<"il est "<<heures<<"heures et "<<minutes<<"minutes "<<secondes<<std::endl;  // le thread fonctionne mais prend-il beaucoup de CPU...?
 //   QLineEdit->TimeRetourEdit->setText(QString("%1 h %2 min").arg(heures).arg(minutes)); ne fonctionne pas, plutôt signal vers le main puis connect
    //emit heureretournee(secondes); //----------------définir le signal à envoyer et où? vers le MainWindow et QLineEdit
    //sleep(1);   // pause d'une seconde
   // }
//}
