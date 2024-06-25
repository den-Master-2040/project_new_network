#ifndef USER_H
#define USER_H
#define SPDLOG_COMPILED_LIB 0
#include "spdlog/spdlog.h"
#include <QObject>
#include <QtCore>
#include "QSslSocket"
#include "QTimer"
#include <QQueue>
#include "sqlworker.h"
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
    QSslSocket *socket;
    int lvl= 0;
    bool findFastGame = false; //флаг быстрой игры
    int group = -1;            //индекс группы, в которой находится пользователь


    //информация только создания для групп
    QString msg= "";
    QString name_group= "";
    QString pass_group= "";
    QString sendedMsgToAnotherUser= ""; //сообщение для другого пользователя

    
    
    sqlWorker *db = nullptr; //указатель на объект работы с бд
    //объекты

    //методы для общего пользования
    void sendMessage(QString message);    
    void RequaredMsg(QString str);
    int updateLvl(int win, int def, int countGame);    
    QString getLogin() const;
    void setLogin(const QString &value);
    void setBlocked(bool value);

    //для сбора данных
    QQueue <QString> buffer;
    QTimer *t_ringBuff = nullptr;
    QTimer *t_readBuff = nullptr;
    
//сигналы
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
    void connectViewers();
    void disconnectViewers();

//слоты
public slots:
    void slotReadyRead();
    void slotReadBuff();
};

#endif // USER_H
