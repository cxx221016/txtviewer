//
// Created by 86159 on 2023/7/28.
//

// You may need to build the project (run Qt uic code generator) to get "ui_setup.h" resolved

#include "setup.h"
#include "ui_setup.h"


setup::setup(QWidget *parent) :
        QWidget(parent), ui(new Ui::setup) {
    ui->setupUi(this);
    connect(ui->trueButton,&QPushButton::clicked,this,&setup::surebutton);
    connect(ui->falseButton,&QPushButton::clicked,this,&setup::cancelbutton);
    ui->brightbar->setRange(0,100);
    ui->brightbar->setValue(80);
    ui->brightbar->setOrientation(Qt::Horizontal);
    ui->fontComboBox->setCurrentFont(QFont("微软雅黑"));
    ui->fontsizeBox->setValue(10);
    ui->fontsizeBox->setRange(1,20);
    ui->fontsizeBox->setSingleStep(1);
    ui->fontsizeBox->setWrapping(true);
    ui->FontcolorBox->setAutoFillBackground(true);
    ui->FontcolorBox->addItems(colorlist);
    ui->FontcolorBox->setCurrentIndex(0);
    ui->backgroundBox->setAutoFillBackground(true);
    ui->backgroundBox->addItems(colorlist);
    ui->backgroundBox->setCurrentIndex(1);
    ui->fontComboBox->setEditable(false);
    loadfilesetup();
}

void setup::loadfilesetup()
{
    QFile file(setupfilename);
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        qDebug()<<"open file failed";
        return;
    }
    QTextStream in(&file);
    QString line;
    while(!in.atEnd())
    {
        line=in.readLine();
        if(line=="")
            continue;
        QStringList list=line.split("=");
        if(list[0]=="font")
        {
            ui->fontComboBox->setCurrentFont(QFont(list[1]));
            setups[0]=list[1];
        }
        else if(list[0]=="fontsize")
        {
            ui->fontsizeBox->setValue(list[1].toInt());
            setups[1]=list[1];
        }
        else if(list[0]=="fontcolor")
        {
            ui->FontcolorBox->setCurrentText(list[1]);
            setups[2]=list[1];
        }
        else if(list[0]=="background")
        {
            ui->backgroundBox->setCurrentText(list[1]);
            setups[3]=list[1];
        }
        else if(list[0]=="bright")
        {
            ui->brightbar->setValue(list[1].toInt());
        }
    }
    file.close();
}

void setup::savefilesetup()
{
    QFile file(setupfilename);
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        qDebug()<<"open file failed";
        return;
    }
    QTextStream out(&file);
    out<<"font="<<ui->fontComboBox->currentFont().family()<<Qt::endl;
    out<<"fontsize="<<ui->fontsizeBox->value()<<Qt::endl;
    out<<"fontcolor="<<ui->FontcolorBox->currentText()<<Qt::endl;
    out<<"background="<<ui->backgroundBox->currentText()<<Qt::endl;
    out<<"bright="<<ui->brightbar->value()<<Qt::endl;
    file.close();
}

void setup::updatesetup()
{
    setups[0]=ui->fontComboBox->currentFont().family();
    setups[1]=QString::number(ui->fontsizeBox->value());
    setups[2]=ui->FontcolorBox->currentText();
    setups[3]=ui->backgroundBox->currentText();
}

void setup::closeEvent(QCloseEvent *event)
{
    savefilesetup();
    this->hide();
}

setup::~setup() {
    delete ui;
}

void setup::surebutton() {
    updatesetup();
    savefilesetup();
    emit setuploaded(setups);
}

void setup::cancelbutton() {
    loadfilesetup();
}