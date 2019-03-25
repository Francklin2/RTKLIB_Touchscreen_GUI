#ifndef OPTIONSSTARTATBOOT_H
#define OPTIONSSTARTATBOOT_H

#include <QDialog>

namespace Ui {
class optionsstartatboot;
}

class optionsstartatboot : public QDialog
{
    Q_OBJECT

public:
    explicit optionsstartatboot(QWidget *parent = 0);
    ~optionsstartatboot();

private:
    Ui::optionsstartatboot *ui;

public slots:

    void Cancel();
    void Save();

signals:
    void SaveOptions(QStringList);
};

#endif // OPTIONSSTARTATBOOT_H
