#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QProcess"
#include "QTimer"

MainWindow::MainWindow(QWidget *parent,network_client *nt)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    network_obj = nt;
    connect(network_obj, &network_client::signalSizeUsers, this, &MainWindow::updateSizeUser);
    //connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
    qDebug() << "Constructor!";
    mainStackedWidget = new QStackedWidget();
    //fmg = new form_game(this);
    fcg = new form_create_group(this, nt);
    connect(fcg,&form_create_group::signalExit, this, &MainWindow::returnMainpaige );

    //ui->stackedWidget->addWidget(fmg);
    ui->stackedWidget->addWidget(fcg);

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_connect_clicked()
{


    //SendToServer("Login, my login=" + login + " my token=" + token + " ");
    t_result_ping->start(600);
}


void MainWindow::on_pushButton_2_clicked()
{
    //SendToServer(ui->lineEdit->text());
    //ui->lineEdit->clear();

}

void MainWindow::on_lineEdit_returnPressed()
{
    //SendToServer(ui->lineEdit->text());
    //ui->lineEdit->clear();

}

void MainWindow::ping_to_server()
{
    //SendToServer("ping");
}

void MainWindow::on_bt_play_clicked()
{


}

void MainWindow::returnMainpaige()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_bt_create_group_clicked()
{
    ui->stackedWidget->setCurrentWidget(fcg);
    formsStack.push(fcg);
}

void MainWindow::updateSizeUser()
{
    ui->label_num_players->setText(QString::number(network_obj->size_users));
}

void MainWindow::on_bt_exit_clicked()
{
    close();
}

void MainWindow::on_bt_profile_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_bt_connect_group_clicked()
{
    network_obj->SendToServer("");
}
