#ifndef OPTIONSSAUVEPOINTS_H
#define OPTIONSSAUVEPOINTS_H

#include <QDialog>

namespace Ui {
class optionssauvepoints;
}

class optionssauvepoints : public QDialog
{
    Q_OBJECT

public:
    explicit optionssauvepoints(QString filePath = "",QString pointName ="", int nummeas = 1, float cyclen = 1, int oldpoint = 0,QString EPSG ="",bool AddGeoid =0,QString GeoidPath ="",QWidget *parent = 0);
    ~optionssauvepoints();

private:
    Ui::optionssauvepoints *ui;

public slots:
    void ChoixFilepath();
    void GeoidFilePath();
    void Cancel();
    void Save();

signals:
    void SaveOptions(QStringList);
};

#endif // OPTIONSSAUVEPOINTS_H
