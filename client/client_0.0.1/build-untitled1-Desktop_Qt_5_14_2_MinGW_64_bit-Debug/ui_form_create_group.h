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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_form_create_group
{
public:
    QStackedWidget *stackedWidgetGroup;
    QWidget *page;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QRadioButton *radioButton;
    QLabel *label;
    QPushButton *pb_create_group;
    QWidget *page_2;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *form_create_group)
    {
        if (form_create_group->objectName().isEmpty())
            form_create_group->setObjectName(QString::fromUtf8("form_create_group"));
        form_create_group->resize(790, 630);
        stackedWidgetGroup = new QStackedWidget(form_create_group);
        stackedWidgetGroup->setObjectName(QString::fromUtf8("stackedWidgetGroup"));
        stackedWidgetGroup->setGeometry(QRect(9, 9, 771, 611));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        pushButton_2 = new QPushButton(page);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 510, 151, 61));
        QFont font;
        font.setPointSize(11);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"\n"
"background-color:qlineargradient(spread:pad, x1:0.494, y1:0.846136, x2:0.494382, y2:1, stop:0 rgba(69, 69, 69, 255), stop:1 rgba(149, 149, 149, 255));\n"
"color:white;\n"
"font: \"Arial\";\n"
"border-radius: 2px;\n"
"}\n"
"QPushButton::pressed{\n"
"\n"
"background-color:qlineargradient(spread:pad, x1:0.426, y1:0.800682, x2:0.427, y2:1, stop:0 rgba(37, 37, 37, 255), stop:1 rgba(87, 87, 87, 255));\n"
"color:white;\n"
"font: \"Arial\";\n"
"border-radius: 2px;\n"
"};\n"
""));
        lineEdit = new QLineEdit(page);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(50, 160, 211, 81));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        lineEdit->setFont(font1);
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(77, 77, 77);\n"
"color:white;\n"
"font: \"Arial\";\n"
"border-radius: 2px;"));
        lineEdit_2 = new QLineEdit(page);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(50, 270, 211, 81));
        lineEdit_2->setFont(font1);
        lineEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(77, 77, 77);\n"
"color:white;\n"
"font: \"Arial\";\n"
"border-radius: 2px;"));
        radioButton = new QRadioButton(page);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(290, 300, 84, 19));
        QFont font2;
        font2.setPointSize(14);
        radioButton->setFont(font2);
        radioButton->setAcceptDrops(false);
        radioButton->setStyleSheet(QString::fromUtf8("color:white;"));
        radioButton->setChecked(true);
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 30, 771, 61));
        QFont font3;
        font3.setPointSize(20);
        label->setFont(font3);
        label->setStyleSheet(QString::fromUtf8("color:white;"));
        label->setAlignment(Qt::AlignCenter);
        pb_create_group = new QPushButton(page);
        pb_create_group->setObjectName(QString::fromUtf8("pb_create_group"));
        pb_create_group->setGeometry(QRect(590, 510, 151, 61));
        pb_create_group->setFont(font);
        pb_create_group->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"\n"
