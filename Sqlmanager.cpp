//
// Created by 86159 on 2023/7/27.
//

#include "Sqlmanager.h"

std::shared_ptr<QSqlDatabase> SqlManager::db = nullptr;
std::shared_ptr<QSqlQuery> SqlManager::query = nullptr;

bool SqlManager::init() {
    if(db!= nullptr)
        return true;
    db = std::make_shared<QSqlDatabase>(QSqlDatabase::addDatabase("QMYSQL"));
    db->setHostName("localhost");
    db->setPort(3306);
    db->setDatabaseName("test");
    db->setUserName("root");
    db->setPassword("031204");
    if (!db->open()) {
        qDebug() << "Error: Failed to connect database." << db->lastError();
        return false;
    } else {
        //qDebug() << "Succeed to connect database." ;
    }
    query = std::make_shared<QSqlQuery>(*db);
    return true;
}

bool SqlManager::close() {
    db->close();
    return true;
}

std::shared_ptr<QSqlQuery> SqlManager::instance() {
    return query;
}
