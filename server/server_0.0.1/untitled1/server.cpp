#include "server.h"
#include "QDataStream"
#include "QThread"
#include <QSslSocket>
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

    db = new sqlWorker();

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

    socket = (QSslSocket*)sender();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_5_9);
    if(in.status() == QDataStream::Ok)
    {
        //qDebug() << "Read message for QDataStream...";
        QString str;
        in >> str;
        qDebug() << "Sended SlotReadyRead Server:" << socket->socketDescriptor()<< " : " << str;
        //Requared(str, socket);
        //SendToClient(str);
    }
    else
    {
        //qDebug() << "fail to read message for ыQDataStream!";
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
            if(users.at(i)->socket->state() == QSslSocket::ConnectedState)
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
    client->group = groups.size()-1;
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
        if((groups.at(i)->secondUser == nullptr && groups.at(i)->firstUser != nullptr)
         ||(groups.at(i)->firstUser == nullptr && groups.at(i)->secondUser != nullptr)||
                (groups.at(i)->firstUser != nullptr && groups.at(i)->secondUser != nullptr))
        {//собираем только группы тех, где один или 2 игрока
            dataGroup = dataGroup + "I";
            dataGroup = dataGroup + QString::number(i);
            dataGroup = dataGroup + " G";
            dataGroup = dataGroup + groups.at(i)->name;
            dataGroup = dataGroup + " U";
            if(groups.at(i)->firstUser!=nullptr)
                dataGroup = dataGroup + groups.at(i)->firstUser->login;
            else if(groups.at(i)->secondUser!=nullptr)
                dataGroup = dataGroup + groups.at(i)->secondUser->login;
            dataGroup = dataGroup + " ";
            if(groups.at(i)->firstUser != nullptr && groups.at(i)->secondUser != nullptr)
                dataGroup +="2";
        }
    }
    SendToSocket(dataGroup,client->socket);
}

void Server::ConnectToGroup()
{
    client = (user*)sender();

    groups.at(client->group)->insertUser(client);
    user *secondUser = groups.at(client->group)->secondUser;

    if(groups.at(client->group)->firstUser != nullptr)
        SendToSocket("CU " + secondUser->login + " " + groups.at(client->group)->name,
                     groups.at(client->group)->firstUser->socket);

    if(secondUser != nullptr)
        SendToSocket("CU " + groups.at(client->group)->firstUser->login + " "
                     + groups.at(client->group)->name,secondUser->socket);


    spdlog::info("Client {0} connected to group ", client->login.toStdString());
}

void Server::ready()
{
    qDebug() << "READY!";
    QSslSocket *socket = (QSslSocket*)sender();
    user *client = new user(socket);
    users.push_back(client);
    connect(client, &user::signalCreateGroup,this ,&Server::CreateGroup);
    connect(client, &user::signalGetDataGroup, this, &Server::SendDataGroup);
    connect(client, &user::signalConnectToGroup, this, &Server::ConnectToGroup);
    connect(client, &user::signalDisconnect, this, &Server::Disconnected);
    connect(client, &user::signalFindUsers, this, &Server::FindUserMM);
    connect(client, &user::connectViewers, this, &Server::connectViewer);
    connect(client, &user::disconnectViewers, this, &Server::disconnectViewer);
    client->db = db;
    QThread *th = new QThread();
    client->moveToThread(th);
    th->start();
    client = nullptr;
    spdlog::info("Client connected {0}",socket->socketDescriptor());

    for(int i = 0; i < users.size(); i++)
        SendToSocket("IS" + QString::number(users.size()), users.at(i)->socket); //количество человек на сервере, рассылаем всем
}

void Server::connectViewer()
{
    client = (user*)sender();

    groups.at(client->group)->insertViewers(client);



    spdlog::info("Viewer {0} connected to group ", client->login.toStdString());
}

void Server::disconnectViewer()
{
    client = (user*)sender();

    groups.at(client->group)->viewers.removeOne(client);

    spdlog::info("Viewer {0} disconnected to group ", client->login.toStdString());
}

void Server::CreateUser(qintptr socketDescriptor)
{

    socket = new QSslSocket;
    //socket->ignoreSslErrors();
    socket->setPrivateKey("C:/server.key", QSsl::Rsa);
    socket->setLocalCertificate("C:/server.crt");
    connect(socket, &QSslSocket::encrypted, this, &Server::ready);

    if (socket->setSocketDescriptor(socketDescriptor)) {

        qDebug() << "createuser1";
        addPendingConnection(socket);
        socket->startServerEncryption();

    } else {

    }
}

void Server::FindUserMM()
{
    client = (user*)sender();
    user * secondclient = nullptr;

    bool hardMM = false;// флаг более грубого поиска
    bool isFound = false;
    for(;!isFound;)
    {

        for(auto user : users)
        {
            //_sleep(1200);
            if(user->findFastGame && user!=client)
            {

                if(!requaredLvl(user->lvl, client->lvl))//если уровень игры неприемлемый
                       if(users.size() > 6 )  //и игроков больше 6
                           if(!hardMM) // флаг более грубого поиска
                                continue;//пропускаем и ищем более подходящего пользователя

                secondclient = user;
                isFound = true;
                break;
            }
        }
        if(hardMM)
            return;//это уже второй проход и мы никого не нашли

        hardMM = true;//если мы никого не нашли, пробуем поискать ещё

    }

    if(secondclient == nullptr) return;

    group * gr = new group();
    gr->insertUser(client);
    gr->insertUser(secondclient);
    gr->name = "fastGame";
    gr->password = "";



    if(gr->firstUser !=nullptr && gr->secondUser != nullptr)
    {
        client->sendMessage("MMW " + secondclient->login + " " + gr->name);
        secondclient->sendMessage("MMB " + client->login + " " + gr->name);
        //gr->SendAll("GO");
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
void Server::SendToSocket(QString message, QSslSocket *socket_sender)
{
    Data.clear();
    QDataStream out (&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);
    out << message;
    if(socket_sender != nullptr)
        if(socket_sender->state() == QSslSocket::ConnectedState)
            socket_sender->write(Data);
    qDebug() << "message: " << message << ", socket: " << socket_sender->socketDescriptor();
}

bool Server::requaredLvl(int user1, int user2)
{

    float coeff = 0;//коэффициент разницы между игроками

    if(user1 < 10 && user2 < 10)
    {
        if(user1 > user2)
        {
            coeff = user1/user2;
        }
        else
        {
            coeff = user2/user1;
        }
        return !(coeff > 2.5);
    }


    if(user1 > user2)
    {
        coeff = user1/user2;
    }
    else
    {
        coeff = user2/user1;
    }

    if(user1 > 25 && user2 >25)
    {
        return !(coeff > 1.20);
    }

}

Server * Server::getServer()
{
    return this;
}


void Server::Requared(QString message, QSslSocket *socket_sender)
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
