#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>
#include <QTcpSocket>
#include "user.h"
#include "QTimer"
#include "group.h"


class Server : public QTcpServer
{

public:
    Server();
    Server(QString ipAddress_ = "89.179.126.139", int port_ = 2525);
    QTcpSocket *socket;
    user *client;
    QByteArray Data;
    void SendToClient(QString message);
    bool start();
    void Requared(QString message, QTcpSocket *socket_sender);
    void SendToSocket(QString message,QTcpSocket *socket_sender);

    Server *getServer();

private:
    QVector <QTcpSocket*> Sockets;
    QVector <user*> users;
    QVector <group*> groups;
    //QVector <QPair<QTcpSocket, qintptr>> mysocketDescriptor;
    QString ipAddress;
    int port;
public slots:
    void incomingConnection(qintptr socketDescriptor) override;
    void SlotReadyRead();
    void Disconnected();
    void CreateGroup();
    void SendDataGroup();
    void ConnectToGroup();
    void CreateUser(qintptr socketDescriptor);
};

#endif // SERVER_H
