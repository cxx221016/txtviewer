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
#include<QStandardItemModel>


class SqlManager {
    static std::shared_ptr<QSqlDatabase> db;
    static std::shared_ptr<QSqlQuery> query;
public:
    static bool init();
    static bool close();
    static std::shared_ptr<QSqlQuery> instance();
    static QStandardItemModel* getbookshelf();
    static bool addbook(const QString& bookname,const QString& location,const QString& type);
    static bool deletebook(const QString& bookname);
    static bool updatalastidx(const QString& bookname,int lastidx);
};

#endif //TXTVIEWER_SQLMANAGER_H
