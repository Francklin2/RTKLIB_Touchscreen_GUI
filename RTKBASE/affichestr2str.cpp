#include "affichestr2str.h"
#include "ui_affichestr2str.h"
#include <QGraphicsTextItem>
#include "optionsstr2str.h"




AfficheStr2str::AfficheStr2str(std::vector<string> arga, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AfficheStr2str)


{

 //      args=arga;


    ui->setupUi(this);
    /*Displays in FullScreen*/
    this->setWindowFlags(Qt::Window);
    this->showFullScreen();


    /*pick up Base Position from last recorded in rover mode*/

  //  PositionMode=2;

     QString filenamebase;

{

  if (PositionMode==1) {filenamebase = "sauvegardepourbase.txt";}
  if (PositionMode==2){filenamebase = "sauvegardepourbaseManual.txt";}

}


    int i=0;
    QStringList list;
    QFile fichierlastpositionforbase(filenamebase);
    fichierlastpositionforbase.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&fichierlastpositionforbase);
    QString ligne;
    while(! flux.atEnd())
    {
        ligne = flux.readLine();
        list<<ligne;
        i=i+1;
    }
    fichierlastpositionforbase.close();



    /*move QString in double base position*/
    bool ok;
    m_str1=list[0];
    m_str2=list[1];
    m_str3=list[2];
//    m_str1.replace(",",".");
//    m_str2.replace(",",".");
//    m_str3.replace(",",".");
    double lat =(m_str1.toDouble(&ok));
    double lon =(m_str2.toDouble(&ok));
    double h =(m_str3.toDouble(&ok));
    string latstr=m_str1.toStdString() ;
    string lonstr=m_str2.toStdString();
    string hstr=m_str3.toStdString() ;




    string Outbaudstr=Outbaudext.toStdString() ;
    string OutSerialPortstr=OutSerialPortext.toStdString() ;
    string OutFormatstr=OutFormatext.toStdString() ;
    string OutFilePathstr=OutFilePathtext.toStdString() ;
    string Inbaudstr=Inbaudext.toStdString() ;
    string InSerialPortstr=InSerialPortext.toStdString() ;
    string InFormatstr=InFormatext.toStdString() ;
    string RtcmMsgstr=RtcmMsgext.toStdString() ;

    if (OutSerialPortstr =="File")
    {
        std::vector<std::string> args1={"carlepremierargesttoujorsleprog","-in",InSerialPortstr+":"+Inbaudstr+":8:n:1:#"+InFormatstr,"-out",OutFilePathstr};
  args=args1;
    }
  else
    {
    std::vector<std::string> args1={"carlepremierargesttoujorsleprog","-in",InSerialPortstr+":"+Inbaudstr+":8:n:1:#"+InFormatstr,"-out",OutSerialPortstr+":"+Outbaudstr+":8:n:1:#"+OutFormatstr,"-msg",RtcmMsgstr,"-p",latstr,lonstr,hstr};
  args=args1;
    }

    /*Str2str.c opening options*/
    int sizeArgs=args.size();
    QVector<QString> qstr(sizeArgs);
    for (int i=0; i<sizeArgs;i++)
    {
        qstr[i] = QString::fromStdString(args[i]);
    }
    ui->textBrowser->setText(QString("CURRENT STR2STR OPTIONS"));
    for (int i=1; i<sizeArgs;i++)
    {
        ui->textBrowser->append(qstr[i]);
    }

    /* SEMBLE FONCTIONNER avec -out et un émetteur
     * std::vector<std::string> args={"carlepremierargtoujorsleprog","-in","serial://ttyACM0:115200:8:n:1:#ubx","-out","serial://ttyUSB0:57600:8:n:1:#RTCM3","-msg","1004,1019,1012,1020,1006,1008"};
     */

    /* SEMBLE FONCTIONNER AVEC COMMANDE INCLUANT LES -p coordonnées transformées en string
     * std::vector<std::string> args={"carlepremierargtoujorsleprog","-in","serial://ttyACM0:115200:8:n:1:#ubx","-p",latstr,lonstr,hstr,"-msg","1004,1019,1012,1020,1006,1008"};
     */

    /* exemple ligne de commande:
    * /home/reach/RTKLIB/app/str2str/gcc/str2str -in serial://ttyMFD1:230400:8:n:1:off#ubx -out tcpsvr://:9000#rtcm3 -msg 1002,1006,1013,1019 -p 60 30 50 -c /home/reach/RTKLIB/app/rtkrcv/reach_raw.cmd
    */

    /*tomojitakasu/RTKLIB » str2str conversion problem with Neo-M8T
     * https://www.bountysource.com/issues/27823895-str2str-conversion-problem-with-neo-m8t
     */


   m_tstr2str->setArgcArgvStr2str(args);
    m_tstr2str->start();

    m_readfile->start();

    QObject::connect(m_readfile,SIGNAL(emitdonneesStr2str(QStringList)),this,SLOT(recupdonneesStr2str(QStringList))); //ok
    QObject::connect(ui->FermeStr2strpushButton,SIGNAL(clicked()),this,SLOT(FermeStr2str()));
    QObject::connect(this,SIGNAL(closeSignal(int)),m_tstr2str,SLOT(close(int)));
    QObject::connect(m_tstr2str,SIGNAL(etatFermetureThreadStr2str(bool)),this,SLOT(finThread(bool)));
}



AfficheStr2str::~AfficheStr2str()
{
    delete ui;
}


void AfficheStr2str::recupdonneesStr2str(QStringList i)
{

    {
         if (PositionMode==1) { ui->Msg1lineEdit->setText(QString("AUTOMATIC BASE POSITION picked up from last rover mode"));}
         if (PositionMode==2) { ui->Msg1lineEdit->setText(QString("MANUAL BASE POSITION entered by user"));}
         if (OutSerialPortext =="File") { ui->Msg1lineEdit->setText(QString("RECORDING RAW DATA FROM GNSS"));}

    }

     if ((PositionMode==1) or (PositionMode==2))
     {
    ui->Msg2lineEdit->setText(QString("LAT = %1 deg   LONG = %2 deg   ALTI= %3 m").arg(m_str1).arg(m_str2).arg(m_str3));
    ui->Msg3lineEdit->setText((i[0]));
     }
     if (OutSerialPortext =="File")
     {
     ui->Msg2lineEdit->setText(QString("WRITTING FILE TO ").append(OutFilePathtext));
     }
}

void AfficheStr2str::FermeStr2str()
{
    emit closeSignal(1);
    ui->Msg4lineEdit->setText(QString("CLOSING IN PROGRESS"));

}


void AfficheStr2str::finThread(bool a)
{
    if (a==true)
    {
        m_readfile->terminate();
        m_tstr2str->terminate();
        this->close();
    }
}

