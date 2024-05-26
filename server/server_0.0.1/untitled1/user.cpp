#include "user.h"
#include "QDataStream"
#include "serverglobal.h"
user::user(quint32 socketDescriptor)
{
    socket = new QTcpSocket();
    socket->setSocketDescriptor(socketDescriptor);

    connect(socket, &QTcpSocket::disconnected, this, &user::signalDisconnect);
    connect(socket, &QTcpSocket::readyRead, this, &user::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
}

user::~user()
{

}

QString user::getLogin() const
{
    return login;
}

void user::setLogin(const QString &value)
{
    login = value;
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
    if(socket != nullptr)
        if(socket->state() == QTcpSocket::ConnectedState)
            socket->write(Data);
    qDebug() << "sendto " << socket->socketDescriptor() << "msg: " << Data;

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

int randomize(int start, int end)
{
    return rand() % (end - start + 1) + start;
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


        qDebug() << "Sended slotReadyReadUser" << socket->socketDescriptor()<< " : " << str;
        switch (str.at(0).unicode()) {
            case 'p'://ping
            {
                sendMessage("1");
                break;
            }
            case 'L'://logining
            {

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
            case 'C'://Create group
            {
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
            case 'G'://getDataGrouo
            {
                if(str.at(1) == 'G')
                    emit signalGetDataGroup();
                if(str.at(1) == 'O')
                {
                    REF_SERVER->getServer()->groups.at(group)->SendAll("GO");

                }
                break;

            }
            case 'O'://Succesful connect to group
            {
                if(str.at(1) == 'K')
                if(str.at(2) == 'C')
                {
                    QString idGroup;
                    for(int i = 4; i < str.size(); i++)
                    {
                        if(str[i] != ' ')
                            idGroup += str.at(i);
                    }
                    group = idGroup.toInt();

                    emit signalConnectToGroup();
                }
                break;
            }
            case 'T'://sendedMsgToAnotherUser
            {
                //str.remove(0,1);
                sendedMsgToAnotherUser = str;
                emit signalsendMessage();
                break;
            }
            case 'H'://sendedMsgToAnotherUser
            {
                //hod
                sendedMsgToAnotherUser = str;
                emit signalsendMessage();
                break;
            }
            case 'N'://Rename user
            {

                QString new_login = "";

                str.remove(0,2);
                new_login = str;
                spdlog::info("Rename user! username old {0} new {1}", login.toStdString(), new_login.toStdString());
                this->login = new_login;
                break;
            }
            case 'D'://ExitGroup
            {
                if(str.at(1) == 'G')
                    emit signalExitGroup();
                break;
            }
            case 'F'://fastgame
            {
                if(str.at(1) == 'G')
                {

                    int size = REF_SERVER->getServer()->groups.size();

                    if(size > 0)
                    {
                        int i = randomize(0, size)-1;
                        group = i;
                        emit signalConnectToGroup();
                    }
                }
                break;
            }
        }

    }
}
