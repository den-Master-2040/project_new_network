#include "group.h"

group::group()
{

}

group::~group()
{
    qDebug() << "~group";
}

void group::insertUser(user* user)
{
    if(firstUser==nullptr)
    {
        firstUser = user;
        connect(firstUser, &user::signalsendMessage, this, &group::slotSendMsgFirtsUser);
        connect(firstUser, &user::signalDisconnect, this, &group::Disconnected);
        connect(firstUser, &user::signalExitGroup, this, &group::Disconnected);

    }
    else if(secondUser==nullptr)
    {
        secondUser = user;
        connect(secondUser, &user::signalsendMessage, this, &group::slotSendMsgSecondUser);
        connect(secondUser, &user::signalDisconnect, this, &group::Disconnected);
        connect(secondUser, &user::signalExitGroup, this, &group::Disconnected);
    }
    else return;//достигнуто максимальное количество игроков
}

void group::slotSendMsgFirtsUser()
{
    if(secondUser!=nullptr)
    SendToSocket(firstUser->sendedMsgToAnotherUser, secondUser->socket);
    //Отправка во второй контроллер(+ возможно в будущем всем зрителям)
}

void group::slotSendMsgSecondUser()
{
    if(firstUser!=nullptr)
    SendToSocket(secondUser->sendedMsgToAnotherUser, firstUser->socket);
    //Отправка во первый контроллер(+ возможно в будущем всем зрителям)
}

void group::Disconnected()
{    
    if(secondUser == (user*)sender() || secondUser == nullptr)
    {
        qDebug() << "group::Disconnected secondUser";
        qDebug() << "SendToSocket(DCT,firstUser->socket)";
        if(firstUser != nullptr)
        SendToSocket("DCT",firstUser->socket);
        secondUser = nullptr;
    }
    if(firstUser == (user*)sender() || firstUser == nullptr)
    {
        qDebug() << "group::Disconnected firstUser";
        qDebug() << "SendToSocket(DCT,secondUser->socket)";
        if(secondUser != nullptr)
        SendToSocket("DCT",secondUser->socket);
        firstUser = nullptr;
    }


    if(firstUser == nullptr && secondUser == nullptr)
        emit signalDestroy();
}


void group::SendToSocket(QString message, QTcpSocket *socket_sender)
{
    Data.clear();
    QDataStream out (&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);
    out << message;
    if(socket_sender != nullptr)
        if(socket_sender->state() == QTcpSocket::ConnectedState)
    socket_sender->write(Data);
}

//используется только для отправки сигнала GO который начинает игру
void group::SendAll(QString message)
{

    if(firstUser == nullptr || secondUser == nullptr) return;

    if(firstUser !=nullptr)
    SendToSocket(message, firstUser->socket);
    if(secondUser !=nullptr)
    SendToSocket(message, secondUser->socket);
}
