#ifndef AFFICHAGERESULTAT_H
#define AFFICHAGERESULTAT_H

#include <QWidget>
#include <QMainWindow>
#include <database.h>
#include <QSqlQuery>
#include <QTableWidget>
#include <QSqlTableModel>

namespace Ui {
class affichageResultat;
}

class affichageResultat : public QMainWindow
{
    Q_OBJECT

public:
    explicit affichageResultat(QWidget *parent = nullptr);
    ~affichageResultat();
    void afficherResultat();

private:
    Ui::affichageResultat *ui;
};

#endif // AFFICHAGERESULTAT_H
