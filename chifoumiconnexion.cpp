#include "chifoumiconnexion.h"
#include "ui_chifoumiconnexion.h"
#include "chifoumi.h"
#include "database.h"
#include <QSqlQuery>
#include <QDebug>
#include <QApplication>



QString username;
QString mdp;

QString  mdpBD;
QString usernameBD;


chifoumiConnexion::chifoumiConnexion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chifoumiConnexion)
{
    ui->setupUi(this);


    QObject::connect(ui->boutonEntrer, SIGNAL(clicked()), this, SLOT(infosDialog()));

}

chifoumiConnexion::~chifoumiConnexion()
{
    delete ui;
}


void chifoumiConnexion::infosDialog(){

    username= ui->username->text();
    mdp= ui->mdp->text();
    connexion();


}


bool chifoumiConnexion::connexion()
{
    bd = new database();
    bool ok = bd->openDatabase();
    qDebug()<<ok;
    QSqlQuery query;
    query.exec("SELECT username,mdp FROM connexion");
    while (query.next()){
        usernameBD= query.value(0).toString();
        mdpBD= query.value(1).toString();
    }

    if (usernameBD==username and mdpBD==mdp){
        qDebug() << "CONNEXION REUSSIE";
        return true;



    }
    else{
        qDebug() << "MAUVAISES INFORMATIONS SAISIES";
        chifoumiConnexion win;
        win.show();
        win.exec();
    }
    return false;
    bd->closeDatabase();


}

void chifoumiConnexion::enregistrementPartie(QString nomJoueur, unsigned int scoreJoueur, unsigned int scoreMachine, unsigned int dureePartie)
{
    bd = new database();
    bool ok = bd->openDatabase();
    qDebug()<<ok;
    QSqlQuery query;

    query.prepare("INSERT INTO partie (NOM, ScoreJoueur, ScoreMachine, DureePartie) "
                  "VALUES (:nom, :scoreJ, :scoreM, :duree)");
    query.bindValue(":nom", nomJoueur );
    query.bindValue(":scoreJ", scoreJoueur);
    query.bindValue(":scoreM", scoreMachine);
    query.bindValue(":duree", dureePartie);
    query.exec();
    qDebug()<<"OPERATION D'ENREGISTREMENT REUSSI";
}
