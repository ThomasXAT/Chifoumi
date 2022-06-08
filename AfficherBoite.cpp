#include "chifoumi.h"
#include "chifoumidialog.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    chifoumiDialog window;

    window.show();

    return a.exec();
}
