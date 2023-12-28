#include "server.h"

Server::Server()
{
    if(this->listen(QHostAddress::Any, 2323))
    {
        qDebug() << "Start!";
    }
    else
    {
        qDebug() << "Not start!";
    }
}

void Server::SendToClient()
{

}

void Server::incomingConnection(qintptr socketDescriptor)
{
    socket = new QTcpSocket();
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead, this, &Server::SlotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);

    Sockets.push_back(socket);
}

void Server::SlotReadyRead()
{

}
