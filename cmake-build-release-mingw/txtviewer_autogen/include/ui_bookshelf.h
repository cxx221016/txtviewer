/********************************************************************************
** Form generated from reading UI file 'bookshelf.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKSHELF_H
#define UI_BOOKSHELF_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_bookshelf
{
public:
    QAction *ImportAction;
    QWidget *centralwidget;
    QTableView *booktable;
    QPushButton *openButton;
    QPushButton *deleteButton;
    QMenuBar *menubar;
    QMenu *FileMenu;
    QMenu *EditMenu;
    QMenu *FormatMenu;
    QMenu *HelloMenu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *bookshelf)
    {
        if (bookshelf->objectName().isEmpty())
            bookshelf->setObjectName("bookshelf");
        bookshelf->resize(400, 300);
        ImportAction = new QAction(bookshelf);
        ImportAction->setObjectName("ImportAction");
        centralwidget = new QWidget(bookshelf);
        centralwidget->setObjectName("centralwidget");
        booktable = new QTableView(centralwidget);
        booktable->setObjectName("booktable");
        booktable->setGeometry(QRect(30, 30, 121, 211));
        openButton = new QPushButton(centralwidget);
        openButton->setObjectName("openButton");
        openButton->setGeometry(QRect(270, 60, 75, 24));
        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(270, 110, 75, 24));
        bookshelf->setCentralWidget(centralwidget);
        menubar = new QMenuBar(bookshelf);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 400, 22));
        FileMenu = new QMenu(menubar);
        FileMenu->setObjectName("FileMenu");
        EditMenu = new QMenu(menubar);
        EditMenu->setObjectName("EditMenu");
        FormatMenu = new QMenu(menubar);
        FormatMenu->setObjectName("FormatMenu");
        HelloMenu = new QMenu(menubar);
        HelloMenu->setObjectName("HelloMenu");
        bookshelf->setMenuBar(menubar);
        statusbar = new QStatusBar(bookshelf);
        statusbar->setObjectName("statusbar");
        bookshelf->setStatusBar(statusbar);

        menubar->addAction(FileMenu->menuAction());
        menubar->addAction(EditMenu->menuAction());
        menubar->addAction(FormatMenu->menuAction());
        menubar->addAction(HelloMenu->menuAction());
        FileMenu->addAction(ImportAction);

        retranslateUi(bookshelf);

        QMetaObject::connectSlotsByName(bookshelf);
    } // setupUi

    void retranslateUi(QMainWindow *bookshelf)
    {
        bookshelf->setWindowTitle(QCoreApplication::translate("bookshelf", "bookshelf", nullptr));
        ImportAction->setText(QCoreApplication::translate("bookshelf", "\345\257\274\345\205\245", nullptr));
        openButton->setText(QCoreApplication::translate("bookshelf", "\346\211\223\345\274\200", nullptr));
        deleteButton->setText(QCoreApplication::translate("bookshelf", "\345\210\240\351\231\244", nullptr));
        FileMenu->setTitle(QCoreApplication::translate("bookshelf", "\346\226\207\344\273\266", nullptr));
        EditMenu->setTitle(QCoreApplication::translate("bookshelf", "\347\274\226\350\276\221", nullptr));
        FormatMenu->setTitle(QCoreApplication::translate("bookshelf", "\346\240\274\345\274\217", nullptr));
        HelloMenu->setTitle(QCoreApplication::translate("bookshelf", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class bookshelf: public Ui_bookshelf {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKSHELF_H
