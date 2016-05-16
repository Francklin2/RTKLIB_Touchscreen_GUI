#ifndef OPTIONS2_H
#define OPTIONS2_H

#include <QDialog>

namespace Ui {
class Options2;
}

class Options2 : public QDialog
{
    Q_OBJECT

public:
    explicit Options2(QWidget *parent = 0);
    ~Options2();

private:
    Ui::Options2 *ui;

public slots:
    void emitSat();
    void emitSat1();
    void emitSat2();
    void emitSat4();
    void emitSat5();
    void emitSat6();

signals:
    void Options2emit(int);
};

#endif // OPTIONS2_H
