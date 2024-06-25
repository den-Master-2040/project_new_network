#include "user.h"
#include "QDataStream"
#include "serverglobal.h"
#include "QTimer"
#include <QTextCodec>
user::user(quint32 socketDescriptor)
{
    socket = new QSslSocket();
    socket->setSocketDescriptor(socketDescriptor);

    connect(socket, &QSslSocket::disconnected, this, &user::signalDisconnect);
    //connect(socket, &QSslSocket::readyRead, this, &user::slotReadyRead);
    connect(socket, &QSslSocket::disconnected, socket, &QSslSocket::deleteLater);

    t_ringBuff = new QTimer();
    connect(t_ringBuff, &QTimer::timeout, this, &user::slotReadyRead);
    t_ringBuff->start(25);

    t_readBuff = new QTimer();
    connect(t_readBuff, &QTimer::timeout, this, &user::slotReadBuff);
    t_readBuff->start(25);

}

user::user(QSslSocket *socket)
{
    this->socket = socket;
    connect(socket, &QSslSocket::disconnected, this, &user::signalDisconnect);
    connect(socket, &QSslSocket::readyRead, this, &user::slotReadyRead);
    connect(socket, &QSslSocket::disconnected, socket, &QSslSocket::deleteLater);

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

void user::setBlocked(bool value)
{
    int indexdb = db->findMyIndex(login);
    if(indexdb == -1)return;
    QSqlRecord record = db->selectIndex(indexdb);
    record.setValue("login", value);
    db->setRecord(indexdb, record);
}



void user::sendMessage(QString message)
{

    QByteArray Data; 
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
        if(socket->state() == QSslSocket::ConnectedState)
            socket->write(Data);
    //qDebug() << "sendto " << socket->socketDescriptor() << "msg: " << Data;

}



void user::RequaredMsg(QString str)
{
    //qDebug() << "Sended slotReadyReadUser" << socket->socketDescriptor()<< " : " << str;
    switch (str.at(0).unicode()) {

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

            int indexdb = db->findMyIndex(login);
            //qDebug() << "indexdb: " << indexdb;
            if(indexdb == -1)
            {
                //spdlog::info("not connect user! false token or login");
                sendMessage("NL");
                return;
            }

            QSqlRecord record = db->selectIndex(indexdb);
            //qDebug() << "loginb: " << record.value("login");
            //qDebug() << "passdb: " << record.value("password");

            if(login != record.value("login") || token != record.value("password") || record.value("isblocked") == 1)
            {
                //spdlog::info("not connect user! false token or login");
                sendMessage("NL");
                return;
            }

            this->login = login;
            this->token = token;

            sendMessage("SL");
            //spdlog::info("Connect user! user login {0}, token {1}", login.toStdString(), token.toStdString());
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
                    //qDebug() << "idgroup: " << idGroup << " pass: " << pass;
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
            //sendedMsgToAnotherUser = "";
            break;
        }
        case 'H'://sendedMsgToAnotherUser
        {
            //hod
            sendedMsgToAnotherUser = str;
            emit signalsendMessage();
            //sendedMsgToAnotherUser = "";
            break;
        }
        case 'N'://Rename user
        {
            if(str.at(1) == 'R')
            {
                int indexdb = db->findMyIndex(this->login);
                //qDebug() << "indexdb: " << indexdb;
                //qDebug() << "login: " << login;
                QString new_login = "";

                str.remove(0,2);
                new_login = str;
                //spdlog::info("Rename user! username old {0} new {1}", login.toStdString(), new_login.toStdString());
                this->login = new_login;


                QSqlRecord record = db->selectIndex(indexdb);
                record.setValue("login", login);                
                //qDebug() << "indexdb: " << indexdb;
                //qDebug() << "login: " << login;
                //qDebug() << db->setRecord(indexdb,record);
                break;
            }
            if(str.at(1) == 'P')
            {
                int indexdb = db->findMyIndex(login);
                //qDebug() << "indexdb: " << indexdb;
                QString new_pass = "";

                str.remove(0,2);
                new_pass = str;
                //spdlog::info("Repass user! pass old {0} new {1}", token.toStdString(), new_pass.toStdString());
                this->token = new_pass;


                QSqlRecord record = db->selectIndex(indexdb);
                record.setValue("password", token);
                db->setRecord(indexdb,record);
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
                ////qDebug() << "size group 0, find for users";

                findFastGame = true;
                emit signalFindUsers();



            }
            break;
        }
        case 'U'://userData
        {
            if(str.at(1) == 'D')
            {
                QString countHod;
                int i = 3;
                for(; i < str.size(); i++)
                {
                    if(str[i] != ' ')
                    {
                        countHod += str[i];
                    }
                    else break;
                }
                i++;
                QString countFihgtFugure;
                for(; i < str.size(); i++)
                {
                    if(str[i] != ' ')
                    {
                        countFihgtFugure += str[i];
                    }
                    else break;
                }
                i++;
                QString levelUser;
                for(; i < str.size(); i++)
                {
                    if(str[i] != ' ')
                    {
                        levelUser += str[i];
                    }
                    else break;
                }
                i++;
                QString countWin;
                for(; i < str.size(); i++)
                {
                    if(str[i] != ' ')
                    {
                        countWin += str[i];
                    }
                    else break;
                }
                i++;
                QString countDef;
                for(; i < str.size(); i++)
                {
                    if(str[i] != ' ')
                    {
                        countDef += str[i];
                    }
                    else break;
                }
                i++;
                QString countDraw;
                for(; i < str.size(); i++)
                {
                    if(str[i] != ' ')
                    {
                        countDraw += str[i];
                    }
                    else break;
                }

                int indexdb = db->findMyIndex(login);
                //qDebug() << "indexdb: " << indexdb;

                QSqlRecord record = db->selectIndex(indexdb);

                record.setValue("countHod", countHod);
                record.setValue("countFihgtFugure", countFihgtFugure);
                record.setValue("levelUser", levelUser);
                record.setValue("countWin", countWin);
                record.setValue("countDef", countDef);
                record.setValue("countDraw", countDraw);

                db->setRecord(indexdb,record);
            }
        }
        case 'R'://registrate
        {
            if(str.at(1) == 'E' || str.at(2) == 'G')
            {

                QString login;
                int i = 4;
                for(; i < str.size(); i++)
                {
                    if(str[i] != ' ')
                    {
                        login += str[i];
                    }
                    else break;
                }

                QString token;
                for(; i < str.size(); i++)
                {
                    if(str[i] != ' ')
                    {
                        token += str[i];
                    }
                    else break;
                }

                int indexdb = db->findMyIndex(login);
                //qDebug() << "indexdb: " << indexdb;
                QSqlRecord record = db->selectIndex(indexdb);
                record.setValue("login", login);
                record.setValue("password", token);

                //qDebug() <<"insertNewUser" ;
                if(db->insertNewUser(login,token))
                {
                    sendMessage("SL");
                }

            }
        }
        case 'I'://sendUserDataStatistick
        {
            if(str.at(1) == 'I')
            {
                int indexdb = db->findMyIndex(login);
                //qDebug() << "indexdb: " << indexdb;
                QSqlRecord record = db->selectIndex(indexdb);

                record.setValue("levelUser",
                                updateLvl(record.value("countWin").toInt(),
                                          record.value("countDef").toInt(),
                                          record.value("countHod").toInt()
                                          )
                                );


                QString data = record.value("countHod").toString()
                + " " + record.value("countFihgtFugure").toString()
                + " " + record.value("levelUser").toString()
                + " " + record.value("countWin").toString()
                + " " + record.value("countDef").toString()
                + " " + record.value("countDraw").toString();
                sendMessage("UD " + data);


            }
            break;
        }
        case 'V':
        {
            if(str.at(1) == 'D')
            {
                //отключаемся из группы в качестве зрителя
                emit disconnectViewers();
                break;
            }


            //подключаемся в группу в качестве зрителя
            QString idGroup;
            int i = 2;
            for( ;i < str.size(); i++)
            {
                if(str[i] != ' ')
                    idGroup += str.at(i);
                else break;
            }
            group = idGroup.toInt();
            emit connectViewers();

        }
        case 'S':
        {
            if(msg.at(1) == 'T')
            {
                REF_SERVER->groups.at(group)->gameIsStarted =false;
            }
        }

    }
}



int user::updateLvl(int win, int def, int countGame)
{
    int lvl = 0;
    lvl = countGame/5; //каждые 5 игр уровень повышается. Не зависимо от побед или поражений
    lvl += win * 0.5;
    lvl += def * 0.05;
    this->lvl = lvl;
    return lvl;
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
            ////qDebug() << "Read message for QDataStream...";
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
    ////qDebug() << "byteBefore" << *byte;

    int start = str.indexOf(0x02);

    str.remove(0,start+1);

    int end = str.indexOf(0x03);
    str.remove(end,str.size()-end+1);
    ////qDebug() << "byteAfter" << *byte;
    ////qDebug() << "bufferSize = " << buffer.size();



    //qDebug() << "byteStr:" << str;
    if(str.size() > 1)
        RequaredMsg(str);
}
