#ifndef FOOD_H
#define FOOD_H
#include <QPoint>
#include "mainwindow.h"

class Food
{
private:
    unsigned int lifeSpan;
    QPoint position;
    MainWindow *playGround;
    unsigned int size;
public:
    Food(MainWindow *playGround, QPoint position, unsigned int lifeSpan, unsigned int size);
    QPoint getPosition();
    unsigned int getLifeSpan();
    bool isEaten(QPoint snakeHead);
    void appear();
    unsigned int getSize();
};

#endif // FOOD_H
