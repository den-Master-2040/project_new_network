#include "network_client.h"
#include <QDataStream>
network_client::network_client(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);
    t_result_ping = new QTimer(this);

    //connect(t_result_ping, &QTimer::timeout, [this](){
    //if(socket->state() != QTcpSocket::UnconnectedState)
    //ui->label_3->setStyleSheet("QLabel{\n	background-color: rgb(255, 255, 0);\n\n}");
    //else
    //ui->label_3->setStyleSheet("QLabel{\n	background-color: rgb(170, 0, 0);\n\n}");
    //});
    connect(socket, &QTcpSocket::readyRead, this, &network_client::slotReadyRead);
    socket->connectToHost("127.0.0.1", 2323);
    SendToServer("Login, my login=" + login + " my token=" + token + " ");
}

void network_client::SendToServer(QString str)
{
    Data.clear();
    QDataStream out (&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);
    out << str;

    qDebug() << socket->state();
    socket->write(Data);
    qDebug() << socket->state();
}

void network_client::RequaredRecvMessage(QString message)
{
    if(message.size() > 0)
    switch (message.at(0).unicode()) {
        case 'Y':
        {
            message.remove(0,1);
            mysocketDescriptor = message.toInt();
            break;
        }
        case 'O':
        {
            if(message.at(1) == 'k')
            {
                emit signalOkToCreateGroup();
            }
            break;
        }
        case 'I':
        {
            if(message.at(1) == 'S')
            {
                message.remove(0,2);
                size_users = message.toInt();
                emit signalSizeUsers();
            }
            break;
        }
        default:break;
    }
}

void network_client::slotReadyRead()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_5_9);
    if(in.status() == QDataStream::Ok)
    {
        //qDebug() << "Read message for QDataStream...";
        QString str;
        in >> str;
        lastMessage = str;
        RequaredRecvMessage(str);
    }
    else
    {
        //qDebug() << "fail to read message for QDataStream!";
    }
}
