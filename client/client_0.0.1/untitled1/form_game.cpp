#include "form_game.h"
#include "ui_form_game.h"
#include "QDebug"

form_game::form_game(QWidget *parent, network_client *nt) :
    QWidget(parent),
    ui(new Ui::form_game)
{
    ui->setupUi(this);
    network_obj = nt;

    ui->setupUi(this);

    scene = new QGraphicsScene(this);   // Инициализируем графическую сцену
    scene->setItemIndexMethod(QGraphicsScene::NoIndex); // настраиваем индексацию элементов

    ui->graphicsView->resize(510,510);  // Устанавливаем размер graphicsView
    ui->graphicsView->setScene(scene);  // Устанавливаем графическую сцену в graphicsView
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    // Настраиваем рендер
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground); // Кэш фона
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    scene->setSceneRect(0,0,510,510); // Устанавливаем размер сцены
    QPixmap *map = new QPixmap("C:/Users/DANIL/Documents/build-moveItem-Desktop_Qt_5_14_2_MinGW_64_bit-Debug/debug/1.png");
    setPlayerMap();

}

void form_game::setPlayerMap()
{
    int color_counter = 0;
    for(int i = 0; i < 8; i++)
    {
        color_counter++;
        for(int j = 0; j < 8; j++)
        {
            MoveItem *item = new MoveItem(&m_chess);        // Создаём графический элемента
            item->setPos(SIZECELL*i,SIZECELL*j);
            item->beMove = false;

            if(color_counter % 2)
                item->color = Qt::lightGray;
            else
                item->color = Qt::green;

            scene->addItem(item);   // Добавляем элемент на графическую сцену
            chessMap.push_back(item);
            color_counter++;
        }
    }

    color_counter = 0;
    for(int i = 0; i < 8; i++)
    {
        color_counter++;
        for(int j = 0; j < 8; j++)
        {
            int num_figure = m_chess.chess_Engine_map[j][i];

            /*int chess_Engine_map[8][8] = {
                {2, 3, 4, 5, 6, 4, 3, 2},
                {1, 1, 1, 1, 1, 1, 1, 1},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {7, 7, 7, 7, 7, 7, 7, 7},
                {8, 9,10,11,12,10, 9, 8}
            };*/

            if(num_figure) //если поле 0, то там нет фигуры, условие не будет выполнено
            {
                MoveItem *chess = new MoveItem(&m_chess);
                chess->beMove=true;
                chess->name = QString::number(num_figure);
                chess->setPos(SIZECELL*i,SIZECELL*j);
                scene->addItem(chess);   // Добавляем элемент на графическую сцену
                chessMap.push_back(chess);
                chess->oldcol = j;
                chess->oldrow = i;
            }
        }
    }
}

void form_game::update_chess_map()
{

}

void form_game::update_chess_array(int arr[8][8])
{
    for(int i = 0; i < 8; ++i)
        for(int j = 0; j < 8; ++j)
            m_chess.chess_Engine_map[i][j] = arr[i][j];
}

form_game::~form_game()
{
    delete ui;
}

void form_game::on_pushButton_clicked()
{
    emit signalExit();
}

void form_game::slotQDynamicsButtonsHandler()
{
     /*QDynamicButton *button = (QDynamicButton*)sender();
     int id_button_local = button->getID();
     if(firstClick < 0)
        firstClick = id_button_local/8 + (id_button_local - (id_button_local/8 * 8) )*10;    //запоминаем первое нажатие
     else
     {
        secondClick = id_button_local/8 + (id_button_local - (id_button_local/8 * 8) )*10;   //запоминаем второе нажатие

        qDebug() << firstClick;
        qDebug() << secondClick;

        if(m_chess.hod(firstClick,secondClick))                                                //обрабатываем
            ui->label->setText("Ход сделан");
        else
            ui->label->setText("неверный ход");

        update_chess_map();

        firstClick = secondClick = -1;
     }*/
}
















