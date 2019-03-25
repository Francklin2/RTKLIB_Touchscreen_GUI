#ifndef MYMESSAGEHANDLER
#define MYMESSAGEHANDLER
#include <QTextStream>
#include <QtGlobal>
#include <QFile>

void myMessageHandler(QtMsgType type, const QMessageLogContext &, const QString & msg);

#endif // MYMESSAGEHANDLER

