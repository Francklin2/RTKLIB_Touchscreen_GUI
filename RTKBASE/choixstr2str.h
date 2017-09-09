#ifndef CHOIXSTR2STR_H
#define CHOIXSTR2STR_H

#include <QDialog>

namespace Ui {
class ChoixStr2Str;
}

class ChoixStr2Str : public QDialog
{
    Q_OBJECT

public:
    explicit ChoixStr2Str(int _save_load, QWidget *parent = 0);
    ~ChoixStr2Str();
    void DemandeNom(int num, QString name);

private:
    Ui::ChoixStr2Str *ui;
    int save_load;
    int numSauve;
    void SaveBase(QString baseFile);
    void LoadBase(QString baseFile);


public slots:
    void SelectBase1();
    void SelectBase2();
    void SelectBase3();
    void SelectBase4();
    void SelectBase5();
    void SelectBase6();
    void SelectBase7();
    void SelectBase8();
    void SelectBase9();
    void SelectBase10();
    void SelectBase11();
    void SelectBase12();
    void Retour();
    void SauveNom(QString newName);

signals:
    void Charge(QString file);
};

#endif // CHOIXSTR2STR_H
