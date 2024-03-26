#include "form_game.h"
#include "ui_form_game.h"
#include "QDebug"

form_game::form_game(QWidget *parent, network_client *nt) :
    QWidget(parent),
    ui(new Ui::form_game)
{
    ui->setupUi(this);
    network_obj = nt;
    //m_vLaayout = new QVBoxLayout(this);
    //m_vLaayout->setGeometry(QRect(20,50,511,511));
    setPlayerMap();
}

void form_game::setPlayerMap()
{
    for(int i = 0; i < 8; i++)
    {
        color_backgroind_counter++;

        for(int j = 0; j <8; j++)
        {
            QDynamicButton *button = new QDynamicButton(this);  // Создаем объект динамической кнопки

            button->SetID(i*8 + j);                             // ID

            //button->setText(QString::number(m_chess.chess_Engine_map[i][j]));            //цифра для дальнейшего наложения картинки на кнопку

            button->setFixedHeight(SIZE_BUTTON+MERGE_BUTTON);   //высота кнопки

            button->setMaximumWidth(SIZE_BUTTON+MERGE_BUTTON);    //ширина

            button->setGeometry(QRect(SIZE_BUTTON * j + 20 ,SIZE_BUTTON * i + 20, SIZE_BUTTON, SIZE_BUTTON));//расставляем кнопки в нужном месте

            /* Применение стиля к шахматной карте*/
            if(color_backgroind_counter%2)
                button->setStyleSheet(QString::fromStdString("QPushButton{"
                                                             "background-color:" + color_white_map + ";"
                                                             "border-style: solid;"
                                                             "border-color: black;"
                                                             "border-width: 2px;"
                                                             "border-radius: 0px;}"));
            else
                button->setStyleSheet(QString::fromStdString("QPushButton{"
                                                             "background-color:" + color_black_map + ";"
                                                             "border-style: solid;"
                                                             "border-color: black;"
                                                             "border-width: 2px;"
                                                             "border-radius: 0px;}"));

            color_backgroind_counter++;


            //ui->formLayout->addWidget(button);
            buttons.push_back(button);

            /* Подключаем сигнал нажатия кнопки к СЛОТ получения номера кнопки
             * */
            connect(button, &QDynamicButton::clicked, this, &form_game::slotQDynamicsButtonsHandler);
        }
    }
    update_chess_map();
}

void form_game::update_chess_map()
{
    for(int i = 0; i < 64; ++i)
    {
        QDynamicButton *button = buttons.at(i);
        //button->setText(QString::number(m_chess.chess_Engine_map[i/8][i%8]));

        QPixmap pixmap("C:/Users/DANIL/Desktop/project_new_network/client/client_0.0.1/untitled1/chess/" + QString::number(m_chess.chess_Engine_map[i/8][i%8]) + ".png");

        QIcon ButtonIcon(pixmap);
        button->setIcon(ButtonIcon);
        button->setIconSize(QSize(SIZE_BUTTON, SIZE_BUTTON));
    }

}

void form_game::update_chess_array(int arr[8][8])
{
    for(int i = 0; i < 8; ++i)
        for(int j = 0; j < 8; ++j)
            m_chess.chess_Engine_map[i][j] = arr[i][j];
    //update_chess_map();
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
     QDynamicButton *button = (QDynamicButton*)sender();
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
     }
}
















