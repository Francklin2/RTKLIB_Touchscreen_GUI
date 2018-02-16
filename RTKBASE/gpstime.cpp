#include <iostream>
#include "gpstime.h"

#include <stdio.h>
#include<cmath>
#include<sstream>

#include <sys/time.h>
#include <QDebug>


using namespace std;

int bissextile(int a, int b)
 {
     int nb=0;
      for (int i=a; i<b; i++)
    {
        if (((i%4==0)&&(i%100!=0)) || (i%400==0)) nb++;
       //compter le nombred’années bissextiles entre 1970 et l’année donnée
    }
     return(nb);
 }

Gpstime::Gpstime()
{
    //ctor
}

Gpstime::~Gpstime()
{
    //dtor
}

void Gpstime::gpswks_t(int wk, double wsec)
{
    struct tm tps = {0,0,1,6,0,80,0,0,0,0,0};  //06/01/80
    time_t s1980 = mktime(&tps);    //nombre de seconds entre 1970 et 1980.
    double s1970;
    s1970 = s1980 + ( wk * 7 * 24 * 3600 ) + wsec ;
    this->s1970_t(s1970);
    printf("hello");
}

void Gpstime::gpswkd_t(int wk, double wday)
{
    double wsec = wday * 24 * 3600 ;
    this->gpswks_t(wk,wsec);
}

void Gpstime::dy_t(double dy)
{
    double sec;
    int y = int(dy) - 1900;

    if (((int(dy)%4==0)&&(int(dy)%100!=0)) || (int(dy)%400==0))
        sec = ( dy - int(dy) ) * 366 * 24 * 3600 ;
    else
        sec = ( dy - int(dy) ) * 365 * 24 * 3600 ;

    struct tm year = {0,0,1,1,0,y,0,0,0,0,0};
    double s1970 = mktime(&year) + sec ;
    this->s1970_t(s1970);
}

void Gpstime::ymdhms_t(int y, int m, int d, int hh, int mm, double ss)
{
    int int_ss = int(ss);
    double D_ss = ss - int_ss ;

    if ( y < 80 )
        y = y + 2000 ;
    else
        if ( y < 100 )
            y = y + 1900 ;

    struct tm date = {int_ss, mm, hh+1, d, m-1, y-1900, 0,0,0,0,0};
    double s1970 = mktime (&date) + D_ss ;

    this->s1970_t(s1970);

}

void Gpstime::yyyyddds_t(int yyyy, int ddd, double s)
{
    int id = 0 , im , ifin = 12 , i = 0 ;

    if (((yyyy%4==0)&&(yyyy%100!=0)) || (yyyy%400==0)) i=1;  // si l année est bisextille
    int day[13] = {0 ,31 ,59+i ,90+i ,120+i ,151+i ,181+i ,212+i ,243+i ,273+i ,304+i ,334+i ,365+i } ;
    while( ifin - id > 1 )
         {
             im = ( id + ifin ) / 2 ;
             if ( ddd <= day[im] ) ifin = im ;  else id = im ;
         }   //dichotomie pour chercher le moi et le jour dans le moi
        int d = ddd - day[id] ;

        int hh = int ( s / 3600 ) ;
        int m = int ( ( s - hh * 3600 ) / 60 ) ;
        double ss = s - hh * 3600 - m * 60 ;

        this->ymdhms_t(yyyy,ifin, d, hh, m, ss);
}

void Gpstime::mjd_t(double mjd)
{
    float nb = bissextile( 1859 , 1970 );
    double s1858 = ( nb * 366 * 24 * 3600 ) + ( ( 1970 - 1859 - nb ) * 365 * 24 * 3600 ) + ( 45 * 24 * 3600 ) ;
    double msd = mjd * 24 * 3600 ;   //second entre 17/11/1858 et 1/1/1970
    double s1970 = msd - s1858 ;
    this->s1970_t(s1970);
}

void Gpstime::jd_t(double jd)
{
    this->mjd_t( jd - 2400000.5 );
}

void Gpstime::jd50_t(double jd50)
{
    int  nb = bissextile ( 1950 , 1970 ) ;
    float j1950 = ( nb * 366 ) + ( ( 1970 - 1950 - nb ) * 365 ) ; //jours entre 1/1/1950 et 1/1/1970
    double s1970 = ( jd50 - j1950 ) * 24 * 3600 ;
    this->s1970_t(s1970);
}

