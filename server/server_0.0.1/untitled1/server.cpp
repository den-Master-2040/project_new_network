#include "server.h"
#include "QDataStream"
//#include "spdlog/spdlog.h"
//#include "user.h"
Server::Server()
{
    spdlog::set_level(spdlog::level::trace);
    spdlog::trace("Constructor Server()");

    //Please, set Ip address and port!
    ipAddress = "89.179.126.139";
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

bool Server::start()
{
    QString info = "Try to listen. Server ip: " + ipAddress + ", port: " + QString::number(port);
    spdlog::info(info.toStdString());
    //Try to listen..
    if(this->listen(QHostAddress(ipAddress), port))
    {
        spdlog::info("Server start successfully!");
        return 0;
    }
    else
    {
        //надо бы прикратить работу приложения после этого..
        spdlog::error("Can't start to listen server! Probably incorrect IP address or port is occupied by another process");
        spdlog::critical("Server start faild!");
        return -1;
    }

}

void Server::incomingConnection(qintptr socketDescriptor)
{
    socket = new QTcpSocket();
    socket->setSocketDescriptor(socketDescriptor);

    client = new user();
    client->setSocket(socket);
    client->socketDescriptor = socketDescriptor;

    users.push_back(client);


    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
    connect(client, &user::signalDisconnect, this, &Server::Disconnected);
    connect(client, &user::signalCreateGroup,this ,&Server::CreateGroup);
    connect(client, &user::signalGetDataGroup, this, &Server::SendDataGroup);

    //QTcpSocket *Lsocket = new QTcpSocket(socket);
    //Sockets.push_back(socket);
    //mysocketDescriptor.push_back(QPair<QTcpSocket, qintptr>(*socket,socketDescriptor));



    spdlog::info("Client connected {0}",socketDescriptor);
    //SendToSocket("Y" + QString::number(socketDescriptor), socket); //Y - your descriptor
    for(int i = 0; i < users.size(); i++)
        SendToSocket("IS" + QString::number(users.size()), users.at(i)->socket); //количество человек на сервере, рассылаем всем
}

void Server::SlotReadyRead()
{
    socket = (QTcpSocket*)sender();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_5_9);
    if(in.status() == QDataStream::Ok)
    {
        //qDebug() << "Read message for QDataStream...";
        QString str;
        in >> str;
        //qDebug() << "Sended " << socket->socketDescriptor()<< " : " << str;
        Requared(str, socket);
        //SendToClient(str);
    }
    else
    {
        //qDebug() << "fail to read message for QDataStream!";
    }

}

void Server::Disconnected()
{

    //socket = (QTcpSocket*)sender();
    client = (user*)sender();

    int i = 0;
    for(; i < users.size(); i++)
    {
        if(client == users[i])
            break;
    }
    users.remove(i);

    spdlog::info("Client {0} disconnected ", client->login.toStdString());
    for(int i = 0; i < users.size(); i++)
        SendToSocket("IS" + QString::number(users.size()), users.at(i)->socket); //количество человек на сервере, рассылаем всем
}

void Server::CreateGroup()
{
    client = (user*)sender();
    group *gr = new group();
    gr->name = client->name_group;
    gr->password = client->pass_group;
    groups.push_back(gr);
    gr->insertUser(client);
    spdlog::info("Client {0} create group!", client->login.toStdString());
    SendToSocket("Ok", client->socket);
}

void Server::SendDataGroup()
{
    client = (user*)sender();

    QString dataGroup = "DG"; //Data Groups
    for(int i = 0; i < groups.size();i++)
    {
        if(groups.at(0)->secondUser == nullptr) //собираем только группы тех, где один игрок
            dataGroup += QString::number(i)+ ' ' + groups.at(i)->name + ' ' + groups.at(i)->firstUser->login + ' ';
    }
}

void Server::SendToClient(QString message)
{
    Data.clear();
    QDataStream out (&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);
    out << message;
    //Requared(message);
    //socket->write(Data);
    //qDebug() << "Send to client" << message;
    for(int i = 0; i < Sockets.size(); i++)
    {
        Sockets[i]->write(Data);
    }
}
void Server::SendToSocket(QString message, QTcpSocket *socket_sender)
{
    Data.clear();
    QDataStream out (&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);
    out << message;
    socket_sender->write(Data);
}


void Server::Requared(QString message, QTcpSocket *socket_sender)
{
    switch (message.at(0).unicode()) {
        case 'L':
        {
            //logining
            int start_login = message.toStdString().find("login") + 6;
            QString login;

            for(int i = start_login; i < message.size(); i++)
            {
                if(message[i] != ' ')
                {
                    login += message[i];
                }
                else break;
            }
            //типо проверка логина

            //ищем токен
            int start_token = message.toStdString().find("token") + 6;
            QString token;
            for(int i = start_token; i < message.size(); i++)
            {
                if(message[i] != ' ')
                {
                    token += message[i];
                }
                else break;
            }
            spdlog::info("Connect user! user login {0}, token {1}", login.toStdString(), token.toStdString());
            break;

        }
        case 'p':
        {
            SendToSocket("1", socket_sender);
            break;
        }
        case 'I':
        {
            spdlog::info("User disconnect");
        }
        case 'C':
        {
            //logining
            int start_name_group = 2;
            QString name_group;
            int i = start_name_group;
            for(; i < message.size(); i++)
            {
                if(message[i] != ' ')
                {
                    name_group += message[i];
                }
                else break;
            }
            //типо проверка логина

            //ищем токен
            int start_pass = i+1;
            QString pass;
            for( i = start_pass; i < message.size(); i++)
            {
                if(message[i] != ' ')
                {
                    pass += message[i];
                }
                else break;
            }
            spdlog::info("Create group! name group {0}, pass {1}", name_group.toStdString(), pass.toStdString());
            break;
        }
    }
}
