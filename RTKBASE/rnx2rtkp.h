#ifndef RNX2RTKP_H
#define RNX2RTKP_H

#include <QProcess>
#include <QDebug>
#include <QFileInfo>
#include <QFile>
#include <QString>
#include <QVector>

#include "mydialog.h"

#include "mainthreadreadfile.h"
#include <QDialog>
#include "MainthreadStr2str.h"
#include "magraphicsscene.h"

extern QString Sol_x_LLH;
extern QString Sol_y_LLH;
extern QString Sol_z_LLH;

 extern QString Sol_x_ECEF;
 extern QString Sol_y_ECEF;
 extern QString Sol_z_ECEF;




class Rnx2rtkp
{
public:
    QString path;
    QString station_obs_file;
    QString station_nav_file;
    QString station_g_file;
    QString _antenna_type_station;
    QVector<QString> _coord_antenna;
    QVector<QString> _coord_station;
    QVector<QString> X_Y_Z_ecef_final;
    QString results;





    void final_results(QString s);
    void rnx2rtkp(int i);

//private:
    void configuration_file();

 //   Ui::MyDialog *ui;
    MainthreadStr2str* m_tstr2str=new MainthreadStr2str;
    MainThreadReadFile* m_readfile=new MainThreadReadFile;
    std::vector<std::string> args;
    std::vector<std::string> args1;
    std::vector<std::string> arga;


};

#endif // RNX2RTKP_H