void Gpstime::s1970_t(double s1970)
{
    this->s1970 = s1970;

    time_t int_s1970 = int(s1970) ;

    double D_s1970 = s1970 - int_s1970 ;
    // mjd & jd
    int  nb = bissextile ( 1859 , 1970 ) ;
    float j1858 = ( nb * 366 ) + ( ( 1970 - 1859 - nb ) * 365 ) + 45 ; //jours entre 17/11/1858 et 1/1/1970
    this->mjd = j1858 + s1970 / ( 24 * 3600 ) ;
    this->jd = this->mjd + 2400000.5 ;

    // jd50
    struct tm tps2 = {0,0,1,1,0,90,0,0,0,0,0}; //01/01/90 symétrique de 1/1/1950
    time_t s1950 = mktime ( &tps2 ) ;
    this->jd50 = ( s1950 + s1970 ) / ( 24 * 3600 ) ;
    // 2em methode jd50
    // int  nb2 = bissextile ( 1950 , 1970 ) ;
    // float j1950 = ( nb2 * 366 ) + ( ( 1970 - 1950 - nb2 ) * 365 ) ; //jours entre 1/1/1950 et 1/1/1970
    // d.jd50 = j1950 + s1970 / ( 24 * 3600 ) ;

    //week day & week second
    struct tm tps = {0,0,1,6,0,80,0,0,0,0,0} ; //06/01/80
    time_t s1980 = mktime ( &tps ) ;       //second between 70 et 80
    double sec =  s1970 - s1980 ;
    this->wk =  sec / ( 7 * 24 * 3600 ) ;
    this->wsec = sec - this->wk * 7 * 24 * 3600 ;

    this->m_date = localtime(& int_s1970);

    //year
    this->yyyy = 1900 + this->m_date->tm_year;
    //year year
    this->yy = -1 ; //cas ou c’est en dehors de l’intervalle exigé
    if ( this->yyyy >= 2000 )
        this->yy = this->yyyy - 2000 ;
    else
        if ( (this->yyyy<=1999) && (this->yyyy>=1980) )
            this->yy = this->yyyy - 1900 ;
    // month
    this->mon = this->m_date->tm_mon + 1 ;


    //day of the month
    this->dd = this->m_date->tm_mday ;


    //this->hh = this->m_date->tm_hour - 1 ;
    this->hh = this->m_date->tm_hour ;
    //je fixe l'heure de travail
    //this->hh = 15 ;
    // minutes after the hour
    this->mm = this->m_date->tm_min;
    //this->mm = 12;
    // seconds after the minute
    this->sec = this->m_date->tm_sec + D_s1970 ;
    //this->sec =0;
    //day second
    this->dsec= this->hh * 3600 + this->mm * 60 + this->sec ;

    // days since January 1
    //this->doy = this->m_date->tm_yday + 1 ;
    ;
    this->doy = this->m_date->tm_yday + 1 ;
    //days since Sunday [0-6]
    this->wd = this->m_date->tm_wday ;

    const std::string weekday[] = { "SUN", "MON",  "TUE", "WED", "THU", "FRI", "SAT"};

    this->wd_en = weekday[this->wd];

    // decimal year
    int i=0;
    if (((this->yyyy%4==0)&&(this->yyyy%100!=0)) || (this->yyyy%400==0))
        i=1;
    this->dy = this->yyyy + ( ( (this->doy-1) * 24 * 3600 + this->dsec ) / ( 3600 * 24 * ( 365 + i )));

    //  GMST
    double D = this->jd - 2451545.0; // Julian days  since 2000 January 1, at 12h UT
    double GMST =  18.697374558 + 24.06570982441908 * D ;
    this->GMST = GMST - 24 * int( GMST / 24.0 ); // Unit : decimal hour

    //  Equation of Equinoxes
    double d2r = M_PI / 180.0;
    double Omega = 125.04 - 0.052954 * D;     // Longitude of the ascending node of the Moon
    double L = 280.47 + 0.98565 * D;          // Mean Longitude of the Sun
    double epsilon = 23.4393 - 0.0000004 * D; // obliquity
    double Delta_psi = -0.000319 * sin (Omega*d2r) - 0.000024 * sin (2*L*d2r); // nutation in longitude
    this->EQEQ = Delta_psi * cos(epsilon * d2r);

    //  GAST
    this->GAST = this->GMST + this->EQEQ;


}

