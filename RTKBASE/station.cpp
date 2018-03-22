#include "station.h"

Station::Station()
{

}

QString Station::Corrdstation_ftp(int doy, int yyyy)
{

    /*------------------------------------------------------------------------------/
        - Generate the link of the station coordinates:
         file  path_ofdownload+yyyy_s+"/"+doy_s+"/"+"coorrgf93_"+yyyy_s+"-"+doy_s+".txt"

        INPUT:
            - doy   :   day of year
            - yyyy  :   the year
        OUTPUT:
            - corrdstation_ftp

    /------------------------------------------------------------------------------*/


    QString ftp="ftp://rgpdata.ign.fr/pub/data/";
    QString doy_s =QString::number(doy-1);

    if (doy==1)
    {
        doy=365;
        yyyy=yyyy-1;
        doy_s =QString::number(doy);
    }

    QString yyyy_s =QString::number(yyyy);

    if(doy_s.size()==1)
        doy_s.prepend("00");

    if(doy_s.size()==2)
         doy_s.prepend("0");

    corrdstation_ftp=ftp+yyyy_s+"/"+doy_s+"/"+"coorrgf93_"+yyyy_s+"-"+doy_s+".txt";

    return corrdstation_ftp;
}



void Station::neareststation()
{
    /*------------------------------------------------------------------------------/
        - The aim of this METHOD:
                - Read the coordinates file station
                - Euclidean distance calculation
                - Sort stations by distance

            INPUT:
                - coordinates file station
            OUTPUT:
                - List of the nearest station to RTK_BASE_Station
                - vect_dist
                - vect_name
                - vect_domes

    /------------------------------------------------------------------------------*/

    QFile file(nomDuFichier);
    int nbline=0;
    int i=0;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug()<<"there is no file ";
            return ;
        }

    QTextStream in(&file);
     while (!in.atEnd())
     {
        QString line = in.readLine();
        nbline++;
        if(nbline>18)
        {
            vect_name<<line.mid(1,4);
            vect_domes<<line.mid(6,10);
            vect_X<<line.mid(15,13).toDouble();
            vect_Y<<line.mid(29,13).toDouble();
            vect_Z<<line.mid(41,13).toDouble();
            /*------------------------------------------------------------------------------/
               - calculating the distance to X0: Euclidean distance
            /------------------------------------------------------------------------------*/

            vect_dist<<qSqrt(qPow(vect_X[i]-X0[0],2)+qPow(vect_Y[i]-X0[1],2)
                    +qPow(vect_Z[i]-X0[2],2));
            i++;
        }
    }



     /*--------------------------------------------------------------------------------------/
         This step consists of deleting stations that have a distance greater than dmax
     /-------------------------------------------------------------------------------------*/
    i=0;
    while(i<vect_dist.size())
     {
        if(vect_dist[i]>=d_max)
         {
             vect_dist.remove(i);
             vect_name.remove(i);
             vect_domes.remove(i);
             vect_X.remove(i);
             vect_Y.remove(i);
             vect_Z.remove(i);
         }
        else{i++;}
    }

    // qDebug()<<vect_dist;                 //uncomment this code line to disply distance within RTK_Base_Station


    /*------------------------------------------------------------------------------/
      - Sort ascending a 1-dimensional array by the bubble sort method
    /------------------------------------------------------------------------------*/

    float aux_dist;
    QString aux_name,aux_domes;
    bool permut;

    do{
        permut=false;
        for(i=0;i<vect_dist.size()-1;i++)
        {
            if(vect_dist[i]>vect_dist[i+1])
            {
                aux_dist=vect_dist[i];
                aux_name=vect_name[i];
                aux_domes=vect_domes[i];
                vect_dist[i]=vect_dist[i+1];
                vect_name[i]=vect_name[i+1];
                vect_domes[i]=vect_domes[i+1];
                vect_dist[i+1]=aux_dist;
                vect_name[i+1]=aux_name;
                vect_domes[i+1]=aux_domes;
                permut=true;
            }
        }
    }while (permut==true);

}



