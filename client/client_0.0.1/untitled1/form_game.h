#ifndef FORM_GAME_H
#define FORM_GAME_H

#include <QWidget>
#include "network_client.h"
namespace Ui {
class form_game;
}

class form_game : public QWidget
{
    Q_OBJECT

public:
    explicit form_game(QWidget *parent = nullptr);
    ~form_game();


private:
    Ui::form_game *ui;
};

#endif // FORM_GAME_H
