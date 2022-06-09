#ifndef AFFICHERRESULTAT_H
#define AFFICHERRESULTAT_H

#include <QDialog>
#include <database.h>
#include <QSqlQuery>
#include <QTableWidget>
#include <QSqlTableModel>

namespace Ui {
class afficherResultat;
}

class afficherResultat : public QDialog
{
    Q_OBJECT

public:
    explicit afficherResultat(QWidget *parent = nullptr);
    ~afficherResultat();
    void resultats();
public slots:
        void effacer();

private:
    Ui::afficherResultat *ui;
    database *bd;
};

#endif // AFFICHERRESULTAT_H
