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

bool SqlManager::addbook(const QString& bookname,const QString& location,const QString& type) {
    if (query->exec(QString("insert into bookshelf values('%1','%2','%3')").arg(bookname).arg(location).arg(type))) {
        return true;
    } else {
        qDebug() << "Error: Fail to insert into bookshelf." << query->lastError();
        return false;
    }
}

bool SqlManager::deletebook(const QString& bookname) {
    if (query->exec(QString("delete from bookshelf where bookname='%1'").arg(bookname))) {
        return true;
    } else {
        qDebug() << "Error: Fail to delete from bookshelf." << query->lastError();
        return false;
    }
}

QStandardItemModel* SqlManager::getbookshelf() {
    auto model = new QStandardItemModel();
    model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("书名")));
    query->exec("select * from bookshelf");
    while (query->next()) {
        model->appendRow(new QStandardItem(query->value(0).toString()));
    }
    return model;
}

bool SqlManager::updatalastidx(const QString& bookname,int lastidx) {
    if (query->exec(QString("update txtviewer set lastidx=%1 where bookname='%2'").arg(lastidx).arg(bookname))) {
        return true;
    } else {
        qDebug() << "Error: Fail to update bookshelf." << query->lastError();
        return false;
    }
}
