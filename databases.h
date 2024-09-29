#ifndef DATABASES_H
#define DATABASES_H

#include<QDebug>
#include <QSqlDatabase>
#include<QtSql/QSql>
#include<QtSql/QSqlDriver>
#include<QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include <QSqlError>
#include "book.h"
class databases
{
public:
    QSqlDatabase db;
    QSqlQuery query;
    databases();
    void create();
    void insert(book& b);
};

#endif // DATABASES_H
