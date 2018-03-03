#include <QDebug>
#include <QMessageBox>

#include "rnx2rtkp.h"
#include "station.h"
#include <fstream>
#include <QGraphicsTextItem>

#include "mydialog.h"
#include "ui_mydialog.h"

#include "mainwindow.h"
#include "mymessagehandler.h"

#include <QTextStream>
#include <QFile>
#include <iostream>
#include <QTimer>

#include "gpstime.h"
#include "downloader.h"
#include "approxcoord.h"

int closestr2str = 0;
int debugUI = 0;

int d_max3;
int Min_station2;
int PBar = 0;

MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);

    QObject::connect(ui->AutoPostP_pushButton,SIGNAL(clicked()),this,SLOT(Start_AutoPP()));
    QObject::connect(ui->Stop_AutoPP_pushButton,SIGNAL(clicked()),this,SLOT(Close_Window()));
    QObject::connect(ui->Save_options_pushButton,SIGNAL(clicked()),this,SLOT(Save_Options()));
    QObject::connect(ui->teststart_pushButton,SIGNAL(clicked()),this,SLOT(Test_start()));
    QObject::connect(ui->teststop_pushButton,SIGNAL(clicked()),this,SLOT(Test_stop()));




    // Open configuration file to read max radius for station and nb of station
        {
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

              ui->Radius_dmax->setCurrentText(QString(list[0]));
              ui->MinStation->setCurrentText(QString(list[1]));
              ui->CaptureTime->setCurrentText(QString(list[2]));
              ui->WaitingTime->setCurrentText(QString(list[3]));
              ui->InSerialPortcomboBox2->setCurrentText(QString(list[4]));
              ui->InBaudratecomboBox2->setCurrentText(QString(list[5]));
              ui->InFormatcomboBox2->setCurrentText(QString(list[6]));
              ui->Autostartbase_comboBox->setCurrentText(QString(list[7]));
              ui->OutSerialPortcomboBox2->setCurrentText(QString(list[8]));
              ui->OutBaudRatecomboBox2->setCurrentText(QString(list[9]));
              ui->OutFormatcomboBox2->setCurrentText(QString(list[10]));
              ui->RtcmMsgcomboBox2->setCurrentText(QString(list[11]));


              ui->InfoCapture_lineEdit->setText(QString("Log "+list[2]+"mn and wait "+list[3]+"mn before process"));
              ui->InfoProcess_lineEdit->setText(QString(list[1])+" stations in a "+(list[0])+"Km radius will be used");

        readoption.close();

    }



}


MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::on_pushButton_run_rnx2rtk_process_RGP_clicked()
{

ui->textBrowser_2->setText(QString("START PROCESSING SEQUENCE"));


    ui->textBrowser->setText("Please wait ... calculation in progress...");
    qInstallMessageHandler(myMessageHandler);

   // processing();




    // Open configuration file to read max radius for station and nb of station
        {
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

         QString dmax2 = (list[0]);
         d_max3 =  dmax2.toInt();

         QString nb_stat_min = (list[1]);
          Min_station2= nb_stat_min.toInt();

        readoption.close();

    }





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

PBar= 5;
on_progressBar_valueChanged(PBar);

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

PBar= 10;
on_progressBar_valueChanged(PBar);



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

        ui->textBrowser_2->setText(QString("WAIT FOR RGP DATA"));


    int observation_time;
    observation_time=(X0.TIME_OF_LAST_OBS[0]*60+X0.TIME_OF_LAST_OBS[1])-(X0.TIME_OF_FIRST_OBS[0]*60+X0.TIME_OF_FIRST_OBS[1]);
    if(observation_time<30)
    {
        qDebug()<<" Not enough observations "<<observation_time<<"<30 min"<<endl;
ui->textBrowser_2->setText(QString("LOG>30mn: NOT ENOUGH OBSERVATION DATA"));
        return;
    }

//  if((yyyy=t.yyyy)&&(mon=t.mon)&&(dd=t.dd)&&(t.hh<X0.TIME_OF_LAST_OBS[0]+1)&&(X0.TIME_OF_LAST_OBS[1]>observation_time/2))

    if(((yyyy=t.yyyy)&&(mon=t.mon)&&(dd=t.dd)&&(t.hh<X0.TIME_OF_LAST_OBS[0]+1)&&(X0.TIME_OF_LAST_OBS[1])/2>observation_time))
    {


        ui->textBrowser_2->setText(QString("WAIT UNTIL RGP DATA IS AVALAIBLE "));

        qDebug()<<" RGP data are not available until "<<X0.TIME_OF_LAST_OBS[0]+1<<":04"<<endl;


        int a= ((X0.TIME_OF_LAST_OBS[0]+1)*3600+5*60)-(t.hh*3600+t.mm*60);

        qDebug()<<"Wait:"<<a<<" sec"<<a/60<<" min"<<endl;



        sleep.sleep(a);
    }

    if(X0.TIME_OF_LAST_OBS[1]<observation_time/2)
    {
        X0.TIME_OF_LAST_OBS[0]=X0.TIME_OF_LAST_OBS[0]-1;
    }

PBar= 15;
on_progressBar_valueChanged(PBar);

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
ui->textBrowser_2->setText(QString("NO INTERNET CONNEXION: DOWNLOAD FAILED"));
        down.downfailed=false;
        return;
    }


    /*------------------------------------------------------------------------------/
        - Sort of stations
    /------------------------------------------------------------------------------*/

    st.X0=X0.approx__coord;                         //Approx coordinates of the RTK_Base station
    st.nomDuFichier=path+down.url.split("/")[7];
    st.neareststation();                            //Sort of stations process

    qDebug()<<"Number of stations within a radius of: "<<d_max3<<"Km:"<<st.vect_name.size()<<" Stations"<<endl;
    qDebug()<<"The stations are :"<<st.vect_name<<endl;


    int i=0,nbstation=0;                            // i reprents the i th nearest station

    while(nbstation<Min_station2)
    {
        /*------------------------------------------------------------------------------/
            Downloading for each 'Min-station' nearest station the following files:
                - Observation file
                - Navigation GPS file
                - Navigation GLONASS file
        /------------------------------------------------------------------------------*/

        //Downloading of the observation file

ui->textBrowser_2->setText(QString("DOWNLOADING OBS DATA FROM STATION %1").arg(st.vect_name[i]));

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

PBar= PBar+5;
on_progressBar_valueChanged(PBar);



             //Downloading of the navigation file (GPS)

ui->textBrowser_2->setText(QString("DOWNLOADING GPS NAV DATA FROM STATION %1").arg(st.vect_name[i]));

        down.file_name=st.data_file_nearest_sation(doy,yyyy,X0.TIME_OF_FIRST_OBS,X0.TIME_OF_LAST_OBS,i)[3];
        down.url=st.data_file_nearest_sation(doy,yyyy,X0.TIME_OF_FIRST_OBS,X0.TIME_OF_LAST_OBS,i)[5];
        down.do_downloader();
        down.unzip_file();

PBar= PBar+5;
on_progressBar_valueChanged(PBar);

          //Downloading of the navigation file (GLONASS)

ui->textBrowser_2->setText(QString("DOWNLOADING GLONASS NAV DATA FROM STATION %1").arg(st.vect_name[i]));

        down.file_name=st.data_file_nearest_sation(doy,yyyy,X0.TIME_OF_FIRST_OBS,X0.TIME_OF_LAST_OBS,i)[6];
        down.url=st.data_file_nearest_sation(doy,yyyy,X0.TIME_OF_FIRST_OBS,X0.TIME_OF_LAST_OBS,i)[8];
        down.do_downloader();
        down.unzip_file();


PBar= PBar+5;
on_progressBar_valueChanged(PBar);


        /*-------------------------------------------------------------------------------/
            Generate the configuration file for the RNX2RTKP calculation process
        /------------------------------------------------------------------------------*/
ui->textBrowser_2->setText(QString("START PROCESSING DATA"));


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
        if (nbstation<Min_station2)
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



    // Stop processing

    on_progressBar_valueChanged(90);

    QFile file_("../work/Log_file.txt");
    if (!file_.open(QIODevice::ReadOnly))
        QMessageBox::information(0,"info",file_.errorString());

    QTextStream in(&file_);
    ui->textBrowser->setText(in.readAll());
    on_progressBar_valueChanged(100);





    extern QString Sol_x_ECEF;
    QString X_ECEF = QString("ECEF X: ").append(Sol_x_ECEF);
    extern QString Sol_y_ECEF;
     QString Y_ECEF = QString("ECEF Y: ").append(Sol_y_ECEF);
     extern QString Sol_z_ECEF;
    QString Z_ECEF = QString("ECEF Z: ").append(Sol_z_ECEF);


    extern QString Sol_x_LLH;
    QString X_LLH = QString("Lat: ").append(Sol_x_LLH);
    extern QString Sol_y_LLH;
     QString Y_LLH = QString("Lon: ").append(Sol_y_LLH);
     extern QString Sol_z_LLH;
    QString Z_LLH = QString("Alt: ").append(Sol_z_LLH);



   ui->ECEF_x_lineEdit->setText(X_ECEF);
   ui->ECEF_y_lineEdit->setText(Y_ECEF);
   ui->ECEF_z_lineEdit->setText(Z_ECEF);

   ui->LLH_Lat_lineEdit->setText(X_LLH);
   ui->LLH_Lon_lineEdit->setText(Y_LLH);
   ui->LLH_Alt_lineEdit->setText(Z_LLH);

ui->textBrowser_2->setText(QString("PROCESSING DONE POSITION COPIED TO FILE AND BASE MODE"));

}

