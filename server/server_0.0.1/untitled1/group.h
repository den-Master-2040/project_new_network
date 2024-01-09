#include "user.h"
#include <QObject>

class group : public QObject
{
    Q_OBJECT
public:
     group();

     //Поля
     QString name;
     QString password;
     user* firstUser = nullptr;
     user* secondUser = nullptr;

     int status = -1;

     void insertUser(user *user);
     void deleteUser();//когда юзер вышел

public slots:
    void slotSendMsgFirtsUser();
    void slotSendMsgSecondUser();
};


