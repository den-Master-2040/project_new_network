#ifndef USER_H
#define USER_H
#define SPDLOG_COMPILED_LIB 0
#include "spdlog/spdlog.h"
#include <QObject>
#include <QtCore>
#include "QSslSocket"
#include "QTimer"
#include <QQueue>
//#include "group.h"
class user : public QObject
{
    Q_OBJECT
public:
    user(quint32 socketDescriptor);
    user(QSslSocket * socket);

    ~user();

    //поля
    QString login = "";
    QString token= "";
    int socketDescriptor;
    QSslSocket *socket;
    QByteArray Data; //для отправки сообщений

    //информация только создания для групп
    QString msg= "";
    QString name_group= "";
    QString pass_group= "";

    QString sendedMsgToAnotherUser= "";

    bool findFastGame = false;
    bool group_created = false;
    int group = -1;
    //объекты

    //методы для общего пользования
    void sendMessage(QString message);
    void getSocket();
    void getDataDestinaition();//функция должна будет возвращать данные из бд с достижениями игрока
    void RequaredMsg(QString str);
    int findStartMsg(QByteArray byte);

    //сигналы
    QString getLogin() const;
    void setLogin(const QString &value);

    QQueue <QString> buffer;
    QTimer *t_ringBuff = nullptr;
    QTimer *t_readBuff = nullptr;

signals:
    void signalDisconnect();
    void signalEnable();

    void signalsendMessage();
    void signalCreateGroup();
    void signalGetDataGroup();
    void signalConnectToGroup();
    void signalExitGroup();
    void signalGo();
    void signalFindUsers();

public slots:
    void slotReadyRead();
    void slotReadBuff();
};

#endif // USER_H
