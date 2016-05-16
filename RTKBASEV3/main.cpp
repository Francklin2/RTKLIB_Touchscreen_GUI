#include "mainwindow.h"
#include "MainThread.h"
#include <QApplication>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    w.showFullScreen();

    return a.exec();
}
