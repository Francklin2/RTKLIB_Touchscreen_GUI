#include "affichesolutions.h"
#include "ui_affichesolutions.h"
#include "magraphicsscene.h"
#include "MainThread.h"
#include "options1.h"
#include "options2.h"
#include "optionssauvepoints.h"
#include <iostream>
#include <stdlib.h>
#include <QtCore>
#include <QFileDialog>
#include <QDebug>
#include <QString>
#include <stdlib.h>
#include <QThread>
#include <QGraphicsTextItem>
#include <cmath>
#include <QMessageBox>
#include <QTime>
#include <QDate>




#define PI 3.14159265

using namespace std;




AfficheSolutions::AfficheSolutions(QString _configFile, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AfficheSolutions),SatStatusSingleRover()
{



    configFile=_configFile;

    std::string str1 = configFile.toStdString(); // transform to string.
    //std::cout<<str1<<std::endl;
    ui->setupUi(this);
    ui->AfficheSolutionsgraphicsView->setScene(&SatStatusSingleRover);
    ui->AfficheSolutionsgraphicsView->setStyleSheet("background:transparent");

    /*Displays in FullScreen*/
    this->setWindowFlags(Qt::Window);
    this->showFullScreen();

    QObject::connect(&SatStatusSingleRover,SIGNAL(SignalMouseMagraphicsScene(bool)),this,SLOT(OuvreOptions2()));


    /*Options settings for RTKRCV.c*/
    std::vector<std::string> args={"carlepremierargtoujorsleprog", "-s","-o",str1};
    m_t->setArgcArgv(args);

    /*This with t MainThread connections*/
    QObject::connect(this,SIGNAL(typeAffichageEmit(int)),m_t,SLOT(afficheRtkrcvsatellite(int)));//launch MainThread functions depending on user choice
    QObject::connect(m_t,SIGNAL(emitdonneesStatus(QStringList)),this,SLOT(recupedonneesStatus(QStringList)));
    QObject::connect(m_t,SIGNAL(emitdonneesSatellites(QStringList,int)),this,SLOT(recupedonneesSatellites(QStringList,int)));
    QObject::connect(m_t,SIGNAL(emitdonneesStream(QStringList,int)),this,SLOT(recupedonneesStream(QStringList,int)));
    QObject::connect(m_t,SIGNAL(etatFermetureVT(bool)),this,SLOT(finThread(bool)));

    /*Buttons connections*/
    QObject::connect(ui->pushButtonXYZ,SIGNAL(clicked()),this,SLOT(unitchoice1()));
    QObject::connect(ui->pushButtonLLH,SIGNAL(clicked()),this,SLOT(unitchoice2()));
    QObject::connect(ui->pushButtonSat1,SIGNAL(clicked()),this,SLOT(satchoice1()));
    QObject::connect(ui->pushButtonSat2,SIGNAL(clicked()),this,SLOT(satchoice2()));
    QObject::connect(ui->pushButtonSat3,SIGNAL(clicked()),this,SLOT(satchoice3()));

    QObject::connect(ui->pushButtonSetSYSTime,SIGNAL(clicked()),m_t,SLOT(setSYStime()));


    QObject::connect(ui->PushButtonSauvegarde,SIGNAL(clicked()),m_t,SLOT(saveposition()));
    QObject::connect(ui->PushButtonSauveOptions,SIGNAL(clicked()),this,SLOT(sauvegardeoptions()));
    QObject::connect(m_t,SIGNAL(savePointNbr(QString)),this,SLOT(affichePointNbr(QString)));


    /*MainThread start*/
    m_t->start();
    initAffichage();
}


AfficheSolutions::~AfficheSolutions()
{
    delete ui;
}

/*Open "Options2": choice of solution display*/
void AfficheSolutions::OuvreOptions2()
{
    QObject::connect(&Options2Rover,SIGNAL(Options2emit(int)),this,SLOT(choixVue(int)));

    Options2Rover.setModal(true);
    Options2Rover.setWindowFlags(Qt::FramelessWindowHint);

 //   QSize Options2RoverSize = Options2Rover.sizeHint();
 //   QRect screenRect = QDesktopWidget().screen()->rect();
 //   Options2Rover.move( QPoint( screenRect.width()/2 - Options2RoverSize.width()/2,
   //                               screenRect.height()/2 - Options2RoverSize.height()/2 ) );


    Options2Rover.exec();
}

