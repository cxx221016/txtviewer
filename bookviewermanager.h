//
// Created by 86159 on 2023/7/27.
//

#ifndef TXTVIEWER_BOOKVIEWERMANAGER_H
#define TXTVIEWER_BOOKVIEWERMANAGER_H
#include <QMainWindow>
#include <QDir>
#include <QMessageBox>
#include <QFile>
#include"bookshelf.h"
#include"bookviewer.h"
#include "setup.h"
#include<memory>

QT_BEGIN_NAMESPACE
namespace Ui { class bookviewermanager; }
QT_END_NAMESPACE

class bookviewermanager:public QWidget{
Q_OBJECT
private:
    QVector<std::shared_ptr<bookviewer>> bookviewers;
    bookshelf* books= nullptr;
    setup* sp= nullptr;
public:
    bookviewermanager(bookshelf* outbooks,setup* outsp,QWidget *parent = nullptr);
public slots:
    void openbook(const QString& bookname,const QString& location,const QString& type);
};


#endif //TXTVIEWER_BOOKVIEWERMANAGER_H
