#ifndef MAINTHREADREADFILE_H
#define MAINTHREADREADFILE_H
#include <QtCore>
#include <QThread>
#include <vector>
#include <stdlib.h>
#include <QMutex>

using namespace std;

class MainThreadReadFile:public QThread
{
    Q_OBJECT
public:
    MainThreadReadFile(QObject *parent=NULL);
    virtual ~MainThreadReadFile();

protected:
    virtual void run();

private:


public slots:

signals:
     void emitdonneesStr2str(QStringList);

};

#endif // MAINTHREADREADFILE_H