void MyDialog::on_progressBar_valueChanged(int value)
{
    ui->progressBar->setValue(value);
}



void MyDialog::Save_Options()
{

  /*Save options for auto post processing The options will be used in Automatic post processing Mode*/

     QString RadiusMaxStation = ui->Radius_dmax->currentText();
     QString MinStat = ui->MinStation->currentText();
     QString Capture_Time = ui->CaptureTime->currentText();
     QString Wait_Time = ui->WaitingTime->currentText();
     QString InputPort = ui->InSerialPortcomboBox2->currentText();
     QString InputBaud = ui->InBaudratecomboBox2->currentText();
     QString InFormat = ui->InFormatcomboBox2->currentText();
     QString Autostartbase =ui->Autostartbase_comboBox->currentText();
     QString Outport =ui->OutSerialPortcomboBox2->currentText();
     QString OutBaud =ui->OutBaudRatecomboBox2->currentText();
     QString OutFormat =ui->OutFormatcomboBox2->currentText();
     QString RTCMmsg =ui->RtcmMsgcomboBox2->currentText();


     std::ofstream q("sauvegardeoptionAutoPPbase.txt");
       QFile optionAutoPPbase("sauvegardeoptionAutoPPbase.txt");
       optionAutoPPbase.open(QIODevice::Append | QIODevice::Text);
       QTextStream out1(&optionAutoPPbase);
    {
       out1<<RadiusMaxStation<<endl;
       out1<<MinStat<<endl;
       out1<<Capture_Time<<endl;
       out1<<Wait_Time<<endl;
       out1<<InputPort<<endl;
       out1<<InputBaud<<endl;
       out1<<InFormat<<endl;
       out1<<Autostartbase<<endl;
       out1<<Outport<<endl;
       out1<<OutBaud<<endl;
       out1<<OutFormat<<endl;
       out1<<RTCMmsg<<endl;


       ui->InfoProcess_lineEdit->setText(QString(MinStat)+" stations in a "+(RadiusMaxStation)+"Km radius will be used");
       ui->InfoCapture_lineEdit->setText(QString("Log "+Capture_Time+"mn and wait "+Wait_Time+"mn before process"));

       }



    optionAutoPPbase.close();

}


 void MyDialog::Start_AutoPP()
 {

     ui->textBrowser_2->setText(QString("START LOGGING RAW DATA FROM GNSS"));

Run_Log_str2str();


}




 void MyDialog::Run_Log_str2str()
 {


     // Open configuration file to use for auto processing

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


          QString Capttime = (list[2]);
          int Capttime2 = Capttime.toInt();
          int CaptureTimer = Capttime2*60000;

          QString Waittime = (list[3]);
          int Waittime2 = Waittime.toInt();
          int WaitTimer = Waittime2*60000;

        QString InputPort2 = (list[4]);
        QString InputBaud2 = (list[5]);
        QString InputFormat2 = (list[6]);


         readoption.close();




     string InSerialPortstr = InputPort2.toStdString();
     string Inbaudstr= InputBaud2.toStdString();
     string InFormatstr = InputFormat2.toStdString();
     string OutFilePathstr = "../RTKBASE/PointsFiles/rover.ubx";


   // Launch str2str


                              arga={"carlepremierargesttoujorsleprog","-in","serial://ttyACM0:115200:8:n:1:#ubx","-out","../RTKBASE/PointsFiles/rover.ubx"};

    std::vector<std::string> args1={"carlepremierargesttoujorsleprog","-in",InSerialPortstr+":"+Inbaudstr+":8:n:1:#"+InFormatstr,"-out",OutFilePathstr};

    args=args1;

 /*Str2str.c opening options*/
 int sizeArgs=args.size();
 QVector<QString> qstr(sizeArgs);

  for (int i=0; i<sizeArgs;i++)
 {
     qstr[i] = QString::fromStdString(args[i]);
 }

 ui->Capture_textBrowser->setText(QString("CURRENT STR2STR OPTIONS"));

 for (int i=1; i<sizeArgs;i++)
 {
     ui->Capture_textBrowser->append(qstr[i]);
 }

   m_tstr2str->setArgcArgvStr2str(args);
   m_tstr2str->start();
   m_readfile->start();

   QObject::connect(m_readfile,SIGNAL(emitdonneesStr2str(QStringList)),this,SLOT(recupdonneesStr2str(QStringList))); //ok
   QObject::connect(this,SIGNAL(closeSignal(int)),m_tstr2str,SLOT(close(int)));
   QObject::connect(m_tstr2str,SIGNAL(etatFermetureThreadStr2str(bool)),this,SLOT(finThread(bool)));

ui->textBrowser_2->setText(QString("RECORDING RAW DATA LOG FROM GNSS"));



  QTimer::singleShot(CaptureTimer, this, SLOT(FermeStr2str()));        // Close str2str and logging

//   ui->Capture_textBrowser->setText(QString("RAW DATA LOGGED WAITING FOR POST PROCESSING"));

   QTimer::singleShot(CaptureTimer+WaitTimer, this, SLOT(on_pushButton_run_rnx2rtk_process_RGP_clicked())); // Wait and start post processing



 }




 void MyDialog::Run_Base_str2str()
 {

ui->textBrowser_2->setText(QString("BASE MODE STARTED"));


     // Open configuration file to use for auto processing

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




        QString InputPort2 = (list[4]);
        QString InputBaud2 = (list[5]);
        QString InputFormat2 = (list[6]);
        QString OutPort2 = (list[8]);
        QString OutBaud2 = (list[9]);
        QString OutFormat2 = (list[10]);
        QString RTCMmsg2 = (list[11]);

         readoption.close();


        // Launch str2str

     string InSerialPortstr = InputPort2.toStdString();
     string Inbaudstr= InputBaud2.toStdString();
     string InFormatstr = InputFormat2.toStdString();
     string OutFilePathstr = "../RTKBASE/PointsFiles/rover.ubx";

     string OutSerialPortstr = OutPort2.toStdString();
     string Outbaudstr = OutBaud2.toStdString();
     string OutFormatstr = OutFormat2.toStdString();
     string RtcmMsgstr = RTCMmsg2.toStdString();
     string latstr = Sol_x_LLH.toStdString();
     string lonstr = Sol_y_LLH.toStdString();
     string hstr = Sol_z_LLH.toStdString();


                         arga={"carlepremierargesttoujorsleprog","-in","serial://ttyACM0:115200:8:n:1:#ubx","-out","serial://ttyUSB0:38400:8:n:1:#rtcm3","-p","48.2","2.2","120.23","-msg","1004,1019,1012,1020,1006,1008"};
std::vector<std::string> args1={"carlepremierargesttoujorsleprog","-in",InSerialPortstr+":"+Inbaudstr+":8:n:1:#"+InFormatstr,"-out",OutSerialPortstr+":"+Outbaudstr+":8:n:1:#"+OutFormatstr,"-msg",RtcmMsgstr,"-p",latstr,lonstr,hstr};


    args=args1;

 /*Str2str.c opening options*/
 int sizeArgs=args.size();
 QVector<QString> qstr(sizeArgs);

  for (int i=0; i<sizeArgs;i++)
 {
     qstr[i] = QString::fromStdString(args[i]);
 }

ui->Capture_textBrowser->setText(QString("CURRENT STR2STR OPTIONS"));

 for (int i=1; i<sizeArgs;i++)
 {
     ui->Capture_textBrowser->append(qstr[i]);
 }

   m_tstr2str->setArgcArgvStr2str(args);
   m_tstr2str->start();
   m_readfile->start();



ui->textBrowser_2->setText(QString("RECORDING RAW DATA LOG FROM GNSS"));

QObject::connect(m_readfile,SIGNAL(emitdonneesStr2str(QStringList)),this,SLOT(recupdonneesStr2str(QStringList))); //ok
QObject::connect(this,SIGNAL(closeSignal(int)),m_tstr2str,SLOT(close(int)));
QObject::connect(m_tstr2str,SIGNAL(etatFermetureThreadStr2str(bool)),this,SLOT(finThread(bool)));


     // Close str2str and logging





 }





 void MyDialog::FermeStr2str()
 {
     emit closeSignal(1);
     ui->textBrowser_2->setText(QString("CLOSING STR2STR LOG IN PROGRESS"));

 }


 void MyDialog::finThread(bool a)
 {
     if (a==true)
     {
         m_readfile->terminate();
         m_tstr2str->terminate();

     }
 }

 void MyDialog::recupdonneesStr2str(QStringList i)
 {

     {

ui->Capture_textBrowser->setText(QString("RECORDING RAW DATA FROM GNSS"));

}

     {
     ui->Capture_textBrowser->setText((i[0]));
     }

}


 void MyDialog::Close_Window()
 {
     emit closeSignal(1);
     ui->textBrowser_2->setText(QString("CLOSING IN PROGRESS"));
     m_readfile->terminate();
     m_tstr2str->terminate();
     this->close();

 }


