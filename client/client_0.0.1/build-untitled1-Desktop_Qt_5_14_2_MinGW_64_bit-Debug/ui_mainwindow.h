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
    QWidget *page_2;
    QLabel *label_2;
    QLineEdit *lineEditName;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEditPass;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(790, 660);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setMinimumSize(QSize(0, 600));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        bt_create_group = new QPushButton(page);
        bt_create_group->setObjectName(QString::fromUtf8("bt_create_group"));
        bt_create_group->setGeometry(QRect(300, 120, 141, 40));
        bt_create_group->setMaximumSize(QSize(150, 40));
        QFont font;
        font.setPointSize(12);
        bt_create_group->setFont(font);
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(580, 520, 91, 41));
        label_num_players = new QLabel(page);
        label_num_players->setObjectName(QString::fromUtf8("label_num_players"));
        label_num_players->setGeometry(QRect(680, 520, 71, 41));
        bt_settings = new QPushButton(page);
        bt_settings->setObjectName(QString::fromUtf8("bt_settings"));
        bt_settings->setGeometry(QRect(300, 300, 141, 40));
        bt_settings->setMaximumSize(QSize(150, 40));
        bt_settings->setFont(font);
        bt_connect_group = new QPushButton(page);
        bt_connect_group->setObjectName(QString::fromUtf8("bt_connect_group"));
        bt_connect_group->setGeometry(QRect(300, 180, 141, 40));
        bt_connect_group->setMaximumSize(QSize(150, 40));
        bt_connect_group->setFont(font);
        bt_exit = new QPushButton(page);
        bt_exit->setObjectName(QString::fromUtf8("bt_exit"));
        bt_exit->setGeometry(QRect(300, 360, 141, 40));
        bt_exit->setMaximumSize(QSize(150, 40));
        bt_exit->setFont(font);
        bt_profile = new QPushButton(page);
        bt_profile->setObjectName(QString::fromUtf8("bt_profile"));
        bt_profile->setGeometry(QRect(300, 240, 141, 40));
        bt_profile->setMaximumSize(QSize(150, 40));
        bt_profile->setFont(font);
        bt_mm = new QPushButton(page);
        bt_mm->setObjectName(QString::fromUtf8("bt_mm"));
        bt_mm->setGeometry(QRect(300, 60, 141, 40));
        bt_mm->setMaximumSize(QSize(150, 40));
        bt_mm->setFont(font);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        label_2 = new QLabel(page_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 30, 771, 61));
        QFont font1;
        font1.setPointSize(24);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        lineEditName = new QLineEdit(page_2);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));
        lineEditName->setGeometry(QRect(10, 150, 341, 41));
        QFont font2;
        font2.setPointSize(11);
        lineEditName->setFont(font2);
        label_3 = new QLabel(page_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 120, 311, 21));
        QFont font3;
        font3.setPointSize(14);
        label_3->setFont(font3);
        label_4 = new QLabel(page_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 200, 311, 21));
        label_4->setFont(font3);
        lineEditPass = new QLineEdit(page_2);
        lineEditPass->setObjectName(QString::fromUtf8("lineEditPass"));
        lineEditPass->setGeometry(QRect(10, 230, 341, 41));
        lineEditPass->setFont(font2);
        pushButton = new QPushButton(page_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(0, 530, 151, 61));
        stackedWidget->addWidget(page_2);

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
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\222\320\260\321\210 \320\277\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        lineEditName->setText(QCoreApplication::translate("MainWindow", "DEN_CHIK_master", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        lineEditPass->setText(QCoreApplication::translate("MainWindow", "123", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
