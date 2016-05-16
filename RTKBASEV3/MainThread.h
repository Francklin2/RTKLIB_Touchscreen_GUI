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
    void sauvegardedansfichier();



signals:
    void emitdonneesStatus(QStringList);
    void emitdonneesSatellites(QStringList,int);
    void emitinterne(int i);
    void emitdonneesStream(QStringList,int);
    void save(int);
    void savePointNbr(int);
    void etatFermetureVT(bool);

protected:
    virtual void run();
    //void exec();

};

#endif // MAINTHREAD_H
