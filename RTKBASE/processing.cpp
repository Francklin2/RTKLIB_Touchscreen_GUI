#include  <QApplication>
#include  <QDebug>
#include  <QDate>
#include  <QThread>
#include  <iostream>
#include  <QProcess>
#include <QDir>

#include  "mainwindow.h"
# include "gpstime.h"
#include  "station.h"
#include  "downloader.h"
#include  "approxcoord.h"
#include  "rnx2rtkp.h"
#include  "processing.h"

#include "mydialog.h"



 extern QString Radmax;
 int d_max1 =  Radmax.toInt();

void processing()
{

    QThread sleep;

    /*------------------------------------------------------------------------------/
        - Chek the existence of the package  directory
        - Package installation
    /------------------------------------------------------------------------------*/

    QString path="../work/";
    if(!QDir("../Package").exists())
    {
        qDebug()<<"----- Package directory does not exist!!!";
        return;
    }

    QProcess install_package ;
    QString install_package_command;
    install_package_command="rm -r -R "+path;
    install_package.start(install_package_command);
    install_package.waitForFinished(-1);
    if (install_package.state()==0)
    {
        install_package_command="mkdir ../work";                                    //create a work folder
        install_package.start(install_package_command);
        install_package.waitForFinished(-1);

        if (install_package.state()==0)
        {
            install_package_command="cp ../Package/Configuration.conf "+path;
            install_package.start(install_package_command);
            install_package.waitForFinished(-1);

            install_package_command=install_package_command="cp ../Package/ngs14.atx "+path;
            install_package.start(install_package_command);
            install_package.waitForFinished(-1);

            install_package_command=install_package_command="cp ../Package/CRX2RNX "+path;
            install_package.start(install_package_command);
            install_package.waitForFinished(-1);

            install_package_command=install_package_command="cp ../Package/rover.ubx "+path;
            install_package.start(install_package_command);
            install_package.waitForFinished(-1);

            install_package_command=install_package_command="cp ../Package/teqc "+path;
            install_package.start(install_package_command);
            install_package.waitForFinished(-1);

            if (install_package.state()==0)
            {
                qDebug()<<"----- The package was successfully installed "<<endl;
                        }
            else
                qDebug()<<"----- Error! comand "<<install_package_command<<endl;
        }
        else
            qDebug()<<"----- Error! comand "<<install_package_command<<endl;
    }
    else
        qDebug()<<"----- Error! comand "<<install_package_command<<endl;

    Rnx2rtkp cal;
    Downloader down;
    Approxcoord X0;
    Station st;
    Gpstime t;

    /*------------------------------------------------------------------------------/
        - GPS_TIME inisialisation
    /------------------------------------------------------------------------------*/

    //t.gpswkd_t();
    t.just_now();
    qDebug()<<" date = " << t.dd << "/" << t.mon << "/" << t.yyyy ;
    qDebug()<<" heure= " << t.hh << ":" << t.mm << ":" << t.sec ;
    //qDebug()<<" doy="<<t.doy;

    /*------------------------------------------------------------------------------/
        - Conversion of ubx file to .obs
        - Search and find of:
                - Approxcoord of the RTK_Base station,
                - Date of observation,
                - Duration of observation
    /------------------------------------------------------------------------------*/

    X0.path=path;
    X0.conversion();
    if (X0.verif_file==false)
        return;
    X0.approx_coord();
    if (X0.verif_file==false)
        return;

    X0.TIME_OF_LAST_OBS[0]=X0.TIME_OF_LAST_OBS[0]+1;
    X0.TIME_OF_FIRST_OBS[0]=X0.TIME_OF_FIRST_OBS[0]+1;

    qDebug()<<"Approx coordinate X0="<<X0.approx__coord[0]<<","<<X0.approx__coord[1]<<","<<X0.approx__coord[2];
    qDebug()<<"Time of first obs= "<<X0.TIME_OF_FIRST_OBS[0]<<":"<<X0.TIME_OF_FIRST_OBS[1];
    qDebug()<<"Time of last obs= "<<X0.TIME_OF_LAST_OBS[0]<<":"<<X0.TIME_OF_LAST_OBS[1];
    qDebug()<<"Date of obs= "<<X0.DATE_OF_OBS[0]<<"/"<<X0.DATE_OF_OBS[1]<<"/"<<X0.DATE_OF_OBS[2];

    int mon=X0.DATE_OF_OBS[1];
    int yyyy=X0.DATE_OF_OBS[2];
    int dd=X0.DATE_OF_OBS[0];
    QDate d(yyyy,mon,dd);
    int doy= d.dayOfYear();

    /*------------------------------------------------------------------------------/
        - Verification of the internet connection
        - Verification of the "RGP-ftp" link
    /------------------------------------------------------------------------------*/

    st.Corrdstation_ftp(doy,yyyy);
    qDebug()<<" FTP of RGP Stations coordinate:"<<st.corrdstation_ftp;

    /*------------------------------------------------------------------------------/

        - Waiting untill the RGP data will be available
        - This part deals with the epoch problem
    /------------------------------------------------------------------------------*/

    int observation_time;
    observation_time=(X0.TIME_OF_LAST_OBS[0]*60+X0.TIME_OF_LAST_OBS[1])-(X0.TIME_OF_FIRST_OBS[0]*60+X0.TIME_OF_FIRST_OBS[1]);
    if(observation_time<30)
    {
        qDebug()<<" Not enough observations "<<observation_time<<"<30 min"<<endl;
        return;
    }

    if((yyyy=t.yyyy)&&(mon=t.mon)&&(dd=t.dd)&&(t.hh<X0.TIME_OF_LAST_OBS[0]+1)&&(X0.TIME_OF_LAST_OBS[1]>observation_time/2))
    {
        qDebug()<<" RGP data are not available until "<<X0.TIME_OF_LAST_OBS[0]+1<<":04"<<endl;

        int a= ((X0.TIME_OF_LAST_OBS[0]+1)*3600+5*60)-(t.hh*3600+t.mm*60);

        qDebug()<<"Wait:"<<a<<" sec"<<a/60<<" min"<<endl;

        sleep.sleep(a);
    }

    if(X0.TIME_OF_LAST_OBS[1]<observation_time/2)
    {
        X0.TIME_OF_LAST_OBS[0]=X0.TIME_OF_LAST_OBS[0]-1;
    }


    /*------------------------------------------------------------------------------/
        - Downloading of the station coordinates file
    /------------------------------------------------------------------------------*/

    down.url=st.corrdstation_ftp;                   //Download link
    down.file_name=down.url.split("/")[7];          //Name of the file to download
    down.saving_path=path;                          //Path of saving
    down.do_downloader();                           //The downloading process

    if(down.downfailed==true)
    {
        qDebug()<<" There is no internet connection:fail to download"<< down.file_name<<endl;
        down.downfailed=false;
        return;
    }


    /*------------------------------------------------------------------------------/
        - Sort of stations
    /------------------------------------------------------------------------------*/

    st.X0=X0.approx__coord;                         //Approx coordinates of the RTK_Base station
    st.nomDuFichier=path+down.url.split("/")[7];
    st.neareststation();                            //Sort of stations process

    qDebug()<<"Number of stations within a radius of: "<<d_max1<<"Km:"<<st.vect_name.size()<<" Stations"<<endl;
    qDebug()<<"The stations are :"<<st.vect_name<<endl;


    int i=0,nbstation=0;                            // i reprents the i th nearest station

    while(nbstation<4)
    {
        /*------------------------------------------------------------------------------/
            Downloading for each 4 nearest station the following files:
                - Observation file
                - Navigation GPS file
                - Navigation GLONASS file
        /------------------------------------------------------------------------------*/

        //Downloading of the observation file

        down.url=st.data_file_nearest_sation(doy,yyyy,X0.TIME_OF_FIRST_OBS,X0.TIME_OF_LAST_OBS,i)[2];       //Download link
        down.file_name=st.data_file_nearest_sation(doy,yyyy,X0.TIME_OF_FIRST_OBS,X0.TIME_OF_LAST_OBS,i)[0]; //Name of the file to download
        down.do_downloader();

        if(down.downfailed==true)
        {
            qDebug()<<"We can't download data for this station:"<< st.vect_name[i]<<"we will try the next nearest station"<<endl;
            down.downfailed=false;
            goto end;
        }

        down.unzip_file();                          //Decompressing process

             //Downloading of the navigation file (GPS)

        down.file_name=st.data_file_nearest_sation(doy,yyyy,X0.TIME_OF_FIRST_OBS,X0.TIME_OF_LAST_OBS,i)[3];
        down.url=st.data_file_nearest_sation(doy,yyyy,X0.TIME_OF_FIRST_OBS,X0.TIME_OF_LAST_OBS,i)[5];
        down.do_downloader();
        down.unzip_file();

          //Downloading of the navigation file (GLONASS)
        down.file_name=st.data_file_nearest_sation(doy,yyyy,X0.TIME_OF_FIRST_OBS,X0.TIME_OF_LAST_OBS,i)[6];
        down.url=st.data_file_nearest_sation(doy,yyyy,X0.TIME_OF_FIRST_OBS,X0.TIME_OF_LAST_OBS,i)[8];
        down.do_downloader();
        down.unzip_file();


        /*-------------------------------------------------------------------------------/
            Generate the configuration file for the RNX2RTKP calculation process
        /------------------------------------------------------------------------------*/


        cal.path=path;
        cal.station_obs_file=st.data_file_nearest_sation(doy,yyyy,X0.TIME_OF_FIRST_OBS,X0.TIME_OF_LAST_OBS,i)[1];
        cal.station_nav_file=st.data_file_nearest_sation(doy,yyyy,X0.TIME_OF_FIRST_OBS,X0.TIME_OF_LAST_OBS,i)[4];
        cal.station_g_file=st.data_file_nearest_sation(doy,yyyy,X0.TIME_OF_FIRST_OBS,X0.TIME_OF_LAST_OBS,i)[7];

        st.station_data(cal.station_obs_file,path);

        qDebug()<<"For the station: "<<st.vect_name[i]<<" the data are:"<<endl;
        qDebug()<<"_antenna_type_station"<<st._antenna_type_station<<endl;
        qDebug()<<"_coord_antena"<<st._coord_antenna[0]<<","<<st._coord_antenna[1]<<","<<st._coord_antenna[2]<<endl;
        qDebug()<<"_coord_station"<<st._coord_station[0]<<","<<st._coord_station[1]<<","<<st._coord_station[2]<<endl;

        cal._antenna_type_station=st._antenna_type_station;
        cal._coord_antenna=st._coord_antenna;
        cal._coord_station=st._coord_station;

        qDebug()<< "----------- Genration of the configuration file ----------- "<<endl;
        cal.configuration_file();

        /*-------------------------------------------------------------------------------/
           The RNX2RTKP calculation process
        /------------------------------------------------------------------------------*/
        cal.rnx2rtkp(nbstation);

        nbstation++;
        qDebug()<<"Number of station downloaded="<<nbstation<<endl;
        end:
        i++;
        if (nbstation<4)
            qDebug()<<"---- ****** Next station:"<<st.vect_name[i]<<" ***** -----"<<endl;

    }


    /*-------------------------------------------------------------------------------/
        - The "Results.pos" file contains the results of the rnx2rtkp calculation
        - A final solution calculated by the median method
    /------------------------------------------------------------------------------*/

    cal.final_results(cal.results);

    qDebug()<<"The position of RTK_BASE station :";
    qDebug()<<cal.X_Y_Z_ecef_final[0];
    qDebug()<<cal.X_Y_Z_ecef_final[1];
    qDebug()<<cal.X_Y_Z_ecef_final[2];
 }




