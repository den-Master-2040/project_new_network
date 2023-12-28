#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>
#include <QTcpSocket>
class Server : public QTcpServer
{

public:
    Server();
    QTcpSocket *socket;
    QByteArray Data;
    void SendToClient();
private:
    QVector <QTcpSocket*> Sockets;
public slots:
    void incomingConnection(qintptr socketDescriptor) override;
    void SlotReadyRead();
};

#endif // SERVER_H
