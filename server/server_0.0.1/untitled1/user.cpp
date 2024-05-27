#include "user.h"
#include "QDataStream"
#include "serverglobal.h"
#include "QTimer"
#include <QTextCodec>
user::user(quint32 socketDescriptor)
{
    socket = new QTcpSocket();
    socket->setSocketDescriptor(socketDescriptor);

    connect(socket, &QTcpSocket::disconnected, this, &user::signalDisconnect);
    //connect(socket, &QTcpSocket::readyRead, this, &user::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);

    t_ringBuff = new QTimer();
    connect(t_ringBuff, &QTimer::timeout, this, &user::slotReadyRead);
    t_ringBuff->start(25);

    t_readBuff = new QTimer();
    connect(t_readBuff, &QTimer::timeout, this, &user::slotReadBuff);
    t_readBuff->start(25);

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

void user::RequaredMsg(QString str)
{
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
                //REF_SERVER->getServer()->groups.at(group)->SendAll("GO");
                emit signalGo();
            }
            break;

        }
        case 'O'://Succesful connect to group
        {
            if(str.at(1) == 'K')
            if(str.at(2) == 'C')
            {
                QString idGroup;
                int i = 4;
                for( ;i < str.size(); i++)
                {
                    if(str[i] != ' ')
                        idGroup += str.at(i);
                    else break;
                }
                group = idGroup.toInt();

                if(REF_SERVER->getServer()->groups.at(group)->password !="")
                {
                    //если у группы есть пароль - проверяем чо прислал юзер
                    QString pass;
                    for(i++; i < str.size(); i++)
                    {
                        if(str[i] != ' ')
                            pass += str.at(i);

                    }
                    qDebug() << "idgroup: " << idGroup << " pass: " << pass;
                    if(pass == REF_SERVER->getServer()->groups.at(group)->password)
                        emit signalConnectToGroup();

                }else //иначе без разбору заходим
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
            if(str.at(1) == 'R')
            {
                QString new_login = "";

                str.remove(0,2);
                new_login = str;
                spdlog::info("Rename user! username old {0} new {1}", login.toStdString(), new_login.toStdString());
                this->login = new_login;
                break;
            }
            if(str.at(1) == 'P')
            {
                QString new_pass = "";

                str.remove(0,2);
                new_pass = str;
                spdlog::info("Repass user! pass old {0} new {1}", login.toStdString(), new_pass.toStdString());
                this->token = new_pass;
                break;
            }
        }
        case 'D'://ExitGroup
        {
            if(str.at(1) == 'G')
            {
                findFastGame = false;
                emit signalExitGroup();
            }
            break;
        }
        case 'F'://fastgame
        {
            if(str.at(1) == 'G')
            {

                //int size = REF_SERVER->getServer()->groups.size();

                //if(size > 0)
                //{
                //    int i = randomize(0, size)-1;
                //    group = i;
                //    emit signalConnectToGroup();
                //    break;
                //}
                //qDebug() << "size group 0, find for users";

                findFastGame = true;
                emit signalFindUsers();



            }
            break;
        }
    }
}

int user::findStartMsg(QByteArray byte)
{
    for(int i = 0; i < byte.size(); i++)
    {
        switch (byte.at(i)) {
            case 'p'://ping
            case 'L':
            case 'C':
            case 'G'://getDataGrouo
            case 'O'://Succesful connect to group
            case 'T'://sendedMsgToAnotherUser
            case 'H'://sendedMsgToAnotherUser
            case 'N'://Rename user
            case 'D'://ExitGroup
            case 'F':
                return i;
            default:
                continue;

        }
        return -1;
    }
}

int randomize(int start, int end)
{
    return rand() % (end - start + 1) + start;
}

void user::slotReadyRead()
{
    if(socket!=nullptr)
    {
        QDataStream in(socket);
        in.setVersion(QDataStream::Qt_5_9);
        if(in.status() == QDataStream::Ok)
        {
            //qDebug() << "Read message for QDataStream...";
            QString str;
            in >> str;

            if(str != "")
                buffer.push_back(str);
        }

    }

}

void user::slotReadBuff()
{
    if(buffer.isEmpty()) return;
    QString str = buffer.front();

    if(!buffer.isEmpty())
        buffer.pop_front();
    //qDebug() << "byteBefore" << *byte;

    int start = str.indexOf(0x02);

    str.remove(0,start+1);

    int end = str.indexOf(0x03);
    str.remove(end,str.size()-end+1);
    //qDebug() << "byteAfter" << *byte;
    //qDebug() << "bufferSize = " << buffer.size();



    qDebug() << "byteStr:" << str;
    if(str.size() > 1)
        RequaredMsg(str);
}
