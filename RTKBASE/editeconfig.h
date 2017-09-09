#ifndef EDITECONFIG_H
#define EDITECONFIG_H

#include <QDialog>

namespace Ui {
class EditeConfig;
}

class EditeConfig : public QDialog
{
    Q_OBJECT

public:
    explicit EditeConfig(QString _modeleFile, QString _configFile,QWidget *parent = 0);
    ~EditeConfig();

private:
    Ui::EditeConfig *ui;
    QString modeleFile;
    QString configFile;
    void Charge(QString filePath);

public slots:
    void Retour();
    void Save();
    void ChangePosMode(int index);
    void ChangeSolFormat(int index);
    void ChangeInpstrtype2(int index);
    void ChangeInpstrtype3(int index);
    void ChangeOutstr1type(int index);
    void ChangeLogstr1type(int index);
    void ChoixSatantfile();
    void ChoixRcvantfile();
    void ChoixGeoidfile();
    void ChoixDCBfile();
    void ChoixEOPfile();
    void ChoixBLQfile();
    void ChoixTempdir();
    void ChoixImpstr2path();
    void ChoixOutstr1path();
    void ChoixLogstr1path();

signals:
    void DemandeRetour();
    void DemandeFerme();
};

#endif // EDITECONFIG_H
