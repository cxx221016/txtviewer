//
// Created by 86159 on 2023/7/27.
//

#ifndef TXTVIEWER_BOOKSHELF_H
#define TXTVIEWER_BOOKSHELF_H

#include <QMainWindow>
#include<QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class bookshelf; }
QT_END_NAMESPACE


class bookshelf : public QMainWindow {
Q_OBJECT

public:
    explicit bookshelf(QWidget *parent = nullptr);

    ~bookshelf() override;

private:
    Ui::bookshelf *ui;
    QStandardItemModel *model;
private:
    void updatebooktable();

private slots:
    void importbook();
    void deletebook();
    void openbook();
    void about();
signals:
    void openbooksignal(QString bookname,QString location,QString type);
};


#endif //TXTVIEWER_BOOKSHELF_H
