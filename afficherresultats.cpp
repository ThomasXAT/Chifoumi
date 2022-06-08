#include "afficherresultats.h"
#include "ui_afficherresultats.h"
#include "chifoumi.h"

afficherResultats::afficherResultats(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::afficherResultats)
{
    //ui->setupUi();

}

afficherResultats::~afficherResultats()
{
    delete ui;
}

void afficherResultats::resultats()
{


    QSqlQueryModel *model = new QSqlQueryModel;



    model->setQuery("SELECT * FROM partie");
    ui->tableView->setModel(model);






}
