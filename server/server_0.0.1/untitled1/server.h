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
    Server();//конструктор сервера
    Server(QString ipAddress_ = "89.179.126.139", int port_ = 2525);//конструктор сервера с заданными параметрами
    QSslSocket *socket; //главный сокет
    
    void SendToClient(QString message);//функция отправки данных для всех клиентов


    void SendToSocket(QString message,QSslSocket *socket_sender);//отправка данных на конкретный сокет

    bool requaredLvl(int user1, int user2); //проверка уровня

    Server *getServer();        //функция для удобного доступа к серверу
    QVector <group*> groups;
    QVector <user*> users;
    
    
    sqlWorker *db = nullptr;
    QString ipAddress = "";
    int port = 0;
    
    user *client;
    QByteArray Data;
    bool viewmode = false;
    //QVector <QPair<QTcpSocket, qintptr>> mysocketDescriptor;
signals:
    void signalstartServer();
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
    void connectViewer();
    void disconnectViewer();
    void start();//функция запуска сервера

private:
    QVector <QSslSocket*> Sockets;


};

#endif // SERVER_H
