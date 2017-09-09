#include "editeconfig.h"
#include "ui_editeconfig.h"
#include "choixedite.h"
#include <QFile>
#include <iostream>
#include <QTextStream>
#include <QInputDialog>
#include <QFileDialog>

EditeConfig::EditeConfig(QString _modeleFile, QString _configFile, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditeConfig)
{
    ui->setupUi(this);

    modeleFile=_modeleFile;
    configFile=_configFile;

    this->setWindowFlags(Qt::Window);
    this->showFullScreen();

    QObject::connect(ui->SaveButton,SIGNAL(clicked()),this,SLOT(Save()));
    QObject::connect(ui->ReturnButton,SIGNAL(clicked()),this,SLOT(Retour()));

    QObject::connect(ui->PosmodeBox,SIGNAL(currentIndexChanged(int)),this,SLOT(ChangePosMode(int)));
    QObject::connect(ui->SolformatBox,SIGNAL(currentIndexChanged(int)),this,SLOT(ChangeSolFormat(int)));
    QObject::connect(ui->Inpstrtype2Box,SIGNAL(currentIndexChanged(int)),this,SLOT(ChangeInpstrtype2(int)));
    QObject::connect(ui->Inpstrtype3Box,SIGNAL(currentIndexChanged(int)),this,SLOT(ChangeInpstrtype3(int)));
    QObject::connect(ui->Outstr1typeBox,SIGNAL(currentIndexChanged(int)),this,SLOT(ChangeOutstr1type(int)));
    QObject::connect(ui->Logstr1typeBox,SIGNAL(currentIndexChanged(int)),this,SLOT(ChangeLogstr1type(int)));


    QObject::connect(ui->SatantfileButton,SIGNAL(clicked()),this,SLOT(ChoixSatantfile()));
    QObject::connect(ui->RcvantfileButton,SIGNAL(clicked()),this,SLOT(ChoixRcvantfile()));
    QObject::connect(ui->GeoidfileButton,SIGNAL(clicked()),this,SLOT(ChoixGeoidfile()));
    QObject::connect(ui->DcbfileButton,SIGNAL(clicked()),this,SLOT(ChoixDCBfile()));
    QObject::connect(ui->EopfileButton,SIGNAL(clicked()),this,SLOT(ChoixEOPfile()));
    QObject::connect(ui->BlqfileButton,SIGNAL(clicked()),this,SLOT(ChoixBLQfile()));
    QObject::connect(ui->TempdirButton,SIGNAL(clicked()),this,SLOT(ChoixTempdir()));
    QObject::connect(ui->Impstr2PathButton,SIGNAL(clicked()),this,SLOT(ChoixImpstr2path()));
    QObject::connect(ui->Outstr1PathButton,SIGNAL(clicked()),this,SLOT(ChoixOutstr1path()));
    QObject::connect(ui->Logstr1PathButton,SIGNAL(clicked()),this,SLOT(ChoixLogstr1path()));

    if(modeleFile!="") Charge(modeleFile);
    else Charge(configFile);
}

EditeConfig::~EditeConfig()
{
    delete ui;
}

void EditeConfig::Retour()
{
    //ChoixEdite FenetreChoixEdit(modeleFile);
    this->close();
    emit DemandeRetour();
    //FenetreChoixEdit.showFullScreen();
    //FenetreChoixEdit.exec();
}

void EditeConfig::ChangePosMode(int index)
{
    if ((index==0)||(index>=6)) ui->FrequencyBox->setEnabled(false);
    else ui->FrequencyBox->setEnabled(true);
    if ((index==1)||(index==2)) ui->DynamicsBox->setEnabled(true);
    else
    {
        ui->DynamicsBox->setEnabled(false);
        ui->DynamicsBox->setCurrentIndex(0);
    }
    if (index==0)
    {
        ui->Posopt1CheckBox->setEnabled(false);
        ui->Posopt2CheckBox->setEnabled(false);
        ui->TidecorrBox->setEnabled(false);
    }
    else
    {
        ui->Posopt1CheckBox->setEnabled(true);
        ui->Posopt2CheckBox->setEnabled(true);
        ui->TidecorrBox->setEnabled(true);
    }
    if ((index==0)||(index>=6)) {if(ui->IonooptBox->itemText(4)=="Estimate STEC") ui->IonooptBox->removeItem(4);}
    else if(ui->IonooptBox->itemText(4)!="Estimate STEC") ui->IonooptBox->insertItem(4,QString("Estimate STEC"));
    if ((index==0))
    {
        if (ui->TropoptBox->itemText(3)=="Estimate ZTD")
        {
            ui->TropoptBox->removeItem(4);
            ui->TropoptBox->removeItem(3);
        }
    }
    else if (ui->TropoptBox->itemText(3)!="Estimate ZTD")
    {
        ui->TropoptBox->insertItems(3,QStringList()<<"Estimate ZTD"<<"Estimate ZTD+GRAD");
    }
    if (index>=6)
    {
        ui->Posopt3CheckBox->setEnabled(true);
        ui->Posopt4CheckBox->setEnabled(true);
    }
    else
    {
        ui->Posopt3CheckBox->setEnabled(false);
        ui->Posopt4CheckBox->setEnabled(false);
    }
    if ((index>=2)&&(index<=5))
    {
        ui->ArmodeBox->setEnabled(true);
        if (ui->GloarmodeBox->itemText(1)!="ON") ui->GloarmodeBox->insertItem(1,QString("ON"));
    }
    else
    {
        ui->ArmodeBox->setEnabled(true);
        ui->ArmodeBox->setCurrentIndex(0);
        if (ui->GloarmodeBox->itemText(1)=="ON") ui->GloarmodeBox->removeItem(1);
    }
}

void EditeConfig::ChangeSolFormat(int index)
{
    if (index==3)
    {
        ui->OutheadBox->setEnabled(false);
        ui->TimesysBox->setEnabled(false);
        ui->TimendecBox->setEnabled(false);
        ui->DegformBox->setEnabled(false);
        ui->FieldsepBox->setEnabled(false);
    }
    else
    {
        ui->OutheadBox->setEnabled(true);
        ui->TimesysBox->setEnabled(true);
        ui->TimendecBox->setEnabled(true);
        ui->DegformBox->setEnabled(true);
        ui->FieldsepBox->setEnabled(true);
    }
}

void EditeConfig::ChangeInpstrtype2(int index)
{
    switch (index)
    {
    case 0:
        ui->SerialPort2Box->setEnabled(false);
        ui->Baudrate2Box->setEnabled(false);
        ui->Impstr2PathBox->setEnabled(false);
        ui->Impstr2PathButton->setEnabled(false);
        ui->Impstr2StreamBox->setEnabled(false);
        ui->Impstr2StreamButton->setEnabled(false);
        ui->Inpstr2formatBox->setEnabled(false);

        break;
    case 1:
        ui->SerialPort2Box->setEnabled(true);
        ui->Baudrate2Box->setEnabled(true);
        ui->Impstr2PathBox->setEnabled(false);
        ui->Impstr2PathButton->setEnabled(false);
        ui->Impstr2StreamBox->setEnabled(false);
        ui->Impstr2StreamButton->setEnabled(false);
        ui->Inpstr2formatBox->setEnabled(true);

        break;
    case 2 :
        ui->SerialPort2Box->setEnabled(false);
        ui->Baudrate2Box->setEnabled(false);
        ui->Impstr2PathBox->setEnabled(true);
        ui->Impstr2PathButton->setEnabled(true);
        ui->Impstr2StreamBox->setEnabled(false);
        ui->Impstr2StreamButton->setEnabled(false);
        ui->Inpstr2formatBox->setEnabled(true);
        break;

    case 3 :
        ui->SerialPort2Box->setEnabled(false);
        ui->Baudrate2Box->setEnabled(false);
        ui->Impstr2PathBox->setEnabled(false);
        ui->Impstr2PathButton->setEnabled(false);
        ui->Impstr2StreamBox->setEnabled(true);
        ui->Impstr2StreamButton->setEnabled(true);
        ui->Inpstr2formatBox->setEnabled(true);
        break;

    }
}


void EditeConfig::ChangeInpstrtype3(int index)
{
    switch (index)
    {
    case 0:
        ui->SerialPort3Box->setEnabled(false);
        ui->Baudrate3Box->setEnabled(false);
        ui->Impstr3PathBox->setEnabled(false);
        ui->Impstr3PathButton->setEnabled(false);
        ui->Impstr3StreamBox->setEnabled(false);
        ui->Impstr3StreamButton->setEnabled(false);
        ui->Inpstr3formatBox->setEnabled(false);

        break;
    case 1:
        ui->SerialPort3Box->setEnabled(true);
        ui->Baudrate3Box->setEnabled(true);
        ui->Impstr3PathBox->setEnabled(false);
        ui->Impstr3PathButton->setEnabled(false);
        ui->Impstr3StreamBox->setEnabled(false);
        ui->Impstr3StreamButton->setEnabled(false);
        ui->Inpstr3formatBox->setEnabled(true);

        break;
    case 2 :
        ui->SerialPort3Box->setEnabled(false);
        ui->Baudrate3Box->setEnabled(false);
        ui->Impstr3PathBox->setEnabled(true);
        ui->Impstr3PathButton->setEnabled(true);
        ui->Impstr3StreamBox->setEnabled(false);
        ui->Impstr3StreamButton->setEnabled(false);
        ui->Inpstr3formatBox->setEnabled(true);
        break;

    case 3 :
        ui->SerialPort3Box->setEnabled(false);
        ui->Baudrate3Box->setEnabled(false);
        ui->Impstr3PathBox->setEnabled(false);
        ui->Impstr3PathButton->setEnabled(false);
        ui->Impstr3StreamBox->setEnabled(true);
        ui->Impstr3StreamButton->setEnabled(true);
        ui->Inpstr3formatBox->setEnabled(true);
        break;

    }
}




