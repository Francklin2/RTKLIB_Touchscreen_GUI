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


#include "approxcoord.h"

Approxcoord::Approxcoord()
{

}

void Approxcoord::conversion()
{    
    /*-------------------------------------------------------------------/
         Aim of the METHOD:
            - Verify the observation file (.ubx) in the PointsFiles directory
            - Convert the observation file (rover.ubx) to rinex file (rover.obs)
            - Save the converted file (rover.obs) in work directory

           PS: Tow different METHOD of conversion are availbale:
                    - Using CONVBIN
                    - Using teqc (standard)
                    - Using teqc (advanced)
                    - the unused METHOD is in comment brakets
    /-------------------------------------------------------------------*/

    if(QFileInfo("../RTKBASE/PointsFiles/rover.ubx").exists())
    {
        qDebug()<<"----- The ubx file exist -----";
        verif_file=true;

        QProcess conversion_;

                //Conversion using convbin ------

        QString command= "convbin ../RTKBASE/PointsFiles/rover.ubx -r ubx -o "+path+"rover.obs -n "+path+"rover.nav";
        qDebug()<<"\n"<<command;

            // Methd2 :Conversion using teqc (standard)
        //QString command_teqc_standard=path+"./teqc "+path+"rover.ubx > "+path+"rover.obs";
        //QString command_teqc_advanced=path+"./teqc -O.obs L1L2C1C2P1P2S1S2L5C5S5 "+path+"rover.ubx > "+path+"rover.obs";

        conversion_.start(command);
        conversion_.waitForFinished(-1);
        if (conversion_.state()==0)
        {
            QString nomDuFichier=path+"rover.obs";
            QFile file(nomDuFichier);
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                qDebug()<<"\n-------- The conversion process from ubx to .obs Failed!! -------- \n";
                verif_file=false;
                return ;
             }
            else
            {
                qDebug()<<"\n-----The conversion process from ubx to .obs finished with success ----- \n";
                verif_file=true;

            }

        }
        else
        {
            qDebug()<<"\n-----The conversion process from ubx to .obs Failed!! ----- \n";
            verif_file=false;
            return;
        }
    }
    else
    {
            qDebug()<<"\n-------- The ubx file doesn't exist in:PointsFiles -------- \n";
            verif_file=false;
            return;
    }

}


void Approxcoord::approx_coord()
{
    /*-------------------------------------------------------------------/
         Aim of the METHOD:
            - Verify the observation file (.obs) exist
            - Read the .obs file
            - Search and find:
                    - The approximate position
                    - The start date of observation
                    - The end of observation
    /-------------------------------------------------------------------*/

    QString nomDuFichier=path+"rover.obs";
    QFile file(nomDuFichier);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"\n-------- There is no .obs file -------- \n";
        verif_file=false;
        return ;
     }

    QTextStream in(&file);

    while (!in.atEnd())
    {
       QString line = in.readLine();

       if(line.contains("TIME OF FIRST OBS"))
       {
           //qDebug()<<"line"<<line;
           TIME_OF_FIRST_OBS.append(line.mid(22,2).toInt());
           TIME_OF_FIRST_OBS.append(line.mid(28,2).toInt());

           DATE_OF_OBS.append(line.mid(16,2).toInt());
           DATE_OF_OBS.append(line.mid(10,2).toInt());
           DATE_OF_OBS.append(line.mid(2,4).toInt());
       }
       if(line.contains("TIME OF LAST OBS"))
       {
           //qDebug()<<"line"<<line;
           TIME_OF_LAST_OBS.append(line.mid(22,2).toInt());
           TIME_OF_LAST_OBS.append(line.mid(28,2).toInt());
       }
       if(line.contains("APPROX POSITION XYZ"))
       {
           //qDebug()<<"line"<<line;
           approx__coord.append(line.split("  ")[1].toDouble());
           approx__coord.append(line.split("  ")[2].toDouble());
           approx__coord.append(line.split("  ")[3].toDouble());
       }
   }

 }



