#include "user.h"
#include "QDataStream"

user::user()
{

}

void user::setSocket(QTcpSocket *socket_)
{
    socket = socket_;
    connect(socket, &QTcpSocket::readyRead, this, &user::slotReadyRead);
    t_ping = new QTimer(this);
    connect(t_ping, &QTimer::timeout, this ,&user::isALife);
    t_ping->start(500);
}

void user::sendMessage(QString message)
{
    Data.clear();
    QDataStream out (&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);
    out << message;
    socket->write(Data);
}

int user::isALife()
{
    qDebug() << "user " << login << " state " << QString::number(socket->state() == QTcpSocket::ConnectedState);
    return socket->state() == QTcpSocket::ConnectedState;
}

void user::getDataDestinaition()
{
    //TODO:
    //должно возвращаться :
    /*
     * Количество:
     * - сыгранных игр
     * - Побед
     * - Поражений
     * - Ничьих
     * Итоговый рейтинг
     * История матчей? (именно с кем был прошлый матч - игрок, время)
    */
}

void user::slotReadyRead()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_5_9);
    if(in.status() == QDataStream::Ok)
    {
        //qDebug() << "Read message for QDataStream...";
        QString str;
        in >> str;
        qDebug() << "Sended " << socket->socketDescriptor()<< " : " << str;
        switch (str.at(0).unicode()) {

            case 'p':
            {
                sendMessage("1");
                break;
            }

        }
        //SendToClient(str);
    }
}
