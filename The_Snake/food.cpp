#include "food.h"
#include <QPoint>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>

unsigned int Food::getSize()
{
    return size;
}

Food::Food(MainWindow *playGround, QPoint position, unsigned int lifeSpan, unsigned int size)
{
    this->playGround = playGround;
    this->position = position;
    this->lifeSpan = lifeSpan;
    this->size = size;
}

QPoint Food::getPosition()
{
    return this->position;
}

unsigned int Food::getLifeSpan()
{
    return this->lifeSpan;
}

bool Food::isEaten(QPoint snakeHead)
{
    if(std::abs(this->position.x() - snakeHead.x()) == 30 || std::abs(this->position.y() - snakeHead.y()) == 30)
        return true;
    return false;
}

void Food::appear()
{
    QGraphicsView *block = new QGraphicsView(this->playGround);
    block->setGeometry(this->position.x(), this->position.y(), this->size, this->size);
    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsRectItem * rect = new QGraphicsRectItem();
    rect->setRect(0,0,this->size, this->size);
    scene->addItem(rect);
    block->setScene(scene);
    block->setBackgroundBrush(QBrush(Qt::green, Qt::SolidPattern));
    block->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    block->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    block->show();
}
