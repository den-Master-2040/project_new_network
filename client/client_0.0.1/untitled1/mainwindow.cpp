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
    t_ping = new QTimer();
    connect(network_obj, &network_client::signalSizeUsers, this, &MainWindow::updateSizeUser);
    connect(network_obj, &network_client::signalendDataGroup,this,&MainWindow::viewDataGroup);
    connect(t_ping, &QTimer::timeout, [this](){
        if(network_obj->socket->state()==QTcpSocket::ConnectedState)
            ui->label_6->setText("Подключено!");
        else
            {
            network_obj->socket->connectToHost("127.0.0.1", 2323);
            network_obj->SendToServer("Login, my login=" + network_obj->login + " my token=" + network_obj->token + " ");
            ui->label_6->setText("Нет связи с сервером...");
        }
    });

    //connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
    qDebug() << "Constructor!";
    mainStackedWidget = new QStackedWidget();
    //fmg = new form_game(this);
    fcg = new form_create_group(this, nt);
    connect(fcg,&form_create_group::signalExit, this, &MainWindow::returnMainpaige );

    //ui->stackedWidget->addWidget(fmg);
    ui->stackedWidget->addWidget(fcg);
    //viewDataGroup();
    ui->label_5->setVisible(false);
    t_ping->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_connect_clicked()
{


    //SendToServer("Login, my login=" + login + " my token=" + token + " ");
    //t_result_ping->start(600);
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

void MainWindow::viewDataGroup()
{


    if(network_obj->groups.size() == 0)
    {
        ui->label_5->setVisible(true);
        return;
    }
    ui->stackedWidget->setCurrentIndex(2);

    ui->scrollArea->takeWidget();
    QWidget *widget = new QWidget();
    QSize size = ui->scrollArea->size();
    widget->setMinimumSize(size.width(),size.height());
    widget->setLayout(ui->gridLayout_2);
    ui->scrollArea->setWidget(widget);
    for(int i = 0; i < network_obj->groups.size(); i++)
    {
        ui->label_5->setVisible(false);
        QLabel *name_group;
        name_group = new QLabel(ui->scrollAreaWidgetContents);
        name_group->setObjectName(QString::fromUtf8("label_5")+QString::number(i));
        name_group->setText(network_obj->groups.at(i).name);
        name_group->setMinimumSize(QSize(200,21));

        ui->gridLayout_2->addWidget(name_group, i+1, 0, 1, 1);

        QLabel *size_player;
        size_player = new QLabel(ui->scrollAreaWidgetContents);
        size_player->setObjectName(QString::fromUtf8("label_5")+QString::number(i));
        size_player->setText("1/2");
        size_player->setMinimumSize(QSize(100,21));

        ui->gridLayout_2->addWidget(size_player, i+1, 1, 1, 1);

        QLabel *id;
        id = new QLabel(ui->scrollAreaWidgetContents);
        id->setObjectName(QString::fromUtf8("label_5")+QString::number(i));
        id->setText(QString::number(network_obj->groups.at(i).id));
        id->setMinimumSize(QSize(100,21));

        ui->gridLayout_2->addWidget(id, i+1, 2, 1, 1);

        QPushButton *pb;
        pb = new QPushButton(ui->scrollAreaWidgetContents);
        pb->setObjectName(QString::fromUtf8("pushButton_2")+QString::number(i));
        pb->setText("Войти");
        pb->setStyleSheet("QPushButton{\n\nbackground-color:qlineargradient(spread:pad, "
                          "x1:0.494, y1:0.846136, x2:0.494382, y2:1, stop:0 rgba(69, 69, 69, "
                          "255), stop:1 rgba(149, 149, 149, 255));\ncolor:white;\nborder-radius:"
                          " 2px;\n}\nQPushButton::pressed{\n\nbackground-color:qlineargradient(spread:pad,"
                          " x1:0.426, y1:0.800682, x2:0.427, y2:1, stop:0 rgba(37, 37, 37, 255), stop:"
                          "1 rgba(87, 87, 87, 255));\ncolor:white;;\nborder-radius: 2px;\n};\n");

        ui->gridLayout_2->addWidget(pb, i+1, 3, 1, 1);

        connect(pb, &QPushButton::clicked,[this,i](){
            //fcg->nameSecondUser = network_obj->groups.at(i).name_first_user;//пихаем логин первого юзера из сети
            fcg->nameFirstUser = network_obj->login;//пихаем свой логин
            fcg->nextPage();
            on_bt_create_group_clicked();
            network_obj->SendToServer("OKC " + QString::number(network_obj->groups.at(i).id)); //get gpoup
        });

    }
}

void MainWindow::Open_group()
{

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
    network_obj->SendToServer("GG"); //get gpoup
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_3_clicked()
{
    network_obj->login = ui->lineEditName->text();
    network_obj->token = ui->lineEditPass->text();

    network_obj->SendToServer("N " + network_obj->login);
}
