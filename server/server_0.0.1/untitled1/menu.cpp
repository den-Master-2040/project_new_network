#include "menu.h"
#include "server.h"
#include "serverglobal.h"
#include "QNetworkInterface"
#include "iostream"
#include "QSqlTableModel"

#include <QSqlRecord>
#include <QSqlTableModel>

bool server_started = false;

using namespace std;


void print_menu() {
    if(!server_started)
    {
        system("cls");  // очищаем экран
        cout <<("Select one menu item\n");
        cout <<("1. Start server\n");

        cout <<("2. Exit\n");
        cout <<(">");
    }
    else
    {
        system("cls");  // очищаем экран
        cout <<("Select one menu item\n");
        cout <<("1. Stop server\n");
        cout <<("2. View all group\n");
        cout <<("3. Create group\n");
        cout <<("4. Delete group\n");
        cout <<("5. block a player\n");
        cout <<("6. View blocked player list\n");
        cout <<("7. Unblock player\n");
        cout <<("8. Old server mode\n");
        cout <<("9. Exit\n");
        cout <<(">");
    }

}

int get_variant(int count, bool value) {
    int variant;
    char s[100]; // строка для считывания введённых данных
    scanf("%s", s); // считываем строку

    // пока ввод некорректен, сообщаем об этом и просим повторить его
    if(value)
    while (sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > count) {
        cout <<("Incorrect input. Try again: "); // выводим сообщение об ошибке
        scanf("%s", s); // считываем строку повторно
    }
    else
        while (sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > 2) {
            cout <<("Incorrect input. Try again: "); // выводим сообщение об ошибке
            scanf("%s", s); // считываем строку повторно
        }

    return variant;
}



Menu::Menu(QObject *parent) : QObject(parent)
{
    QThread *th = new QThread();
    Server * server;
    int variant; // выбранный пункт меню
    bool exit = false;
    do {
        print_menu(); // выводим меню на экран

        variant = get_variant(9 ,server_started); // получаем номер выбранного пункта меню

        switch (variant) {
            case 1:
                {
                    if(!server_started)
                    {

                        ServerGlobal* serverGl = new ServerGlobal();

                        server = serverGl->getServer();


                        QHostAddress serverip;

                        int i = 0;
                        const QHostAddress &localhost = QHostAddress(QHostAddress::LocalHost);
                        for (const QHostAddress &address: QNetworkInterface::allAddresses()) {
                            if (address.protocol() == QAbstractSocket::IPv4Protocol && address != localhost)
                                 {qDebug() << "local pc ip: " << address.toString(); serverip = address;;i++;}
                        }
                        connect(this, &Menu::signalstartServer, server, &Server::start);

                        if(i > 1)
                        {
                            qDebug() << "Not auto set ip...";
                            qDebug() << "Please enter ip address";
                            qDebug() << "ip:";

                            std::string address;
                            std::cin >> address;
                            server->ipAddress = QString::fromStdString(address);
                            server->port = 2323;


                            server->moveToThread(th);
                            emit signalstartServer();
                        }
                        else
                        {
                            server->ipAddress = serverip.toString();
                            server->port = 2323;


                            server->moveToThread(th);
                            emit signalstartServer();
                        }
                        th->start();
                        server_started = true;
                    }
                    else
                    {
                        server->destroyed();
                        server_started = false;

                    }
                    break;
                }
            case 2:
            {
                if(server_started)
                {
                    cout <<("+---------------------+----------------+---------------+\n");
                    cout <<("|        group        |    nameuser1   |   nameuser2   |\n");
                    cout <<("+---------------------+----------------+---------------+\n");
                    for(auto item : server->groups)
                    {
                        cout << item->name.toStdString() << " " << ((item->firstUser == nullptr) ? "none" : item->firstUser->getLogin().toStdString()) << " " <<
                                ((item->secondUser == nullptr) ? "none" : item->secondUser->getLogin().toStdString()) << endl;
                    }
                    cout << endl;
                }
                else
                {
                    exit= true;
                }

                break;
            }
            case 3:
            {
                group *gr = new group();
                string namegr;
                cout << "Enter the name group";
                cin >> namegr;
                gr->name = QString::fromStdString(namegr);

                string passgr;
                cout << "Enter the pass group";
                cin >> passgr;
                gr->password = QString::fromStdString(passgr);

                server->groups.append(gr);
                cout << "Group created!";
                break;
            }
            case 4:
            {
                string namegr;
                cout << "Enter the name group";
                cin >> namegr;
                bool isdeleted = false;

                for (auto item : server->groups) {
                    if(item->name.toStdString() == namegr)
                    {
                        server->groups.removeOne(item);
                        isdeleted = true;
                        break;
                    }
                }

                if(isdeleted)
                    cout << "Group delete";
                else
                    cout << "Group not found...";

                break;
            }
            case 5:
            {
                string nameuser;
                cout << "Enter the name user";
                cin >> nameuser;
                int indexdb = server->db->findMyIndex(QString::fromStdString(nameuser));
                if(indexdb == -1)return;
                QSqlRecord record = server->db->selectIndex(indexdb);
                record.setValue("isblocked", true);


                if(server->db->setRecord(indexdb, record))
                    cout << "User blocked";
                else
                    cout << "User not found...";

                break;
            }
            case 6:
            {
                server->db->db.open();
                QSqlTableModel model(nullptr, server->db->db);

                model.setTable("user");

                model.select();
                cout << "login blocked users:" << endl;
                for(int i = 0; true; i++){
                    if(model.record(i).value("id").toInt() == 0) break;
                    if(model.record(i).value("isblocked") == 1) qDebug() <<model.record(i).value("login").toString();
                }
                server->db->db.close();
                break;
            }
            case 7:
            {
                string nameuser;
                cout << "Enter the name user";
                cin >> nameuser;
                int indexdb = server->db->findMyIndex(QString::fromStdString(nameuser));
                if(indexdb == -1)return;
                QSqlRecord record = server->db->selectIndex(indexdb);
                record.setValue("isblocked", false);


                if(server->db->setRecord(indexdb, record))
                    cout << "User deblocked";
                else
                    cout << "User not found...";

                break;
            }
            case 8:            
            {
                server->viewmode = true;
                break;
            }
            case 9:            
            {
                exit= true;
                break;
            }
        }

        if (!exit)
            system("pause"); // задерживаем выполнение, чтобы пользователь мог увидеть результат выполнения выбранного пункта
    } while (!exit);
}