/*Display windows solution display*/
void AfficheSolutions::choixVue(int i)
{
    cout<<"le chiffre est le: "<<i<<endl;
    if (i==1) ChoixVueSats();
    if (i==2) ChoixVueStatus();
    if (i==3) ChoixVueNavidata();
    if (i==4) FermeTout();
    if (i==5) ChoixVueStream();
    if (i==6) ChoixVueDoneesCom();
}

/*Updating display windows*/
void AfficheSolutions::ChoixVueSats()
{
    emit typeAffichageEmit(11);
    initAffichage();
    SatStatusSingleRover.clear();
    ui->lineEditSatellites->show();
    ui->progressBarSatellites->show();
}
void AfficheSolutions::ChoixVueStatus()
{
    emit typeAffichageEmit(12);
    m_choix=1;
    initAffichage();
    SatStatusSingleRover.clear();
}
void AfficheSolutions::ChoixVueDoneesCom()
{
    emit typeAffichageEmit(12);
    initAffichage();
    m_choix=2;
    SatStatusSingleRover.clear();
}
void AfficheSolutions::ChoixVueNavidata()
{
    emit typeAffichageEmit(13);
    initAffichage();
    SatStatusSingleRover.clear();
    ui->lineEditPosEvol->show();
    ui->widget->show();

    /*---------METTRE UNE CONDITIONS TYPE while points vide NE PAS ACTIVER CETTE OPTIONS CAR SINON PLANTE----*/

    /*generate some data*/
    QVector<double> x(101), y(101); // initialize with entries 0..100
    ui->widget->addGraph();
    if (points.size()!=0)
    {
        for (int i=1; i<points.size(); ++i)
        {
          x[i] = points[i].x();
          y[i] = points[i].y();
        }

    /*create graph*/
    ui->widget->graph(0)->setData(x, y);
    ui->widget->xAxis->setLabel("latitude");
    ui->widget->yAxis->setLabel("longitude");
    ui->widget->xAxis->setRange(x[1]-abs(x[1]-x[points.size()-1]), x[1]+abs(x[1]-x[points.size()-1]));
    ui->widget->yAxis->setRange(y[1]-abs(y[1]-y[points.size()-1]), y[1]+abs(y[1]-y[points.size()-1]));
    ui->widget->replot();
    }
    ui->AfficheSolutionsgraphicsView->setScene(&SatStatusSingleRover);
}

void AfficheSolutions::ChoixVueObserv()
{
    emit typeAffichageEmit(14);
    SatStatusSingleRover.clear();
    SatStatusSingleRover.addRect( 0, 0, 441, 261 );
    ui->AfficheSolutionsgraphicsView->setScene(&SatStatusSingleRover);
}

void AfficheSolutions::ChoixVueStream()
{
    emit typeAffichageEmit(15);
    initAffichage();
    SatStatusSingleRover.clear();
}

