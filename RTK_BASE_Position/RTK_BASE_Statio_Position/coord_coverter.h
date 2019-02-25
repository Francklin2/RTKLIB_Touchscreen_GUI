#ifndef COORD_COVERTER_H
#define COORD_COVERTER_H
#include <QVector>


class Coord_coverter
{

private:
    //static final;
    static const double  a = 6378137.0;              //WGS-84 semi-major axis
    static const double e2 = 6.6943799901377997e-3;  //WGS-84 first eccentricity squared
    static const double a1 = 4.2697672707157535e+4;  //a1 = a*e2
    static const double a2 = 1.8230912546075455e+9;  //a2 = a1*a1
    static const double a3 = 1.4291722289812413e+2;  //a3 = a1*e2/2
    static const double a4 = 4.5577281365188637e+9;  //a4 = 2.5*a2
    static const double a5 = 4.2840589930055659e+4;  //a5 = a1+a3
    static const double a6 = 9.9330562000986220e-1;  //a6 = 1-e2
    double zp,w2,w,r2,r,s2,c2,s,c,ss;
    double g,rg,rf,u,v,m,f,p,x,y,z;
    double n,lat,lon,alt;
public:

    QVector<double> ecef_to_geo( QVector<double> ecef );
    QVector<double> geo_to_ecef(QVector< double> geo );





};

#endif // COORD_COVERTER_H
