/********************************************************************************
** Form generated from reading UI file 'bookviewer.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKVIEWER_H
#define UI_BOOKVIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_bookviewer
{
public:
    QAction *setaction;
    QWidget *centralwidget;
    QTextBrowser *bookBrowser;
    QLabel *chapternamelabel;
    QPushButton *nextButton;
    QPushButton *dirButton;
    QPushButton *prevButton;
    QLabel *booknamelabel;
    QListWidget *chapterlist;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *bookviewer)
    {
        if (bookviewer->objectName().isEmpty())
            bookviewer->setObjectName("bookviewer");
        bookviewer->resize(400, 669);
        setaction = new QAction(bookviewer);
        setaction->setObjectName("setaction");
        centralwidget = new QWidget(bookviewer);
        centralwidget->setObjectName("centralwidget");
        bookBrowser = new QTextBrowser(centralwidget);
        bookBrowser->setObjectName("bookBrowser");
        bookBrowser->setGeometry(QRect(20, 70, 341, 511));
        chapternamelabel = new QLabel(centralwidget);
        chapternamelabel->setObjectName("chapternamelabel");
        chapternamelabel->setGeometry(QRect(20, 40, 351, 21));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setBold(true);
        chapternamelabel->setFont(font);
        nextButton = new QPushButton(centralwidget);
        nextButton->setObjectName("nextButton");
        nextButton->setGeometry(QRect(260, 590, 75, 24));
        dirButton = new QPushButton(centralwidget);
        dirButton->setObjectName("dirButton");
        dirButton->setGeometry(QRect(140, 590, 75, 24));
        prevButton = new QPushButton(centralwidget);
        prevButton->setObjectName("prevButton");
        prevButton->setGeometry(QRect(30, 590, 75, 24));
        booknamelabel = new QLabel(centralwidget);
        booknamelabel->setObjectName("booknamelabel");
        booknamelabel->setGeometry(QRect(20, 10, 351, 20));
        booknamelabel->setFont(font);
        chapterlist = new QListWidget(centralwidget);
        chapterlist->setObjectName("chapterlist");
        chapterlist->setEnabled(true);
        chapterlist->setGeometry(QRect(15, 31, 361, 591));
        bookviewer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(bookviewer);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 400, 22));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        bookviewer->setMenuBar(menubar);
        statusbar = new QStatusBar(bookviewer);
        statusbar->setObjectName("statusbar");
        bookviewer->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(setaction);

        retranslateUi(bookviewer);

        QMetaObject::connectSlotsByName(bookviewer);
    } // setupUi

    void retranslateUi(QMainWindow *bookviewer)
    {
        bookviewer->setWindowTitle(QCoreApplication::translate("bookviewer", "boolviewer", nullptr));
        setaction->setText(QCoreApplication::translate("bookviewer", "\350\256\276\347\275\256", nullptr));
        chapternamelabel->setText(QCoreApplication::translate("bookviewer", "\347\253\240\350\212\202\345\220\215", nullptr));
        nextButton->setText(QCoreApplication::translate("bookviewer", "\344\270\213\344\270\200\347\253\240", nullptr));
        dirButton->setText(QCoreApplication::translate("bookviewer", "\347\233\256\345\275\225", nullptr));
        prevButton->setText(QCoreApplication::translate("bookviewer", "\344\270\212\344\270\200\347\253\240", nullptr));
        booknamelabel->setText(QCoreApplication::translate("bookviewer", "\345\260\217\350\257\264\345\220\215", nullptr));
        menu->setTitle(QCoreApplication::translate("bookviewer", "\346\237\245\347\234\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class bookviewer: public Ui_bookviewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKVIEWER_H
