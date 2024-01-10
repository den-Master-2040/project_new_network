#ifndef network_client_H
#define network_client_H

#include <QObject>
#include <QTcpSocket>
#include <QTimer>

struct group{
    int id = -1;
    QString name = "";
    QString name_first_user = "";
};


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
    QString login = "DEN_CHIK_";
    QString token = "1qaz";
    int size_users = -1;
    QVector<group> groups;
    QString login_secondUser;
    QString messageToUser;
public slots:
    void slotReadyRead();

signals:
    void signalOkToCreateGroup();
    void signalSizeUsers();
    void signalendDataGroup();
    void signalSecondLogin();
    void signalRecvMessageFromAnotherUser();
};

#endif // network_client_H
