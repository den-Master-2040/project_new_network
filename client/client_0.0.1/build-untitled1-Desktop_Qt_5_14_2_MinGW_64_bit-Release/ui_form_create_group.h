/********************************************************************************
** Form generated from reading UI file 'form_create_group.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_CREATE_GROUP_H
#define UI_FORM_CREATE_GROUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_form_create_group
{
public:
    QLineEdit *lineEdit;
    QRadioButton *radioButton;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QPushButton *pb_create_group;
    QPushButton *pushButton_2;

    void setupUi(QWidget *form_create_group)
    {
        if (form_create_group->objectName().isEmpty())
            form_create_group->setObjectName(QString::fromUtf8("form_create_group"));
        form_create_group->resize(790, 630);
        lineEdit = new QLineEdit(form_create_group);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(60, 150, 211, 81));
        QFont font;
        font.setPointSize(14);
        lineEdit->setFont(font);
        radioButton = new QRadioButton(form_create_group);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(300, 280, 84, 19));
        radioButton->setFont(font);
        lineEdit_2 = new QLineEdit(form_create_group);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(60, 250, 211, 81));
        lineEdit_2->setFont(font);
        label = new QLabel(form_create_group);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 40, 791, 61));
        QFont font1;
        font1.setPointSize(20);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        pb_create_group = new QPushButton(form_create_group);
        pb_create_group->setObjectName(QString::fromUtf8("pb_create_group"));
        pb_create_group->setGeometry(QRect(610, 540, 151, 61));
        QFont font2;
        font2.setPointSize(11);
        pb_create_group->setFont(font2);
        pushButton_2 = new QPushButton(form_create_group);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 540, 151, 61));
        pushButton_2->setFont(font2);

        retranslateUi(form_create_group);

        QMetaObject::connectSlotsByName(form_create_group);
    } // setupUi

    void retranslateUi(QWidget *form_create_group)
    {
        form_create_group->setWindowTitle(QCoreApplication::translate("form_create_group", "Form", nullptr));
        lineEdit->setText(QCoreApplication::translate("form_create_group", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\263\321\200\321\203\320\277\320\277\321\213...", nullptr));
        radioButton->setText(QCoreApplication::translate("form_create_group", "\320\265\321\201\321\202\321\214", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("form_create_group", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        label->setText(QCoreApplication::translate("form_create_group", "\320\241\320\276\320\267\320\264\320\260\320\275\320\270\320\265 \320\263\321\200\321\203\320\277\320\277\321\213", nullptr));
        pb_create_group->setText(QCoreApplication::translate("form_create_group", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
        pushButton_2->setText(QCoreApplication::translate("form_create_group", "\320\222\321\213\321\205\320\276\320\264\n"
" \320\262 \320\263\320\273\320\262\320\260\320\275\320\276\320\265 \320\274\320\265\320\275\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class form_create_group: public Ui_form_create_group {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_CREATE_GROUP_H
