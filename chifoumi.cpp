#include "chifoumi.h"
#include "chifoumiJeu.h"
#include "ui_chifoumi.h"
#include "QShortcut"



ChifoumiJeu monJeu;




chifoumi::chifoumi(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::chifoumi)
{
    ui->setupUi(this);
    QObject::connect(ui->boutonPartie, SIGNAL(clicked()), this, SLOT(nouvellePartie()));
    QObject::connect(ui->pierre, SIGNAL(clicked()), this, SLOT(coupPierre()));
    QObject::connect(ui->feuille, SIGNAL(clicked()), this, SLOT(coupFeuille()));
    QObject::connect(ui->ciseau, SIGNAL(clicked()), this, SLOT(coupCiseau()));
    QObject::connect(ui->BoutonPause, SIGNAL(clicked()), this, SLOT(boutonPause()));
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
    timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(temp()));









}

chifoumi::~chifoumi()
{
    delete ui;
}


void chifoumi::nouvellePartie(){
    ui->pierre->setEnabled(true);
    ui->feuille->setEnabled(true);
    ui->ciseau->setEnabled(true);
    ui->BoutonPause->setEnabled(true);
    monJeu.initScores();
    monJeu.initCoups();
    scoreJoueur.setNum(monJeu.getScoreJoueur());
    scoreMachine.setNum(monJeu.getScoreMachine());
    ui->scoreJoueur->setText(scoreJoueur);
    ui->scoreMachine->setText(scoreMachine);
    sec = 30;
    timer->start();
    temp();



}
void chifoumi::boutonPause(){
     if (Pause==true){
         timer->start();
         ui->BoutonPause->setText("Pause");
         ui->boutonPartie->setEnabled(true);
         ui->pierre->setEnabled(true);
         ui->feuille->setEnabled(true);
         ui->ciseau->setEnabled(true);
         Pause=false;

     }

     else {
         timer->stop();
         ui->boutonPartie->setEnabled(false);
         ui->pierre->setEnabled(false);
         ui->feuille->setEnabled(false);
         ui->ciseau->setEnabled(false);
         ui->BoutonPause->setText("Reprendre la Partie");
         Pause=true;
     }
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
    infosApp.setInformativeText("Version 5.0\n"
                                "Créé par Thomas Jorge, Guilhem Poties et Noah Gomes\n"
                                "Version du 11/05/2022");
    infosApp.setStandardButtons(QMessageBox::Ok);
    infosApp.exec();
}

void chifoumi::finPartieGagnant()
{
    QMessageBox finPartieGagnant;
    finPartieGagnant.setWindowTitle("Fin de Partie");
    if(monJeu.getScoreMachine()>monJeu.getScoreJoueur()){
        gagnant="La machine a gagné avec un score de ";
        gagnant.append( QString::number(monJeu.getScoreMachine()));

        finPartieGagnant.setInformativeText(gagnant);
    }
    if(monJeu.getScoreMachine()<monJeu.getScoreJoueur()){
        gagnant="Bravo ! Vous avez gagné avec un score de ";
        gagnant.append( QString::number(monJeu.getScoreJoueur()));

        finPartieGagnant.setInformativeText(gagnant);
    }
    if(monJeu.getScoreMachine()==monJeu.getScoreJoueur()){
        gagnant="EGALITE ENTRE LA MACHINE ET LE JOUEUR !! ";


        finPartieGagnant.setInformativeText(gagnant);
    }

    finPartieGagnant.setStandardButtons(QMessageBox::Ok);
    finPartieGagnant.exec();
}


void chifoumi::temp()
{


        if (sec==0){
            timer->stop();

            tempsEcoule="PARTIE TERMINEE";
            ui->TIMER->setText(tempsEcoule);
            ui->TIMER->setFont(QFont("Times", 8, QFont::Bold));
            ui->TIMER->setAlignment(Qt::AlignCenter);
            ui->pierre->setEnabled(false);
            ui->feuille->setEnabled(false);
            ui->ciseau->setEnabled(false);
            finPartieGagnant();

        }
        else{
            sec--;
            tempsEcoule="";
            tempsEcoule="TEMPS RESTANT: ";
            tempsEcoule.append( QString::number(sec));
            ui->TIMER->setText(tempsEcoule);
            ui->TIMER->setFont(QFont("Times", 8, QFont::Bold));
            ui->TIMER->setAlignment(Qt::AlignCenter);
        }




}
