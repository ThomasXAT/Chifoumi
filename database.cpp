#include "database.h"

database::database()
{
    this->db = QSqlDatabase::addDatabase(CONNECT_TYPE);
    this->db.setDatabaseName(DATABASE_NAME);
}

bool database:: openDatabase()
{

    return this->db.open();

}

void database:: closeDatabase()
{
    this->db.close();


}
