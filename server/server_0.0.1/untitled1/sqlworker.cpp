#include "sqlworker.h"

sqlWorker::sqlWorker(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase("QSQLITE");

    db.setHostName("127.0.0.1");

    db.setDatabaseName("C:/Users/DANIL/Desktop/users.db");


    db.setUserName("root");

    db.setPassword("");
}

QSqlRecord sqlWorker::selectIndex(int i)
{
    g_lock.lock();
    db.open();
    QSqlTableModel model(nullptr,db);

    model.setTable("user");

    model.select();
    db.close();
    g_lock.unlock();
    return model.record(i);
}

bool sqlWorker::setRecord(int row, QSqlRecord record)
{
    g_lock.lock();
    db.open();
    QSqlTableModel model(nullptr,db);
    model.setTable("user");
    model.select();
    bool res = model.setRecord(row,record);
    db.close();
    g_lock.unlock();
    return res;
}

int sqlWorker::findMyIndex(QString login)
{
    g_lock.lock();
    db.open();
    QSqlTableModel model(nullptr,db);

    model.setTable("user");

    model.select();

    for(int i = 0; i < model.rowCount();i++)
    {
        if(model.record(i).value("login") == login)
            return i;
    }

    db.close();
    g_lock.unlock();
    return -1;
}

bool sqlWorker::insertNewUser(QString login, QString pass)
{
    g_lock.lock();
    db.open();
    QSqlTableModel model(nullptr,db);

    model.setTable("user");

    model.select();

    QSqlRecord name = model.record();

    name.setValue("login", login);
    name.setValue("password", pass);

    bool result = model.insertRecord(0,name);
    db.close();
    g_lock.unlock();
    return result;
}