void AfficheSolutions::recupedonneesStatus(QStringList i)
{
    std::cout<<"Status"<<std::endl;
    if (m_choix==1)
    {
        //ui->lineEditSatellites->hide();//car vue par défaut et donc ne passe pas par void AfficheSolutions::ChoixVueStatus()
    ui->lineEditStatut->show();
    ui->lineEditPositionXYZ->show();
    ui->lineEditPositionX->show();
    ui->lineEditPositionY->show();
    ui->lineEditPositionZ->show();
    ui->lineEditPositionLLH->show();
    ui->lineEditPositionLat->show();
    ui->lineEditPositionLong->show();
    ui->lineEditPositionH->show();
    ui->lineEditPositioningMode->show();
    ui->lineEditModePosition->show();
    ui->lineEditRunningTime->show();
    ui->lineEditGPSTime->show();
    ui->lineEditSYSTime->show();
    ui->lineEditTimeToRun->show();
    ui->lineEditTimeGPS->show();
    ui->lineEditTimeSYS->show();
    ui->pushButtonSetSYSTime->show();
    ui->lineEditSolutionStatus1->show();
    ui->lineEditSolutionStatus2->show();
    ui->PushButtonSauvegarde->show();
    ui->PushButtonSauveOptions->show();
    ui->MessageUserlineEdit->show();
    ui->lineEditSatRover->show();
    ui->lineEditSatBase->show();
    ui->lineEditSatValides->show();
    ui->pushButtonLLH->show();
    ui->pushButtonXYZ->show();


    if (m_UnitChoice==1)
    {
    ui->lineEditPositionX->setText(QString("X = %1 m").arg(i[1]));
    ui->lineEditPositionY->setText(QString("Y = %1 m").arg(i[2]));
    ui->lineEditPositionZ->setText(QString("Z = %1 m").arg(i[3]));

    ui->lineEditPositionLat->setText(QString("X = %1 m").arg(i[18]));
    ui->lineEditPositionLong->setText(QString("Y = %1 m").arg(i[19]));
    ui->lineEditPositionH->setText(QString("Z = %1 m").arg(i[20]));

    }
    if (m_UnitChoice==2)
    {
    ui->lineEditPositionX->setText(QString("Lat = %1 deg").arg(i[4]));
    ui->lineEditPositionY->setText(QString("Lon = %1 deg").arg(i[5]));
    ui->lineEditPositionZ->setText(QString("H = %1 m").arg(i[6]));

    ui->lineEditPositionLat->setText(QString("X = %1 m").arg(i[18]));
    ui->lineEditPositionLong->setText(QString("Y = %1 m").arg(i[19]));
    ui->lineEditPositionH->setText(QString("Z = %1 m").arg(i[20]));
    }




    ui->lineEditTimeSYS->setText(QString("%1").arg(i[13]));

    ui->lineEditTimeToRun->setText(QString("%1").arg(i[7]));

    ui->lineEditTimeGPS->setText(QString("%1").arg(i[13]));

  QString TimeSYS = (QDate::currentDate().toString("yyyy/MM/dd"));
  TimeSYS.append("  ");
  TimeSYS.append(QTime::currentTime().toString("hh:mm:ss"));
  ui->lineEditTimeSYS->setText(TimeSYS);

  ui->lineEditModePosition->setText(QString("%1").arg(i[8]));
    ui->lineEditSolutionStatus2->setText(QString("%1").arg(i[9]));
    ui->lineEditSatRover->setText(QString("Sat Rover number: %1").arg(i[10]));
    ui->lineEditSatBase->setText(QString("Sat Base number: %1").arg(i[11]));
    ui->lineEditSatValides->setText(QString("Valide Sat number : %1").arg(i[12]));

    bool ok;
    int SatValides =(i[12].toInt(&ok));
    qDebug()<<"conversion réussie:"<<ok<<"--------------------";
    if(SatValides==0)
    {
    ui->MessageUserlineEdit->setText(QString("Searching valides satellites"));
    }
    else
    {
    ui->MessageUserlineEdit->setText(QString(""));
    }
    ui->AfficheSolutionsgraphicsView->setScene(&SatStatusSingleRover);

    QString str=i[4];
    QString str1=i[5];
    str.replace(",",".");// replace la virgule par un point dans le QString pour ensuite convertir
    str1.replace(",",".");
    double x =(str.toDouble(&ok));
    double y=(str1.toDouble(&ok));

    if (x!=0)
    {
        if (m_compteur<101)
            {
            points.append(QPointF(x,y));
            m_compteur ++;
            }
    }

    qDebug()<<points;
    qDebug()<<points.size();

    }

    if (m_choix==2)
    {
             SatStatusSingleRover.clear();
             QGraphicsTextItem *texta[10];
             int b=70;
             for(int j = 0; j < 10; +j++)
             {
                  texta[j]=new QGraphicsTextItem;
                  texta[j]=SatStatusSingleRover.addText(i[14+j], QFont("Monospace",12));
                  texta[j]->setPos(20, b);
                  b=b+30;
             }
    }
}