void EditeConfig::ChangeOutstr1type(int index)
{
    switch (index)
    {
    case 0:
        ui->SerialPortOutBox->setEnabled(false);
        ui->BaudrateOutBox->setEnabled(false);
        ui->Outstr1PathBox->setEnabled(false);
        ui->Outstr1PathButton->setEnabled(false);
        ui->OutstrformatBox->setEnabled(false);
        break;
    case 1:
        ui->SerialPortOutBox->setEnabled(true);
        ui->BaudrateOutBox->setEnabled(true);
        ui->Outstr1PathBox->setEnabled(false);
        ui->Outstr1PathButton->setEnabled(false);
        ui->OutstrformatBox->setEnabled(true);
        break;
    case 2 :
        ui->SerialPortOutBox->setEnabled(false);
        ui->BaudrateOutBox->setEnabled(false);
        ui->Outstr1PathBox->setEnabled(true);
        ui->Outstr1PathButton->setEnabled(true);
        ui->OutstrformatBox->setEnabled(true);
        break;
    }
}

void EditeConfig::ChangeLogstr1type(int index)
{
    switch (index)
    {
    case 0:
        ui->Logstr1PathBox->setEnabled(false);
        ui->Logstr1PathButton->setEnabled(false);
        break;
    case 1:
        ui->Logstr1PathBox->setEnabled(true);
        ui->Logstr1PathButton->setEnabled(true);
        break;
    }
}

void EditeConfig::ChoixSatantfile()
{
    QString filePath = QFileDialog::getOpenFileName(this,tr("Satellites Antenna File"),"../RTKBASE/data",tr("Antenna Files (*.atx);;All Files (*)"));
    if (filePath!="") ui->SatantfileBox->setText(filePath);
}

void EditeConfig::ChoixRcvantfile()
{
    QString filePath = QFileDialog::getOpenFileName(this,tr("Recever Antenna File"),"../RTKBASE/data",tr("Antenna Files (*.atx);;All Files (*)"));
    if (filePath!="") ui->RcvantfileBox->setText(filePath);
}

void EditeConfig::ChoixGeoidfile()
{
    QString filePath = QFileDialog::getOpenFileName(this,tr("Geoid File"),"../RTKBASE/data",tr("All Files (*)"));
    if (filePath!="") ui->GeoidfileBox->setText(filePath);
}

void EditeConfig::ChoixDCBfile()
{
    QString filePath = QFileDialog::getOpenFileName(this,tr("DCB File"),"../RTKBASE/data",tr("DCB Files (*.DCB);;All Files (*)"));
    if (filePath!="") ui->DcbfileBox->setText(filePath);
}

void EditeConfig::ChoixEOPfile()
{
    QString filePath = QFileDialog::getOpenFileName(this,tr("EOP File"),"../RTKBASE/data",tr("EOP Files (*.EOP);;All Files (*)"));
    if (filePath!="") ui->EopfileBox->setText(filePath);
}

void EditeConfig::ChoixBLQfile()
{
    QString filePath = QFileDialog::getOpenFileName(this,tr("Ocean Loading BLQ File"),"../RTKBASE/data",tr("BLQ Files (*.atx);;All Files (*)"));
    if (filePath!="") ui->BlqfileBox->setText(filePath);
}

void EditeConfig::ChoixTempdir()
{
    QString dirPath = QFileDialog::getExistingDirectory(this,tr("FTP/HTTP Local Directory"),"../RTKBASE/data",QFileDialog::ShowDirsOnly|QFileDialog::DontResolveSymlinks);
    if (dirPath!="") ui->TempdirBox->setText(dirPath);
}

void EditeConfig::ChoixImpstr2path()
{
    QString filePath = QFileDialog::getOpenFileName(this,tr("Input 2 Stream File"),"../RTKBASE/data",tr("All Files (*)"));
    if (filePath!="") ui->Impstr2PathBox->setText(filePath);
}

void EditeConfig::ChoixOutstr1path()
{
    QString filePath = QFileDialog::getSaveFileName(this,tr("Output Stream File"),"../RTKBASE/data",tr("All Files (*)"));
    if (filePath!="") ui->Outstr1PathBox->setText(filePath);
}

void EditeConfig::ChoixLogstr1path()
{
    QString filePath = QFileDialog::getSaveFileName(this,tr("Log Stream File"),"../RTKBASE/data",tr("All Files (*)"));
    if (filePath!="") ui->Logstr1PathBox->setText(filePath);
}

