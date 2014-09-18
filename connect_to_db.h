#ifndef CONNECT_TO_DB_H
#define CONNECT_TO_DB_H

#pragma once

#include <QSqlDatabase>

class Database {
public:
    Database();

    bool Connect();

private:
    QSqlDatabase db;

};


#endif // CONNECT_TO_DB_H
