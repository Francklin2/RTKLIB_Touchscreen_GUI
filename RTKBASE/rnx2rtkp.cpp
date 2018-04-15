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
#include <QThread>

#include "rnx2rtkp.h"
#include "coord_coverter.h"

#include "mydialog.h"
#include "ui_mydialog.h"

#include <iostream>
#include <fstream>

 QString Sol_x_ECEF;
 QString Sol_y_ECEF;
 QString Sol_z_ECEF;

 QString Sol_x_LLH;
 QString Sol_y_LLH;
 QString Sol_z_LLH;


QString Mode_str2str;






void Rnx2rtkp::configuration_file()
{
    // Open configuration file to read max radius for station and nb of station
 QString Server;


        int ti=1;
        QStringList list;
        QString fileName = "sauvegardeoptionAutoPPbase.txt";
        QFile readoption(fileName);
        readoption.open(QIODevice::ReadOnly | QIODevice::Text);
        //---------verifier ouverture fichier......
        QTextStream flux(&readoption);
        QString ligne;
        while(! flux.atEnd())
        {
           ligne = flux.readLine();
           //traitement de la ligne
           qDebug()<<ligne;
           list<<ligne;
           ti=ti+1;
        }

           Server = (list[12]);

        readoption.close();


    /*-------------------------------------------------------------------------------/
      - Convert ECEF to llh coordinates
    /------------------------------------------------------------------------------*/
    QVector<QString> LLH_station_as_string;

//        if(Server=="rgpdata.ign.fr")
//        {
    QVector<double> ecef;
    ecef.append(_coord_station[0].toDouble());
    ecef.append(_coord_station[1].toDouble());
    ecef.append(_coord_station[2].toDouble());

    Coord_coverter c;
    //qDebug()<<c.ecef_to_geo(ecef);  //en rad


    LLH_station_as_string.append(QString::number(qRadiansToDegrees(c.ecef_to_geo(ecef)[0])));
    LLH_station_as_string.append(QString::number(qRadiansToDegrees(c.ecef_to_geo(ecef)[1])));
    LLH_station_as_string.append(QString::number(c.ecef_to_geo(ecef)[2]));
    qDebug()<<"LLH_station_as_string"<<LLH_station_as_string<<endl;

  //      }

//    if(Server=="geodesy.noaa.gov")
//        {
//
//            LLH_station_as_string.append((_coord_stationLLH)[0]);
//            LLH_station_as_string.append((_coord_stationLLH)[1]);
//            LLH_station_as_string.append((_coord_stationLLH)[2]);
//            qDebug()<<"LLH_station_as_string"<<LLH_station_as_string<<endl;

  //      }





    /*-------------------------------------------------------------------------------/
        Generate the configuration file for the RNX2RTKP calculation process
    /------------------------------------------------------------------------------*/

    QString s;
    QString nomDuFichier=path+"Configuration.conf";
    QFile file_(nomDuFichier);

    if(QFileInfo(nomDuFichier).exists())
    {
        qDebug()<<"An old configuration file exist"<<endl;

        QProcess deleting;
        QString deleting_command;

        deleting_command="rm -f "+nomDuFichier;

        deleting.start(deleting_command);
        deleting.waitForFinished(-1);
        if (deleting.state()==0)
        {
           qDebug()<<"The existed configuration file was deleted"<<endl;
        }
    }

    /*-------------------------------------------------------------------------------/
        Generate the configuration file for the RNX2RTKP calculation process:
            - Generate a new blank Cofiguration_file in the work space
    /------------------------------------------------------------------------------*/
    QProcess copying;
    QString copying_command;

    copying_command="cp ../Package/Configuration.conf "+path;

    copying.start(copying_command);
    copying.waitForFinished(-1);
    if (copying.state()==0)
    {
       qDebug()<<"A new blank Configuration_file was created in the work space for the next station !"<<endl;
    }

    /*-------------------------------------------------------------------------------/
        Generate the configuration file for the RNX2RTKP calculation process:
            - Filling the new configuration_file with data:
                - Antenna type
                - Antenna position (calibration)
    /------------------------------------------------------------------------------*/

    if (file_.open(QIODevice::ReadOnly |QIODevice::WriteOnly| QIODevice::Text))
    {
        QTextStream textstream(&file_);
        while (!textstream.atEnd())
        {
           QString line = textstream.readLine();

           if(line.contains("ant2-pos1 "))
           {
               QString linemod1=line.replace(20,LLH_station_as_string[0].length(),LLH_station_as_string[0]);
               s.append(linemod1+"\n");
           }

           if(line.contains("ant2-pos2 "))
           {
               QString linemod2=line.replace(20,LLH_station_as_string[1].length(),LLH_station_as_string[1]);
               s.append(linemod2+"\n");
           }

           if(line.contains("ant2-pos3 "))
           {
               QString linemod3=line.replace(20,LLH_station_as_string[2].length(),LLH_station_as_string[2]);
               s.append(linemod3+"\n");
           }
           if(line.contains("ant2-anttype "))
           {
               QString linemod4=line.replace(20,_antenna_type_station.length(),_antenna_type_station);
               s.append(linemod4+"\n");
           }

           if(line.contains("ant2-antdele "))
           {
               QString linemod5=line.replace(20,_coord_antenna[0].length(),_coord_antenna[0]);
               s.append(linemod5+"\n");
           }

           if(line.contains("ant2-antdeln "))
           {
               QString linemod6=line.replace(20,_coord_antenna[1].length(),_coord_antenna[1]);
               s.append(linemod6+"\n");
           }

           if(line.contains("ant2-antdelu "))
           {
               QString linemod7=line.replace(20,_coord_antenna[2].length(),_coord_antenna[2]);
               s.append(linemod7+"\n");
           }

           if((!line.contains("ant2-pos1 ")&&(!line.contains("ant2-pos2 "))&&(!line.contains("ant2-pos3 "))&&(!line.contains("ant2-anttype "))&&(!line.contains("ant2-antdele "))&&(!line.contains("ant2-antdeln "))&&(!line.contains("ant2-antdelu "))))
               s.append(line+"\n");
        }
        file_.resize(0);
        textstream<<s;
        file_.close();
        qDebug()<<"The configuration file is ready for the rnx2rtkp process !"<<endl;
    }
}


