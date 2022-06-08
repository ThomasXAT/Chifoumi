#ifndef CHIFOUMICONNEXION_H
#define CHIFOUMICONNEXION_H

#include <QDialog>
#include <database.h>
#include <QSqlQuery>

namespace Ui {
class chifoumiConnexion;
}

class chifoumiConnexion : public QDialog
{
    Q_OBJECT

public:
    explicit chifoumiConnexion(QWidget *parent = nullptr);
    ~chifoumiConnexion();
    bool connexionReussie=false;

private slots:
    void infosDialog();

public slots:
    bool connexion();
    void enregistrementPartie(QString nomJoueur, unsigned int scoreJoueur, unsigned int scoreMachine, unsigned int dureePartie);

private:
    Ui::chifoumiConnexion *ui;
    database *bd;
};

#endif // CHIFOUMICONNEXION_H
