/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *bt_create_group;
    QLabel *label;
    QLabel *label_num_players;
    QPushButton *bt_settings;
    QPushButton *bt_connect_group;
    QPushButton *bt_exit;
    QPushButton *bt_profile;
    QPushButton *bt_mm;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *page_2;
    QLabel *label_2;
    QLineEdit *lineEditName;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEditPass;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QWidget *page_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *pushButton_4;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QLabel *label_11;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(790, 660);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color:rgb(43, 43, 43);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setMinimumSize(QSize(0, 629));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        bt_create_group = new QPushButton(page);
        bt_create_group->setObjectName(QString::fromUtf8("bt_create_group"));
        bt_create_group->setGeometry(QRect(300, 170, 141, 40));
        bt_create_group->setMaximumSize(QSize(150, 40));
        QFont font;
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        bt_create_group->setFont(font);
        bt_create_group->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(580, 570, 91, 41));
        label->setStyleSheet(QString::fromUtf8("\n"
"color:white;\n"
"font: \"Arial\";\n"
""));
        label_num_players = new QLabel(page);
        label_num_players->setObjectName(QString::fromUtf8("label_num_players"));
        label_num_players->setGeometry(QRect(680, 570, 71, 41));
        label_num_players->setStyleSheet(QString::fromUtf8("\n"
"color:white;\n"
"font: \"Arial\";\n"
""));
        bt_settings = new QPushButton(page);
        bt_settings->setObjectName(QString::fromUtf8("bt_settings"));
        bt_settings->setGeometry(QRect(300, 350, 141, 40));
        bt_settings->setMaximumSize(QSize(150, 40));
        bt_settings->setFont(font);
        bt_settings->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        bt_connect_group = new QPushButton(page);
        bt_connect_group->setObjectName(QString::fromUtf8("bt_connect_group"));
        bt_connect_group->setGeometry(QRect(300, 230, 141, 40));
        bt_connect_group->setMaximumSize(QSize(150, 40));
        bt_connect_group->setFont(font);
        bt_connect_group->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        bt_exit = new QPushButton(page);
        bt_exit->setObjectName(QString::fromUtf8("bt_exit"));
        bt_exit->setGeometry(QRect(300, 410, 141, 40));
        bt_exit->setMaximumSize(QSize(150, 40));
        bt_exit->setFont(font);
        bt_exit->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        bt_profile = new QPushButton(page);
        bt_profile->setObjectName(QString::fromUtf8("bt_profile"));
        bt_profile->setGeometry(QRect(300, 290, 141, 40));
        bt_profile->setMaximumSize(QSize(150, 40));
        bt_profile->setFont(font);
        bt_profile->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        bt_mm = new QPushButton(page);
        bt_mm->setObjectName(QString::fromUtf8("bt_mm"));
        bt_mm->setGeometry(QRect(300, 110, 141, 40));
        bt_mm->setMaximumSize(QSize(150, 40));
        bt_mm->setFont(font);
        bt_mm->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        label_5 = new QLabel(page);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(470, 243, 261, 16));
        label_5->setStyleSheet(QString::fromUtf8("\n"
"color:white;\n"
"font: \"Arial\";\n"
""));
        label_6 = new QLabel(page);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 570, 91, 41));
        label_6->setStyleSheet(QString::fromUtf8("\n"
"color:white;\n"
"font: \"Arial\";\n"
""));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        label_2 = new QLabel(page_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 30, 771, 61));
        QFont font1;
        font1.setPointSize(24);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("\n"
"color:white;"));
        label_2->setAlignment(Qt::AlignCenter);
        lineEditName = new QLineEdit(page_2);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));
        lineEditName->setGeometry(QRect(10, 150, 341, 41));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        lineEditName->setFont(font2);
        lineEditName->setStyleSheet(QString::fromUtf8("background-color:rgb(99, 99, 99);\n"
"color:white;\n"
"font: \"Arial\";\n"
"border-radius: 2px;"));
        label_3 = new QLabel(page_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 120, 311, 21));
        QFont font3;
        font3.setPointSize(14);
        label_3->setFont(font3);
        label_3->setStyleSheet(QString::fromUtf8("\n"
"color:white;\n"
""));
        label_4 = new QLabel(page_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 200, 311, 21));
        label_4->setFont(font3);
        label_4->setStyleSheet(QString::fromUtf8("\n"
"color:white;"));
        lineEditPass = new QLineEdit(page_2);
        lineEditPass->setObjectName(QString::fromUtf8("lineEditPass"));
        lineEditPass->setGeometry(QRect(10, 230, 341, 41));
        lineEditPass->setFont(font2);
        lineEditPass->setStyleSheet(QString::fromUtf8("background-color:rgb(99, 99, 99);\n"
"color:white;\n"
"font: \"Arial\";\n"
"border-radius: 2px;"));
        pushButton = new QPushButton(page_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 530, 151, 61));
        QFont font4;
        font4.setPointSize(14);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(50);
        pushButton->setFont(font4);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        pushButton_3 = new QPushButton(page_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(600, 530, 151, 61));
        pushButton_3->setFont(font4);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        scrollArea = new QScrollArea(page_3);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(90, 170, 581, 281));
        scrollArea->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(31, 31, 31);\n"
