#ifndef GPSTIME_H_INCLUDED
#define GPSTIME_H_INCLUDED
#include <iostream>

#include <sys/time.h>



class Gpstime
{
    public:
        Gpstime();
        virtual ~Gpstime();
        void s1970_t(double s1970);
        void jd_t(double jd);
        void mjd_t(double mjd);
        void jd50_t(double jd50);
        void ymdhms_t(int y, int m, int d, int hh, int mm, double ss);
        void yyyyddds_t(int yyyy, int ddd, double s);
        void gpswkd_t(int wk, double wday);
        void gpswks_t (int wk, double wsec);
        void dy_t(double dy);

        void iso_t(std::string s);
        void just_now();

        void afficher ();
        void print_dates();

        void add_day(double d);
        void add_h(double h);
        void add_s(double s);
        void wk00();
        void day00();
        void h00();
        void m00();

        double get_s1970() const {return s1970;}
        double get_jd() const {return jd;}
        double get_mjd() const {return mjd;}
        double get_jd50() const {return jd50;}
        int get_wk() const {return wk;}
        double get_wsec() const {return wsec;}
        int get_yy() const {return yy;}
        int get_yyyy() const {return yyyy;}
        int get_mon() const {return mon;}
        int get_doy() const {return doy;}
        int get_dd() const {return dd;}
        int get_hh() const {return hh;}
        int get_mm() const {return mm;}
        double get_sec() const {return sec;}
        int get_wd() const {return wd;}
        double get_dsec() const {return dsec;}
        double get_dy() const {return dy;}
        double get_GMST() const {return GMST;}
        double get_EQEQ() const {return EQEQ;}
        double get_GAST() const {return GAST;}

   //private:
        double s1970;
        double jd , mjd , jd50 ;
        int wk;
        double wsec;
        int yy, yyyy, mon, doy;
        int dd , hh , mm ;
        double sec ;
        int wd;
        std::string wd_en;
        double dsec;
        double dy;
        struct tm *m_date;
        double GMST;
        double EQEQ;
        double GAST;


        void give_time();
};
#endif // GPSTIME_H


