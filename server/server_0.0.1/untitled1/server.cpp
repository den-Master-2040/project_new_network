#include "server.h"
#include "QDataStream"
//#include "spdlog/spdlog.h"
//#include "user.h"
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

bool Server::start()
{
    QString info = "Try to listen. Server ip: " + ipAddress + ", port: " + QString::number(port);
    spdlog::info(info.toStdString());

    //Пытаемся запустить сервер
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
    CreateUser(socketDescriptor);
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
        qDebug() << "Sended SlotReadyRead Server:" << socket->socketDescriptor()<< " : " << str;
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
    user* client = (user*)sender();
    //Нам нужно выполнить ряд действий, когда пользователь отключился
    QString lg = client->getLogin();
    qDebug() << "user Index:" << users.indexOf(client);
    users.remove(users.indexOf(client));//удалить его из общей структуры данных пользователей
    delete client;
    if(users.size() > 0)
        for(int i = 0; i < users.size(); i++)
            if(users.at(i)->socket->state() == QTcpSocket::ConnectedState)
                SendToSocket("IS" + QString::number(users.size()), users.at(i)->socket); //количество человек на сервере, рассылаем всем
    spdlog::info("Client {0} disconnected ", lg.toStdString());
}

void Server::CreateGroup()
{
    client = (user*)sender();
    group *gr = new group();
    gr->name = client->name_group;
    gr->password = client->pass_group;
    groups.push_back(gr);
    connect(gr, &group::signalDestroy, [this,gr](){
        groups.removeOne(gr);
        delete gr;
    });


    gr->insertUser(client);
    spdlog::info("Client {0} create group!", client->login.toStdString());
    SendToSocket("Ok", client->socket);
}

void Server::SendDataGroup()
{
    client = (user*)sender();

    QString dataGroup = "Dg"; //Data Groups

    if(groups.size() == 0)
        SendToSocket(dataGroup,client->socket);

    for(int i = 0; i < groups.size();i++)
    {
        if(groups.at(0)->secondUser == nullptr) //собираем только группы тех, где один игрок
            dataGroup += 'I' + QString::number(i)+ ' ' + 'G' +groups.at(i)->name + ' ' + 'U' +groups.at(i)->firstUser->login + ' ';
    }
    SendToSocket(dataGroup,client->socket);
}

void Server::ConnectToGroup()
{
    client = (user*)sender();

    groups.at(client->group)->insertUser(client);
    user *secondUser = groups.at(client->group)->secondUser;
    SendToSocket("CU " + secondUser->login,groups.at(client->group)->firstUser->socket);

    SendToSocket("CU " + groups.at(client->group)->firstUser->login,secondUser->socket);
    spdlog::info("Client {0} connected to group ", client->login.toStdString());
}

void Server::CreateUser(qintptr socketDescriptor)
{
    user *client_ = new user(socketDescriptor);//создаем объект пользователя. Он сам себе создаст нужный сокет.
    client = client_;

    users.push_back(client);
    connect(client, &user::signalCreateGroup,this ,&Server::CreateGroup);
    connect(client, &user::signalGetDataGroup, this, &Server::SendDataGroup);
    connect(client, &user::signalConnectToGroup, this, &Server::ConnectToGroup);
    connect(client, &user::signalDisconnect, this, &Server::Disconnected);
    client = nullptr;
    spdlog::info("Client connected {0}",socketDescriptor);

    for(int i = 0; i < users.size(); i++)
        SendToSocket("IS" + QString::number(users.size()), users.at(i)->socket); //количество человек на сервере, рассылаем всем
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
    if(socket_sender != nullptr)
        if(socket_sender->state() == QTcpSocket::ConnectedState)
            socket_sender->write(Data);
    qDebug() << "message: " << message << ", socket: " << socket_sender->socketDescriptor();
}

Server * Server::getServer()
{
    return this;
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
            break;
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
