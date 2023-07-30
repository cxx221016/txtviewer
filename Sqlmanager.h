//
// Created by 86159 on 2023/7/27.
//



#ifndef TXTVIEWER_SQLMANAGER_H
#define TXTVIEWER_SQLMANAGER_H
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlError>
#include<QtSql/QSqlDriver>
#include<memory>


class SqlManager {
    static std::shared_ptr<QSqlDatabase> db;
    static std::shared_ptr<QSqlQuery> query;
public:
    static bool init();
    static bool close();
    static std::shared_ptr<QSqlQuery> instance();
};

#endif //TXTVIEWER_SQLMANAGER_H