"background-color:qlineargradient(spread:pad, x1:0.494, y1:0.846136, x2:0.494382, y2:1, stop:0 rgba(69, 69, 69, 255), stop:1 rgba(149, 149, 149, 255));\n"
"color:white;\n"
"font: \"Arial\";\n"
"border-radius: 2px;\n"
"}\n"
"QPushButton::pressed{\n"
"\n"
"background-color:qlineargradient(spread:pad, x1:0.426, y1:0.800682, x2:0.427, y2:1, stop:0 rgba(37, 37, 37, 255), stop:1 rgba(87, 87, 87, 255));\n"
"color:white;\n"
"font: \"Arial\";\n"
"border-radius: 2px;\n"
"};\n"
""));
        stackedWidgetGroup->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        label_2 = new QLabel(page_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(-4, 40, 781, 61));
        QFont font4;
        font4.setPointSize(22);
        label_2->setFont(font4);
        label_2->setStyleSheet(QString::fromUtf8("color:white;"));
        label_2->setAlignment(Qt::AlignCenter);
        lineEdit_3 = new QLineEdit(page_2);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(420, 440, 221, 31));
        lineEdit_3->setStyleSheet(QString::fromUtf8("background-color: rgb(77, 77, 77);\n"
"color:white;\n"
"font: \"Arial\";\n"
"border-radius: 2px;"));
        pushButton = new QPushButton(page_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(650, 440, 80, 31));
        pushButton->setStyleSheet(QString::fromUtf8("background-color:qlineargradient(spread:pad, x1:0.494, y1:0.846136, x2:0.494382, y2:1, stop:0 rgba(69, 69, 69, 255), stop:1 rgba(149, 149, 149, 255));\n"
"color:white;\n"
"font: \"Arial\";\n"
"border-radius: 2px;"));
        groupBox = new QGroupBox(page_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 110, 371, 361));
        groupBox->setFont(font1);
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(77, 77, 77);\n"
"color:white;\n"
"font: \"Arial\";\n"
"border-radius: 2px;"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(100, 60, 261, 51));
        label_3->setFont(font1);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 60, 61, 51));
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(100, 110, 261, 51));
        label_5->setFont(font1);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 110, 61, 51));
        label_6->setAlignment(Qt::AlignCenter);
        pushButton_3 = new QPushButton(page_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(610, 510, 151, 71));
        pushButton_3->setFont(font1);
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color:qlineargradient(spread:pad, x1:0.494, y1:0.846136, x2:0.494382, y2:1, stop:0 rgba(69, 69, 69, 255), stop:1 rgba(149, 149, 149, 255));\n"
"color:white;\n"
"font: \"Arial\";\n"
"border-radius: 2px;"));
        pushButton_4 = new QPushButton(page_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 510, 151, 71));
        pushButton_4->setFont(font1);
        pushButton_4->setAutoFillBackground(false);
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color:rgb(99, 99, 99);background-color:qlineargradient(spread:pad, x1:0.494, y1:0.846136, x2:0.494382, y2:1, stop:0 rgba(69, 69, 69, 255), stop:1 rgba(149, 149, 149, 255));\n"
"color:white;\n"
"font: \"Arial\";\n"
"border-radius: 2px;color:white;\n"
"font: \"Arial\";\n"
"border-radius: 2px;"));
        textBrowser = new QTextBrowser(page_2);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(420, 140, 311, 291));
        textBrowser->setStyleSheet(QString::fromUtf8("background-color: rgb(77, 77, 77);\n"
"color:white;\n"
"font: \"Arial\";\n"
"border-radius: 2px;"));
        stackedWidgetGroup->addWidget(page_2);

        retranslateUi(form_create_group);

        stackedWidgetGroup->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(form_create_group);
    } // setupUi

    void retranslateUi(QWidget *form_create_group)
    {
        form_create_group->setWindowTitle(QCoreApplication::translate("form_create_group", "Form", nullptr));
        pushButton_2->setText(QCoreApplication::translate("form_create_group", "\320\222\321\213\321\205\320\276\320\264\n"
" \320\262 \320\263\320\273\320\262\320\260\320\275\320\276\320\265 \320\274\320\265\320\275\321\216", nullptr));
        lineEdit->setText(QCoreApplication::translate("form_create_group", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\263\321\200\321\203\320\277\320\277\321\213...", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("form_create_group", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        radioButton->setText(QCoreApplication::translate("form_create_group", "\320\265\321\201\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("form_create_group", "\320\241\320\276\320\267\320\264\320\260\320\275\320\270\320\265 \320\263\321\200\321\203\320\277\320\277\321\213", nullptr));
        pb_create_group->setText(QCoreApplication::translate("form_create_group", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("form_create_group", "\320\223\321\200\321\203\320\277\320\277\320\260", nullptr));
        pushButton->setText(QCoreApplication::translate("form_create_group", "->", nullptr));
        groupBox->setTitle(QCoreApplication::translate("form_create_group", "\320\230\320\263\321\200\320\276\320\272\320\270", nullptr));
        label_3->setText(QCoreApplication::translate("form_create_group", "\320\230\320\263\321\200\320\276\320\272", nullptr));
        label_4->setText(QCoreApplication::translate("form_create_group", "img", nullptr));
        label_5->setText(QCoreApplication::translate("form_create_group", "\320\230\320\263\321\200\320\276\320\272", nullptr));
        label_6->setText(QCoreApplication::translate("form_create_group", "img", nullptr));
        pushButton_3->setText(QCoreApplication::translate("form_create_group", "\320\235\320\260\321\207\320\260\321\202\321\214", nullptr));
        pushButton_4->setText(QCoreApplication::translate("form_create_group", "\320\262\321\213\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class form_create_group: public Ui_form_create_group {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_CREATE_GROUP_H
