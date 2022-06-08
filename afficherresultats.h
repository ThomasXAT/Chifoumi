#ifndef AFFICHERRESULTATS_H
#define AFFICHERRESULTATS_H

#include <QMainWindow>
#include <database.h>
#include <QSqlQuery>
#include <QTableWidget>
#include <QSqlTableModel>

namespace Ui {
class afficherResultats;
}

class afficherResultats : public QWidget
{
    Q_OBJECT

public:
    explicit afficherResultats(QWidget *parent = nullptr);
    ~afficherResultats();
    void resultats();


private:
    Ui::afficherResultats *ui;
};

#endif // AFFICHERRESULTATS_H