QVector<QString> Station::data_file_nearest_sation(int doy,int yyyy,QVector<int>TIME_OF_FIRST_OBS,QVector<int>TIME_OF_LAST_OBS,int i)
{


    QString ftp="ftp://rgpdata.ign.fr/pub/data/";
    QString yyyy_s =QString::number(yyyy);
    QString doy_s =QString::number(doy);

    if(doy_s.size()==1)
        doy_s.prepend("00");

    if(doy_s.size()==2)
         doy_s.prepend("0");

    int hh=TIME_OF_LAST_OBS[0];
    int mm=TIME_OF_LAST_OBS[1];


    QString epoque;
    if(hh==2 && mm>4)
        epoque="b";
    if(hh==3 && mm>4)
        epoque="c";
    if(hh==4 && mm>4)
        epoque="d";
    if(hh==5 && mm>4)
        epoque="e";
    if(hh==6 && mm>4)
        epoque="f";
    if(hh==7 && mm>4)
        epoque="g";
    if(hh==8 && mm>4)
        epoque="h";
    if(hh==9 && mm>4)
        epoque="i";
    if(hh==10 && mm>4)
        epoque="j";
    if(hh==11 && mm>4)
        epoque="k";
    if(hh==12 && mm>4)
        epoque="l";
    if(hh==13 && mm>4)
        epoque="m";
    if(hh==14 && mm>4)
        epoque="n";
    if(hh==15 && mm>4)
        epoque="o";
    if(hh==16 && mm>4)
        epoque="p";
    if(hh==17 && mm>4)
        epoque="q";
    if(hh==18 && mm>4)
        epoque="r";
    if(hh==19 && mm>4)
        epoque="s";
    if(hh==20 && mm>4)
        epoque="t";
    if(hh==21 && mm>4)
        epoque="u";
    if(hh==22 && mm>4)
        epoque="v";
    if(hh==23 && mm>4)
    {
        doy_s =QString::number(doy-1);
        epoque="w";
    }
    if(hh==00 && mm>4)
    {
        epoque="x";
        doy_s =QString::number(doy-1);
    }
    if(hh==01 && mm>4)
        epoque="a";

    QVector<QString> V;
    QString stationname=vect_name[i].toLower();

    //Observation file of the station
    QString d_file_z=stationname+doy_s+epoque+"."+yyyy_s.mid(2,2)+"d.Z";
    QString d_file=stationname+doy_s+epoque+"."+yyyy_s.mid(2,2)+"d";
    QString ftp_d_file=ftp+yyyy_s+"/"+doy_s+"/"+"data_30/"+d_file_z;

    V.append(d_file_z);     // Name of the file to download compressed
    V.append(d_file);       // Name of the file
    V.append(ftp_d_file);   // FTP lik


    //GPS Navigation file of the station
    QString n_file_z=stationname+doy_s+epoque+"."+yyyy_s.mid(2,2)+"n.Z";
    QString n_file=stationname+doy_s+epoque+"."+yyyy_s.mid(2,2)+"n";
    QString ftp_n_file=ftp+yyyy_s+"/"+doy_s+"/"+"data_30/"+n_file_z;

    V.append(n_file_z);
    V.append(n_file);
    V.append(ftp_n_file);

    //GLONSS Navigation file of the station
    QString g_file_z=stationname+doy_s+epoque+"."+yyyy_s.mid(2,2)+"g.Z";
    QString g_file=stationname+doy_s+epoque+"."+yyyy_s.mid(2,2)+"g";
    QString ftp_g_file=ftp+yyyy_s+"/"+doy_s+"/"+"data_30/"+g_file_z;
    V.append(g_file_z);
    V.append(g_file);
    V.append(ftp_g_file);

    return V;
}


void Station::station_data(QString station_obs_file,QString path )
{
    /*------------------------------------------------------------------------------/
        - The aim of this METHOD:
                - Read the observation file of the station
                - recover the data that characterizes the statione

            INPUT:
                - Observation file of the station       [sitejjjs.aad]
            OUTPUT:
                - _antenna_type_station
                - _coord_antenna
                -  _coord_station
    /------------------------------------------------------------------------------*/

    _antenna_type_station.clear();
    _coord_antenna.clear();
    _coord_station.clear();


    QString nomDuFichier=path+station_obs_file;
    QFile file(nomDuFichier);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"There is no observation file "<<endl;
        return ;
     }
    QTextStream in(&file);
    while (!in.atEnd())
    {
       QString line = in.readLine();

       if(line.contains("ANT # / TYPE"))
       {
           //qDebug()<<"line ANT # / TYPE:"<<line<<endl;
          _antenna_type_station.append(line.split("     ")[2]);
       }

       if(line.contains("APPROX POSITION XYZ"))
       {
           //qDebug()<<"line:APPROX POSITION XYZ"<<line<<endl;
           _coord_station.append(line.split("  ")[1]);
           _coord_station.append(line.split("  ")[2]);
           _coord_station.append(line.split("  ")[3]);
       }
       if(line.contains("ANTENNA: DELTA H/E/N"))
       {
           //qDebug()<<"line ANTENNA: DELTA H/E/N:"<<line<<endl;
           _coord_antenna.append(line.split("        ")[1]);
           _coord_antenna.append(line.split("        ")[2]);
           _coord_antenna.append(line.split("        ")[3]);
       }
   }

}





