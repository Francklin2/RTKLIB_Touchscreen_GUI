#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QVector>
#include "MainthreadStr2str.h"
#include <QtGui>


namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    void AfficheHeureSyst(int);
    void OuvreOptions();
    void OuvreRover();
    void OuvreAfficheSolutiosStr2str();
    void OuvreHelp();
    void Shutdown();

private:
    Ui::MainWindow *ui;



};



#endif // MAINWINDOW_H
