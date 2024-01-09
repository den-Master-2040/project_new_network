#include "mainwindow.h"

#include <QApplication>

#include <network_client.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    network_client *nt = new network_client();
    MainWindow w(0, nt);
    w.show();
    return a.exec();
}
