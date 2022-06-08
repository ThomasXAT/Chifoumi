#include "chifoumi.h"
#include "chifoumidialog.h"
#include "chifoumiconnexion.h"
#include <QApplication>
#include "afficherresultats.h"


int main(int argc, char *argv[])
{
    bool ok=false;
    QApplication a(argc, argv);
    chifoumiConnexion connexion;
    chifoumi w;
    while (ok==false){
        if(connexion.connexion()==true)
        {
            w.setWindowTitle("Chifoumi");
            w.setWindowIcon(QIcon(QString::fromUtf8(":/chifoumi/images (1)/images/versus.gif")));
            w.show();
            ok=true;
        }

    }




    return a.exec();
}
