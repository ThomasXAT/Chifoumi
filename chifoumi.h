#ifndef CHIFOUMI_H
#define CHIFOUMI_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>

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

private slots:
    void infosApp();
    void finPartieGagnant();

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
    QString TImer;
    bool Pause=false;
    QString gagnant;
    QString tempsEcoule;
    QString scoreMachine;
    QString scoreJoueur;
};
#endif // CHIFOUMI_H
