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

    /*Data.clear();
    QDataStream out (&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);
    out << message;
    socket->write(Data);*/
    msg.clear();
    msg = message;
    emit signalsendMessage();

    Data.clear();
    QDataStream out (&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);
    out << message;
    socket->write(Data);

}

int user::isALife()
{
    //qDebug() << "user " << login << " state " << QString::number(socket->state() == QTcpSocket::ConnectedState);
    if(socket->state() == QTcpSocket::ConnectedState)
    {
        //сокет работает нормально
        return 1;
    }
    else
    {
        //сокет умер или не подключен!
        emit signalDisconnect();
        t_ping->stop();
        return -1;
    }
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
        //qDebug() << str;
        //qDebug() << "Sended " << socket->socketDescriptor()<< " : " << str;
        switch (str.at(0).unicode()) {

            case 'p':
            {

                //ping

                sendMessage("1");
                break;
            }
            case 'L':
            {

                //logining (authorithation)

                //logining

                int start_login = str.toStdString().find("login") + 6;
                QString login;

                for(int i = start_login; i < str.size(); i++)
                {
                    if(str[i] != ' ')
                    {
                        login += str[i];
                    }
                    else break;
                }
                this->login = login;
                //типо проверка логина

                //ищем токен
                int start_token = str.toStdString().find("token") + 6;
                QString token;
                for(int i = start_token; i < str.size(); i++)
                {
                    if(str[i] != ' ')
                    {
                        token += str[i];
                    }
                    else break;
                }
                this->token = token;
                spdlog::info("Connect user! user login {0}, token {1}", login.toStdString(), token.toStdString());
                break;

            }
            case 'C':
            {

                //Create group

                int start_name_group = 2;
                QString name_group;

                int i = start_name_group;
                for(; i < str.size(); i++)
                {
                    if(str[i] != ' ')
                    {
                        name_group += str[i];
                    }
                    else break;
                }

                //ищем токен
                int start_pass = i+1;
                QString pass;
                for(i = start_pass; i < str.size(); i++)
                {
                    if(str[i] != ' ')
                    {
                        pass += str[i];
                    }
                    else break;
                }
                this->name_group = name_group;
                this->pass_group = pass;
                emit signalCreateGroup();

                break;

            }
        }

    }
}
