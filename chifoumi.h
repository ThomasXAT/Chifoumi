#ifndef CHIFOUMI_H
#define CHIFOUMI_H

#include <QMainWindow>
#include <QMessageBox>

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

public slots:
    void nouvellePartie();
    void coupPierre();
    void coupCiseau();
    void coupFeuille();

private:
    Ui::chifoumi *ui;
    QString scoreMachine;
    QString scoreJoueur;
};
#endif // CHIFOUMI_H
