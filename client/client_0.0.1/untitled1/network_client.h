#ifndef network_client_H
#define network_client_H

#include <QObject>
#include <QTcpSocket>
#include <QTimer>
class network_client : public QObject
{
    Q_OBJECT
public:
    explicit network_client(QObject *parent = nullptr);
    void SendToServer(QString str);
    void RequaredRecvMessage(QString message);

    QByteArray Data;
    QTcpSocket *socket= nullptr;
    int mysocketDescriptor = -1; // дескриптор который присвоил нам сервер
    //QTimer *t_ping = nullptr;
    QTimer *t_result_ping = nullptr;
    QString lastMessage;
    QString login = "DEN_CHIK_master";
    QString token = "1qaz";
    int size_users = -1;

public slots:
    void slotReadyRead();

signals:
    void signalOkToCreateGroup();
    void signalSizeUsers();
};

#endif // network_client_H
