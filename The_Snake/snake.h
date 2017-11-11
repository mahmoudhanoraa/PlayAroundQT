#ifndef SNAKE_H
#define SNAKE_H
#include <QString>
#include <QPoint>
#include <deque>
#include "mainwindow.h"

class Snake
{
private:
    std::deque<QPoint> snakeBlocks;
    MainWindow *playGround;
    unsigned int snakeBlockSize;
    QString lastPos;
public:
    Snake(MainWindow *playGround, QPoint initPosition, unsigned int blockSize);
    Snake(int x, int y);
    void appear();
    bool move(QString direc);
    bool isDead(QPoint head);
    std::deque<QPoint> getSnake();
    void grow();
    QString getLastPos();
    QPoint getHead();
};

#endif // SNAKE_H
