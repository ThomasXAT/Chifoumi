#ifndef CHIFOUMI_H
#define CHIFOUMI_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class chifoumi; }
QT_END_NAMESPACE

class chifoumi : public QMainWindow
{
    Q_OBJECT

public:
    chifoumi(QWidget *parent = nullptr);
    ~chifoumi();
    void coupMachine();
    QString nom;
    void personnaliser();


private slots:
    void infosApp();
    void finPartieGagnant();
    void afficherBoite();
    void resultats();


public slots:
    void nouvellePartie();
    void boutonPause();
    void coupPierre();
    void coupCiseau();
    void coupFeuille();
    void temp();


private:
    Ui::chifoumi *ui;
    QTimer *timer;
    int sec;
    QLabel *CompteurTemps;
    QString tempsEcoule;
    QString points;
    QString scoreMachine;
    QString scoreJoueur;
    QString TImer;
    bool Pause=false;
    QString gagnant;
    QString joueur;
    unsigned int ptsPartie=5;


};
#endif // CHIFOUMI_H
