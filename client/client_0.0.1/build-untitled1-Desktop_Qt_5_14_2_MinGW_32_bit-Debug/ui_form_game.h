/********************************************************************************
** Form generated from reading UI file 'form_game.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_GAME_H
#define UI_FORM_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_form_game
{
public:
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QWidget *form_game)
    {
        if (form_game->objectName().isEmpty())
            form_game->setObjectName(QString::fromUtf8("form_game"));
        form_game->resize(771, 611);
        pushButton = new QPushButton(form_game);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(9, 570, 111, 41));
        label = new QLabel(form_game);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(600, 30, 161, 31));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(form_game);

        QMetaObject::connectSlotsByName(form_game);
    } // setupUi

    void retranslateUi(QWidget *form_game)
    {
        form_game->setWindowTitle(QCoreApplication::translate("form_game", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("form_game", "PushButton", nullptr));
        label->setText(QCoreApplication::translate("form_game", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class form_game: public Ui_form_game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_GAME_H
