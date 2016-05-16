#ifndef AFFICHESOLUTIONSSTR2STR_H
#define AFFICHESOLUTIONSSTR2STR_H
#include"MainthreadStr2str.h"
#include "magraphicsscene.h"
#include <QDialog>

namespace Ui {
class AfficheSolutionsStr2str;
}

class AfficheSolutionsStr2str : public QDialog
{
    Q_OBJECT

public:
    explicit AfficheSolutionsStr2str(QWidget *parent = 0);
    ~AfficheSolutionsStr2str();
    MainthreadStr2str* tstr2str=new MainthreadStr2str;
    MaGraphicsScene Str2strGraphicscene;

private:
    Ui::AfficheSolutionsStr2str *ui;

public slots:
    //void OuvreStr2str();

};

#endif // AFFICHESOLUTIONSSTR2STR_H
