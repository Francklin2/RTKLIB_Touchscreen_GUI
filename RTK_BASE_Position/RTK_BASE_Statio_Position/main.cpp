#include <QApplication>
#include <processing.h>

#include"mymessagehandler.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow ww;
    ww.show();
    //processing();

    return a.exec();
}
