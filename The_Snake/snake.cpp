#include "snake.h"
#include <QPoint>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QDebug>

QString Snake::getLastPos()
{
    return this->lastPos;
}

QPoint Snake::getHead()
{
    return this->snakeBlocks[0];
}

Snake::Snake(MainWindow *playGround, QPoint initPosition,unsigned int blockSize)
{
    this->playGround = playGround;
    this->snakeBlockSize = blockSize;
    this->snakeBlocks.push_back(QPoint(initPosition.x(), initPosition.y() - blockSize));
    this->snakeBlocks.push_back(initPosition);
}

Snake::Snake(int x, int y)
{
    this->lastPos = QString("hanora");
}

void Snake::appear()
{
    for(int i = 0; i < this->snakeBlocks.size(); i++){
        QGraphicsView *block = new QGraphicsView(this->playGround);
        block->setGeometry(this->snakeBlocks[i].x(), this->snakeBlocks[i].y(), this->snakeBlockSize, this->snakeBlockSize);
        QGraphicsScene *scene = new QGraphicsScene();
        QGraphicsRectItem * rect = new QGraphicsRectItem();
        rect->setRect(0,0,this->snakeBlockSize, this->snakeBlockSize);
        scene->addItem(rect);
        block->setScene(scene);
        block->setBackgroundBrush(QBrush(Qt::red, Qt::SolidPattern));
        block->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
        block->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
        block->show();
    }
}

bool Snake::move(QString direc)
{
    QPoint head = this->snakeBlocks.back();
            if(!direc.compare("up") && this->lastPos.compare("down")){
                qDebug() << direc << endl;
                this->snakeBlocks.pop_back();
                head.setY(this->snakeBlocks[0].y() - this->snakeBlockSize);
                head.setX(this->snakeBlocks[0].x());
                this->snakeBlocks.push_front(head);
                this->lastPos = "up";
            }

            else if(!direc.compare("down") && this->lastPos.compare("up")){
                qDebug() << direc << endl;
                this->snakeBlocks.pop_back();
                head.setY(this->snakeBlocks[0].y() + this->snakeBlockSize);
                head.setX(this->snakeBlocks[0].x());
                this->snakeBlocks.push_front(head);
                this->lastPos = "down";
            }
            else if(!direc.compare("left") && this->lastPos.compare("right")){
                qDebug() << direc << endl;
                this->snakeBlocks.pop_back();
                head.setY(this->snakeBlocks[0].y());
                head.setX(this->snakeBlocks[0].x() - this->snakeBlockSize);
                this->snakeBlocks.push_front(head);
                this->lastPos = "left";
            }
            else if(!direc.compare("right") && this->lastPos.compare("left")){
                qDebug() << direc << endl;
                this->snakeBlocks.pop_back();
                head.setY(this->snakeBlocks[0].y());
                head.setX(this->snakeBlocks[0].x() + this->snakeBlockSize);
                this->snakeBlocks.push_front(head);
                this->lastPos = "right";
            }
            return this->isDead(head);
}

bool Snake::isDead(QPoint head)
{
    bool outPlayGround = head.y() < 0 || head.y() > this->playGround->geometry().height() ||
            head.x() < 0 || head.x() > this->playGround->geometry().width();
    if(outPlayGround){
        this->playGround->close();
        return true;
    }
    for(int i = 4; i < this->snakeBlocks.size(); i++){
        if(std::abs(head.x() - this->snakeBlocks[i].x()) == this->snakeBlockSize &&
                std::abs(head.y() - this->snakeBlocks[i].y()) == this->snakeBlockSize){
            this->playGround->close();
            return true;
        }
    }
    return false;
}

std::deque<QPoint> Snake::getSnake()
{
    return this->snakeBlocks;
}

void Snake::grow()
{
    QPoint head;

    if(!this->lastPos.compare("left")){
        head.setY(this->snakeBlocks[0].y());
        head.setX(this->snakeBlocks[0].x() - this->snakeBlockSize);
    }
    else if(!this->lastPos.compare("right")){
        head.setY(this->snakeBlocks[0].y());
        head.setX(this->snakeBlocks[0].x() + this->snakeBlockSize);
    }
    else if(!this->lastPos.compare("up")){
        head.setY(this->snakeBlocks[0].y() - this->snakeBlockSize);
        head.setX(this->snakeBlocks[0].x());
    }
    else if(!this->lastPos.compare("down")){
        head.setY(this->snakeBlocks[0].y() + this->snakeBlockSize);
        head.setX(this->snakeBlocks[0].x());
    }

    this->snakeBlocks.push_front(head);
}
