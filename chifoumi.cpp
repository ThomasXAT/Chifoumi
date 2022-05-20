#include "chifoumi.h"
#include "chifoumiJeu.h"
#include "ui_chifoumi.h"
#include "QShortcut"



ChifoumiJeu monJeu;
QString scoreMachine;
QString scoreJoueur;


chifoumi::chifoumi(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::chifoumi)
{
    ui->setupUi(this);
    QObject::connect(ui->boutonPartie, SIGNAL(clicked()), this, SLOT(nouvellePartie()));
    QObject::connect(ui->pierre, SIGNAL(clicked()), this, SLOT(coupPierre()));
    QObject::connect(ui->feuille, SIGNAL(clicked()), this, SLOT(coupFeuille()));
    QObject::connect(ui->ciseau, SIGNAL(clicked()), this, SLOT(coupCiseau()));
    QObject::connect(ui->actionA_Propos_de_l_application, SIGNAL(triggered()), this, SLOT(infosApp()));
    new QShortcut(QKeySequence(Qt::ALT + Qt::Key_F + Qt::Key_F3), this, SLOT(close()));
    new QShortcut(QKeySequence(Qt::Key_F +Qt::Key_F1), this, SLOT(infosApp()));
    monJeu.initCoups();
    monJeu.initScores();
    scoreJoueur.setNum(monJeu.getScoreJoueur());
    scoreMachine.setNum(monJeu.getScoreMachine());
    ui->scoreJoueur->setText(scoreJoueur);
    ui->scoreMachine->setText(scoreMachine);
    ui->scoreMachine->setFont(QFont("Times", 15, QFont::Bold));
    ui->scoreJoueur->setFont(QFont("Times", 15, QFont::Bold));
    ui->scoreMachine->setAlignment(Qt::AlignCenter);
    ui->scoreJoueur->setAlignment(Qt::AlignCenter);


}

chifoumi::~chifoumi()
{
    delete ui;
}


void chifoumi::nouvellePartie(){
    ui->pierre->setEnabled(true);
    ui->feuille->setEnabled(true);
    ui->ciseau->setEnabled(true);


}
void chifoumi::coupPierre(){
    ui->coupJoueur->setPixmap(QPixmap(QString::fromUtf8(":/chifoumi/images (1)/images/pierre.gif")));
    monJeu.setCoupJoueur(monJeu.pierre);
    coupMachine();
}

void chifoumi::coupCiseau(){
    ui->coupJoueur->setPixmap(QPixmap(QString::fromUtf8(":/chifoumi/images (1)/images/ciseau.gif")));
    monJeu.setCoupJoueur(monJeu.ciseau);
    coupMachine();


}
void chifoumi::coupFeuille(){
    ui->coupJoueur->setPixmap(QPixmap(QString::fromUtf8(":/chifoumi/images (1)/images/papier.gif")));
    monJeu.setCoupJoueur(monJeu.papier);
    coupMachine();
}

void chifoumi::coupMachine(){

    monJeu.setCoupMachine(monJeu.genererUnCoup());
    switch (monJeu.getCoupMachine())
    {
    case (monJeu.pierre):
         ui->coupMachine->setPixmap(QPixmap(QString::fromUtf8(":/chifoumi/images (1)/images/pierre.gif")));
        break;

    case (monJeu.papier):
        ui->coupMachine->setPixmap(QPixmap(QString::fromUtf8(":/chifoumi/images (1)/images/papier.gif")));
        break;

    case (monJeu.ciseau):
       ui->coupMachine->setPixmap(QPixmap(QString::fromUtf8(":/chifoumi/images (1)/images/ciseau.gif")));
        break;
    }
    QString scoreMachine;
    QString scoreJoueur;
     monJeu.majScores(monJeu.determinerGagnant());
     scoreJoueur.setNum(monJeu.getScoreJoueur());
     scoreMachine.setNum(monJeu.getScoreMachine());
     ui->scoreJoueur->setText(scoreJoueur);
     ui->scoreMachine->setText(scoreMachine);
     ui->scoreJoueur->setText(scoreJoueur);
     ui->scoreMachine->setFont(QFont("Times", 15, QFont::Bold));
     ui->scoreJoueur->setFont(QFont("Times", 15, QFont::Bold));
     ui->scoreMachine->setAlignment(Qt::AlignCenter);
     ui->scoreJoueur->setAlignment(Qt::AlignCenter);


}

void chifoumi::infosApp()
{
    QMessageBox infosApp;
    infosApp.setWindowTitle("A propos de l'application");
    infosApp.setInformativeText("Version 3.0\n"
                                "Créé par Thomas Jorge, Poties Guilhem et Gomes Noah\n"
                                "Version du 11/05/2022");
    infosApp.setStandardButtons(QMessageBox::Ok);
    infosApp.exec();
}
