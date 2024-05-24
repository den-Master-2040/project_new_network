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
    SendToSocket(firstUser->sendedMsgToAnotherUser, secondUser->socket);
    //Отправка во второй контроллер(+ возможно в будущем всем зрителям)
}

void group::slotSendMsgSecondUser()
{
    SendToSocket(secondUser->sendedMsgToAnotherUser, firstUser->socket);
    //Отправка во первый контроллер(+ возможно в будущем всем зрителям)
}

void group::Disconnected()
{    
    if(secondUser == (user*)sender())
        secondUser = nullptr;
    if(firstUser == (user*)sender())
        firstUser = nullptr;

    if(firstUser == nullptr && secondUser == nullptr)
        emit signalDestroy();
}


void group::SendToSocket(QString message, QTcpSocket *socket_sender)
{
    Data.clear();
    QDataStream out (&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);
    out << message;
    socket_sender->write(Data);
}

void group::SendAll(QString message)
{
    if(firstUser !=nullptr)
    SendToSocket(message, firstUser->socket);
    if(secondUser !=nullptr)
    SendToSocket(message, secondUser->socket);
}
