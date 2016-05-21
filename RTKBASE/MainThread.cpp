#include <QThread>
#include <QMutex>
#include "MainThread.h"
#include <stdlib.h>
#include "vt.h"
#include <iostream>
#include <fstream>
#include <string>
#include <QList>

using namespace std;

extern "C" int mainRTKlib(int argc, char **argv);
extern "C" int ouvreVT(int argc, char **argv);
extern "C" void affichestatus(vt_t *vt);
extern "C" void affichesat(vt_t *vt);
extern "C" void afficheNaviData(vt_t *vt);
extern "C" void afficheStream(vt_t *vt);
extern "C" int fermeVT();



MainThread ::MainThread(QObject* parent):
QThread(parent)
{
    stopped = false;
}

MainThread::~MainThread()
{
     exit();
     wait();
}
void MainThread::setArgcArgv(std::vector<string> args)
{
    argc=args.size();
    argv=new char*[argc];
    int i=0;
    for (auto &s : args)
    {
        char *arg = new char[s.size() + 1];
        copy(s.begin(), s.end(), arg);
        arg[s.size()] = '\0';
        argv[i]=arg;
        i++;
    }
}


void MainThread::afficheRtkrcvsatellite(int i)
{
    cout<<"le chiffre est le: "<<i<<endl;
    if (i==11) m_choix=2;
    if (i==12) m_choix=1;
    if (i==13) m_choix=3;
    if (i==14) affichesat(&vt);
    if (i==15) m_choix=5;
    if (i==16) m_choix=7;
}

void MainThread::stop()
{
    qDebug()<<"-----------------on est avant la fermeture de VT-------------------";
    fermeVT();
    qDebug()<<"-----------------on est après la fermeture de VT-------------------";

    /*problèmes de droits en écriture dans le dossier???*/

    /*create folder if folder doesn't exist*/
    QString Folder="PointsFiles";
    QDir dir(Folder);
    if(!dir.exists())
    {
        dir.mkpath(".");
    }

    QString path=QDir::currentPath();
    QFile::copy(NomFichier,path+"/"+Folder+"/"+NomFichier);
    QFile::remove(NomFichier);

    sleep(3);
    stopped = true; // après ne retourne pas dans le run()...
    emit etatFermetureVT(true);
}

void MainThread::run()
{
    while (!stopped)
    {
        vt.state=0;
        std::ofstream r("infosouverture.txt");

        ouvreVT(argc,argv);
        sleep(2);

        /*create file for saving last point*/
        std::ofstream p("essaisauvegarde.txt");

        while(1)
        {
        if (m_choix==1) etatstatut();
        if (m_choix==2) etatsatellite();
        if (m_choix==3) etatNaviData();
        if (m_choix==5) etatStream();
        if (m_choix==6) sauvegardedansfichier();
        if (m_choix==7) stop();
        }

    }
    stopped = false;
    qDebug()<<"from MainThread: "<<currentThreadId();
}


void MainThread::etatsatellite()
{
    std::ofstream o("essaiprojet.txt");
    affichesat(&vt);

    /*Open, read line by line and then close file*/
    int i=1;
    QStringList list;
    QString fileName = "essaiprojet.txt";
    QFile fichier(fileName);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    /*Check if file is opened*/
    QTextStream flux(&fichier);
    QString ligne;
    while(! flux.atEnd())
    {
        ligne = flux.readLine();
        //traitement de la ligne
        qDebug()<<ligne;
        list<<ligne;
        i=i+1;
    }
    qDebug()<<"nombre de lignes = "<<i-1;
    qDebug()<<list;
    fichier.close();
    emit emitdonneesSatellites(list,i-1);

    sleep(1);
    remove("essaiprojet.txt");
}

