#include "affichageresultat.h"
#include "ui_affichageresultat.h"

affichageResultat::affichageResultat(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::affichageResultat)
{
    ui->setupUi(this);
}

affichageResultat::~affichageResultat()
{
    delete ui;
}



void affichageResultat::afficherResultat()
{
    QSqlQueryModel *model = new QSqlQueryModel;

    model->setQuery("SELECT * FROM partie ");
    ui->tableView->setModel(model);


}
