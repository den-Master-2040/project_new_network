#include "serverglobal.h"

ServerGlobal::ServerGlobal()
{

}

//Метод, который отдаёт единственный на всю программу указатель на сервер.
//Нужен, чтобы иметь лёгкий доступ ко всей программе из любой её точки.
Server *ServerGlobal::getServer()
{
    static std::unique_ptr<ServerGlobal> instanse (new ServerGlobal());
    if(instanse->server != nullptr)
        return instanse->server;
    else
    {
        instanse->createServer();
        return instanse->server;
    }
}

Server *ServerGlobal::createServer()
{
    server = new Server("",0);
    return  server;
}
