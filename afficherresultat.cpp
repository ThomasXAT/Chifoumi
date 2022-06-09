#include "afficherresultat.h"
#include "ui_afficherresultat.h"

afficherResultat::afficherResultat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::afficherResultat)
{
    ui->setupUi(this);
    QObject::connect(ui->effacer, SIGNAL(clicked()), this, SLOT(effacer()));
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
void afficherResultat::effacer(){
    QSqlQuery query;
    query.exec("DELETE FROM partie");
    resultats();
}
