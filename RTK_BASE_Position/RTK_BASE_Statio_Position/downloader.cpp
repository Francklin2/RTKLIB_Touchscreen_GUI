#include "downloader.h"

void Downloader::do_downloader()
{
    /*-------------------------------------------------------------------/
         Aim of the METHOD do_downloader():
            - Check internet connection
            - Download file
                INPUT:
                    - url:          Download link (ftp)
                    - file_name:    Name of the file to download
                    - saving_path:  Path of saving (work directory)

                OUTPUT:
                    - Answer on download status
    /-------------------------------------------------------------------*/

    QNetworkAccessManager manager;
    QNetworkReply *response = manager.get(QNetworkRequest(QUrl(url)));

    QEventLoop event;
        QObject::connect(response, SIGNAL(finished()),&event, SLOT(quit()));
    event.exec();

   if(response->error())
    {
       downfailed = true;
       qDebug() << "ERROR!";
       qDebug() << response->errorString()<<endl;
       return;
    }
    else
    {
        saving_path.append(file_name);
        QFile *file = new QFile(saving_path);
        if(file->open(QFile::WriteOnly))
        {
            file->write(response->readAll());
            file->flush();
            file->close();
            response->deleteLater();
            qDebug()<<"The download of "<<file_name<<" is complete!"<<endl;

        }
        saving_path="../work/";
   }

}

void Downloader::unzip_file()
{
    /*-------------------------------------------------------------------/
         Aim of the METHOD unzip_file():
            - Uncompress the z-files (*.n.Z,*.g.Z and *.d.Z files)
                - Standard uncompressing (zip file)
                - Logic uncompression using uncmpress_hatanaka() METHOD.

            - Uncompress file:
                INPUT:
                    - file_name:    Name of the file to download
                    - saving_path:  Path of saving (work directory)

                OUTPUT:
                    - Uncompressed file
    /-------------------------------------------------------------------*/

    if(QFileInfo("../work/"+file_name).exists())
    {
            QProcess unzip_;
            QString command="uncompress "+saving_path+file_name;
            qDebug()<<command;
            unzip_.start(command);
            unzip_.waitForFinished(-1);
            if (unzip_.state()==0)
            {
                qDebug()<<"----- The standard uncompressing process of "<<file_name<<" finished"<<endl;
                if (file_name[file_name.length()-3]=='d')
                {
                    file_name=file_name.remove(file_name.length()-2,2);
                    uncmpress_hatanaka();
                }
            }
    }
    else
    {
        qDebug()<<"----- The "<<file_name<<" doesn't exist"<<endl;
    }
}




void Downloader::uncmpress_hatanaka()
{
    /*-------------------------------------------------------------------/
         Aim of the uncmpress_hatanaka():
            - Logic uncompression of the station observation file

            - INPUT:
                    - *.d   file
            - OUTPUT:
                    - *.o   file
    /-------------------------------------------------------------------*/
    QString file_name2=file_name;
    if(QFileInfo(saving_path+file_name2.replace(file_name2.length()-1,1,"o")).exists())
    {
        QProcess deleting;
        QString command="rm -f "+saving_path+file_name2;
        deleting.start(command);
        deleting.waitForFinished(-1);

        if (deleting.state()==0)
        {
            qDebug()<<"----- Deleting existing o-file finished"<<endl;
        }

    }

    //"convert d file to o file

    if(QFileInfo(saving_path+file_name).exists())
    {
        QProcess convert_d2o;
        QString command=saving_path+"./CRX2RNX "+saving_path+file_name;
        qDebug()<<command;

        convert_d2o.start(command);
        convert_d2o.waitForFinished(-1);

        if (convert_d2o.state()==0)
        {
            qDebug()<<"----- Hatanaka uncompression of"<<file_name<<" file, done with sucess!"<<endl;
        }
    }
else
    {
        qDebug()<<"----- The"<<file_name<<"doesn't exist"<<endl;
    }

}


