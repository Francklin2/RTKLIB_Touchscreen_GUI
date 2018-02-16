#include"mymessagehandler.h"



void myMessageHandler(QtMsgType type, const QMessageLogContext &, const QString & msg)
{
    /*-----------------------------------------------------------------------------/
        - qInstallMessageHandler :Function that prints out debug messages,
        warnings, critical and fatal error messages
        - create a logfille in the work directory
    /-----------------------------------------------------------------------------*/

    QString txt;
    switch (type) {
    case QtDebugMsg:
        txt = QString("Debug: %1").arg(msg);
        break;
    case QtWarningMsg:
        txt = QString("Warning: %1").arg(msg);
    break;
    case QtCriticalMsg:
        txt = QString("Critical: %1").arg(msg);
    break;
    case QtFatalMsg:
        txt = QString("Fatal: %1").arg(msg);
    break;
    }
    QFile outFile("../work/Log_file.txt");
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream ts(&outFile);
    ts << txt << endl;
}
