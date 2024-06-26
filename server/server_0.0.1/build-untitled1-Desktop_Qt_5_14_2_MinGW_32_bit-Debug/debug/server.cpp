#include "server.h"
#include "QDataStream"
#define SPDLOG_COMPILED_LIB 0
#include "spdlog/spdlog.h"
Server::Server()
{
    spdlog::set_level(spdlog::level::trace);
    spdlog::trace("Constructor Server()");

    //Please, set Ip address and port!
    ipAddress = "127.0.0.1";
    port = 2323;
    QString info = "Server default ip: " + ipAddress + ", port: " + QString::number(port);
    spdlog::info(info.toStdString());


}
Server::Server(QString ipAddress_, int port_)
    :ipAddress(ipAddress_), port(port_)
{
    spdlog::set_level(spdlog::level::trace);
    spdlog::trace("Constructor Server()");

    //Please, set Ip address and port!

    QString info = "Server ip: " + ipAddress + ", port: " + QString::number(port);
    spdlog::info(info.toStdString());
}


void Server::incomingConnection(qintptr socketDescriptor)
{
    socket = new QTcpSocket();
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead, this, &Server::SlotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
    connect(socket, &QTcpSocket::disconnected, this,&Server::Disconnected);

    QTcpSocket *Lsocket = new QTcpSocket(socket);
    Sockets.push_back(Lsocket);
    //mysocketDescriptor.push_back(QPair<QTcpSocket, qintptr>(*socket,socketDescriptor));
    spdlog::info("Client connected {0}",socketDescriptor);
}

void Server::SlotReadyRead()
{
    socket = (QTcpSocket*)sender();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_5_9);
    if(in.status() == QDataStream::Ok)
    {
        qDebug() << "Read message for QDataStream...";
        QString str;
        in >> str;
        qDebug() << "Sended" << socket->socketDescriptor()<< " : " << str;

        SendToClient(str);
    }
    else
    {
        qDebug() << "fail to read message for QDataStream!";
    }

}

void Server::Disconnected()
{
    for(int i = 0; i <Sockets.size();i++)
    {
        if(Sockets[i] == socket)
            qDebug() << "Disconnected////..." << Sockets[i]->socketDescriptor();
    }
    socket = (QTcpSocket*)sender();
    //qintptr descriprot;
    //for(int i = 0; i < Sockets
    qDebug() << "Disconnected..." << socket->socketDescriptor();
}

void Server::SendToClient(QString message)
{
    Data.clear();
    QDataStream out (&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);
    out << message;
    Requared(message);
    //socket->write(Data);
    qDebug() << "Send to client" << message;
    for(int i = 0; i < Sockets.size(); i++)
    {
        Sockets[i]->write(Data);
    }
}

bool Server::start()
{
    QString info = "Try to listen. Server ip: " + ipAddress + ", port: " + QString::number(port);
    spdlog::info(info.toStdString());
    //Try to listen..
    if(this->listen(QHostAddress(ipAddress), port))
    {
        spdlog::info("Server start successfully!");

    }
    else
    {
        //надо бы прикратить работу приложения после этого..
        spdlog::error("Can't start to listen server! Probably incorrect IP address or port is occupied by another process");
        spdlog::critical("Server start faild!");

    }
}

void Server::Requared(QString message)
{
    switch (message.at(0).unicode()) {
        case 'L':
        {
            //logining
            int start_login = message.toStdString().find("login");
            QString login;
            for(QChar item : login)
            {
                if(item!=' ')
                    login +=item;
                else break;
            }

        }
    }
}
