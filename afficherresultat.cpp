#include "afficherresultat.h"
#include "ui_afficherresultat.h"

afficherResultat::afficherResultat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::afficherResultat)
{
    ui->setupUi(this);
}

afficherResultat::~afficherResultat()
{
    delete ui;
}

void afficherResultat::resultats()
{

    bd = new database();
    bool ok = bd->openDatabase();
    QSqlQueryModel *model = new QSqlQueryModel;



    model->setQuery("SELECT * FROM partie");
    ui->tableView->setModel(model);






}
