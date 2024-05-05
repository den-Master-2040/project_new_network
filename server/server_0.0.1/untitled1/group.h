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

     int status = -1;

     void insertUser(user *user);
     QByteArray Data;

     void deleteUser();//когда юзер вышел
     void sendMsg();
private:
     void SendToSocket(QString message, QTcpSocket *socket_sender);
 signals:
     void signalDestroy();

private slots:
    void slotSendMsgFirtsUser();
    void slotSendMsgSecondUser();
public slots:
    void Disconnected();
};


