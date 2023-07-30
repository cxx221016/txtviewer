//
// Created by 86159 on 2023/7/28.
//

#ifndef TXTVIEWER_SETUP_H
#define TXTVIEWER_SETUP_H

#include <QWidget>
#include<QFile>
#include<iostream>
#include<QCloseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class setup; }
QT_END_NAMESPACE

static QStringList colorlist
        {
                "black",
                "white",
                "red",
                "darkRed",
                "green",
                "darkGreen",
                "blue",
                "darkBlue",
                "cyan",
                "darkCyan",
                "magenta",
                "darkMagenta",
                "yellow",
                "darkYellow",
                "gray",
                "darkGray",
                "lightGray",
                "transparent"
        };




class setup : public QWidget {
Q_OBJECT

public:
    explicit setup(QWidget *parent = nullptr);
    ~setup() override;

private:
    QString setupfilename="setup.ini";
    Ui::setup *ui;
    QVector<QString> setups=QVector<QString>(4);
private:
    void loadfilesetup();
    void closeEvent(QCloseEvent *event) override;
    void savefilesetup();
    void updatesetup();
public slots:
    void surebutton();
    void cancelbutton();
signals:
    void setuploaded(const QVector<QString>& setups);
};


#endif //TXTVIEWER_SETUP_H
