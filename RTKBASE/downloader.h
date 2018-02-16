#ifndef DOWNLOADER_H
#define DOWNLOADER_H
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QObject>
#include <QDateTime>
#include <QFile>
#include <QDebug>
#include <QString>
#include <QVector>
#include <QCoreApplication>
#include <QFileInfo>
#include <QProcess>

class Downloader:public QObject
{
    Q_OBJECT
public:
    void do_downloader();
    void unzip_file();

    QString url;
    QString file_name ;
    QString saving_path;
    bool downfailed=false;


private:
    void uncmpress_hatanaka();

};

#endif // DOWNLOADER_H
