#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>
#include <QTcpSocket>
class Server : public QTcpServer
{

public:
    Server();
    Server(QString ipAddress_ = "127.0.0.1", int port_ = 2323);
    QTcpSocket *socket;
    QByteArray Data;
    void SendToClient(QString message);
    bool start();
    void Requared(QString message);
private:
    QVector <QTcpSocket*> Sockets;
    //QVector <QPair<QTcpSocket, qintptr>> mysocketDescriptor;
    QString ipAddress;
    int port;
public slots:
    void incomingConnection(qintptr socketDescriptor) override;
    void SlotReadyRead();
    void Disconnected();
};

#endif // SERVER_H