void Gpstime::just_now()
{
   struct timeval tm;
   gettimeofday(&tm, NULL);
   this->s1970_t(tm.tv_sec+tm.tv_usec*1e-6);

}


void Gpstime::iso_t(std::string s)
{
    // format yyyy-MM-ddThh:mm:ss.sss
    std::string::size_type sz;
    std:: string chaine = s.substr(0,4); // extraire année
    int yyyy, mm , dd, hh,m, ss;
    float ms;
    stringstream(chaine)>>yyyy;
    chaine = s.substr(5,2); //extraire mois
    stringstream(chaine)>>mm;
    chaine = s.substr(8,2); //extraire joue
    stringstream(chaine)>>dd;
    chaine = s.substr(11,2); //extraire heure
    stringstream(chaine)>>hh;
    chaine = s.substr(14,2); //extraire minutes
    stringstream(chaine)>>m;
    chaine = s.substr(17,2); //extraire secondes
    stringstream(chaine)>>ss;
    chaine = s.substr(20,3); //extraire secondes
    stringstream(chaine)>>ms;
    ms = ss + ms / 1000 ;
    return ymdhms_t(yyyy, mm, dd, hh, m, ms);
}

void Gpstime::afficher ()
{
        cout<<endl;
        printf(" s1970= %.6f\n", this->s1970 );
        printf(" mjd  = %.10f\n", this->mjd );
        printf(" jd   = %.10f\n", this->jd );
        printf(" jd50 = %.10f\n", this->jd50 );
        printf(" wk   = %d\n", this->wk );
        printf(" wsec = %.6f\n", this->wsec );
        cout<< " date = " << this->dd << "/" << this->mon << "/" << this->yyyy << std::endl;
        cout<< " heure= " << this->hh << ":" << this->mm << ":" << this->sec << std::endl;
        printf(" yy   = %d\n", this->yy );
        printf(" doy  = %d\n", this->doy );
        printf(" wd   = %d\n", this->wd );
        printf(" dsec = %.6f\n",this->dsec );
        printf(" dy   = %.15f\n", this->dy );
        printf(" GMST = %.5f\n", this->GMST );
        printf(" EQEQ = %.5f\n", this->EQEQ );
        printf(" GAST = %.5f\n", this->GAST );
}

void Gpstime::print_dates ()
{

    printf(" s1970= %.6f\n", this->s1970 );
    printf(" YYYY/MM/DD = %04d/%02d/%02d\n",this->yyyy,this->mon,this->dd);
    printf(" HH:MM:SS = %02d:%02d:%09.6f\n",this->hh,this->mm,this->sec);
    printf(" GPS week = %d\n", this->wk );
    printf(" Day of week = %d (%s)\n", this->wd, std::string(this->wd_en).c_str());
    printf(" Second of week = %.6f\n", this->wsec );
    printf(" Second of day = %.6f\n",this->dsec );
    printf(" Modified Julian Date  = %.10f\n", this->mjd );
    printf(" Julian Date   = %.10f\n", this->jd );
    printf(" Julian date since 1950/01/01 = %.10f\n", this->jd50 );
    printf(" YYYY   = %04d DOY  = %03d\n", this->yyyy,this->doy );
    printf(" Decimal year  = %.4f\n", this->dy );
    printf(" GMST (dec. hour) = %.6f\n", this->GMST );
    printf(" EQEQ (dec. hour) = %.6f\n", this->EQEQ );
    printf(" GAST (dec. hour) = %.6f\n", this->GAST );
}



//Ajout et soustraction de durées
void Gpstime::add_day(double d)
{
    this->s1970_t(this->s1970 + d * 24.0 * 3600.0);
}

void Gpstime::add_h(double h)
{
    this->s1970_t(this->s1970 + h * 3600.0);
}

void Gpstime::add_s(double s)
{
    this->s1970_t(this->s1970 + s);
}

//Recherche des début de périodes
void Gpstime::wk00()
{
    this->gpswkd_t(this->wk, 0);
}

void Gpstime::day00()
{
    this->ymdhms_t(this->yyyy,this->mon,this->dd, 0, 0, 0);
}

void Gpstime::h00()
{
    this->ymdhms_t(this->yyyy,this->mon,this->dd,this->hh, 0, 0);
}

void Gpstime::m00()
{
    this->ymdhms_t(this->yyyy,this->mon,this->dd,this->hh, this->mm, 0);
}
