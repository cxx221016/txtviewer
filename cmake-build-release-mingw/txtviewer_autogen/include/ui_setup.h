/********************************************************************************
** Form generated from reading UI file 'setup.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETUP_H
#define UI_SETUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_setup
{
public:
    QScrollBar *brightbar;
    QLabel *brightlabel;
    QLabel *Fontsizelabel;
    QSpinBox *fontsizeBox;
    QLabel *Fontlabel;
    QFontComboBox *fontComboBox;
    QLabel *Fontcolorlabel;
    QLabel *backgroundlabel;
    QComboBox *FontcolorBox;
    QComboBox *backgroundBox;
    QPushButton *trueButton;
    QPushButton *falseButton;

    void setupUi(QWidget *setup)
    {
        if (setup->objectName().isEmpty())
            setup->setObjectName("setup");
        setup->resize(400, 300);
        brightbar = new QScrollBar(setup);
        brightbar->setObjectName("brightbar");
        brightbar->setGeometry(QRect(150, 30, 160, 16));
        brightbar->setOrientation(Qt::Horizontal);
        brightlabel = new QLabel(setup);
        brightlabel->setObjectName("brightlabel");
        brightlabel->setGeometry(QRect(40, 30, 54, 16));
        Fontsizelabel = new QLabel(setup);
        Fontsizelabel->setObjectName("Fontsizelabel");
        Fontsizelabel->setGeometry(QRect(40, 110, 54, 16));
        fontsizeBox = new QSpinBox(setup);
        fontsizeBox->setObjectName("fontsizeBox");
        fontsizeBox->setGeometry(QRect(150, 110, 42, 22));
        Fontlabel = new QLabel(setup);
        Fontlabel->setObjectName("Fontlabel");
        Fontlabel->setGeometry(QRect(40, 70, 54, 16));
        fontComboBox = new QFontComboBox(setup);
        fontComboBox->setObjectName("fontComboBox");
        fontComboBox->setGeometry(QRect(150, 70, 224, 22));
        Fontcolorlabel = new QLabel(setup);
        Fontcolorlabel->setObjectName("Fontcolorlabel");
        Fontcolorlabel->setGeometry(QRect(40, 150, 54, 16));
        backgroundlabel = new QLabel(setup);
        backgroundlabel->setObjectName("backgroundlabel");
        backgroundlabel->setGeometry(QRect(40, 190, 54, 16));
        FontcolorBox = new QComboBox(setup);
        FontcolorBox->setObjectName("FontcolorBox");
        FontcolorBox->setGeometry(QRect(150, 150, 68, 22));
        backgroundBox = new QComboBox(setup);
        backgroundBox->setObjectName("backgroundBox");
        backgroundBox->setGeometry(QRect(150, 190, 68, 22));
        trueButton = new QPushButton(setup);
        trueButton->setObjectName("trueButton");
        trueButton->setGeometry(QRect(70, 240, 75, 24));
        falseButton = new QPushButton(setup);
        falseButton->setObjectName("falseButton");
        falseButton->setGeometry(QRect(200, 240, 75, 24));

        retranslateUi(setup);

        QMetaObject::connectSlotsByName(setup);
    } // setupUi

    void retranslateUi(QWidget *setup)
    {
        setup->setWindowTitle(QCoreApplication::translate("setup", "setup", nullptr));
        brightlabel->setText(QCoreApplication::translate("setup", "\344\272\256\345\272\246", nullptr));
        Fontsizelabel->setText(QCoreApplication::translate("setup", "\345\255\227\344\275\223\345\244\247\345\260\217", nullptr));
        Fontlabel->setText(QCoreApplication::translate("setup", "\345\255\227\344\275\223", nullptr));
        Fontcolorlabel->setText(QCoreApplication::translate("setup", "\345\255\227\344\275\223\351\242\234\350\211\262", nullptr));
        backgroundlabel->setText(QCoreApplication::translate("setup", "\350\203\214\346\231\257\351\242\234\350\211\262", nullptr));
        trueButton->setText(QCoreApplication::translate("setup", "\347\241\256\345\256\232", nullptr));
        falseButton->setText(QCoreApplication::translate("setup", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class setup: public Ui_setup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUP_H
