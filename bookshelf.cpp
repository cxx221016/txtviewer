//
// Created by 86159 on 2023/7/27.
//

// You may need to build the project (run Qt uic code generator) to get "ui_bookshelf.h" resolved

#include "bookshelf.h"
#include "ui_bookshelf.h"
#include "Sqlmanager.h"
#include "bookviewer.h"
#include "util.h"
#include<QFileDialog>
#include<QMessageBox>
#include<QInputDialog>
#include<QDebug>
#include<QComboBox>



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
    connect(ui->aboutAction, &QAction::triggered, this, &bookshelf::about);
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
//    QString fileordir = QInputDialog::getText(this, "导入书籍", "请输入文件或文件夹");
//    if (fileordir.isEmpty()) {
//        return;
//    }
    QDialog* dialog=new QDialog(this);
    dialog->setWindowTitle("导入书籍");
    dialog->resize(300,100);
    QComboBox* combobox=new QComboBox(dialog);
    combobox->addItem("文件");
    combobox->addItem("文件夹");
    combobox->move(100,20);
    QPushButton* okbutton=new QPushButton("确定",dialog);
    okbutton->move(100,60);
    connect(okbutton,&QPushButton::clicked,dialog,&QDialog::accept);
    QString fileordir=dialog->exec()==QDialog::Accepted?combobox->currentText():"";

    if(fileordir=="文件")
    {
        QString filename = QFileDialog::getOpenFileName(this, "选择文件", "D:\\Download", "TXT文件(*.txt)");
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
        QString dirname = QFileDialog::getExistingDirectory(this, "选择文件夹", "D:\\Download");
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

void bookshelf::about() {
    QMessageBox::about(this, "关于",
                       "Txtviewer\n"
                       "作者：崔向向\n"
                       "学号：521021911118\n"
                       "班级：F2103302\n"
                       "学院：电子信息与电气工程学院\n"
                       "学校：上海交通大学\n"
                       "Github: https://cxx221016.github.io/\n"
                       "版本：1.0.0\n"
                       "编译时间："+static_cast<QString>(__DATE__)+"\n");
}

