#include "network_client.h"
#include <QDataStream>
network_client::network_client(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);
    t_result_ping = new QTimer(this);

    //connect(t_result_ping, &QTimer::timeout, [this](){
    //if(socket->state() != QTcpSocket::UnconnectedState)
    //ui->label_3->setStyleSheet("QLabel{\n	background-color: rgb(255, 255, 0);\n\n}");
    //else
    //ui->label_3->setStyleSheet("QLabel{\n	background-color: rgb(170, 0, 0);\n\n}");
    //});
    connect(socket, &QTcpSocket::readyRead, this, &network_client::slotReadyRead);
    socket->connectToHost("89.179.126.139", 2323);
    SendToServer("Login, my login=" + login + " my token=" + token + " ");
}

void network_client::SendToServer(QString str)
{
    Data.clear();
    QDataStream out (&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);
    out << str;

    qDebug() << socket->state();
    socket->write(Data);
    qDebug() << socket->state();
}

void network_client::RequaredRecvMessage(QString message)
{
    if(message.size() > 0)
    switch (message.at(0).unicode()) {
        case 'Y':
        {
            message.remove(0,1);
            mysocketDescriptor = message.toInt();
            break;
        }
        case 'O':
        {
            if(message.at(1) == 'k')
            {
                emit signalOkToCreateGroup();
            }
            break;
        }
        case 'I':
        {
            if(message.at(1) == 'S')
            {
                message.remove(0,2);
                size_users = message.toInt();
                emit signalSizeUsers();
            }
            break;
        }
        case 'D':
        {
            if(message.size() > 2){
            if(message.at(1) == 'g')
            {
                group lg;
                groups.clear();
                for(int i = 0; i < message.size(); i++)
                {


                    if(message.at(i) == 'I')
                    {
                        QString index;
                        for(i++;message.at(i) != ' '; i++)
                            index+=message.at(i);

                        lg.id = index.toInt();
                        i++;
                    }

                    if(message.at(i) == 'G')
                    {
                        QString name_group;
                        for(i++;message.at(i) != ' '; i++)
                            name_group+=message.at(i);

                        lg.name = name_group;
                        i++;
                    }

                    if(message.at(i) == 'U')
                    {
                        QString user_login;
                        for(i++;message.at(i) != ' '; i++)
                            user_login+=message.at(i);

                        lg.name_first_user = user_login;

                    }
                    if(lg.id != -1 && lg.name != "" && lg.name_first_user != "")
                    {
                        groups.push_back(lg);
                        lg.id = -1;
                        lg.name = "";
                        lg.name_first_user = "";
                    }
                }
                emit signalendDataGroup();

            }
            } else emit signalendDataGroup();
            break;
        }
        case 'C':
        {
            if(message.at(1) == 'U')
            {
                QString lsu;
                for(int i = 3; i < message.size(); i++)
                    lsu += message.at(i);

                login_secondUser = lsu;
                qDebug() << "login_secondUser: " << login_secondUser;
                emit signalSecondLogin();
            }
            break;
        }
        case 'T':
        {
            message.remove(0, 1);
            messageToUser = message;
            emit signalRecvMessageFromAnotherUser();
            break;
        }
        default:break;
    }
}

void network_client::slotReadyRead()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_5_9);
    if(in.status() == QDataStream::Ok)
    {
        //qDebug() << "Read message for QDataStream...";
        QString str;
        in >> str;
        lastMessage = str;
        RequaredRecvMessage(str);
    }
    else
    {
        //qDebug() << "fail to read message for QDataStream!";
    }
}
