#ifndef GESTIONCONFIG_H
#define GESTIONCONFIG_H

#include <QDialog>
#include "choixconfig.h"

namespace Ui {
class GestionConfig;
}

class GestionConfig : public QDialog
{
    Q_OBJECT

public:
    explicit GestionConfig(QWidget *parent = 0);
    ~GestionConfig();

private:
    Ui::GestionConfig *ui;

public slots:
    void OuvreChoixNouveau();
    void OuvreChoixEdit();
    void Retour();
    void Affiche();

signals:
    void DemandeMAJ();

};

#endif // GESTIONCONFIG_H
