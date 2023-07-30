//
// Created by 86159 on 2023/7/27.
//

// You may need to build the project (run Qt uic code generator) to get "ui_bookshelf.h" resolved

#include "bookshelf.h"
#include "ui_bookshelf.h"
#include "Sqlmanager.h"
#include "bookviewer.h"


bookshelf::bookshelf(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::bookshelf) {
    ui->setupUi(this);
    model = new QStandardItemModel();
    ui->booktable->setModel(model);
    ui->booktable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->booktable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->booktable->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->booktable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->booktable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    model->setColumnCount(1);
    model->setHeaderData(0, Qt::Horizontal, "书名");
    connect(ui->ImportAction, &QAction::triggered, this, &bookshelf::importbook);
    connect(ui->deleteButton, &QPushButton::clicked, this, &bookshelf::deletebook);
    connect(ui->openButton, &QPushButton::clicked, this, &bookshelf::openbook);
    connect(ui->booktable, &QTableView::doubleClicked, this, &bookshelf::openbook);
    updatebooktable();
}

bookshelf::~bookshelf() {
    delete ui;
}

void bookshelf::updatebooktable() {
    model->clear();
    model->setColumnCount(1);
    model->setHeaderData(0, Qt::Horizontal, "书名");
    SqlManager::instance()->exec("select * from txtviewer");
    while (SqlManager::instance()->next()) {
        model->appendRow(new QStandardItem(SqlManager::instance()->value(0).toString()));
    }
}

void bookshelf::importbook() {
    QString fileordir = QInputDialog::getText(this, "导入书籍", "请输入文件或文件夹");
    if (fileordir.isEmpty()) {
        return;
    }
    if(fileordir=="文件")
    {
        QString filename = QFileDialog::getOpenFileName(this, "选择文件", ".", "TXT文件(*.txt)");
        if (filename.isEmpty()) {
            return;
        }
        QString bookname= getbookname(filename);
        QString location=filename;
        QString type="file";
        QString sql = QString("insert into txtviewer values('%1','%2','%3',0)").arg(bookname).arg(location).arg(type);
        SqlManager::instance()->exec(sql);
        updatebooktable();
    }
    else if(fileordir=="文件夹")
    {
        QString dirname = QFileDialog::getExistingDirectory(this, "选择文件夹", ".");
        if (dirname.isEmpty()) {
            return;
        }
        QString bookname=QInputDialog::getText(this,"输入书名","请输入书名");
        if(bookname.isEmpty())
        {
            return;
        }
        QString location=dirname;
        QString type="dir";
        QString sql = QString("insert into txtviewer values('%1','%2','%3',0)").arg(bookname).arg(location).arg(type);
        SqlManager::instance()->exec(sql);
        updatebooktable();
    }
    else
    {
        QMessageBox::warning(this,"错误","请输入文件或文件夹");
        return;
    }

}

void bookshelf::deletebook() {
    QModelIndex index = ui->booktable->currentIndex();
    if (!index.isValid()) {
        return;
    }
    QString bookname = model->item(index.row(), 0)->text();
    QString sql = QString("delete from txtviewer where bookname='%1'").arg(bookname);
    SqlManager::instance()->exec(sql);
    updatebooktable();
}

void bookshelf::openbook() {
    QModelIndex index = ui->booktable->currentIndex();
    if (!index.isValid()) {
        return;
    }
    QString bookname = model->item(index.row(), 0)->text();
    QString sql = QString("select * from txtviewer where bookname='%1'").arg(bookname);
    SqlManager::instance()->exec(sql);
    SqlManager::instance()->next();
    QString location=SqlManager::instance()->value(1).toString();
    QString type=SqlManager::instance()->value(2).toString();
    emit openbooksignal(bookname,location,type);
    //this->close();
}

