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


#include <QtMath>

#include "coord_coverter.h"



QVector<double> Coord_coverter::ecef_to_geo(QVector<double> ecef)
{

    /*------------------------------------------------------------------------------/
        Convert Earth-Centered-Earth-Fixed (ECEF) to lat, Lon, Altitude
        Input :
            - A three element array containing x, y, z in meters
        OUTPUT:
            - Array contains lat and lon in radians, and altitude in meters
    /------------------------------------------------------------------------------*/


     QVector<double> geo; //= new double[3];   //Results go here (Lat, Lon, Altitude)
     geo.append(0);
     geo.append(0);
     geo.append(0);
     x = ecef[0];
     y = ecef[1];
     z = ecef[2];
     zp = qFabs( z );
     w2 = x*x + y*y;
     w = qSqrt( w2 );
     r2 = w2 + z*z;
     r = qSqrt( r2 );
     geo[1] = qAtan2( y, x );       //Lon (final)

     s2 = z*z/r2;
     c2 = w2/r2;
     u = a2/r;
     v = a3 - a4/r;
     if( c2 > 0.3 )
     {
         s = ( zp/r )*( 1.0 + c2*( a1 + u + s2*v )/r );
         geo[0] = qAsin( s );      //Lat
         ss = s*s;
         c = qSqrt( 1.0 - ss );
     }
     else
     {
         c = ( w/r )*( 1.0 - s2*( a5 - u - c2*v )/r );
         geo[0] = qAcos( c );      //Lat
         ss = 1.0 - c*c;
         s = qSqrt( ss );
     }
     g = 1.0 - e2*ss;
     rg = a/qSqrt( g );
     rf = a6*rg;
     u = w - rg*c;
     v = zp - rf*s;
     f = c*u + s*v;
     m = c*v - s*u;
     p = m/( rf/g + f );
     geo[0] = geo[0] + p;     //Lat
     geo[2] = f + m*p/2.0;    //Altitude
     if( z < 0.0 ){
         geo[0] *= -1.0;     //Lat
     }

     return geo ;           //Return Lat, Lon, Altitude in that order
 }



QVector<double> Coord_coverter::geo_to_ecef(QVector<double> geo)

 {
    /*------------------------------------------------------------------------------/
        Convert Lat, Lon, Altitude to Earth-Centered-Earth-Fixed (ECEF)
        INPUT:
            - Three element array containing lat, lon (rads) and alt (m)
        OUTPUT:
            - Array contains x, y, z in meters
    /------------------------------------------------------------------------------*/


    QVector<double>ecef;                             //Results go here (x, y, z)
    ecef.append(0);
    ecef.append(0);
    ecef.append(0);
    lat = geo[0];
    lon = geo[1];
    alt = geo[2];
    n = a/qSqrt( 1 - e2*qSin( lat )*qSin( lat ) );
    ecef[0] = ( n + alt )*qCos( lat )*qCos( lon );   //ECEF x
    ecef[1] = ( n + alt )*qCos( lat )*qSin( lon );   //ECEF y
    ecef[2] = ( n*(1 - e2 ) + alt )*qSin( lat );     //ECEF z
    return ecef ;                                    //Return x, y, z in ECEF
}

