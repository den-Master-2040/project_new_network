#include <QCoreApplication>
#include <server.h>
#include <serverglobal.h>
#include <iostream>
#include <QNetworkInterface>
#define SPDLOG_COMPILED_LIB 0
#include "spdlog/spdlog.h"

#include "menu.h"
int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);
    Menu menu;
    return a.exec();
}
