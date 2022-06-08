#include "chifoumidialog.h"
#include "ui_chifoumidialog.h"




QString temps;
unsigned int tempsSec;
QString name;
QString points;
unsigned int pointsInt;

chifoumiDialog::chifoumiDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chifoumiDialog)
{
    ui->setupUi(this);
    QObject::connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(infosDialog()));
}

chifoumiDialog::~chifoumiDialog()
{
    delete ui;
}


void chifoumiDialog::infosDialog(){
    name= ui->nom->text();
    temps= ui->temps->text();
    points= ui->points->text();
    bool ok;
    tempsSec=temps.toInt(&ok,10);
    pointsInt=points.toInt(&ok,10);




}
unsigned int chifoumiDialog::dureePartie(){
     return tempsSec;
}
QString chifoumiDialog::nomJoueur(){
    return name;
}
unsigned int chifoumiDialog::pointsMax(){
    return pointsInt;
}
