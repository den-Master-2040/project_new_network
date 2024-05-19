#ifndef USER_H
#define USER_H
#define SPDLOG_COMPILED_LIB 0
#include "spdlog/spdlog.h"
#include <QObject>
#include <QtCore>
#include "QTcpSocket"
#include "QTimer"
//#include "group.h"
class user : public QObject
{
    Q_OBJECT
public:
    user(quint32 socketDescriptor);

    ~user();

    //поля
    QString login;
    QString token;
    int socketDescriptor;
    QTcpSocket *socket;
    QByteArray Data; //для отправки сообщений

    //информация только создания для групп
    QString msg;
    QString name_group;
    QString pass_group;

    QString sendedMsgToAnotherUser;

    bool group_created = false;
    int group = -1;
    //объекты
    QTimer *t_ping = nullptr;

    //методы для общего пользования
    void sendMessage(QString message);
    void isAlive();
    void getSocket();
    void getDataDestinaition();//функция должна будет возвращать данные из бд с достижениями игрока

    //сигналы
    QString getLogin() const;
    void setLogin(const QString &value);

signals:
    void signalDisconnect();
    void signalEnable();

    void signalsendMessage();
    void signalCreateGroup();
    void signalGetDataGroup();
    void signalConnectToGroup();
    void signalExitGroup();

public slots:
    void slotReadyRead();
};

#endif // USER_H
