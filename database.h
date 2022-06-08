#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>

#define DATABASE_NAME "chifoumi"  //ici indiquer le nom du DNS permettant d'accéder a la BD
#define CONNECT_TYPE "QODBC"   //permet d'indiquer que l'on veut utiliser le driver odbc

class database
{
public:
    database();
    bool openDatabase();
    void closeDatabase();

private:
    QSqlDatabase db;
};

#endif // DATABASE_H
