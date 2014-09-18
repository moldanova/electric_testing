#include "connect_to_db.h"

#include <QSqlQuery>
#include <QSql>
#include <QSqlDriver>
#include <QSqlError>
#include <QDebug>
#include <QSqlRecord>

Database::Database()
{
//
}

bool Database::Connect()
{
    db = QSqlDatabase::addDatabase("QPSQL");
    if (!db.isValid()) {
        qDebug() << db.lastError();
        return false;
    }

    db.setHostName("localhost");
    db.setPort(5432);
    db.setUserName("server");
    db.setPassword("1234");
    db.setDatabaseName("electric_testing");

    if (!db.open()) {
        qDebug() << "database wasn't opened";
        qDebug() << db.lastError();
        return false;
    }

    return true;
}
