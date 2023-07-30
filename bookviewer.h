//
// Created by 86159 on 2023/7/27.
//

#ifndef TXTVIEWER_BOOKVIEWER_H
#define TXTVIEWER_BOOKVIEWER_H

#include <QMainWindow>
#include <QMap>
#include<QString>
#include<QFile>
#include<QDir>
#include<algorithm>
#include<QMessageBox>
#include<unordered_map>
#include<QListWidgetItem>
#include"setup.h"
#include"Sqlmanager.h"


QT_BEGIN_NAMESPACE
namespace Ui { class bookviewer; }
QT_END_NAMESPACE

class bookviewer : public QMainWindow {
Q_OBJECT

public:
    bookviewer(const QString& bookname,const QString& location,const QString& type,setup* outsp,QWidget *parent = nullptr);

    ~bookviewer() override;

private:
    setup* sp;
    Ui::bookviewer *ui;
    bool hasload=false;
    QString bookname;
    QString location;
    QString type;
    QVector<std::pair<QString,QString>> booksplit;
    QMap<QString,int> indexmap;
    void splitbook();
    void splitbookfile();
    void splitbookdir();
    void showbyname(const QString& chaptername);
    void loadchapterlist();
    void closeEvent(QCloseEvent *event) override;
private slots:
    void nextchapter();
    void prevchapter();
    void showchapter();
    void showbyclick(QListWidgetItem* item);
    void setupbutton();
public slots:
    void applysetup(const QVector<QString>& setups);

};


#endif //TXTVIEWER_BOOKVIEWER_H
