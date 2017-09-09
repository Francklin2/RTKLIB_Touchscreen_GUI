#ifndef AFFICHESTR2STR_H
#define AFFICHESTR2STR_H
#include "mainthreadreadfile.h"
#include <QDialog>
#include "MainthreadStr2str.h"
#include "magraphicsscene.h"
#include "optionsstr2str.h"

namespace Ui {
class AfficheStr2str;
}

class AfficheStr2str : public QDialog
{
    Q_OBJECT

public:
    explicit AfficheStr2str(std::vector<std::string> arga,QWidget *parent = 0);
    ~AfficheStr2str();


private:
    Ui::AfficheStr2str *ui;
    MainthreadStr2str* m_tstr2str=new MainthreadStr2str;
    MainThreadReadFile* m_readfile=new MainThreadReadFile;
    QString m_str1, m_str2, m_str3;
    std::vector<std::string> args;
    std::vector<std::string> args1;



public slots:
    void recupdonneesStr2str(QStringList);
    void FermeStr2str();
    void finThread(bool);

signals:
    void closeSignal(int);

};

#endif // AFFICHESTR2STR_H
