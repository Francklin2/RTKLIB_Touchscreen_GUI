// RTKBASE is a GUI interface for RTKLIB made for the Raspberry pî and a touchscreen  
//   Copyright (C) 2016  
//   David ENSG PPMD-15  
//   Francklin N'guyen van <francklin2@wanadoo.fr>
//   Sylvain Poulain <sylvain.poulain@giscan.com>
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





#ifndef MAINTHREAD_H
#define MAINTHREAD_H
#include <QtCore>
#include <QThread>
#include <vector>
#include <stdlib.h>
#include <QMutex>



class MainThread : public QThread
{
    Q_OBJECT

public:
   MainThread(QObject *parent=NULL);
   virtual ~MainThread();
   void setArgcArgv(std::vector<std::string> args);
   void stop();

   QString _filePath = QString("");
   QString _pointName = QString("");
   int _numOfMeasures = 1;
   float _cycleLength = 1;
   bool _addMeasures = false;

private:
   //-------------------suite aux conseils de Jean-Michael
   int argc;
   char **argv; // [] pour correspondre à ce qui fait que ça fonctionne dans le "main" int main(int argc, char *argv[])  prog crash...
   // char **argv; // accepte mais crash après...
    //QMutex mu;
   int m_choix=5;
   volatile bool stopped;
   int m_k=0;
   QString NomFichier;


public slots:
    void afficheRtkrcvsatellite(int i);
    void etatsatellite();
    void etatstatut();
    void etatNaviData();
    void etatStream();
    void saveposition();
    void sauvegardedansfichier(QString filePath = QString("testSauvegarde.txt"), QString pointName = QString(""), int numOfMeasures = 1, float cycleLong = 1,bool addMeasures = false);
    void changeSaveOptions(QStringList options);
    void setSYStime();



signals:
    void emitdonneesStatus(QStringList);
    void emitdonneesSatellites(QStringList,int);
    void emitinterne(int i);
    void emitdonneesStream(QStringList,int);
    void save(int);
    void savePointNbr(QString);
    void etatFermetureVT(bool);

protected:
    virtual void run();
    //void exec();

};

#endif // MAINTHREAD_H
