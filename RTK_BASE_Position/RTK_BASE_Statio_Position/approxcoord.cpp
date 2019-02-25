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

    if(QFileInfo("../PointsFiles/rover.ubx").exists())
    {
        qDebug()<<"----- The ubx file exist -----";
        verif_file=true;

        QProcess conversion_;

                //Conversion using convbin ------

        QString command= "convbin ../PointsFiles/rover.ubx -r ubx -o "+path+"rover.obs -n "+path+"rover.nav";
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



