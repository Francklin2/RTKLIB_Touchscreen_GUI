#ifndef APPROXCOORD_H
#define APPROXCOORD_H
#include <QProcess>
#include <QDebug>
#include <QFileInfo>
#include <QFile>
#include <QString>
#include <QVector>

class Approxcoord
{
public:
    Approxcoord();
    void conversion();
    void approx_coord();
    QVector<double> approx__coord;
    QVector<int> TIME_OF_FIRST_OBS,TIME_OF_LAST_OBS,DATE_OF_OBS;
    QString path;

    bool verif_file;                    //The status of a file (true = the file exist)
};

#endif // APPROXCOORD_H