void AfficheSolutions::recupedonneesSatellites(QStringList i, int a)
{
    SatStatusSingleRover.clear();
    ui->pushButtonSat1->show();
    ui->pushButtonSat2->show();
    ui->pushButtonSat3->show();
    if (m_SatChoice==1)
    {
            QGraphicsTextItem *text[a+1];
            int b=70;
            for(int j = 0; j < a;j=j+3)
                {
                text[j]=new QGraphicsTextItem;
                i[j]=i.at(j)+", azimuth : "+i[j+1]+", elevation : "+i[j+2];
                if (a<24)
                {
                    text[j]=SatStatusSingleRover.addText(i[j], QFont("Monospace",14));
                                    b=b+30;
                }
                if ((a>=24)&&(a<36))
                {
                    text[j]=SatStatusSingleRover.addText(i[j], QFont("Monospace",12));
                    b=b+30;
                }
                if (a>=36)
                {
                    text[j]=SatStatusSingleRover.addText(i[j], QFont("Monospace",9));
                    b=b+20;
                }
                text[j]->setPos(0,b);
                //b=b+30;
                }
    }
    if (m_SatChoice==2)
    {
    QGraphicsTextItem *text[a+1];
    bool ok;
    double x[a];
    QString str[a];
    string cherche = "OK";
    int actual_x=30;
    for(int j = 0; j < a; +j++)
    {
         if (j%3 == 2)
         {
            str[j]=i[j];
            str[j].replace(",",".");// replace la virgule par un point dans le QString pour ensuite convertir
            x[j] =(str[j].toDouble(&ok));

            //addrect(X0,Y0,W,H): X0, Y0=ordonnée à partir de en haut à gauche ici maxy, W=largeur, H=hauteur depuis Y0, donc négatif.
            //if(!i[j-2].contains("-"))   G08 OK
            if(i[j-2].toStdString().find(cherche)==string::npos)
            {
                SatStatusSingleRover.addRect(QRectF(actual_x,350,9,-x[j]*2),QPen(),QBrush(Qt::red));
            }
            else
            {
                SatStatusSingleRover.addRect(QRectF(actual_x,350,9,-x[j]*2),QPen(),QBrush(Qt::green));
            }

            text[j]=new QGraphicsTextItem;
            text[j]=SatStatusSingleRover.addText(i[j-2], QFont("Monospace",8));
            text[j]->setPos(actual_x-20,350-x[j]*2-50);
            text[j+1]=SatStatusSingleRover.addText(i[j], QFont("Monospace",8));
            text[j+1]->setPos(actual_x-20,350-x[j]*2-40);
            actual_x=actual_x+20;
            SatStatusSingleRover.addRect(actual_x+20,350,9,0);  // pour créer espace entre les colonnes
            actual_x=actual_x+20;
         }
    }
    text[a+1]=new QGraphicsTextItem;
    text[a+1]=SatStatusSingleRover.addText("Satellites elevations", QFont("Monospace",14));
    text[a+1]->setPos(50,50);
    }

    if (m_SatChoice==3)
    {
    QGraphicsTextItem *text[a+2];
    bool ok;
    double x[a];
    QString str[a];
    string cherche = "OK";
    double xcentreellipse=400;
    double ycentreellipse=200;
    SatStatusSingleRover.addEllipse(300,100,200,200);//xDuBordGauche,yDuBordGauche,grand axe,petit axe
    for(int j = 0; j < a; +j++)
        {
            if (j%3 == 1)
            {

                str[j]=i[j];
                str[j].replace(",",".");// replace la virgule par un point dans le QString pour ensuite convertir
                x[j] =(str[j].toDouble(&ok));
                x[j]=-x[j];
                QPointF p;
                p += QPointF(400+100*cos(x[j]*PI/180),200+100*sin(x[j]*PI/180));
                SatStatusSingleRover.addLine(xcentreellipse,ycentreellipse,400+100*cos(x[j]*PI/180),200+100*sin(x[j]*PI/180));//x1,y1,x2,y2
                SatStatusSingleRover.addEllipse(xcentreellipse+100*cos(x[j]*PI/180)-5,ycentreellipse+100*sin(x[j]*PI/180),10,10);//xDuBordGauche,yDuBordGauche,grand axe,petit axe
                //SatStatusSingleRover.addEllipse(QPointF(400+100*cos(x[j]*PI/180),200+100*sin(x[j]*PI/180)),10.0,10.0);//xDuBordGauche,yDuBordGauche,grand axe,petit axe
                //http://doc.qt.io/qt-5/qpainterpath.html#addEllipse-2
                text[j]=new QGraphicsTextItem;
                text[j]=SatStatusSingleRover.addText(i[j-1], QFont("Monospace",8));

                if(i[j-1].toStdString().find(cherche)==string::npos)
                {
                    text[j]->setDefaultTextColor(Qt::red);
                }
                else
                {
                    text[j]->setDefaultTextColor(Qt::green);
                }

                if ((x[j]>=-270)&(x[j]<=-90))
                {
                    text[j]->setRotation(x[j]+180);
                }
                else
                {
                    text[j]->setRotation(x[j]);
                }

             text[j]->setPos(400+100*cos(x[j]*PI/180),200+100*sin(x[j]*PI/180));
            }
        }
    text[a+1]=new QGraphicsTextItem;
    text[a+1]=SatStatusSingleRover.addText("Satellites azimuths", QFont("Monospace",14));
    text[a+1]->setPos(50,180);
    text[a+2]=new QGraphicsTextItem;
    text[a+2]=SatStatusSingleRover.addText("Nord", QFont("Monospace",14));
    text[a+2]->setPos(550,180);
    }

    ui->AfficheSolutionsgraphicsView->viewport()->update();
    ui->progressBarSatellites->setValue(a/3);
}

