#include "MainthreadStr2str.h"
#include <QThread>
#include <QMutex>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <QList>
#include <QFile>

using namespace std;

extern "C" int mainstr2str(int argc, char **argv);
extern "C" int etatStream();
extern "C" int fermeStr2str();


MainthreadStr2str::MainthreadStr2str(QObject* parent):
QThread(parent)
{
    m_stopped = false;
}


MainthreadStr2str::~MainthreadStr2str()
{
     exit();
     wait();
     // nettoyage
}


void MainthreadStr2str::stop()
{
    qDebug()<<"-----------------on est avant la fermeture-------------------";
    fermeStr2str();
    qDebug()<<"-----------------on est après la fermeture-------------------";
    sleep(3);
    m_stopped = true; // après ne retourne pas dans le run()...
    emit etatFermetureThreadStr2str(true);
    //terminate();
}



void MainthreadStr2str::setArgcArgvStr2str(std::vector<string> args)
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


void MainthreadStr2str::close(int i)
{
    if (i==1) m_choix=2;
}


void MainthreadStr2str::run()
{

    while (!m_stopped)
    {
        qDebug()<<"je suis ici";
        mainstr2str(argc,argv);


        while(1)
        {
            qDebug()<<"------------------------------------------------------on est dans le while-----------------------------------------------";
            if (m_choix==1) etatStream();
            if (m_choix==2) stop();
            sleep(1);
        }
    }
    m_stopped = false;
        //exec();

}

