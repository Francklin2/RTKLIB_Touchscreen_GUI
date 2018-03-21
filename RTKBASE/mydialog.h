#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
#include <QLineEdit>

#include "rnx2rtkp.h"

#include "mainthreadreadfile.h"
#include <QDialog>
#include "MainthreadStr2str.h"
#include "magraphicsscene.h"

#include "mylineedit.h"

#include "gpstime.h"
#include "downloader.h"
#include "approxcoord.h"

extern QString Autostart_Base;
extern int debugUI;
extern int Min_station2;


namespace Ui {
class MyDialog;
}

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyDialog(QWidget *parent = 0);
    ~MyDialog();

 int CaptureTimer;
 QVector<int> stat_dist_debug;



private:
Ui::MyDialog *ui;

MainthreadStr2str* m_tstr2str=new MainthreadStr2str;
MainThreadReadFile* m_readfile=new MainThreadReadFile;

MainthreadStr2str* m_tstr2str2=new MainthreadStr2str;
MainThreadReadFile* m_readfile2=new MainThreadReadFile;


std::vector<std::string> args;
std::vector<std::string> args1;
std::vector<std::string> arga;

public slots:
void Run_Log_str2str();
void Run_Base_str2str();
void recupdonneesStr2str(QStringList i);
void FermeStr2str();
void finThread(bool);
void Close_Window();
void Start_AutoPP();
void Test_start();
void Test_stop();
void StopLog();

private slots:
    void on_pushButton_run_rnx2rtk_process_RGP_clicked();
    void on_progressBar_valueChanged(int value);
    void Save_Options();






signals:
    void closeSignal(int);

};

#endif // MYDIALOG_H