void AfficheSolutions::recupedonneesStream(QStringList i, int a)
{
    ui->lineEditStream->show();
    SatStatusSingleRover.clear();
    QGraphicsTextItem *text[a+1];
    int b=70;
    for(int j = 0; j < a; +j++)
    {
         text[j]=new QGraphicsTextItem;
         text[j]=SatStatusSingleRover.addText(i[j], QFont("Monospace",10));
         text[j]->setPos(20, b);
         b=b+30;
    }
}

void AfficheSolutions::FermeTout()
{
    emit typeAffichageEmit(16);
}

/*Default display*/
void AfficheSolutions::initAffichage()
{
    ui->lineEditStatut->hide();
    ui->lineEditPositionXYZ->hide();
    ui->lineEditPositionX->hide();
    ui->lineEditPositionY->hide();
    ui->lineEditPositionZ->hide();
    ui->lineEditPositionLLH->hide();
    ui->lineEditPositionLat->hide();
    ui->lineEditPositionLong->hide();
    ui->lineEditPositionH->hide();
    ui->lineEditPositioningMode->hide();
    ui->lineEditModePosition->hide();
    ui->lineEditRunningTime->hide();
    ui->lineEditGPSTime->hide();
    ui->lineEditSYSTime->hide();
    ui->pushButtonSetSYSTime->hide();
    ui->lineEditTimeToRun->hide();
    ui->lineEditTimeGPS->hide();
    ui->lineEditTimeSYS->hide();
    ui->lineEditSatellites->hide();
    ui->lineEditSolutionStatus1->hide();
    ui->lineEditSolutionStatus2->hide();
    ui->lineEditStream->hide();
    ui->progressBarSatellites->hide();
    ui->PushButtonSauvegarde->hide();
    ui->PushButtonSauveOptions->hide();
    ui->widget->hide();
    ui->MessageUserlineEdit->hide();
    ui->lineEditSatRover->hide();
    ui->lineEditSatBase->hide();
    ui->lineEditSatValides->hide();
    ui->pushButtonLLH->hide();
    ui->pushButtonXYZ->hide();
    ui->pushButtonSat1->hide();
    ui->pushButtonSat2->hide();
    ui->pushButtonSat3->hide();
    ui->lineEditPosEvol->hide();


}


void AfficheSolutions::affichePointNbr(QString i)
{
    ui->MessageUserlineEdit->setText(QString("Point %1 saved in file").arg(i));
}


void AfficheSolutions::finThread(bool a)
{
    if (a==true)
    {
        m_t->terminate();
        this->close();
    }
}


void AfficheSolutions::unitchoice1()
{
    m_UnitChoice=1;
}

void AfficheSolutions::unitchoice2()
{
    m_UnitChoice=2;
}

void AfficheSolutions::satchoice1()
{
    m_SatChoice=1;
}

void AfficheSolutions::satchoice2()
{
    m_SatChoice=2;
}

void AfficheSolutions::satchoice3()
{
    m_SatChoice=3;
}

void AfficheSolutions::sauvegardeoptions()
{
    optionssauvepoints *FenetreSaveOptions = new optionssauvepoints(m_t->_filePath,m_t->_pointName,m_t->_numOfMeasures,m_t->_cycleLength,m_t->_addMeasures);
    QObject::connect(FenetreSaveOptions,SIGNAL(SaveOptions(QStringList)),m_t,SLOT(changeSaveOptions(QStringList)));
    FenetreSaveOptions->setModal(true);
    FenetreSaveOptions->setWindowFlags(Qt::FramelessWindowHint);
    FenetreSaveOptions->exec();
}

//void AfficheSolutions::setSYSTime()
//{
//    m_UnitChoice=3;
//    emit typeAffichageEmit(12);
//    m_choix=1;
//    QString getGPStime= (QString("%1").arg(i[13]));
//    getGPStime.resize(10);
//    getGPStime.left(10);
//    getGPStime.remove(QRegExp("[/]."));
//    QString getGPSdate = getGPStime;

    //    QString getGPStimeset = getGPStime.right(8);
//    QString setTimeSYS = getGPSdate;
//    setTimeSYS.append(" ");
//    setTimeSYS.append(getGPStimeset);
//    getGPSdate.left(10);
//    getGPSdate.remove(QRegExp("[/]."));
//    QProcess setPIdate;
//    setPIdate.startDetached("sudo date -s "+getGPSdate);
//    setPIdate.startDetached("sudo date -s 20170817");
//    QProcess setPItime;
//    setPItime.startDetached("sudo timedatectl set-time HH:MM:SS 10:10:10");
//}