void Rnx2rtkp::rnx2rtkp(int i)
{

    /*-------------------------------------------------------------------------------/
        The rnx2rtkp process:
        INPUT:
            - Observation file                                  ---> rover.obs
            - Observation file of the station                   ---> [sitejjjs.aad]
            - GPS navigation file of the station                ---> [sitejjjs.aan]
            - GLONASS navigation file of the station            ---> [sitejjjs.aag]
            - Configuration file                                ---> Configuration.conf
        OUTPUT:
            - File containing the results of the calculations   ---> i-resultats.pos

        CALCULATION STEPS:
            - Step 1 : verification of all files
            - Step 2 : rnx2rtkp process
            - Step 3 : saving results
    /------------------------------------------------------------------------------*/

    // Open configuration file to read max radius for station and nb of station
 QString Server;


        int ti=1;
        QStringList list;
        QString fileName = "sauvegardeoptionAutoPPbase.txt";
        QFile readoption(fileName);
        readoption.open(QIODevice::ReadOnly | QIODevice::Text);
        //---------verifier ouverture fichier......
        QTextStream flux(&readoption);
        QString ligne;
        while(! flux.atEnd())
        {
           ligne = flux.readLine();
           //traitement de la ligne
           qDebug()<<ligne;
           list<<ligne;
           ti=ti+1;
        }

           Server = (list[12]);

        readoption.close();





    /**Step1**/

    QString obs_station=station_obs_file.replace(station_obs_file.length()-1,1,"o");
    QString nav_GPS_station=station_nav_file;
    QString nav_GLONASS_station=station_g_file;

    if((QFileInfo(path+"rover.obs").exists()) && (QFileInfo(path+obs_station).exists()) && (QFileInfo(path+nav_GPS_station).exists()) && (QFileInfo(path+nav_GLONASS_station).exists()) && (QFileInfo(path+"Configuration.conf").exists()))
    {
        qDebug()<<"The obs file:rover.obs exist"<<endl;
        qDebug()<<"The observation station:"<<obs_station<<" exist"<<endl;
        qDebug()<<"The GPS navigation file:"<< nav_GPS_station<<" exist"<<endl;
        qDebug()<<"The GLONASS navigation file:"<<nav_GLONASS_station<< " exist"<<endl;
        qDebug()<<"The configuration file of station"<<obs_station<<" exist"<<endl;
    }
    else
    {
        qDebug()<<"The process failed: lack of files !!"<<endl;
    }


    /**Step2 & Step 3**/
    QString nomDuFichier=path+QString::number(i)+"-res_"+station_obs_file+".pos";

    QProcess rnx2rtkp;
    rnx2rtkp.setStandardOutputFile(nomDuFichier);                   //The name of output file of the rnx2rtkp process
    QString command;
    if(Server=="rgpdata.ign.fr")
    {
    command="rnx2rtkp -k "+path+"Configuration.conf "+path+"rover.obs "+path+station_obs_file+" "+path+station_nav_file+" "+path+station_g_file;
    }
    if(Server=="geodesy.noaa.gov")
    {
    command="rnx2rtkp -k "+path+"Configuration.conf "+path+"rover.obs "+path+station_obs_file+" "+path+"rover.nav";
    }

    qDebug()<<"The rnx2rtk process:"<<command<<endl;
    rnx2rtkp.start(command);
    rnx2rtkp.waitForFinished(-1);

    if (rnx2rtkp.state()==0)
    {
        results.append("%"+station_obs_file+"\n");

        QFile file__(nomDuFichier);

        if (file__.open(QIODevice::ReadOnly |QIODevice::WriteOnly| QIODevice::Text))
        {
            int nbline=0;
            QTextStream textstream_(&file__);
            while (!textstream_.atEnd())
            {
               QString line_ = textstream_.readLine();
               nbline++;
               if(Server=="rgpdata.ign.fr" && (nbline>23))
               {
                   results.append(line_+"\n");
               }
               if(Server=="geodesy.noaa.gov" && (nbline>22))
               {
                   results.append(line_+"\n");
               }

          }

            file__.close();
            qDebug()<<"The rnx2rtk process finished with success !!"<<endl;

            resultstat.append(results);

        }
    }

}


