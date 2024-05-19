#include "moveitem.h"

MoveItem::MoveItem(chess_Engine *m_chess, QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    this->m_chess = m_chess;
}

MoveItem::~MoveItem()
{

}

QRectF MoveItem::boundingRect() const
{
    return QRectF (0,0,SIZECELL,SIZECELL);
}

void MoveItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //qDebug() << "paint";
    if(name == "")
    {
        painter->setPen(color);
        painter->setBrush(color);
        painter->setBackground(color);
    }
    else
    {
        QPixmap *map = new QPixmap("C:/Users/DANIL/Desktop/build-moveItem-Desktop_Qt_5_14_2_MinGW_32_bit-Debug/debug/chess/" +name+".png");
        *map = map->scaledToWidth(SIZECELL);
        *map = map->scaledToHeight(SIZECELL);
        painter->drawPixmap(0,0,*map);
    }


    painter->drawRect(0,0,SIZECELL,SIZECELL);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void MoveItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    /* Устанавливаем позицию графического элемента
     * в графической сцене, транслировав координаты
     * курсора внутри графического элемента
     * в координатную систему графической сцены
     * */
    //qDebug() << "mouseMoveEvent";
    if(beMove)
        this->setPos(mapToScene(event->pos()));
}

void MoveItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "mousePressEvent";
    /* При нажатии мышью на графический элемент
     * заменяем курсор на руку, которая держит этот элемента
     * */
    this->setCursor(QCursor(Qt::ClosedHandCursor));

    Q_UNUSED(event);
}

void MoveItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "mouseReleaseEvent";
    /* При отпускании мышью элемента
     * заменяем на обычный курсор стрелку
     * */
    if(beMove)
        setPosToCell();

    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}

void MoveItem::setPosToCell()
{
    QPointF pos = scenePos();

    int x = pos.x();
    int y = pos.y();

    qDebug() << "x: "<< x;
    qDebug() << "y: "<< y;

    x = x / SIZECELL;
    y = y / SIZECELL;

    if(x > 7 || x < 0 || y > 7 || y < 0) {
        qDebug() << "Out of range";
        returnToRange(x,y);
    }

    col = x;
    row = y;


    qDebug() << "col: "<< col;
    qDebug() << "row: "<< row;

    x*=SIZECELL;
    y*=SIZECELL;

    qDebug() << "xR: "<< x;
    qDebug() << "yR: "<< y;


    //здесь должны быть прверки

    pos.setX(x);
    pos.setY(y);

    int firstClick = oldcol * 10 + oldrow; //место ОТКУДА ходим
    int secondClick = row * 10 + col;      //место, КУДА ходим

    qDebug() << "firstClick: "<< firstClick;
    qDebug() << "secondClick: "<< secondClick;
    if(m_chess->hod(firstClick,secondClick))

    {
        this->setPos(pos);
        oldcol = row;
        oldrow = col;
    }
    else
       this->setPos(QPointF(oldrow*SIZECELL,oldcol*SIZECELL));





}

void MoveItem::returnToRange(int &x, int &y)
{
    if(x < 0) x = 0;
    if(x > 7) x = 7;
    if(y < 0) y = 0;
    if(y > 7) y = 7;
}

