#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>

namespace Ui {
class MyDialog;
}

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyDialog(QWidget *parent = 0);
    ~MyDialog();

private slots:
    void on_pushButton_run_rnx2rtk_process_RGP_clicked();

    void on_progressBar_valueChanged(int value);

private:
    Ui::MyDialog *ui;
};

#endif // MYDIALOG_H