void EditeConfig::Save()
{
    QFile configNames(QString("../RTKBASE/data/ConfigNames"));
    int num;
    QString string=configFile;
    if (configFile[configFile.size()-6]==QChar('1'))
    {
        string.remove(0,string.size()-6);
        string.chop(4);
        num=string.toInt();
    }
    else
    {
        string.remove(0,string.size()-5);
        string.chop(4);
        num=string.toInt();
    }
    std::cout<<"Le numéro du fichie de configuration d'enregistrement est :"<<num<<std::endl;
    QTextStream fluxNames(&configNames);
    configNames.open(QIODevice::ReadOnly|QIODevice::Text);
    QString ligne;
    int i=0;
    while((!fluxNames.atEnd())&&(i!=num))
    {
        ligne=fluxNames.readLine();
        if (!ligne.startsWith("#")) i+=1;
    }

    QFile file(configFile);
    QTextStream flux(&file);
    file.remove();
    file.open(QIODevice::WriteOnly|QIODevice::Truncate);

    flux<<"# Fichier de configuration <<"<<ligne<<">>."<<endl;
    flux<<endl;

    flux<<qSetFieldWidth(20)<<left<<"console-passwd"<<qSetFieldWidth(0)<<"="<<"admin"
       <<"     # (add password here)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"console-timetype"<<qSetFieldWidth(0)<<"="<<"gpst"
       <<"     # (0:gpst,1:utc,2:jst,3:tow)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"console-soltype"<<qSetFieldWidth(0)<<"="<<"dms"
       <<"     # (0:dms,1:deg,2:xyz,3:enu,4:pyl)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"console-solflag"<<qSetFieldWidth(0)<<"="<<"2"
       <<"     # (0:off,1:std+2:age/ratio/ns)"<<endl;



    flux<<qSetFieldWidth(20)<<left<<"inpstr1-type"<<qSetFieldWidth(0)<<"="<<ui->Inpstrtype1Box->currentText()
       <<"     # (0:off,1:serial,2:file,3:tcpsvr,4:tcpcli,7:ntripcli,8:ftp,9:http)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"inpstr2-type"<<qSetFieldWidth(0)<<"="<<ui->Inpstrtype2Box->currentText()
       <<"     # (0:off,1:serial,2:file,3:tcpsvr,4:tcpcli,7:ntripcli,8:ftp,9:http)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"inpstr3-type"<<qSetFieldWidth(0)<<"="<<ui->Inpstrtype3Box->currentText()
       <<"     # (0:off,1:serial,2:file,3:tcpsvr,4:tcpcli,7:ntripcli,8:ftp,9:http)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"inpstr1-path"<<qSetFieldWidth(0)<<"="<<ui->SerialPort1Box->currentText()
       <<":"<<ui->Baudrate1Box->currentText()<<":8:n:1:off"<<endl;
    if (ui->Inpstrtype2Box->currentIndex()==1)

        flux<<qSetFieldWidth(20)<<left<<"inpstr2-path"<<qSetFieldWidth(0)<<"="<<ui->SerialPort2Box->currentText()
       <<":"<<ui->Baudrate2Box->currentText()<<":8:n:1:off"<<endl;
    if (ui->Inpstrtype2Box->currentIndex()==2)
        flux<<qSetFieldWidth(20)<<left<<"inpstr2-path"<<qSetFieldWidth(0)<<"="<<ui->Impstr2PathBox->text()<<endl;

    else
        flux<<qSetFieldWidth(20)<<left<<"inpstr2-path"<<qSetFieldWidth(0)<<"="<<ui->Impstr2StreamBox->text()<<endl;


    if (ui->Inpstrtype3Box->currentIndex()==1)

        flux<<qSetFieldWidth(20)<<left<<"inpstr3-path"<<qSetFieldWidth(0)<<"="<<ui->SerialPort3Box->currentText()
       <<":"<<ui->Baudrate3Box->currentText()<<":8:n:1:off"<<endl;
    if (ui->Inpstrtype3Box->currentIndex()==2)
        flux<<qSetFieldWidth(20)<<left<<"inpstr3-path"<<qSetFieldWidth(0)<<"="<<ui->Impstr3PathBox->text()<<endl;

    else
        flux<<qSetFieldWidth(20)<<left<<"inpstr3-path"<<qSetFieldWidth(0)<<"="<<ui->Impstr3StreamBox->text()<<endl;


//    flux<<qSetFieldWidth(20)<<left<<"inpstr3-path"<<qSetFieldWidth(0)<<"="<<""<<endl;
    flux<<qSetFieldWidth(20)<<left<<"inpstr1-format"<<qSetFieldWidth(0)<<"="<<ui->Inpstr1formatBox->currentText()
       <<"     # (0:rtcm2,1:rtcm3,2:oem4,3:oem3,4:ubx,5:ss2,6:hemis,7:skytraq,8:sp3)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"inpstr2-format"<<qSetFieldWidth(0)<<"="<<ui->Inpstr2formatBox->currentText()
       <<"     # (0:rtcm2,1:rtcm3,2:oem4,3:oem3,4:ubx,5:ss2,6:hemis,7:skytraq,8:sp3)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"inpstr3-format"<<qSetFieldWidth(0)<<"="<<ui->Inpstr3formatBox->currentText()
       <<"     # (0:rtcm2,1:rtcm3,2:oem4,3:oem3,4:ubx,5:ss2,6:hemis,7:skytraq,8:sp3)"<<endl;

    flux<<qSetFieldWidth(20)<<left<<"inpstr2-nmeareq"<<qSetFieldWidth(0)<<"="<<"off"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"inpstr2-nmealat"<<qSetFieldWidth(0)<<"="<<"0"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"inpstr2-nmealon"<<qSetFieldWidth(0)<<"="<<"0"<<endl;

    flux<<qSetFieldWidth(20)<<left<<"outstr1-type"<<qSetFieldWidth(0)<<"="<<ui->Outstr1typeBox->currentText()
       <<"     # (0:off,1:serial,2:file,3:tcpsvr,4:tcpcli,6:ntripsvr)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"outstr2-type"<<qSetFieldWidth(0)<<"="<<ui->OutstrtypeBox2->currentText()
       <<"     # (0:off,1:serial,2:file,3:tcpsvr,4:tcpcli,6:ntripsvr)"<<endl;
    if (ui->Outstr1typeBox->currentIndex()==1) flux<<qSetFieldWidth(20)<<left<<"outstr1-path"<<qSetFieldWidth(0)<<"="<<ui->SerialPortOutBox->currentText()
       <<":"<<ui->BaudrateOutBox->currentText()<<":8:n:1:off"<<endl;
   else flux<<qSetFieldWidth(20)<<left<<"outstr1-path"<<qSetFieldWidth(0)<<"="<<ui->Outstr1PathBox->text()<<endl;

    if (ui->OutstrtypeBox2->currentIndex()==1) flux<<qSetFieldWidth(20)<<left<<"outstr2-path"<<qSetFieldWidth(0)<<"="<<ui->SerialPortOutBox2->currentText()
       <<":"<<ui->BaudrateOutBox->currentText()<<":8:n:1:off"<<endl;
   else flux<<qSetFieldWidth(20)<<left<<"outstr2-path"<<qSetFieldWidth(0)<<"="<<ui->Outstr1PathBox2->text()<<endl;

//        flux<<qSetFieldWidth(20)<<left<<"outstr2-path"<<qSetFieldWidth(0)<<"="<<ui->Outstr1PathBox2->text()<<endl;

        flux<<qSetFieldWidth(20)<<left<<"outstr1-format"<<qSetFieldWidth(0)<<"="<<ui->OutstrformatBox->currentText()
       <<"     # (0:llh,1:xyz,2:enu,3:nmea)"<<endl;

        flux<<qSetFieldWidth(20)<<left<<"outstr2-format"<<qSetFieldWidth(0)<<"="<<ui->OutstrformatBox2->currentText()
       <<"     # (0:llh,1:xyz,2:enu,3:nmea)"<<endl;

    flux<<qSetFieldWidth(20)<<left<<"logstr1-type"<<qSetFieldWidth(0)<<"="<<ui->Logstr1typeBox->currentText()
       <<"     # (0:off,1:serial,2:file,3:tcpsvr,4:tcpcli,6:ntripsvr)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"logstr2-type"<<qSetFieldWidth(0)<<"="<<ui->Logstr1typeBox2->currentText()
       <<"     # (0:off,1:serial,2:file,3:tcpsvr,4:tcpcli,6:ntripsvr)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"logstr3-type"<<qSetFieldWidth(0)<<"="<<ui->Logstr1typeBox3->currentText()
       <<"     # (0:off,1:serial,2:file,3:tcpsvr,4:tcpcli,6:ntripsvr)"<<endl;

    flux<<qSetFieldWidth(20)<<left<<"logstr1-path"<<qSetFieldWidth(0)<<"="<<ui->Logstr1PathBox->text()<<endl;
    flux<<qSetFieldWidth(20)<<left<<"logstr2-path"<<qSetFieldWidth(0)<<"="<<ui->Logstr1PathBox2->text()<<endl;
    flux<<qSetFieldWidth(20)<<left<<"logstr3-path"<<qSetFieldWidth(0)<<"="<<ui->Logstr1PathBox3->text()<<endl;

    flux<<qSetFieldWidth(20)<<left<<"misc-svrcycle"<<qSetFieldWidth(0)<<"="<<ui->SvrcycleBox->currentText()
       <<"     # (ms)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"misc-timeout"<<qSetFieldWidth(0)<<"="<<ui->TimeoutBox->currentText()
       <<"     # (ms)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"misc-reconnect"<<qSetFieldWidth(0)<<"="<<ui->ReconnectBox->currentText()
       <<"     # (ms)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"misc-nmeacycle"<<qSetFieldWidth(0)<<"="<<ui->NmeacycleBox->currentText()
       <<"     # (ms)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"misc-buffsize"<<qSetFieldWidth(0)<<"="<<ui->BuffsizeBox->currentText()
       <<"     # (bytes)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"misc-navmsgsel"<<qSetFieldWidth(0)<<"="<<ui->NavmsgselBox->currentText()
       <<"     # (0:all,1:rover,1:base,2:corr)"<<endl;


    flux<<qSetFieldWidth(20)<<left<<"misc-startcmd"<<qSetFieldWidth(0)<<"="<<"./rtkstart.sh"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"misc-stopcmd"<<qSetFieldWidth(0)<<"="<<"./rtkshut.sh"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"file-cmdfile1"<<qSetFieldWidth(0)<<"="<<"../../../data/oem4_raw_1hz.cmd"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"file-cmdfile2"<<qSetFieldWidth(0)<<"="<<"../../../data/oem4_raw_1hz.cmd"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"file-cmdfile3"<<qSetFieldWidth(0)<<"="<<""<<endl;

    flux<<qSetFieldWidth(20)<<left<<"pos1-posmode"<<qSetFieldWidth(0)<<"="<<ui->PosmodeBox->currentText()
       <<"     # (0:single,1:dgps,2:kinematic,3:static,4:movingbase,5:fixed,6:ppp-kine,7:ppp-static)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"pos1-frequency"<<qSetFieldWidth(0)<<"="<<ui->FrequencyBox->currentText()
       <<"     # (1:l1,2:l1+l2,3:l1+l2+l5)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"pos1-soltype"<<qSetFieldWidth(0)<<"="<<"forward"
       <<"     # (0:forward,1:backward,2:combined)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"pos1-elmask"<<qSetFieldWidth(0)<<"="<<ui->ElmaskBox->currentText()
       <<"     # (deg)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"pos1-snrmask"<<qSetFieldWidth(0)<<"="<<ui->SnrmaskLine->text()
       <<"     # (dBHz)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"pos1-dynamics"<<qSetFieldWidth(0)<<"="<<ui->DynamicsBox->currentText()
       <<"     # (0:off,1:on)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"pos1-tidecorr"<<qSetFieldWidth(0)<<"="<<ui->TidecorrBox->currentText()
       <<"     # (0:off,1:on)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"pos1-ionoopt"<<qSetFieldWidth(0)<<"="<<ui->IonooptBox->currentText()
       <<"     # (0:off,1:brdc,2:sbas,3:dual-freq,4:est-stec)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"pos1-tropopt"<<qSetFieldWidth(0)<<"="<<ui->TropoptBox->currentText()
       <<"     # (0:off,1:saas,2:sbas,3:est-ztd,4:est-ztdgrad)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"pos1-sateph"<<qSetFieldWidth(0)<<"="<<ui->SatephBox->currentText()
       <<"     # (0:brdc,1:precise,2:brdc+sbas,3:brdc+ssrapc,4:brdc+ssrcom)"<<endl;
//    if (ui->Posopt1CheckBox->isChecked()) flux<<qSetFieldWidth(20)<<left<<"pos1-posopt1"<<qSetFieldWidth(0)<<"="<<"on"
//       <<"     # (0:off,1:on)"<<endl;
//    else flux<<qSetFieldWidth(20)<<left<<"pos1-posopt1"<<qSetFieldWidth(0)<<"="<<"off"
//            <<"     # (0:off,1:on)"<<endl;
//    if (ui->Posopt2CheckBox->isChecked()) flux<<qSetFieldWidth(20)<<left<<"pos1-posopt2"<<qSetFieldWidth(0)<<"="<<"on"
//       <<"     # (0:off,1:on)"<<endl;
//    else flux<<qSetFieldWidth(20)<<left<<"pos1-posopt2"<<qSetFieldWidth(0)<<"="<<"off"
//            <<"     # (0:off,1:on)"<<endl;
//    if (ui->Posopt3CheckBox->isChecked()) flux<<qSetFieldWidth(20)<<left<<"pos1-posopt3"<<qSetFieldWidth(0)<<"="<<"on"
//       <<"     # (0:off,1:on)"<<endl;
//    else flux<<qSetFieldWidth(20)<<left<<"pos1-posopt3"<<qSetFieldWidth(0)<<"="<<"off"
//            <<"     # (0:off,1:on)"<<endl;
//    if (ui->Posopt4CheckBox->isChecked()) flux<<qSetFieldWidth(20)<<left<<"pos1-posopt4"<<qSetFieldWidth(0)<<"="<<"on"
//       <<"     # (0:off,1:on)"<<endl;
//    else flux<<qSetFieldWidth(20)<<left<<"pos1-posopt4"<<qSetFieldWidth(0)<<"="<<"off"
//            <<"     # (0:off,1:on)"<<endl;
//    if (ui->Posopt5CheckBox->isChecked()) flux<<qSetFieldWidth(20)<<left<<"pos1-posopt5"<<qSetFieldWidth(0)<<"="<<"on"
//       <<"     # (0:off,1:on)"<<endl;
//    else flux<<qSetFieldWidth(20)<<left<<"pos1-posopt"<<qSetFieldWidth(0)<<"="<<"off"
//            <<"     # (0:off,1:on)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"pos1-exclsats"<<qSetFieldWidth(0)<<"="<<ui->ExclsatsLine->text()
       <<"     # (prn ...)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"pos1-navsys"<<qSetFieldWidth(0)<<"="<<ui->NavsysGPSCheckBox->isChecked()
          +ui->NavsysSBASCheckBox->isChecked()*2+ui->NavsysGLONASSCheckBox->isChecked()*4
          +ui->NavsysGalileoCheckBox->isChecked()*8+ui->NavsysQZSSCheckBox->isChecked()*16
          +ui->NavsysBeiDouCheckBox->isChecked()*32<<"     # (1:gps+2:sbas+4:glo+8:gal+16:qzs+32:comp)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"pos2-armode"<<qSetFieldWidth(0)<<"="<<ui->ArmodeBox->currentText()
       <<"     # (0:off,1:continuous,2:instantaneous,3:fix-and-hold)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"pos2-gloarmode"<<qSetFieldWidth(0)<<"="<<ui->GloarmodeBox->currentText()
       <<"     # (0:off,1:on,2:autocal)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"pos2-arthres"<<qSetFieldWidth(0)<<"="<<ui->ArthresBox->currentText()<<endl;
    flux<<qSetFieldWidth(20)<<left<<"pos2-arlockcnt"<<qSetFieldWidth(0)<<"="<<ui->ArlockcntBox->currentText()<<endl;
    flux<<qSetFieldWidth(20)<<left<<"pos2-arelmask"<<qSetFieldWidth(0)<<"="<<ui->ArelmaskBox->currentText()
       <<"     # (deg)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"pos2-aroutcnt"<<qSetFieldWidth(0)<<"="<<ui->AroutcntBox->currentText()<<endl;
    flux<<qSetFieldWidth(20)<<left<<"pos2-arminfix"<<qSetFieldWidth(0)<<"="<<ui->ArminfixBox->currentText()<<endl;
    flux<<qSetFieldWidth(20)<<left<<"pos2-slipthres"<<qSetFieldWidth(0)<<"="<<ui->SlipthresBox->currentText()
       <<"     # (m)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"pos2-maxage"<<qSetFieldWidth(0)<<"="<<ui->MaxageBox->currentText()
       <<"     # (s)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"pos2-rejionno"<<qSetFieldWidth(0)<<"="<<ui->RejionnoBox->currentText()
       <<"     # (m)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"pos2-niter"<<qSetFieldWidth(0)<<"="<<ui->NiterBox->currentText()<<endl;
    flux<<qSetFieldWidth(20)<<left<<"pos2-baselen"<<qSetFieldWidth(0)<<"="<<ui->BaselenLine->text()
       <<"     # (m)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"pos2-basesig"<<qSetFieldWidth(0)<<"="<<ui->BasesigLine->text()
       <<"     # (m)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"out-solformat"<<qSetFieldWidth(0)<<"="<<ui->SolformatBox->currentText()
       <<"     # (0:llh,1:xyz,2:enu,3:nmea)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"out-outhead"<<qSetFieldWidth(0)<<"="<<ui->OutheadBox->currentText()
       <<"     # (0:off,1:on)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"out-outopt"<<qSetFieldWidth(0)<<"="<<"off"
       <<"     # (0:off,1:on)"<<endl;
//    flux<<qSetFieldWidth(20)<<left<<"pos2-elmaskhold"<<qSetFieldWidth(0)<<"="<<ui->ElmaskBox->currentText()
//       <<"     # (deg)"<<endl;



//    flux<<qSetFieldWidth(20)<<left<<"pos2-rejgdop"<<qSetFieldWidth(0)<<"="<<ui->RejgdopBox->currentText()<<endl;






    if (ui->TimesysBox->currentIndex()<2)
    {
        flux<<qSetFieldWidth(20)<<left<<"out-timesys"<<qSetFieldWidth(0)<<"="<<"gpst"
           <<"     # (0:gpst,1:utc,2:jst)"<<endl;
        flux<<qSetFieldWidth(20)<<left<<"out-timeform"<<qSetFieldWidth(0)<<"="<<ui->TimesysBox->currentText()
           <<"     # (0:tow,1:hms)"<<endl;
    }
    else
    {
        flux<<qSetFieldWidth(20)<<left<<"out-timesys"<<qSetFieldWidth(0)<<"="<<ui->TimesysBox->currentText()
           <<"     # (0:gpst,1:utc,2:jst)"<<endl;
        flux<<qSetFieldWidth(20)<<left<<"out-timeform"<<qSetFieldWidth(0)<<"="<<"hms"
           <<"     # (0:tow,1:hms)"<<endl;
    }
    flux<<qSetFieldWidth(20)<<left<<"out-timendec"<<qSetFieldWidth(0)<<"="<<ui->TimendecBox->currentText()<<endl;
    flux<<qSetFieldWidth(20)<<left<<"out-degform"<<qSetFieldWidth(0)<<"="<<ui->DegformBox->currentText()
       <<"     # (0:deg,1:dms)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"out-fieldsep"<<qSetFieldWidth(0)<<"="<<ui->FieldsepBox->text()<<endl;
    flux<<qSetFieldWidth(20)<<left<<"out-height"<<qSetFieldWidth(0)<<"="<<ui->HeightBox->currentText()
       <<"     # (0:ellipsoidal,1:geodetic)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"out-geoid"<<qSetFieldWidth(0)<<"="<<ui->GeoidBox->currentText()
       <<"     # (0:internal,1:egm96,2:egm08_2.5,3:egm08_1,4:gsi2000)"<<endl;

    flux<<qSetFieldWidth(20)<<left<<"out-solstatic"<<qSetFieldWidth(0)<<"="<<"all"
       <<"     # (0:all,1:single)"<<endl;

    flux<<qSetFieldWidth(20)<<left<<"out-nmeaintv1"<<qSetFieldWidth(0)<<"="<<ui->Nmeaintv1Box->text()
       <<"     # (s)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"out-nmeaintv2"<<qSetFieldWidth(0)<<"="<<ui->Nmeaintv2Box->text()
       <<"     # (s)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"out-outstat"<<qSetFieldWidth(0)<<"="<<ui->OutstatBox->currentText()
       <<"     # (0:off,1:state,2:residual)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"stats-erratio"<<qSetFieldWidth(0)<<"="<<ui->Eratio1Box->currentText()<<endl;
//    flux<<qSetFieldWidth(20)<<left<<"stats-eratio2"<<qSetFieldWidth(0)<<"="<<ui->Eratio2Box->currentText()<<endl;
    flux<<qSetFieldWidth(20)<<left<<"stats-errphase"<<qSetFieldWidth(0)<<"="<<ui->ErrphaseBox->currentText()
       <<"     # (m)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"stats-errphaseel"<<qSetFieldWidth(0)<<"="<<ui->ErrphaseelBox->currentText()
       <<"     # (m)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"stats-errphasebl"<<qSetFieldWidth(0)<<"="<<ui->ErrphaseblBox->currentText()
       <<"     # (m/10km)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"stats-errdoppler"<<qSetFieldWidth(0)<<"="<<ui->ErrdopplerBox->currentText()
       <<"     # (Hz)"<<endl;


    flux<<qSetFieldWidth(20)<<left<<"stats-stdbias"<<qSetFieldWidth(0)<<"=""30"
       <<"     # (m)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"stats-stdiono"<<qSetFieldWidth(0)<<"="<<"0.03"
       <<"     # (m)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"stats-stdtrop"<<qSetFieldWidth(0)<<"="<<"0.3"
       <<"     # (m)"<<endl;


    flux<<qSetFieldWidth(20)<<left<<"stats-prnaccelh"<<qSetFieldWidth(0)<<"="<<ui->PrnaccelhBox->currentText()
       <<"     # (m/s^2)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"stats-prnaccelv"<<qSetFieldWidth(0)<<"="<<ui->PrnaccelvBox->currentText()
       <<"     # (m/s^2)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"stats-prnbias"<<qSetFieldWidth(0)<<"="<<ui->PrnbiasBox->currentText()
       <<"     # (m)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"stats-prniono"<<qSetFieldWidth(0)<<"="<<ui->PrnionoBox->currentText()
       <<"     # (m)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"stats-prntrop"<<qSetFieldWidth(0)<<"="<<ui->PrntropBox->currentText()
       <<"     # (m)"<<endl;

    flux<<qSetFieldWidth(20)<<left<<"stats-clkstab"<<qSetFieldWidth(0)<<"="<<ui->ClckstabBox->currentText()
       <<"     # (s/s)"<<endl;
//    if (ui->RovpostypeBox->currentIndex()<2)
        flux<<qSetFieldWidth(20)<<left<<"ant1-postype"<<qSetFieldWidth(0)<<"="<<ui->RovpostypeBox->currentText()
       <<"     # (0:llh,1:xyz,2:single,3:posfile,4:rinexhead,5:rtcm)"<<endl;
//    else flux<<qSetFieldWidth(20)<<left<<"ant1-postype"<<qSetFieldWidth(0)<<"="<<5
//            <<"     # (0:llh,1:xyz,2:single,3:posfile,4:rinexhead,5:rtcm)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"ant1-pos1"<<qSetFieldWidth(0)<<"="<<ui->Rovpos1Box->text()
       <<"     # (m)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"ant1-pos2"<<qSetFieldWidth(0)<<"="<<ui->Rovpos2Box->text()
       <<"     # (m)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"ant1-pos3"<<qSetFieldWidth(0)<<"="<<ui->Rovpos3Box->text()
       <<"     # (m)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"ant1-anttype"<<qSetFieldWidth(0)<<"="<<ui->RovanttypeBox->currentText()<<endl;
    flux<<qSetFieldWidth(20)<<left<<"ant1-antdele"<<qSetFieldWidth(0)<<"="<<ui->RovantdeleBox->text()
       <<"     # (m)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"ant1-antdeln"<<qSetFieldWidth(0)<<"="<<ui->RovantdelnBox->text()
       <<"     # (m)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"ant1-antdelu"<<qSetFieldWidth(0)<<"="<<ui->RovantdeluBox->text()
       <<"     # (m)"<<endl;
//    if (ui->BspostypeBox->currentIndex()<2)
        flux<<qSetFieldWidth(20)<<left<<"ant2-postype"<<qSetFieldWidth(0)<<"="<<ui->BspostypeBox->currentText()
       <<"     # (0:llh,1:xyz,2:single,3:posfile,4:rinexhead,5:rtcm)"<<endl;
//    else flux<<qSetFieldWidth(20)<<left<<"ant2-postype"<<qSetFieldWidth(0)<<"="<<5
//            <<"     # (0:llh,1:xyz,2:single,3:posfile,4:rinexhead,5:rtcm)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"ant2-pos1"<<qSetFieldWidth(0)<<"="<<ui->Bspos1Box->text()
       <<"     # (m)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"ant2-pos2"<<qSetFieldWidth(0)<<"="<<ui->Bspos2Box->text()
       <<"     # (m)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"ant2-pos3"<<qSetFieldWidth(0)<<"="<<ui->Bspos3Box->text()
       <<"     # (m)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"ant2-anttype"<<qSetFieldWidth(0)<<"="<<ui->BsanttypeBox->currentText()<<endl;
    flux<<qSetFieldWidth(20)<<left<<"ant2-antdele"<<qSetFieldWidth(0)<<"="<<ui->BsantdeleBox->text()
       <<"     # (m)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"ant2-antdeln"<<qSetFieldWidth(0)<<"="<<ui->BsantdelnBox->text()
       <<"     # (m)"<<endl;
    flux<<qSetFieldWidth(20)<<left<<"ant2-antdelu"<<qSetFieldWidth(0)<<"="<<ui->BsantdeluBox->text()
       <<"     # (m)"<<endl;
//    flux<<qSetFieldWidth(20)<<left<<"mysc-fswapmargin"<<qSetFieldWidth(0)<<"="<<ui->FswapmarginBox->currentText()
//       <<"     # (s)"<<endl;
//    flux<<qSetFieldWidth(20)<<left<<"misc-proxyadr"<<qSetFieldWidth(0)<<"="<<ui->ProxyadrBox->text()<<endl;
    flux<<qSetFieldWidth(20)<<left<<"misc-timeinterp"<<qSetFieldWidth(0)<<"="<<"off"
       <<"     # (0:off,1:on)"<<endl;

    flux<<qSetFieldWidth(20)<<left<<"misc-sbasatsel"<<qSetFieldWidth(0)<<"="<<ui->SbasatselBox->text()
       <<"     # (0:all)"<<endl;

    flux<<qSetFieldWidth(20)<<left<<"file-satantfile"<<qSetFieldWidth(0)<<"="<<ui->SatantfileBox->text()<<endl;
    flux<<qSetFieldWidth(20)<<left<<"file-rcvantfile"<<qSetFieldWidth(0)<<"="<<ui->RcvantfileBox->text()<<endl;

    flux<<qSetFieldWidth(20)<<left<<"file-staposfile"<<qSetFieldWidth(0)<<"="<<"../RTKBASE/data/station.pos"<<endl;

    flux<<qSetFieldWidth(20)<<left<<"file-geoidfile"<<qSetFieldWidth(0)<<"="<<ui->GeoidfileBox->text()<<endl;
    flux<<qSetFieldWidth(20)<<left<<"file-dcbfile"<<qSetFieldWidth(0)<<"="<<ui->DcbfileBox->text()<<endl;

//    flux<<qSetFieldWidth(20)<<left<<"file-eopfile"<<qSetFieldWidth(0)<<"="<<ui->EopfileBox->text()<<endl;
//    flux<<qSetFieldWidth(20)<<left<<"file-blqfile"<<qSetFieldWidth(0)<<"="<<ui->BlqfileBox->text()<<endl;
    flux<<qSetFieldWidth(20)<<left<<"file-tempdir"<<qSetFieldWidth(0)<<"="<<ui->TempdirBox->text()<<endl;

        flux<<qSetFieldWidth(20)<<left<<"file-geexfile"<<qSetFieldWidth(0)<<"="<<""<<endl;
        flux<<qSetFieldWidth(20)<<left<<"file-solstatfile"<<qSetFieldWidth(0)<<"="<<""<<endl;
        flux<<qSetFieldWidth(20)<<left<<"file-tracefile"<<qSetFieldWidth(0)<<"="<<""<<endl;

    file.close();



    emit DemandeFerme();
    this->close();
}

