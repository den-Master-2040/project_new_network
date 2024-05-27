#include "user.h"
#include <QObject>
#include <QTcpSocket>
class group : public QObject
{
    Q_OBJECT
public:
     group();
     ~group();
     //Поля
     QString name;
     QString password;
     user* firstUser = nullptr;
     user* secondUser = nullptr;


     void insertUser(user *user);
     QByteArray Data;

     void deleteUser();//когда юзер вышел
     void sendMsg();
     void SendToSocket(QString message, QTcpSocket *socket_sender);
     void SendAll(QString message);
private:

 signals:
     void signalDestroy();

private slots:
    void slotSendMsgFirtsUser();
    void slotSendMsgSecondUser();
public slots:
    void Disconnected();
    void slotGo();
};


