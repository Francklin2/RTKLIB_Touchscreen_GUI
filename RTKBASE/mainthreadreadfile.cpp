// RTKBASE is a GUI interface for RTKLIB made for the Raspberry pî and a touchscreen
//   Copyright (C) 2016
//   David ENSG PPMD-2016 (first rtkbase release)
//   Francklin N'guyen van <francklin2@wanadoo.fr>
//   Sylvain Poulain <sylvain.poulain@giscan.com>
//   Vladimir ENSG PPMD-2017 (editable configuration)
//   Saif Aati ENSG PPMD-2018 (post processing)
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.


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