void Rnx2rtkp::final_results(QString s)
{


    /*---------------------------------------------------------------------------------------------------/
        Aim of final_results() METHOD:
        - Creating the Final OUTPUT file of the rnx2rtkp process   ---> resultats.pos
        - This file contains the results of RNX2RTKP calculations with different stations download
        - Using the median method to calculate the final coordinates of RTK_BAse sation
     /--------------------------------------------------------------------------------------------------*/

    QString nomDuFichier=path+"resultats.pos";
    QFile file_(nomDuFichier);

    if (file_.open(QIODevice::WriteOnly| QIODevice::Text))
    {
        QTextStream textstream(&file_);
        textstream<<s;
        file_.close();
    }


    QVector<QString> x_ecef,y_ecef,z_ecef;
//    QVector<QString> stat;
    int nbline=0;

    if (file_.open(QIODevice::ReadOnly|QIODevice::Text))
    {
       QTextStream textstream_(&file_);
       while (!textstream_.atEnd())
        {
          QString line_ = textstream_.readLine();
          nbline++;


          if(nbline==1)
           {
              stat.append(line_.mid(1,4));
           }


          if(nbline==3)
           {
              x_ecef.append(line_.mid(25,14));
              y_ecef.append(line_.mid(41,14));
              z_ecef.append(line_.mid(55,14));

              stat_x_ecef.append(x_ecef[0]);
              stat_y_ecef.append(y_ecef[0]);
              stat_z_ecef.append(z_ecef[0]);
           }

          if(nbline==4)
           {
              stat.append(line_.mid(1,4));
           }


          if(nbline==6)
           {
               x_ecef.append(line_.mid(25,14));
               y_ecef.append(line_.mid(41,14));
               z_ecef.append(line_.mid(55,14));

               stat_x_ecef.append(x_ecef[1]);
               stat_y_ecef.append(y_ecef[1]);
               stat_z_ecef.append(z_ecef[1]);
           }

          if(nbline==7)
           {
              stat.append(line_.mid(1,4));
           }


           if(nbline==9)
           {
               x_ecef.append(line_.mid(25,14));
               y_ecef.append(line_.mid(41,14));
               z_ecef.append(line_.mid(55,14));

               stat_x_ecef.append(x_ecef[2]);
               stat_y_ecef.append(y_ecef[2]);
               stat_z_ecef.append(z_ecef[2]);
           }

           if(nbline==10)
            {
               stat.append(line_.mid(1,4));
            }


           if(nbline==12)
           {
               x_ecef.append(line_.mid(25,14));
               y_ecef.append(line_.mid(41,14));
               z_ecef.append(line_.mid(55,14));

               stat_x_ecef.append(x_ecef[3]);
               stat_y_ecef.append(y_ecef[3]);
               stat_z_ecef.append(z_ecef[3]);
           }

           if(nbline==13)
            {
               stat.append(line_.mid(1,4));
            }



           if(nbline==15)
           {
               x_ecef.append(line_.mid(25,14));
               y_ecef.append(line_.mid(41,14));
               z_ecef.append(line_.mid(55,14));

               stat_x_ecef.append(x_ecef[4]);
               stat_y_ecef.append(y_ecef[4]);
               stat_z_ecef.append(z_ecef[4]);
           }

           if(nbline==16)
            {
               stat.append(line_.mid(1,4));
            }


           if(nbline==18)
           {
               x_ecef.append(line_.mid(25,14));
               y_ecef.append(line_.mid(41,14));
               z_ecef.append(line_.mid(55,14));

               stat_x_ecef.append(x_ecef[5]);
               stat_y_ecef.append(y_ecef[5]);
               stat_z_ecef.append(z_ecef[5]);
           }


        }
        file_.close();
    }


//    std::sort(x_ecef.begin(), x_ecef.end(), std::greater<QString>());
//    std::sort(y_ecef.begin(), y_ecef.end(), std::greater<QString>());
//    std::sort(z_ecef.begin(), z_ecef.end(), std::greater<QString>());



    extern int Min_station2;
    int Min_station;
    Min_station = Min_station2;





    if (nbline == 3)
    {
        X_Y_Z_ecef_final.append(QString::number((x_ecef[0].toDouble()+x_ecef[0].toDouble())/2, 'f', 4));
        X_Y_Z_ecef_final.append(QString::number((y_ecef[0].toDouble()+y_ecef[0].toDouble())/2, 'f', 4));
        X_Y_Z_ecef_final.append(QString::number((z_ecef[0].toDouble()+z_ecef[0].toDouble())/2, 'f', 4));

        // Create string for solution output

     Sol_x_ECEF = (QString::number((x_ecef[0].toDouble()+x_ecef[0].toDouble())/2, 'f', 4));
     Sol_y_ECEF = (QString::number((y_ecef[0].toDouble()+y_ecef[0].toDouble())/2, 'f', 4));
     Sol_z_ECEF = (QString::number((z_ecef[0].toDouble()+z_ecef[0].toDouble())/2, 'f', 4));




    }



    if (nbline == 6)
{
    X_Y_Z_ecef_final.append(QString::number((x_ecef[0].toDouble()+x_ecef[1].toDouble())/2, 'f', 4));
    X_Y_Z_ecef_final.append(QString::number((y_ecef[0].toDouble()+y_ecef[1].toDouble())/2, 'f', 4));
    X_Y_Z_ecef_final.append(QString::number((z_ecef[0].toDouble()+z_ecef[1].toDouble())/2, 'f', 4));

    // Create string for solution output

 Sol_x_ECEF = (QString::number((x_ecef[0].toDouble()+x_ecef[1].toDouble())/2, 'f', 4));
 Sol_y_ECEF = (QString::number((y_ecef[0].toDouble()+y_ecef[1].toDouble())/2, 'f', 4));
 Sol_z_ECEF = (QString::number((z_ecef[0].toDouble()+z_ecef[1].toDouble())/2, 'f', 4));



}


if(nbline == 9)
{
    X_Y_Z_ecef_final.append(QString::number((x_ecef[0].toDouble()+x_ecef[1].toDouble()+x_ecef[2].toDouble())/3, 'f', 4));
    X_Y_Z_ecef_final.append(QString::number((y_ecef[0].toDouble()+y_ecef[1].toDouble()+y_ecef[2].toDouble())/3, 'f', 4));
    X_Y_Z_ecef_final.append(QString::number((z_ecef[0].toDouble()+z_ecef[1].toDouble()+z_ecef[2].toDouble())/3, 'f', 4));

    // Create string for solution output

 Sol_x_ECEF = (QString::number((x_ecef[0].toDouble()+x_ecef[1].toDouble()+x_ecef[2].toDouble())/3, 'f', 4));
 Sol_y_ECEF = (QString::number((y_ecef[0].toDouble()+y_ecef[1].toDouble()+y_ecef[2].toDouble())/3, 'f', 4));
 Sol_z_ECEF = (QString::number((z_ecef[0].toDouble()+z_ecef[1].toDouble()+z_ecef[2].toDouble())/3, 'f', 4));

}



if(nbline == 12)
{
    X_Y_Z_ecef_final.append(QString::number((x_ecef[0].toDouble()+x_ecef[1].toDouble()+x_ecef[2].toDouble()+x_ecef[3].toDouble())/4, 'f', 4));
    X_Y_Z_ecef_final.append(QString::number((y_ecef[0].toDouble()+y_ecef[1].toDouble()+y_ecef[2].toDouble()+y_ecef[3].toDouble())/4, 'f', 4));
    X_Y_Z_ecef_final.append(QString::number((z_ecef[0].toDouble()+z_ecef[1].toDouble()+z_ecef[2].toDouble()+z_ecef[3].toDouble())/4, 'f', 4));

    // Create string for solution output

 Sol_x_ECEF = (QString::number((x_ecef[0].toDouble()+x_ecef[1].toDouble()+x_ecef[2].toDouble()+x_ecef[3].toDouble())/4, 'f', 4));
 Sol_y_ECEF = (QString::number((y_ecef[0].toDouble()+y_ecef[1].toDouble()+y_ecef[2].toDouble()+y_ecef[3].toDouble())/4, 'f', 4));
 Sol_z_ECEF = (QString::number((z_ecef[0].toDouble()+z_ecef[1].toDouble()+z_ecef[2].toDouble()+z_ecef[3].toDouble())/4, 'f', 4));

}


if(nbline == 15)
{
    X_Y_Z_ecef_final.append(QString::number((x_ecef[0].toDouble()+x_ecef[1].toDouble()+x_ecef[2].toDouble()+x_ecef[3].toDouble()+x_ecef[4].toDouble())/5, 'f', 4));
    X_Y_Z_ecef_final.append(QString::number((y_ecef[0].toDouble()+y_ecef[1].toDouble()+y_ecef[2].toDouble()+y_ecef[3].toDouble()+y_ecef[4].toDouble())/5, 'f', 4));
    X_Y_Z_ecef_final.append(QString::number((z_ecef[0].toDouble()+z_ecef[1].toDouble()+z_ecef[2].toDouble()+z_ecef[3].toDouble()+z_ecef[4].toDouble())/5, 'f', 4));

    // Create string for solution output

 Sol_x_ECEF = (QString::number((x_ecef[0].toDouble()+x_ecef[1].toDouble()+x_ecef[2].toDouble()+x_ecef[3].toDouble()+x_ecef[4].toDouble())/5, 'f', 4));
 Sol_y_ECEF = (QString::number((y_ecef[0].toDouble()+y_ecef[1].toDouble()+y_ecef[2].toDouble()+y_ecef[3].toDouble()+y_ecef[4].toDouble())/5, 'f', 4));
 Sol_z_ECEF = (QString::number((z_ecef[0].toDouble()+z_ecef[1].toDouble()+z_ecef[2].toDouble()+z_ecef[3].toDouble()+z_ecef[4].toDouble())/5, 'f', 4));

}


if(nbline == 18)
{
    X_Y_Z_ecef_final.append(QString::number((x_ecef[0].toDouble()+x_ecef[1].toDouble()+x_ecef[2].toDouble()+x_ecef[3].toDouble()+x_ecef[4].toDouble()+x_ecef[5].toDouble())/6, 'f', 4));
    X_Y_Z_ecef_final.append(QString::number((y_ecef[0].toDouble()+y_ecef[1].toDouble()+y_ecef[2].toDouble()+y_ecef[3].toDouble()+y_ecef[4].toDouble()+y_ecef[5].toDouble())/6, 'f', 4));
    X_Y_Z_ecef_final.append(QString::number((z_ecef[0].toDouble()+z_ecef[1].toDouble()+z_ecef[2].toDouble()+z_ecef[3].toDouble()+z_ecef[4].toDouble()+z_ecef[5].toDouble())/6, 'f', 4));

    // Create string for solution output

 Sol_x_ECEF = (QString::number((x_ecef[0].toDouble()+x_ecef[1].toDouble()+x_ecef[2].toDouble()+x_ecef[3].toDouble()+x_ecef[4].toDouble()+x_ecef[5].toDouble())/6, 'f', 4));
 Sol_y_ECEF = (QString::number((y_ecef[0].toDouble()+y_ecef[1].toDouble()+y_ecef[2].toDouble()+y_ecef[3].toDouble()+y_ecef[4].toDouble()+y_ecef[5].toDouble())/6, 'f', 4));
 Sol_z_ECEF = (QString::number((z_ecef[0].toDouble()+z_ecef[1].toDouble()+z_ecef[2].toDouble()+z_ecef[3].toDouble()+z_ecef[4].toDouble()+z_ecef[5].toDouble())/6, 'f', 4));

}

/*Save Solution position in ECEF. This position will be used in cs2cs*/



std::ofstream E("sauvegarde_results_ECEF.txt");
QFile fichierlastpositionECEF("sauvegarde_results_ECEF.txt*");
fichierlastpositionECEF.open(QIODevice::Append | QIODevice::Text);
QTextStream outE(&fichierlastpositionECEF);

{
    outE<<X_Y_Z_ecef_final[0]<<endl;
    outE<<X_Y_Z_ecef_final[1]<<endl;
    outE<<X_Y_Z_ecef_final[2]<<endl;
}
  fichierlastpositionECEF.close();




    /*-------------------------------------------------------------------------------/
      - Converte ECEF to llh coordinates
    /------------------------------------------------------------------------------*/

  QProcess convert;
  convert.setWorkingDirectory( "/home/francklin/cs2cs_gui" );

  QStringList param;
  param << "+proj=geocent"<<"+datum=WGS84"<<"+to"<<"+proj=latlong"<<"+datum=WGS84"<<"-f"<<"%.12f"<<"test";

  convert.start("cs2cs", param);
  if (convert.waitForStarted())
  {
     convert.waitForFinished();
     QString output;
     output = convert.readAllStandardOutput();


     QString line = output;

     qDebug() << "line:" << line << "\n";
     QStringList list = line.split(QRegExp("\\s"));

     double element;

     for(int i = 0; i < list.size(); i++)
     {
         element = list.at(i).toDouble();
         qDebug() << "element:" << element << "\n";
     }


//ui->Info_textBrowser->setText(QString(output));

//ui->Info_textBrowser->append(QString("LAT: "+list[1]));
//ui->Info_textBrowser->append(QString("LON: "+list[0]));
//ui->Info_textBrowser->append(QString("ALT: "+list[2]));
     QVector<QString> LLH_station_as_string;
     Sol_x_LLH = (QString((list)[1]));
     Sol_y_LLH = (QString((list)[0]));
     Sol_z_LLH = (QString((list)[2]));

  }




  /*------------------------------------------------------------------------------*/

/*  QVector<double> Sol_ecef;
    Sol_ecef.append(Sol_x_ECEF.toDouble());
    Sol_ecef.append(Sol_y_ECEF.toDouble());
    Sol_ecef.append(Sol_z_ECEF.toDouble());

    Coord_coverter c;
    //qDebug()<<c.ecef_to_geo(ecef);  //en rad

    QVector<QString> LLH_station_as_string;
    Sol_x_LLH = (QString::number(qRadiansToDegrees(c.ecef_to_geo(Sol_ecef)[0])));
    Sol_y_LLH = (QString::number(qRadiansToDegrees(c.ecef_to_geo(Sol_ecef)[1])));
    Sol_z_LLH = (QString::number(c.ecef_to_geo(Sol_ecef)[2]));

 */
    //qDebug()<<"LLH_station_as_string"<<LLH_station_as_string<<endl;



    /*Save Solution position. This position will be used in Base Mode*/
   std::ofstream q("sauvegardepourbase.txt");
    QFile fichierlastpositionforbase("sauvegardepourbase.txt");
    fichierlastpositionforbase.open(QIODevice::Append | QIODevice::Text);
    QTextStream out1(&fichierlastpositionforbase);
    //out1<<"essai";
   // if(i>1)
    {
        out1<<Sol_x_LLH<<endl;
        out1<<Sol_y_LLH<<endl;
        out1<<Sol_z_LLH<<endl;
    }
      fichierlastpositionforbase.close();
 qDebug()<<"The result was copied to automatic base position in LLH"<<endl;



// Open configuration file to use for auto base mode
// check if base mode is on and start base mode

    int i=1;
    QStringList list;
    QString fileName = "sauvegardeoptionAutoPPbase.txt";
    QFile readoption(fileName);
    readoption.open(QIODevice::ReadOnly | QIODevice::Text);
    //---------verifier ouverture fichier......
    QTextStream flux(&readoption);
    QString ligne;
    while(! flux.atEnd())
    {
       ligne = flux.readLine();
       //traitement de la ligne
       qDebug()<<ligne;
       list<<ligne;
       i=i+1;
    }

   QString Autostart_Base = (list[7]);

    readoption.close();

    MyDialog cal;

 if (Autostart_Base == "on")        // Check to start againstr2str in base mode with position results
 {


cal.Run_Base_str2str();

// Launch str2str


 }



}


