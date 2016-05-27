#include "mainthreadreadfile.h"
#include <fstream>

using namespace std;


MainThreadReadFile::MainThreadReadFile(QObject* parent):
QThread(parent)
{
}


MainThreadReadFile::~MainThreadReadFile()
{
     exit();
     wait();
     // nettoyage
}

void MainThreadReadFile::run()
{

    /*------crée le fichier "tampon"------------------*/
    std::ofstream o("essaiprojetStr2str.txt");


    while (1)
    {

        /*-------ouvre, lit ligne par ligne puis ferme le fichier------------*/
        int i=1;
        //QString a[11]; // mettre un indice supérieur pour cause de i=i+1...
        QStringList list;
        QString fileName = "essaiprojetStr2str.txt";
        QFile fichier(fileName);
        fichier.open(QIODevice::ReadOnly | QIODevice::Text);
        //---------verifier ouverture fichier......
        QTextStream flux(&fichier);
        QString ligne;
        while(! flux.atEnd())
        {
            ligne = flux.readLine();
            //traitement de la ligne
            qDebug()<<"------------------"<<ligne;
            list<<ligne;
            i=i+1;
        }
        fichier.close();
        if (i!=1)emit emitdonneesStr2str(list);
        sleep(4);
    }

        /*------------supprime le fichier---------*/
        //remove("essaiprojetStr2Str.txt");



        exec();

}
