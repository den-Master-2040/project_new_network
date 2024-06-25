#ifndef SQLWORKER_H
#define SQLWORKER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QDebug>
#include <mutex>
class sqlWorker : public QObject
{
    Q_OBJECT
public:
    explicit sqlWorker(QObject *parent = nullptr);

    QSqlRecord selectIndex(int i);

    bool setRecord(int row, QSqlRecord record);

    int findMyIndex(QString login);
    bool insertNewUser(QString login, QString pass);
    QSqlDatabase db;
private:
    std::mutex g_lock;
signals:

};

#endif // SQLWORKER_H
