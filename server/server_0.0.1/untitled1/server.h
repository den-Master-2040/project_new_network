#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>
#include <QSslSocket>
#include "user.h"
#include "QTimer"
#include "group.h"
#include "sqlworker.h"

class Server : public QTcpServer
{

public:
    Server();
    Server(QString ipAddress_ = "89.179.126.139", int port_ = 2525);
    QSslSocket *socket;
    user *client;
    QByteArray Data;
    void SendToClient(QString message);
    bool start();
    void Requared(QString message, QSslSocket *socket_sender);
    void SendToSocket(QString message,QSslSocket *socket_sender);

    bool requaredLvl(int user1, int user2);

    Server *getServer();
    QVector <group*> groups;
    QVector <user*> users;
    int socket_desc;
    sqlWorker *db = nullptr;
private:
    QVector <QSslSocket*> Sockets;


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
    void FindUserMM();
    void ready();
};

#endif // SERVER_H
