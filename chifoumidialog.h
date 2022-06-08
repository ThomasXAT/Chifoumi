#ifndef CHIFOUMIDIALOG_H
#define CHIFOUMIDIALOG_H

#include <QDialog>

namespace Ui {
class chifoumiDialog;
}

class chifoumiDialog : public QDialog
{
    Q_OBJECT

public:
    explicit chifoumiDialog(QWidget *parent = nullptr);
    ~chifoumiDialog();
    unsigned int dureePartie();
    unsigned int pointsMax();
    QString nomJoueur();


private slots:
    void infosDialog();
private:
    Ui::chifoumiDialog *ui;

};

#endif // CHIFOUMIDIALOG_H