"\n"
"color:white;\n"
"font: \"Arial\";\n"
"border-radius: 2px;"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 581, 281));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        scrollArea->setWidget(scrollAreaWidgetContents);
        label_7 = new QLabel(page_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(90, 140, 221, 16));
        label_7->setStyleSheet(QString::fromUtf8("\n"
"color:white;"));
        label_8 = new QLabel(page_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(300, 136, 51, 20));
        label_8->setStyleSheet(QString::fromUtf8("\n"
"color:white;"));
        pushButton_4 = new QPushButton(page_3);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 530, 151, 61));
        pushButton_4->setFont(font4);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        label_9 = new QLabel(page_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(0, 29, 771, 41));
        QFont font5;
        font5.setPointSize(18);
        label_9->setFont(font5);
        label_9->setStyleSheet(QString::fromUtf8("\n"
"color:white;"));
        label_9->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(page_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(580, 80, 181, 20));
        label_10->setStyleSheet(QString::fromUtf8("\n"
"color:white;"));
        lineEdit = new QLineEdit(page_3);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(90, 460, 151, 21));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color:rgb(99, 99, 99);\n"
"color:white;\n"
"font: \"Arial\";\n"
"border-radius: 2px;"));
        pushButton_2 = new QPushButton(page_3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(250, 460, 80, 21));
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
        label_11 = new QLabel(page_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(390, 136, 81, 20));
        label_11->setStyleSheet(QString::fromUtf8("\n"
"color:white;"));
        stackedWidget->addWidget(page_3);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 790, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        bt_create_group->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\272\320\276\320\274\320\275\320\260\321\202\321\203", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\230\320\263\321\200\320\276\320\272\320\276\320\262 \320\262 \321\201\320\265\321\202\320\270:", nullptr));
        label_num_players->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\275\320\265\321\202 </p><p>\320\277\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\321\217</p></body></html>", nullptr));
        bt_settings->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        bt_connect_group->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\321\201\320\276\320\265\320\264\320\270\320\275\320\270\321\202\321\214\321\201\321\217 ", nullptr));
        bt_exit->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\271\321\202\320\270", nullptr));
        bt_profile->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        bt_mm->setText(QCoreApplication::translate("MainWindow", "\320\221\321\213\321\201\321\202\321\200\320\260\321\217 \320\270\320\263\321\200\320\260", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260 \321\201\320\265\321\200\320\262\320\265\321\200\320\265 \320\275\320\265\321\202 \320\275\320\270 \320\276\320\264\320\275\320\276\320\271 \320\263\321\200\321\203\320\277\320\277\321\213! \320\241\320\276\320\267\320\264\320\260\320\271\321\202\320\265 \321\201\320\262\320\276\321\216!", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\276!", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\222\320\260\321\210 \320\277\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        lineEditName->setText(QCoreApplication::translate("MainWindow", "DEN_CHIK_master", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        lineEditPass->setText(QCoreApplication::translate("MainWindow", "123", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\263\321\200\321\203\320\277\320\277\321\213", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\230\320\263\321\200\320\276\320\272\320\276\320\262", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\223\321\200\321\203\320\277\320\277\321\213 \320\270\320\263\321\200\320\276\320\272\320\276\320\262", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "*\321\202\320\276\320\273\321\214\320\272\320\276 \321\201\320\262\320\276\320\261\320\276\320\264\320\275\321\213\320\265", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217 \320\263\321\200\321\203\320\277\320\277\321\213...", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\277\320\276\320\270\321\201\320\272", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\320\270\320\264\320\265\320\275\321\202\320\270\321\204\320\270\320\272\320\260\321\202\320\276\321\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
