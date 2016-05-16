#ifndef MAINTHREADSTR2STR_H
#define MAINTHREADSTR2STR_H
#include <QtCore>
#include <QThread>
#include <vector>
#include <stdlib.h>
#include <QMutex>

using namespace std;

class MainthreadStr2str:public QThread
{
        Q_OBJECT
public:
    MainthreadStr2str(QObject *parent=NULL);
    virtual ~MainthreadStr2str();
    void setArgcArgvStr2str(std::vector<std::string> args);
    void stop();

protected:
    virtual void run();

private:
    int argc;
    char **argv;
    int m_choix=1;
    volatile bool m_stopped;

public slots:
    void close(int);


signals:
    void etatFermetureThreadStr2str(bool);

};


#endif // MAINTHREADSTR2STR_H
