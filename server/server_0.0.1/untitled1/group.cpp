#include "group.h"

group::group()
{

}

group::~group()
{
    //qDebug() << "~group";
}

void group::insertUser(user* user)
{
    //user->moveToThread(thread());
    if(firstUser==nullptr)
    {
        firstUser = user;
        user->sendedMsgToAnotherUser = "";
        connect(firstUser, &user::signalsendMessage, this, &group::slotSendMsgFirtsUser);
        connect(firstUser, &user::signalDisconnect, this, &group::Disconnected);
        connect(firstUser, &user::signalExitGroup, this, &group::Disconnected);
        connect(firstUser, &user::signalGo, this, &group::slotGo);

    }
    else if(secondUser==nullptr)
    {
        secondUser = user;
        user->sendedMsgToAnotherUser = "";
        connect(secondUser, &user::signalsendMessage, this, &group::slotSendMsgSecondUser);
        connect(secondUser, &user::signalDisconnect, this, &group::Disconnected);
        connect(secondUser, &user::signalExitGroup, this, &group::Disconnected);
        connect(secondUser, &user::signalGo, this, &group::slotGo);



    }
    else return;//достигнуто максимальное количество игроков

}

void group::slotSendMsgFirtsUser()
{
    if(firstUser!=nullptr)
        SendToSocket(firstUser->sendedMsgToAnotherUser, secondUser->socket);
    //Отправка во второй контроллер(+ возможно в будущем всем зрителям)
    if(firstUser!=nullptr && viewers.size() > 0)
        sendViewers( firstUser->sendedMsgToAnotherUser);
}

void group::slotSendMsgSecondUser()
{
    if(secondUser!=nullptr)
        SendToSocket(secondUser->sendedMsgToAnotherUser, firstUser->socket);

    if(secondUser!=nullptr && viewers.size() > 0)
        sendViewers( secondUser->sendedMsgToAnotherUser);
}

void group::Disconnected()
{    
    if(secondUser == (user*)sender() || secondUser == nullptr)
    {
        //qDebug() << "group::Disconnected secondUser";

        if(firstUser != nullptr)
        {
            //qDebug() << "SendToSocket(DCT,firstUser->socket)";
            SendToSocket("DCT",firstUser->socket);
            firstUser->findFastGame = false;
        }
        secondUser = nullptr;
    }
    if(firstUser == (user*)sender() || firstUser == nullptr)
    {
        //qDebug() << "group::Disconnected firstUser";

        if(secondUser != nullptr)
        {
            //qDebug() << "SendToSocket(DCT,secondUser->socket)";
            if(firstUser != nullptr)
            secondUser->findFastGame = false;
            SendToSocket("DCT",secondUser->socket);
        }
        firstUser = nullptr;
    }
    //qDebug() << "(firstUser == nullptr)" << (firstUser == nullptr);
    //qDebug() << "(secondUser == nullptr)" << (secondUser == nullptr);

    if(firstUser == nullptr && secondUser == nullptr){
        //emit signalDestroy();
        this->destroyed();
    }
}

void group::slotGo()
{
    qDebug() << "slotGo";
    SendAll("GO");

    sendViewers("GOV");
    gameIsStarted = true;
}


void group::SendToSocket(QString message, QTcpSocket *socket_sender)
{
    QByteArray Data;
    Data.clear();
    QDataStream out (&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);
    out << message;
    if(socket_sender != nullptr)
        if(socket_sender->state() == QTcpSocket::ConnectedState)
    socket_sender->write(Data);
    qDebug() << "sendedGroup" << socket_sender->socketDescriptor() << "data:" << Data;
}

//используется только для отправки сигнала GO который начинает игру
void group::SendAll(QString message)
{

    if(firstUser == nullptr || secondUser == nullptr) return;

    if(firstUser !=nullptr)
    {
        SendToSocket(message + "W", firstUser->socket);

    }

    if(secondUser !=nullptr)
    {
        SendToSocket(message + "B", secondUser->socket);
    }
}

void group::insertViewers(user *user)
{
    viewers.append(user);
    if(secondUser!=nullptr && firstUser !=nullptr)
        sendViewers("CV " + secondUser->login + " " + firstUser->login + " " + name);
    if(secondUser==nullptr && firstUser !=nullptr)
        sendViewers("CV none " + firstUser->login + " " + name);
    if(secondUser!=nullptr && firstUser ==nullptr)
        sendViewers("CV " + secondUser->login + " none " + name);
}

void group::sendViewers(QString str)
{
    QByteArray Data;
    Data.clear();
    QDataStream out (&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);
    out << str;
    for(auto socket_sender : viewers)
    {
        if(socket_sender!=nullptr && socket_sender->socket != nullptr)
            if(socket_sender->socket->state() == QTcpSocket::ConnectedState)
        socket_sender->socket->write(Data);
        qDebug() << "sendedViewers" << socket_sender->socket->socketDescriptor() << "data:" << Data;
    }
}
