//
// Created by 86159 on 2023/7/27.
//

// You may need to build the project (run Qt uic code generator) to get "ui_bookviewer.h" resolved

#include "bookviewer.h"
#include "ui_bookviewer.h"
#include "util.h"


bookviewer::bookviewer(const QString& bookname,const QString& location,const QString& type,setup* outsp,QWidget *parent) :
        QMainWindow(parent), ui(new Ui::bookviewer) {
    ui->setupUi(this);
    sp=outsp;
    this->bookname=bookname;
    this->location=location;
    this->type=type;
    ui->booknamelabel->setText(bookname);
    ui->chapterlist->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->chapterlist->hide();
    splitbook();
    loadchapterlist();
    connect(ui->nextButton,&QPushButton::clicked,this,&bookviewer::nextchapter);
    connect(ui->prevButton,&QPushButton::clicked,this,&bookviewer::prevchapter);
    connect(ui->dirButton,&QPushButton::clicked,this,&bookviewer::showchapter);
    connect(ui->chapterlist,&QListWidget::itemDoubleClicked,this,&bookviewer::showbyclick);
    connect(ui->setaction,&QAction::triggered,this,&bookviewer::setupbutton);
    SqlManager::instance()->exec("select * from txtviewer where bookname='"+bookname+"'");
    SqlManager::instance()->next();
    int lastidx=SqlManager::instance()->value(3).toInt();
    showbyname(booksplit[lastidx].first);
}

bookviewer::~bookviewer() {
    delete ui;
}

void bookviewer::splitbook() {

    if(type=="file")
    {
        splitbookfile();
        hasload=true;
    }
    else if(type=="dir")
    {
        splitbookdir();
        hasload=true;
    }
    //QMessageBox::information(this,"info","load success");
}

void bookviewer::splitbookfile() {
    QFile file(location);
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        qDebug()<<"open file failed";
        return;
    }
    QTextStream in(&file);
    QString line;
    QString content;
    QString chaptername="";
    while(!in.atEnd())
    {
        line=in.readLine();
        if(ischaptername(line))
        {
            if(!chaptername.isEmpty())
            {
                booksplit.push_back(std::make_pair(chaptername,content));
                indexmap[chaptername]=booksplit.size()-1;
            }
            //qDebug()<<"chaptername: "<<chaptername;
            chaptername=removespace(line);
            content="";
        }
        else
        {
            content+=line+"\n";
        }
    }
    file.close();
}

void bookviewer::splitbookdir() {
    QDir dir(location);
    QStringList filelist=dir.entryList(QDir::Files);
    std::sort(filelist.begin(),filelist.end(),[](const QString& str1,const QString& str2)
    {
        QString str1number=getcontentnumber(str1);
        QString str2number=getcontentnumber(str2);
        int str1num=str1number.toInt();
        int str2num=str2number.toInt();
        return str1num<str2num;
    });//sort filelist
    std::for_each(filelist.begin(),filelist.end(),[&](QString& str){str=location+"/"+str;});//add location to filelist

    for(int i=0;i<filelist.length();i++)
    {
        QFile file(filelist[i]);
        if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
        {
            qDebug()<<"open file failed";
        }
        QByteArray precontent=file.readAll();
        QString chaptername= getbookname(filelist[i]);
        QString content=QString::fromUtf8(precontent);
        booksplit.emplace_back(std::make_pair(chaptername,content));
        indexmap.insert(chaptername,booksplit.size()-1);
        file.close();
    }
}

void bookviewer::showbyclick(QListWidgetItem *item)
{
    QString chaptername=item->text();
    showbyname(chaptername);
    ui->chapterlist->hide();
}

void bookviewer::showbyname(const QString& chaptername) {
    if(!hasload)
    {
        splitbook();
    }
    SqlManager::updatalastidx(bookname,indexmap[chaptername]);
    ui->bookBrowser->setText(booksplit[indexmap[chaptername]].second);
    ui->bookBrowser->setAlignment(Qt::AlignCenter);
    //ui->bookBrowser->show();
    ui->chapternamelabel->setText(chaptername);
}

void bookviewer::nextchapter()
{
    if(!hasload)
    {
        splitbook();
    }
    QString chaptername=ui->chapternamelabel->text();
    auto idx=indexmap[chaptername];
    if(idx==booksplit.size()-1)
    {
        QMessageBox::information(this,"提示","已经是最后一章了");
        return;
    }
    showbyname(booksplit[idx+1].first);
}

void bookviewer::prevchapter()
{
    if(!hasload)
    {
        splitbook();
    }
    QString chaptername=ui->chapternamelabel->text();
    auto idx=indexmap[chaptername];
    if(idx==0)
    {
        QMessageBox::information(this,"提示","已经是第一章了");
        return;
    }
    showbyname(booksplit[idx-1].first);
}

void bookviewer::loadchapterlist()
{
    if(!hasload)
    {
        splitbook();
    }
    ui->chapterlist->clear();
    for(auto it=booksplit.begin();it!=booksplit.end();it++)
    {
        ui->chapterlist->addItem(it->first);
    }
}

void bookviewer::showchapter()
{
    if(!hasload)
    {
        splitbook();
    }
    SqlManager::instance()->exec("select * from txtviewer where bookname='"+bookname+"'");
    SqlManager::instance()->next();
    int lastidx=SqlManager::instance()->value(3).toInt();
    //qDebug()<<"lastidx: "<<lastidx;
    ui->chapterlist->setCurrentRow(lastidx);
    ui->chapterlist->show();
}

void bookviewer::applysetup(const QVector<QString> &setups)
{
    auto font=setups[0];
    auto fontsize=setups[1].toInt();
    auto fontcolor=setups[2];
    auto backgroundcolor=setups[3];
    ui->bookBrowser->setFont(QFont(font,fontsize));
    ui->bookBrowser->setStyleSheet("background-color:"+backgroundcolor+";color:"+fontcolor+";");
}

void bookviewer::closeEvent(QCloseEvent *event)
{
    int idx=indexmap[ui->chapternamelabel->text()];
    SqlManager::instance()->exec(QString("update txtviewer set lastidx=%1 where bookname='%2'").arg(idx).arg(bookname));
}

void bookviewer::setupbutton()
{
    sp->show();
}
