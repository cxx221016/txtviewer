#include <QApplication>
#include <QPushButton>
#include"Sqlmanager.h"
#include"bookshelf.h"
#include "bookviewermanager.h"
#include"setup.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    SqlManager::init();
    bookshelf* books=new bookshelf;
    setup* sp=new setup;
    sp->hide();
    bookviewermanager* manager=new bookviewermanager(books,sp);
    books->show();


    return QApplication::exec();
}
