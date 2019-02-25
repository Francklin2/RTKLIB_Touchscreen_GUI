#ifndef STATION_H
#define STATION_H
#include <QString>
#include <QVector>
#include <QDebug>
#include <QList>
#include <QtMath>
#include <QTextEdit>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QDebug>

#include "approxcoord.h"

class Station
{
public:

    Station();

    QString corrdstation_ftp;                               // ftp link of the coordinate station file, Example:"coorrgf93_2018-020.txt"
    QString nomDuFichier;
    QString _antenna_type_station;                          // Contains the antenna type of each station

    QVector<QString> _coord_antenna;                        // Contains the coordinates antenna of each station
    QVector<QString> _coord_station;                        // Contains the coordinates of the station
    QVector<QString> vect_name;                             // Contains the names of the stations
    QVector<QString> vect_domes;                            // Contains the international number of each station

    QVector<double> vect_X,vect_Y,vect_Z,vect_dist;
    QVector<double>X0;                                      // Estimated position of RTK_base_station

    void neareststation();
    void station_data(QString station_obs_file,QString path);

    QString Corrdstation_ftp(int doy,int yyyy);
    QVector<QString> data_file_nearest_sation(int doy,int yyyy,QVector<int>TIME_OF_FIRST_OBS,QVector<int>TIME_OF_LAST_OBS, int i);

//private:
    static const float d_max=100000.0;                      // Max search radius for stations
    static const int nb_stat_min=4;                         // Minimum number of stations to start the calculation
};

#endif // STATION_H
