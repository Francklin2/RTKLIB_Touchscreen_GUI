#ifndef OPTIONSSTR2STR_H
#define OPTIONSSTR2STR_H

#include <QDialog>

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
    void OuvreDefault2();

};

#endif // OPTIONSSTR2STR_H