void EditeConfig::Charge(QString filePath)
{
    QFile file(filePath);
    QTextStream flux(&file);
    file.open(QIODevice::ReadOnly|QIODevice::Truncate);
    QString line;
    QStringList liste;
    //std::cout<<"Le fichier modèle est : "<<filePath.toStdString()<<std::endl;
    //std::cout<<"On est au début, à la position <<"<<flux.pos()<<">> !!!!!"<<std::endl;
    while(!flux.atEnd())
    {
        line = flux.readLine();
        //qDebug()<<line;
        liste<<line;
    }
    file.close();
    //std::cout<<"A là fin, on a <<"<<liste.length()<<">> lignes dans la liste..."<<std::endl;

    int timesys=10;
    int timeform=10;
    for(int i=0;i<liste.length();i++)
    {
        QStringList decomp;
        if ((liste[i]!="")&&(liste[i][0]!=QChar('#'))) decomp = liste[i].split(" ",QString::SkipEmptyParts);
        else continue;
        decomp[1].remove("=");
        std::cout<<"Le nombre de parties dans la ligne <<"<<decomp[0].toStdString()<<">> analysée est : "<<decomp.length()<<std::endl;
        if(decomp[0]=="pos1-posmode")
        {
            if((decomp[1]=="0")||(decomp[1]=="single")) ui->PosmodeBox->setCurrentIndex(0);
            else if((decomp[1]=="1")||(decomp[1]=="dgps")) ui->PosmodeBox->setCurrentIndex(1);
            else if((decomp[1]=="2")||(decomp[1]=="kinematic")) ui->PosmodeBox->setCurrentIndex(2);
            else if((decomp[1]=="3")||(decomp[1]=="static")) ui->PosmodeBox->setCurrentIndex(3);
            else if((decomp[1]=="4")||(decomp[1]=="movingbase")) ui->PosmodeBox->setCurrentIndex(4);
            else if((decomp[1]=="5")||(decomp[1]=="fixed")) ui->PosmodeBox->setCurrentIndex(5);
            else if((decomp[1]=="6")||(decomp[1]=="ppp-kine")) ui->PosmodeBox->setCurrentIndex(6);
            else if((decomp[1]=="7")||(decomp[1]=="ppp-static")) ui->PosmodeBox->setCurrentIndex(7);
            else std::cout<<"Valeur de <pos1-posmode> incomprise"<<std::endl;
        }
        else if(decomp[0]=="pos1-frequency")
        {
            if((decomp[1]=="1")||(decomp[1]=="l1")) ui->FrequencyBox->setCurrentIndex(0);
            else if((decomp[1]=="2")||(decomp[1]=="l1+l2")) ui->FrequencyBox->setCurrentIndex(1);
            else if((decomp[1]=="3")||(decomp[1]=="l1+l2+l5")) ui->FrequencyBox->setCurrentIndex(2);
            else std::cout<<"Valeur de <pos1-frequency> incomprise"<<std::endl;
        }
        else if(decomp[0]=="pos1-elmask") ui->ElmaskBox->setEditText(decomp[1]);
        else if(decomp[0]=="pos1-snrmask") ui->SnrmaskLine->setText(decomp[1]);
        else if(decomp[0]=="pos1-dynamics")
        {
            if((decomp[1]=="0")||(decomp[1]=="off")) ui->DynamicsBox->setCurrentIndex(0);
            else if((decomp[1]=="1")||(decomp[1]=="on")) ui->DynamicsBox->setCurrentIndex(1);
            else std::cout<<"Valeur de <pos1-dynamics> incomprise"<<std::endl;
        }
        else if(decomp[0]=="pos1-tidecorr")
        {
            if((decomp[1]=="0")||(decomp[1]=="off")) ui->DynamicsBox->setCurrentIndex(0);
            else if((decomp[1]=="1")||(decomp[1]=="on")) ui->DynamicsBox->setCurrentIndex(1);
            else std::cout<<"Valeur de <pos1-tidecorr> incomprise"<<std::endl;
        }
        else if(decomp[0]=="pos1-ionoopt")
        {
            if((decomp[1]=="0")||(decomp[1]=="off")) ui->IonooptBox->setCurrentIndex(0);
            else if((decomp[1]=="1")||(decomp[1]=="brdc")) ui->IonooptBox->setCurrentIndex(1);
            else if((decomp[1]=="2")||(decomp[1]=="sbas")) ui->IonooptBox->setCurrentIndex(2);
            else if((decomp[1]=="3")||(decomp[1]=="dual-freq")) ui->IonooptBox->setCurrentIndex(3);
            else if((decomp[1]=="4")||(decomp[1]=="est-stec")) ui->IonooptBox->setCurrentIndex(4);
            else if((decomp[1]=="5")||(decomp[1]=="ionex-tec")) ui->IonooptBox->setCurrentIndex(5);
            else if((decomp[1]=="6")||(decomp[1]=="qzs-brdc")) ui->IonooptBox->setCurrentIndex(6);
            else if((decomp[1]=="7")||(decomp[1]=="qzs-lex")) ui->IonooptBox->setCurrentIndex(7);
            else std::cout<<"Valeur de <pos1-ionoopt> incomprise"<<std::endl;
        }
        else if(decomp[0]=="pos1-tropopt")
        {
            if((decomp[1]=="0")||(decomp[1]=="off")) ui->TropoptBox->setCurrentIndex(0);
            else if((decomp[1]=="1")||(decomp[1]=="saas")) ui->TropoptBox->setCurrentIndex(1);
            else if((decomp[1]=="2")||(decomp[1]=="sbas")) ui->TropoptBox->setCurrentIndex(2);
            else if((decomp[1]=="3")||(decomp[1]=="est-ztd")) ui->TropoptBox->setCurrentIndex(3);
            else if((decomp[1]=="4")||(decomp[1]=="est-ztdgrad")) ui->TropoptBox->setCurrentIndex(4);
            else std::cout<<"Valeur de <pos1-tropopt> incomprise"<<std::endl;
        }
        else if(decomp[0]=="pos1-sateph")
        {
            if((decomp[1]=="0")||(decomp[1]=="brdc")) ui->SatephBox->setCurrentIndex(0);
            else if((decomp[1]=="1")||(decomp[1]=="precise")) ui->SatephBox->setCurrentIndex(1);
            else if((decomp[1]=="2")||(decomp[1]=="brdc+sbas")) ui->SatephBox->setCurrentIndex(2);
            else if((decomp[1]=="3")||(decomp[1]=="brdc+ssrapc")) ui->SatephBox->setCurrentIndex(3);
            else if((decomp[1]=="4")||(decomp[1]=="brdc+ssrcom")) ui->SatephBox->setCurrentIndex(4);
            else std::cout<<"Valeur de <pos1-sateph> incomprise"<<std::endl;
        }
        else if(decomp[0]=="pos1-posopt1")
        {
            if((decomp[1]=="0")||(decomp[1]=="off")) ui->Posopt1CheckBox->setChecked(false);
            else if((decomp[1]=="1")||(decomp[1]=="on")) ui->Posopt1CheckBox->setChecked(true);
            else std::cout<<"Valeur de <pos1-posopt1> incomprise"<<std::endl;
        }
        else if(decomp[0]=="pos1-posopt2")
        {
            if((decomp[1]=="0")||(decomp[1]=="off")) ui->Posopt2CheckBox->setChecked(false);
            else if((decomp[1]=="1")||(decomp[1]=="on")) ui->Posopt2CheckBox->setChecked(true);
            else std::cout<<"Valeur de <pos1-posopt2> incomprise"<<std::endl;
        }
        else if(decomp[0]=="pos1-posopt3")
        {
            if((decomp[1]=="0")||(decomp[1]=="off")) ui->Posopt3CheckBox->setChecked(false);
            else if((decomp[1]=="1")||(decomp[1]=="on")) ui->Posopt3CheckBox->setChecked(true);
            else std::cout<<"Valeur de <pos1-posopt3> incomprise"<<std::endl;
        }
        else if(decomp[0]=="pos1-posopt4")
        {
            if((decomp[1]=="0")||(decomp[1]=="off")) ui->Posopt4CheckBox->setChecked(false);
            else if((decomp[1]=="1")||(decomp[1]=="on")) ui->Posopt4CheckBox->setChecked(true);
            else std::cout<<"Valeur de <pos1-posopt4> incomprise"<<std::endl;
        }
        else if(decomp[0]=="pos1-posopt5")
        {
            if((decomp[1]=="0")||(decomp[1]=="off")) ui->Posopt5CheckBox->setChecked(false);
            else if((decomp[1]=="1")||(decomp[1]=="on")) ui->Posopt5CheckBox->setChecked(true);
            else std::cout<<"Valeur de <pos1-posopt5> incomprise"<<std::endl;
        }
        else if(decomp[0]=="pos1-exclsats") ui->ExclsatsLine->setText(decomp[1]);
        else if(decomp[0]=="pos1-navsys")
        {
            int i=decomp[1].toInt();
            if (i>=32)
            {
                ui->NavsysBeiDouCheckBox->setChecked(true);
                i-=32;
            }
            else ui->NavsysBeiDouCheckBox->setChecked(false);
            if (i>=16)
            {
                ui->NavsysQZSSCheckBox->setChecked(true);
                i-=16;
            }
            else ui->NavsysQZSSCheckBox->setChecked(false);
            if (i>=8)
            {
                ui->NavsysGalileoCheckBox->setChecked(true);
                i-=8;
            }
            else ui->NavsysGalileoCheckBox->setChecked(false);
            if (i>=4)
            {
                ui->NavsysGLONASSCheckBox->setChecked(true);
                i-=4;
            }
            else ui->NavsysGLONASSCheckBox->setChecked(false);
            if (i>=2)
            {
                ui->NavsysSBASCheckBox->setChecked(true);
                i-=2;
            }
            else ui->NavsysSBASCheckBox->setChecked(false);
            if (i>=1)
            {
                ui->NavsysGPSCheckBox->setChecked(true);
            }
            else ui->NavsysGPSCheckBox->setChecked(false);
        }
        else if(decomp[0]=="pos2-armode")
        {
            if((decomp[1]=="0")||(decomp[1]=="off")) ui->ArmodeBox->setCurrentIndex(0);
            else if((decomp[1]=="1")||(decomp[1]=="continuous")) ui->ArmodeBox->setCurrentIndex(1);
            else if((decomp[1]=="2")||(decomp[1]=="instantaneous")) ui->ArmodeBox->setCurrentIndex(2);
            else if((decomp[1]=="3")||(decomp[1]=="fix-and-hold")) ui->ArmodeBox->setCurrentIndex(3);
            else std::cout<<"Valeur de <pos2-armode> incomprise"<<std::endl;
        }
        else if(decomp[0]=="pos2-gloarmode")
        {
            if((decomp[1]=="0")||(decomp[1]=="off")) ui->GloarmodeBox->setCurrentIndex(0);
            else if((decomp[1]=="1")||(decomp[1]=="on")) ui->GloarmodeBox->setCurrentIndex(1);
            else if((decomp[1]=="2")||(decomp[1]=="autocal")) ui->GloarmodeBox->setCurrentIndex(2);
            else std::cout<<"Valeur de <pos2-gloarmode> incomprise"<<std::endl;
        }
        else if(decomp[0]=="pos2-arthres") ui->ArthresBox->setEditText(decomp[1]);
        else if(decomp[0]=="pos2-arlockcnt") ui->ArlockcntBox->setEditText(decomp[1]);
        else if(decomp[0]=="pos2-arelmask") ui->ArelmaskBox->setEditText(decomp[1]);
        else if(decomp[0]=="pos2-arminfix") ui->ArminfixBox->setEditText(decomp[1]);
        else if(decomp[0]=="pos2-elmaskhold") ui->ElmaskBox->setEditText(decomp[1]);
        else if(decomp[0]=="pos2-aroutcnt") ui->AroutcntBox->setEditText(decomp[1]);
        else if(decomp[0]=="pos2-slipthres") ui->SlipthresBox->setEditText(decomp[1]);
        else if(decomp[0]=="pos2-maxage") ui->MaxageBox->setEditText(decomp[1]);
        else if(decomp[0]=="pos2-rejgdop") ui->RejgdopBox->setEditText(decomp[1]);
        else if(decomp[0]=="pos2-rejionno") ui->RejionnoBox->setEditText(decomp[1]);
        else if(decomp[0]=="pos2-niter") ui->NiterBox->setEditText(decomp[1]);
        else if(decomp[0]=="pos2-baselen") ui->BaselenLine->setText(decomp[1]);
        else if(decomp[0]=="pos2-basesig") ui->BasesigLine->setText(decomp[1]);

        else if(decomp[0]=="inpstr1-type")
        {
            if((decomp[1]=="0")||(decomp[1]=="off")) ui->Inpstrtype1Box->setCurrentIndex(0);
            else if((decomp[1]=="1")||(decomp[1]=="serial")) ui->Inpstrtype1Box->setCurrentIndex(1);
            else if((decomp[1]=="2")||(decomp[1]=="file")) ui->Inpstrtype1Box->setCurrentIndex(2);
            else if((decomp[1]=="3")||(decomp[1]=="ntripcli")) ui->Inpstrtype1Box->setCurrentIndex(3);
            else std::cout<<"Valeur de <inpstr1-type> incomprise"<<std::endl;
        }

        else if(decomp[0]=="inpstr1-path")
        {
            QStringList path = decomp[1].split(":");
            ui->SerialPort1Box->setEditText(path[0]);
            ui->Baudrate1Box->setEditText(path[1]);
        }


        else if(decomp[0]=="inpstr2-type")
        {
            if((decomp[1]=="0")||(decomp[1]=="off")) ui->Inpstrtype2Box->setCurrentIndex(0);
            else if((decomp[1]=="1")||(decomp[1]=="serial")) ui->Inpstrtype2Box->setCurrentIndex(1);
            else if((decomp[1]=="2")||(decomp[1]=="file")) ui->Inpstrtype2Box->setCurrentIndex(2);
            else if((decomp[1]=="3")||(decomp[1]=="ntripcli")) ui->Inpstrtype2Box->setCurrentIndex(3);
            else std::cout<<"Valeur de <inpstr2-type> incomprise"<<std::endl;
        }

        else if((decomp[0]=="inpstr2-path")&&(decomp[1].size()>0))
        {
            if (decomp[1].contains(":8:n:1:off"))
            {
                QStringList path = decomp[1].split(":");
                ui->SerialPort2Box->setEditText(path[0]);
                ui->Baudrate2Box->setEditText(path[1]);
            }

            else if(decomp[1].contains("/media")) ui->Impstr2PathBox->setText(decomp[1]);
                 if(decomp[1].contains("@")) ui->Impstr2StreamBox->setText(decomp[1]);                }


        else if(decomp[0]=="inpstr3-type")
        {
            if((decomp[1]=="0")||(decomp[1]=="off")) ui->Inpstrtype3Box->setCurrentIndex(0);
            else if((decomp[1]=="1")||(decomp[1]=="serial")) ui->Inpstrtype3Box->setCurrentIndex(1);
            else if((decomp[1]=="2")||(decomp[1]=="file")) ui->Inpstrtype3Box->setCurrentIndex(2);
            else if((decomp[1]=="3")||(decomp[1]=="ntripcli")) ui->Inpstrtype3Box->setCurrentIndex(3);
            else std::cout<<"Valeur de <inpstr3-type> incomprise"<<std::endl;
        }

        else if((decomp[0]=="inpstr3-path")&&(decomp[1].size()>0))
        {
             if (decomp[1].contains(":8:n:1:off"))
            {
                QStringList path = decomp[1].split(":");
                ui->SerialPort3Box->setEditText(path[0]);
                ui->Baudrate3Box->setEditText(path[1]);

            }


             else if(decomp[1].contains("/media")) ui->Impstr3PathBox->setText(decomp[1]);
                  if(decomp[1].contains("@")) ui->Impstr3StreamBox->setText(decomp[1]);                }






        else if(decomp[0]=="inpstr1-format") ui->Inpstr1formatBox->setEditText(decomp[1]);
        else if(decomp[0]=="inpstr2-format") ui->Inpstr2formatBox->setEditText(decomp[1]);
        else if(decomp[0]=="inpstr3-format") ui->Inpstr3formatBox->setEditText(decomp[1]);

        else if(decomp[0]=="outstr1-type")
        {
            if((decomp[1]=="0")||(decomp[1]=="off")) ui->Outstr1typeBox->setCurrentIndex(0);
            else if((decomp[1]=="1")||(decomp[1]=="serial")) ui->Outstr1typeBox->setCurrentIndex(1);
            else if((decomp[1]=="2")||(decomp[1]=="file")) ui->Outstr1typeBox->setCurrentIndex(2);
            else std::cout<<"Valeur de <outstr1-type> incomprise"<<std::endl;
        }

        else if(decomp[0]=="outstr2-type")
        {
            if((decomp[1]=="0")||(decomp[1]=="off")) ui->OutstrtypeBox2->setCurrentIndex(0);
            else if((decomp[1]=="1")||(decomp[1]=="serial")) ui->OutstrtypeBox2->setCurrentIndex(1);
            else if((decomp[1]=="2")||(decomp[1]=="file")) ui->OutstrtypeBox2->setCurrentIndex(2);
            else std::cout<<"Valeur de <outstr1-type> incomprise"<<std::endl;
        }

        else if((decomp[0]=="outstr1-path")&&(decomp[1].size()>0))
        {
            if (decomp[1].contains(":"))
            {
                QStringList path = decomp[1].split(":");
                ui->SerialPortOutBox->setEditText(path[0]);
                ui->BaudrateOutBox->setEditText(path[1]);
            }
            else
                ui->Outstr1PathBox->setText(decomp[1]);
        }

        else if((decomp[0]=="outstr2-path")&&(decomp[1].size()>0))
        {
            if (decomp[1].contains(":"))
            {
                QStringList path = decomp[1].split(":");
                ui->SerialPortOutBox2->setEditText(path[0]);
                ui->BaudrateOutBox2->setEditText(path[1]);
            }
            else
                ui->Outstr1PathBox2->setText(decomp[1]);
        }



        else if(decomp[0]=="outstr1-format") ui->OutstrformatBox->setEditText(decomp[1]);
        else if(decomp[0]=="outstr2-format") ui->OutstrformatBox2->setEditText(decomp[1]);

        else if(decomp[0]=="logstr1-type")
        {
            if((decomp[1]=="0")||(decomp[1]=="off")) ui->Logstr1typeBox->setCurrentIndex(0);
            else if((decomp[1]=="2")||(decomp[1]=="file")) ui->Logstr1typeBox->setCurrentIndex(1);
            else std::cout<<"Valeur de <logstr1-type> incomprise"<<std::endl;
        }

        else if(decomp[0]=="logstr2-type")
        {
            if((decomp[1]=="0")||(decomp[1]=="off")) ui->Logstr1typeBox2->setCurrentIndex(0);
            else if((decomp[1]=="2")||(decomp[1]=="file")) ui->Logstr1typeBox2->setCurrentIndex(1);
            else std::cout<<"Valeur de <logstr2-type> incomprise"<<std::endl;
        }

        else if(decomp[0]=="logstr3-type")
        {
            if((decomp[1]=="0")||(decomp[1]=="off")) ui->Logstr1typeBox3->setCurrentIndex(0);
            else if((decomp[1]=="2")||(decomp[1]=="file")) ui->Logstr1typeBox3->setCurrentIndex(1);
            else std::cout<<"Valeur de <logstr3-type> incomprise"<<std::endl;
        }



        else if(decomp[0]=="logstr1-path") ui->Logstr1PathBox->setText(decomp[1]);
        else if(decomp[0]=="logstr2-path") ui->Logstr1PathBox2->setText(decomp[1]);
        else if(decomp[0]=="logstr3-path") ui->Logstr1PathBox3->setText(decomp[1]);



        else if(decomp[0]=="out-solformat")
        {
            if((decomp[1]=="0")||(decomp[1]=="llh")) ui->SolformatBox->setCurrentIndex(0);
            else if((decomp[1]=="1")||(decomp[1]=="xyz")) ui->SolformatBox->setCurrentIndex(1);
            else if((decomp[1]=="2")||(decomp[1]=="enu")) ui->SolformatBox->setCurrentIndex(2);
            else if((decomp[1]=="3")||(decomp[1]=="nmea")) ui->SolformatBox->setCurrentIndex(3);
            else std::cout<<"Valeur de <out_solformat> incomprise"<<std::endl;
        }
        else if(decomp[0]=="out-outstat")
        {
            if((decomp[1]=="0")||(decomp[1]=="off")) ui->OutstatBox->setCurrentIndex(0);
            else if((decomp[1]=="1")||(decomp[1]=="state")) ui->OutstatBox->setCurrentIndex(1);
            else if((decomp[1]=="2")||(decomp[1]=="residual")) ui->OutstatBox->setCurrentIndex(2);
            else std::cout<<"Valeur de <out-outstat> incomprise"<<std::endl;
        }
        else if(decomp[0]=="out-outhead")
        {
            if((decomp[1]=="0")||(decomp[1]=="off")) ui->OutheadBox->setCurrentIndex(0);
            else if((decomp[1]=="1")||(decomp[1]=="on")) ui->OutheadBox->setCurrentIndex(1);
            else std::cout<<"Valeur de <out-outhead> incomprise"<<std::endl;
        }
        else if(decomp[0]=="out-tymesys")
        {
            if((decomp[1]=="0")||(decomp[1]=="gpst"))
            {
                if (timeform==0) ui->TimesysBox->setCurrentIndex(0);
                else if (timeform==1) ui->TimesysBox->setCurrentIndex(1);
                else timesys=0;
            }
            else if((decomp[1]=="1")||(decomp[1]=="utc")) ui->TimesysBox->setCurrentIndex(2);
            else if((decomp[1]=="2")||(decomp[1]=="jst")) ui->TimesysBox->setCurrentIndex(3);
            else std::cout<<"Valeur de <out-timesys> incomprise"<<std::endl;
        }
        else if(decomp[0]=="out-timeform")
        {
            if(timesys==0)
            {
                if ((decomp[1]=="0")||(decomp[1]=="tow")) ui->TimesysBox->setCurrentIndex(0);
                else if ((decomp[1]=="1")||(decomp[1]=="hms")) ui->TimesysBox->setCurrentIndex(1);
                else std::cout<<"Valeur de <out-timeform> incomprise"<<std::endl;
            }
            else if ((decomp[1]=="0")||(decomp[1]=="tow")) timeform=0;
            else if ((decomp[1]=="1")||(decomp[1]=="hms")) timeform=1;
            else std::cout<<"Valeur de <out-timeform> incomprise"<<std::endl;
        }
        else if(decomp[0]=="out-timendec") ui->TimendecBox->setEditText(decomp[1]);
        else if(decomp[0]=="out-degform")
        {
            if((decomp[1]=="0")||(decomp[1]=="deg")) ui->DegformBox->setCurrentIndex(0);
            else if((decomp[1]=="1")||(decomp[1]=="dms")) ui->DegformBox->setCurrentIndex(1);
            else std::cout<<"Valeur de <out-degform> incomprise"<<std::endl;
        }
        else if(decomp[0]=="out-fieldsep") ui->FieldsepBox->setText(decomp[1]);
        else if(decomp[0]=="out-height")
        {
            if((decomp[1]=="0")||(decomp[1]=="ellipsoidal")) ui->HeightBox->setCurrentIndex(0);
            else if((decomp[1]=="1")||(decomp[1]=="geodetic")) ui->HeightBox->setCurrentIndex(1);
            else std::cout<<"Valeur de <out-height> incomprise"<<std::endl;
        }
        else if(decomp[0]=="out-geoid") ui->GeoidBox->setEditText(decomp[1]);
        else if(decomp[0]=="out-nmeaintv1") ui->Nmeaintv1Box->setText(decomp[1]);
        else if(decomp[0]=="out-nmeaintv2") ui->Nmeaintv2Box->setText(decomp[1]);
        else if(decomp[0]=="stats-eratio1") ui->Eratio1Box->setEditText(decomp[1]);
        else if(decomp[0]=="stats-eratio2") ui->Eratio2Box->setEditText(decomp[1]);
        else if(decomp[0]=="stats-errphase") ui->ErrphaseBox->setEditText(decomp[1]);
        else if(decomp[0]=="stats-errphaseel") ui->ErrphaseelBox->setEditText(decomp[1]);
        else if(decomp[0]=="stats-errphasebl") ui->ErrphaseblBox->setEditText(decomp[1]);
        else if(decomp[0]=="stats-errdoppler") ui->ErrdopplerBox->setEditText(decomp[1]);
        else if(decomp[0]=="stats-prnaccelh") ui->PrnaccelhBox->setEditText(decomp[1]);
        else if(decomp[0]=="stats-prnaccelv") ui->PrnaccelvBox->setEditText(decomp[1]);
        else if(decomp[0]=="stats-prnbias") ui->PrnbiasBox->setEditText(decomp[1]);
        else if(decomp[0]=="stats-prtrop") ui->PrntropBox->setEditText(decomp[1]);
        else if(decomp[0]=="stats-prniono") ui->PrnionoBox->setEditText(decomp[1]);
        else if(decomp[0]=="stats-clkstab") ui->ClckstabBox->setEditText(decomp[1]);
        else if(decomp[0]=="file-satantfile") ui->SatantfileBox->setText(decomp[1]);
        else if(decomp[0]=="file-rcvantfile") ui->RcvantfileBox->setText(decomp[1]);
        else if(decomp[0]=="file-geoidfile") ui->GeoidfileBox->setText(decomp[1]);
        else if(decomp[0]=="file-dcbfile") ui->DcbfileBox->setText(decomp[1]);
        else if(decomp[0]=="file-eopfile") ui->EopfileBox->setText(decomp[1]);
        else if(decomp[0]=="file-blqfile") ui->BlqfileBox->setText(decomp[1]);
        else if(decomp[0]=="file-tempdir") ui->TempdirBox->setText(decomp[1]);
        else if(decomp[0]=="ant1-postype")
        {
            if((decomp[1]=="0")||(decomp[1]=="llh")) ui->RovpostypeBox->setCurrentIndex(0);
            else if((decomp[1]=="1")||(decomp[1]=="xyz")) ui->RovpostypeBox->setCurrentIndex(1);
            else if((decomp[1]=="2")||(decomp[1]=="single")) ui->RovpostypeBox->setCurrentIndex(2);
            else if((decomp[1]=="3")||(decomp[1]=="posfile")) ui->RovpostypeBox->setCurrentIndex(3);
            else if((decomp[1]=="4")||(decomp[1]=="rinexhead")) ui->RovpostypeBox->setCurrentIndex(4);
            else if((decomp[1]=="5")||(decomp[1]=="rtcm")) ui->RovpostypeBox->setCurrentIndex(5);
            else std::cout<<"Valeur de <ant1-postype> incomprise"<<std::endl;
        }
        else if(decomp[0]=="ant1-pos1") ui->Rovpos1Box->setText(decomp[1]);
        else if(decomp[0]=="ant1-pos2") ui->Rovpos2Box->setText(decomp[1]);
        else if(decomp[0]=="ant1-pos3") ui->Rovpos3Box->setText(decomp[1]);
        else if(decomp[0]=="ant1-anttype")
        {
            ui->RovanttypeBox->setEditText(decomp[1]);
            if (decomp[1]!="") ui->RovantCheckBox->setChecked(true);
            else ui->RovantCheckBox->setChecked(false);
        }
        else if(decomp[0]=="ant1-antdele") ui->RovantdeleBox->setText(decomp[1]);
        else if(decomp[0]=="ant1-antdeln") ui->RovantdelnBox->setText(decomp[1]);
        else if(decomp[0]=="ant1-antdelu") ui->RovantdeluBox->setText(decomp[1]);
        else if(decomp[0]=="ant2-postype")
        {
            if((decomp[1]=="0")||(decomp[1]=="llh")) ui->BspostypeBox->setCurrentIndex(0);
            else if((decomp[1]=="1")||(decomp[1]=="xyz")) ui->BspostypeBox->setCurrentIndex(1);
            else if((decomp[1]=="2")||(decomp[1]=="single")) ui->BspostypeBox->setCurrentIndex(2);
            else if((decomp[1]=="3")||(decomp[1]=="posfile")) ui->BspostypeBox->setCurrentIndex(3);
            else if((decomp[1]=="4")||(decomp[1]=="rinexhead")) ui->BspostypeBox->setCurrentIndex(4);
            else if((decomp[1]=="5")||(decomp[1]=="rtcm")) ui->BspostypeBox->setCurrentIndex(5);
            else std::cout<<"Valeur de <ant2-postype> incomprise"<<std::endl;
        }
        else if(decomp[0]=="ant2-pos1") ui->Bspos1Box->setText(decomp[1]);
        else if(decomp[0]=="ant2-pos2") ui->Bspos2Box->setText(decomp[1]);
        else if(decomp[0]=="ant2-pos3") ui->Bspos3Box->setText(decomp[1]);
        else if(decomp[0]=="ant2-anttype")
        {
            ui->BsanttypeBox->setEditText(decomp[1]);
            if (decomp[1]!="") ui->BsantCheckBox->setChecked(true);
            else ui->BsantCheckBox->setChecked(false);
        }
        else if(decomp[0]=="ant2-antdele") ui->BsantdeleBox->setText(decomp[1]);
        else if(decomp[0]=="ant2-antdeln") ui->BsantdelnBox->setText(decomp[1]);
        else if(decomp[0]=="ant2-antdelu") ui->BsantdeluBox->setText(decomp[1]);
        else if(decomp[0]=="mysc-svrcycle") ui->SvrcycleBox->setEditText(decomp[1]);
        else if(decomp[0]=="mysc-buffsize") ui->BuffsizeBox->setEditText(decomp[1]);
        else if(decomp[0]=="mysc-timeout") ui->TimeoutBox->setEditText(decomp[1]);
        else if(decomp[0]=="mysc-reconnect") ui->ReconnectBox->setEditText(decomp[1]);
        else if(decomp[0]=="mysc-nmeacycle") ui->NmeacycleBox->setEditText(decomp[1]);
        else if(decomp[0]=="mysc-fswapmargin") ui->FswapmarginBox->setEditText(decomp[1]);
        else if(decomp[0]=="mysc-navmsgsel")
        {
            if((decomp[1]=="0")||(decomp[1]=="all")) ui->NavmsgselBox->setCurrentIndex(0);
            else if((decomp[1]=="1")||(decomp[1]=="rover")) ui->NavmsgselBox->setCurrentIndex(1);
            else if((decomp[1]=="2")||(decomp[1]=="base")) ui->NavmsgselBox->setCurrentIndex(2);
            else if((decomp[1]=="3")||(decomp[1]=="corr")) ui->NavmsgselBox->setCurrentIndex(3);
            else std::cout<<"Valeur de <mysc-navmsgsel> incomprise"<<std::endl;
        }
        else if(decomp[0]=="mysc-proxyadr") ui->ProxyadrBox->setText(decomp[1]);
        else if(decomp[0]=="mysc-sbasatsel") ui->SbasatselBox->setText(decomp[1]);
    }
    ChangePosMode(ui->PosmodeBox->currentIndex());
    ChangeSolFormat(ui->SolformatBox->currentIndex());
    ChangeInpstrtype2(ui->Inpstrtype2Box->currentIndex());
    ChangeInpstrtype3(ui->Inpstrtype3Box->currentIndex());
    ChangeOutstr1type(ui->Outstr1typeBox->currentIndex());
    ChangeLogstr1type(ui->Logstr1typeBox->currentIndex());
}