void MainThread::etatstatut()
{
    /*create buffer file*/
    std::ofstream o("essaiprojet.txt");

    /*Launch function of rtkrcv.c relative to the solution to print*/
    affichestatus(&vt);

    /*Open, read line by line and then close file*/
    int i=1;
    QStringList list;
    QString fileName = "essaiprojet.txt";
    QFile fichier(fileName);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    //---------verifier ouverture fichier......
    QTextStream flux(&fichier);
    QString ligne;
    while(! flux.atEnd())
    {
        ligne = flux.readLine();
        //traitement de la ligne
        qDebug()<<ligne;
        list<<ligne;
        i=i+1;
    }
    fichier.close();

    /*Save last position. This position will be used in Base Mode*/
    std::ofstream q("sauvegardepourbase.txt");
    QFile fichierlastpositionforbase("sauvegardepourbase.txt");
    fichierlastpositionforbase.open(QIODevice::Append | QIODevice::Text);
    QTextStream out1(&fichierlastpositionforbase);
    //out1<<"essai";
    if(i>1)
    {
        out1<<list[4]<<endl;
        out1<<list[5]<<endl;
        out1<<list[6]<<endl;
    }
    fichierlastpositionforbase.close();

    emit emitdonneesStatus(list);
    sleep(1);// on constate que dans cette partie, le sleep bloque la GUI, ie on n'est plus vraiment dans un Thread mais dans une fonction normale...

    /*Delete File*/
    remove("essaiprojet.txt");

}

void MainThread::etatNaviData()
{
    /*Launch function of rtkrcv.c relative to the solution to print*/
    afficheNaviData(&vt);

    sleep(1);
}


void MainThread::etatStream()
{
    std::ofstream o("essaiprojet.txt");
    /*Launch function of rtkrcv.c relative to the solution to print*/
    afficheStream(&vt);

    /*Open, read line by line and then close file*/
    int i=1;
    QStringList list;
    QString fileName = "essaiprojet.txt";
    QFile fichier(fileName);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    //---------verifier ouverture fichier......
    QTextStream flux(&fichier);
    QString ligne;
    while(! flux.atEnd())
    {
        ligne = flux.readLine();
        //traitement de la ligne
        list<<ligne;
        i=i+1;
    }
    fichier.close();
    emit emitdonneesStream(list,i-1);

    sleep(1);
    remove("essaiprojet.txt");
}

void MainThread::saveposition()
{
    qDebug()<<"le bouton save fonctionne";
    emit save(1);
    m_choix=6;
}

void MainThread::sauvegardedansfichier()
{

    /*------crée le fichier "tampon"------------------*/
    std::ofstream o("essaiprojet.txt");

    /*Launch function of rtkrcv.c relative to the solution to print*/
    affichestatus(&vt);

    /*Open, read line by line and then close file*/
    int i=1;
    QStringList list;
    QString fileName = "essaiprojet.txt";
    QFile fichier(fileName);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    /*check if file is opened*/
    QTextStream flux(&fichier);
    QString ligne;
    while(! flux.atEnd())
    {
        ligne = flux.readLine();
        //traitement de la ligne
        qDebug()<<ligne;
        list<<ligne;
        i=i+1;
    }
    fichier.close();
    /*delete buffer file*/
    remove("essaiprojet.txt");
    /*----------------------------------------------*/


    QString str;
    if(m_k==0)
    {
        str=list[13];
        str.replace("/","");
        str.replace(" ","_");
        str.replace(":","");
        qDebug()<<str;
        QString z=str.mid(15);
        str.remove(z);// horaire type GDH: groupe/date/heure
        NomFichier=str+".txt";
        qDebug()<<NomFichier;
    }

    QFile fichiersauvegarde(NomFichier);


    sleep(1);

    fichiersauvegarde.open(QIODevice::Append | QIODevice::Text);


    /*Save points in NomFichier in Folder*/

    QTextStream out(&fichiersauvegarde);
    out << "point numero :"<<m_k<<" heure rover : "<<list[13]<<" latitude :"<<list[4] <<" longitude :"<<list[5]<<" hauteur :"<<list[6]<<" X : "<<list[1]<<" Y :"<<list[2]<<" Z : "<<list[3]<<'\n';
    emit savePointNbr(m_k);
    fichiersauvegarde.close();

    sleep(1);

    m_k=m_k+1;

    m_choix=1;//pour retour dans la boucle du Thread


}

