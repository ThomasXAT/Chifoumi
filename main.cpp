#include "chifoumi.h"
#include "chifoumidialog.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    chifoumi w;
    w.setWindowTitle("Chifoumi");
    w.setWindowIcon(QIcon(QString::fromUtf8(":/chifoumi/images (1)/images/versus.gif")));
    w.show();

    return a.exec();
}
