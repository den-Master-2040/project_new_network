#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QStackedWidget>
#include "form_game.h"
#include "form_create_group.h"
#include "stack"
#include "network_client.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, network_client *nt = nullptr);
    ~MainWindow();


    QTimer *t_ping = nullptr;
    QTimer *t_result_ping = nullptr;

private slots:
    void on_connect_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_returnPressed();
    void ping_to_server();
    void returnMainpaige();
    void on_bt_create_group_clicked();
    void updateSizeUser();
    void viewDataGroup();
    void Open_group();

    void on_bt_exit_clicked();

    void on_bt_profile_clicked();

    void on_pushButton_clicked();

    void on_bt_connect_group_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    std::stack<QWidget *> formsStack;
    QStackedWidget *mainStackedWidget = nullptr;
    //form_game *fmg;
    form_create_group *fcg;
    Ui::MainWindow *ui = nullptr;

    network_client *network_obj = nullptr;
    QString *dataInSocket;

};
#endif // MAINWINDOW_H
