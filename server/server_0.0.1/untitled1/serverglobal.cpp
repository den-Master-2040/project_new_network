#include "serverglobal.h"

ServerGlobal::ServerGlobal()
{

}

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
    server = new Server("127.0.0.1",2323);
    return  server;
}
