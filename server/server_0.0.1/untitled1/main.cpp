#include <QCoreApplication>
#include <server.h>
#include <serverglobal.h>
#define SPDLOG_COMPILED_LIB 0


#include "spdlog/spdlog.h"
int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);


    ServerGlobal* serverGl = new ServerGlobal();
    Server * server = serverGl->getServer();


    server->start();
     // Set global log level to debug
    //spdlog::error("Some error message with arg: {}", 1);
    //spdlog::warn("Easy padding in numbers like {:08d}", 12);
    //spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    //spdlog::info("Support for floats {:03.2f}", 1.23456);
    //spdlog::info("Positional args are {1} {0}..", "too", "supported");
    //spdlog::trace("{:<30}", "left aligned");
    //spdlog::debug("This message should be displayed..");
    // change log pattern
    //spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");
    // Compile time log levels
    // define SPDLOG_ACTIVE_LEVEL to desired level
    //SPDLOG_TRACE("Some trace message with param {}", 42);
    //SPDLOG_DEBUG("Some debug message");
    return a.exec();
}
