#ifndef SERVERGLOBAL_H
#define SERVERGLOBAL_H
#include "server.h"

//класс для работы с объектом сервер. Нужен для получения объекта сервер в дочерних класах
class ServerGlobal
{
public:
    ServerGlobal();
    static Server* getServer();

private:
    Server * createServer();
    Server * server = nullptr;
};
#define REF_SERVER (ServerGlobal::getServer())
#endif // SERVERGLOBAL_H
