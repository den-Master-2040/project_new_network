#include "form_game.h"
#include "ui_form_game.h"
#include "QDebug"
form_game::form_game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::form_game)
{
    ui->setupUi(this);
    qDebug() << "form_game()";

}

form_game::~form_game()
{
    delete ui;
}
