#ifndef MENU_H
#define MENU_H

#include <QObject>

class Menu : public QObject
{
    Q_OBJECT
public:
    explicit Menu(QObject *parent = nullptr);

signals:
    void signalstartServer();
};

#endif // MENU_H