void MyDialog::Test_start()
{

    // Open configuration file to use for auto processing

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



       QString InputPort2 = (list[4]);
       QString InputBaud2 = (list[5]);
       QString InputFormat2 = (list[6]);
       QString Autostart_Base = (list[7]);
       QString OutPort2 = (list[8]);
       QString OutBaud2 = (list[9]);
       QString OutFormat2 = (list[10]);
       QString RTCMmsg2 = (list[11]);







        readoption.close();





    string InSerialPortstr = InputPort2.toStdString();
    string Inbaudstr= InputBaud2.toStdString();
    string InFormatstr = InputFormat2.toStdString();
    string OutSerialPortstr = OutPort2.toStdString();
    string Outbaudstr = OutBaud2.toStdString();
    string OutFormatstr = OutFormat2.toStdString();
    string RtcmMsgstr = RTCMmsg2.toStdString();
 //   string latstr = Sol_x_LLH.toStdString();
 //   string lonstr = Sol_y_LLH.toStdString();
 //   string hstr = Sol_z_LLH.toStdString();


    string latstr = "48.888";
    string lonstr = "2.222";
    string hstr = "155.111";



    // Launch str2str

                             arga={"carlepremierargesttoujorsleprog","-in","serial://ttyACM0:115200:8:n:1:#ubx","-out","serial://ttyUSB0:38400:8:n:1:#rtcm3","-p","48.2","2.2","120.23","-msg","1004,1019,1012,1020,1006,1008"};
   std::vector<std::string> args1={"carlepremierargesttoujorsleprog","-in",InSerialPortstr+":"+Inbaudstr+":8:n:1:#"+InFormatstr,"-out",OutSerialPortstr+":"+Outbaudstr+":8:n:1:#"+OutFormatstr,"-msg",RtcmMsgstr,"-p",latstr,lonstr,hstr};


args=args1;

// }

/*Str2str.c opening options*/
int sizeArgs=args.size();
QVector<QString> qstr(sizeArgs);

for (int i=0; i<sizeArgs;i++)
{
 qstr[i] = QString::fromStdString(args[i]);
}

ui->Capture_textBrowser->setText(QString("CURRENT STR2STR OPTIONS"));

for (int i=1; i<sizeArgs;i++)
{
 ui->Capture_textBrowser->append(qstr[i]);
}


m_tstr2str->setArgcArgvStr2str(args);
m_tstr2str->start();
m_readfile->start();

QObject::connect(m_readfile,SIGNAL(emitdonneesStr2str(QStringList)),this,SLOT(recupdonneesStr2str(QStringList))); //ok
QObject::connect(this,SIGNAL(closeSignal(int)),m_tstr2str,SLOT(close(int)));
QObject::connect(m_tstr2str,SIGNAL(etatFermetureThreadStr2str(bool)),this,SLOT(finThread(bool)));







}

void MyDialog::Test_stop()
{
    emit closeSignal(1);
    ui->textBrowser_2->setText(QString("CLOSING IN PROGRESS"));
   closestr2str=1;

}
