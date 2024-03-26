#ifndef FORM_GAME_H
#define FORM_GAME_H
#include <QWidget>
#include "chess_engine.h"
#include "network_client.h"
#include <QVBoxLayout>
#include "qdynamicbutton.h"
namespace Ui {
class form_game;
}

class form_game : public QWidget
{
    Q_OBJECT

public:
    explicit form_game(QWidget *parent = nullptr, network_client * nt = nullptr);
    ~form_game();
    void setPlayerMap();

    int counter_click_button = 0;
    int firstClick = -1;
    int secondClick = -1;
    //QVBoxLayout *m_vLaayout;
    int SIZE_BUTTON = 60;
    int MERGE_BUTTON = 2;
    int color_backgroind_counter = 0;

    std::string color_white_map = "white";
    std::string color_black_map = "gray";
    chess_Engine m_chess;                    //логика шахмат

    QVector<QDynamicButton*> buttons;
    void update_chess_map();
    void update_chess_array(int arr[8][8]);
signals:
    void signalExit();
private slots:
    void on_pushButton_clicked();
    void slotQDynamicsButtonsHandler();
private:
    network_client *network_obj;
    Ui::form_game *ui;
};

#endif // FORM_GAME_H
