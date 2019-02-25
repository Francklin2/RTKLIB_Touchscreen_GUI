#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>

#include "mydialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void barstatus(int value);



private slots:

    void on_pushButton_run_clicked();

private:
    Ui::MainWindow *ui;

    MyDialog *mDialog;          // Create a pointer to a MAINWINDOW object
};

#endif // MAINWINDOW_H
