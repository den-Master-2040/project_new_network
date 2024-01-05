#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QProcess"
#include "QTimer"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    t_ping = new QTimer(this);
    connect(t_ping, &QTimer::timeout, this, &MainWindow::ping_to_server);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotReadyRead);
    //connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
    qDebug() << "Constructor!";

    t_ping->start(500);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SendToServer(QString str)
{
    Data.clear();
    QDataStream out (&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);
    out << str;

    qDebug() << socket->state();
    socket->write(Data);
    qDebug() << socket->state();
}

void MainWindow::RequaredRecvMessage(QString message)
{
    switch (message.at(0).unicode()) {
        case 'Y':
        {
            message.remove(0,1);
            mysocketDescriptor = message.toInt();
        }
    }
}

void MainWindow::on_connect_clicked()
{

    socket->connectToHost(ui->lineEdit_2->text(), 2323);
    SendToServer("Login, my login=" + login + " my token=" + token + " ");

}

void MainWindow::slotReadyRead()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_5_9);
    if(in.status() == QDataStream::Ok)
    {
        QString str;
        in >> str;
        //qDebug() << str;
        ui->textBrowser->append(str);
        RequaredRecvMessage(str);
    }
    else
    {
        ui->textBrowser->append("Error read...");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    SendToServer(ui->lineEdit->text());
    ui->lineEdit->clear();

}

void MainWindow::on_lineEdit_returnPressed()
{
    SendToServer(ui->lineEdit->text());
    ui->lineEdit->clear();

}

void MainWindow::ping_to_server()
{
    SendToServer("ping");
}
