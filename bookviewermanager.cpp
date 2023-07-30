//
// Created by 86159 on 2023/7/27.
//

#include "bookviewermanager.h"

bookviewermanager::bookviewermanager(bookshelf *outbooks, setup* outsp,QWidget *parent) : QWidget(parent) {
    sp=outsp;
    books=outbooks;
    connect(books, &bookshelf::openbooksignal, this, &bookviewermanager::openbook);
}

void bookviewermanager::openbook(const QString &bookname, const QString &location, const QString &type) {
    if(type=="file") {
        QFile file(location);
        if(!file.exists())
        {
            QMessageBox::information(this,"info","file not exist");
            return;
        }
        file.close();
    }
    else if(type=="dir") {
        QDir dir(location);
        if(!dir.exists())
        {
            QMessageBox::information(this,"info","dir not exist");
            return;
        }
    }
    auto bookv=std::make_shared<bookviewer>(bookname,location,type,sp,this);
    connect(sp,&setup::setuploaded,bookv.get(),&bookviewer::applysetup);
    bookviewers.push_back(bookv);
    sp->surebutton();
    //qDebug()<<"openbook: "<<bookname<<" "<<location<<" "<<type;
    bookv->show();
}