#ifndef OPTIONSSTR2STR_H
#define OPTIONSSTR2STR_H
#include <QDialog>
#include <QLineEdit>
#include "mylineedit.h"

#include "affichestr2str.h"

extern int PositionMode;
extern QString Outbaudext;
extern QString OutSerialPortext;
extern QString OutFilePathtext;
extern QString OutFormatext;
extern QString Inbaudext;
extern QString InSerialPortext;
extern QString InFormatext;
extern QString RtcmMsgext;





namespace Ui {
class OptionsStr2str;
}

class OptionsStr2str : public QDialog
{
    Q_OBJECT



public:
    explicit OptionsStr2str(QWidget *parent = 0);
    ~OptionsStr2str();
    std::vector<std::string> arga;



private:
    Ui::OptionsStr2str *ui;


public slots:
    void OuvreDefault1();
    void SaveBase();
    void LoadBase();
    void AppelleClavier(MyLineEdit *line);


private slots:


    void on_pushButtonManual_clicked();
    void on_radioButtonPositionAuto_clicked();
    void on_radioButtonPositionManual_clicked();

    void on_UpdateOptionspushButton_clicked();

    void Charge(QString baseFile);
};

#endif // OPTIONSSTR2STR_H
