#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "snake.h"
#include <QPoint>
#include "food.h"
#include <QTimer>
#include <QDebug>
#include <QKeyEvent>
#include <QLabel>
#include <QGraphicsView>
#include <SFML/Window.hpp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    unsigned int windowWidth = 1000;
    unsigned int windowHeight = 700;
    unsigned int blockSize = 30;
    unsigned int initSnakeX = windowWidth/2;
    unsigned int initSnakeY = windowHeight/2;


    this->setFixedSize(windowWidth, windowHeight);
    this->ui->setupUi(this);
    this->ui->levelLabel->setText(QString::number(this->level));
    this->ui->scoreLabel->setText(QString::number(this->score));
    this->s = new Snake(this, QPoint(initSnakeX, initSnakeY), blockSize);
    this->s->appear();
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(refreshTheGame()));
    timer->start(this->gameTimerMilles);
}

MainWindow::~MainWindow()
{
    delete this->ui;
    delete this->s;
    for(int i = 0; i < this->food.size(); i++){
        delete food[i];
    }
}

void MainWindow::clear()
{
    while ( QGraphicsView* w = this->findChild<QGraphicsView*>() ){
        delete w;
    }

}

void MainWindow::addFood()
{
    int x = qrand()%1000;
    int y = qrand()%700 - 30;
    Food *f = new Food(this, QPoint(x, y), 60, 30);
    this->food.push_back(f);
    f->appear();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W){
        this->clear();
        if(!this->s->move("up"))
            this->draw();

    }
    if(event->key() == Qt::Key_S){
        this->clear();
        if(!this->s->move("down"))
            this->draw();

    }
    if(event->key() == Qt::Key_A){
        this->clear();
        if(!this->s->move("left"))
            this->draw();

    }
    if(event->key() == Qt::Key_D){
        this->clear();
        if(!this->s->move("right"))
            this->draw();

    }
}

void MainWindow::refreshTheGame()
{
    this->moveCounter++;
    this->foodDropCounter++;

    sf::Joystick::update();
    if(sf::Joystick::isConnected(0)){
        int y_pos = (int) sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
        int x_pos = (int) sf::Joystick::getAxisPosition(0, sf::Joystick::X);
        qDebug() << y_pos << " " << x_pos << endl;
        int maxJoystickVal = std::max(std::abs(y_pos), std::abs(x_pos));
        this->moveFlagJoyStick = 10 - maxJoystickVal/10;
        if(std::abs(y_pos) > std::abs(x_pos)){
            if(y_pos > 0){
                this->s->move("down");
            }else{
                this->s->move("up");
            }
        }else{
            if(x_pos > 0){
                this->s->move("right");
            }else{
                this->s->move("left");
            }
        }
    }
    if(this->foodDropCounter == this->foodDropFlag){
        qDebug() << "New Food" << endl;
        this->foodDropCounter = 0;
        if(this->food.size() < 3)
            this->addFood();
    }
    if(this->moveCounter >= this->moveFlag || this->moveCounter >= this->moveFlagJoyStick){
        this->moveCounter = 0;
        this->clear();
        //read the joystick
        if(!s->move(s->getLastPos()))
            this->draw();

    }

}

void MainWindow::draw()
{
    this->s->appear();
    for(int i = 0; i < this->food.size(); i++){
        QPoint head = this->s->getHead();
        QPoint foodPos = this->food[i]->getPosition();
        unsigned int foodSize = this->food[i]->getSize();
        if(std::abs(head.x() - foodPos.x()) <= foodSize  &&
                    std::abs(head.y() - foodPos.y()) <=  foodSize){
            this->score += 10;
            this->s->grow();
            this->food.erase(this->food.begin() + i);
            i--;
            continue;
        }
        food[i]->appear();
    }
    this->ui->scoreLabel->setText(QString::number(this->score));
    if(this->score/100 + 1 > this->level){
        this->level = this->score / 100 + 1;
        this->ui->levelLabel->setText(QString::number(this->level));
        if(this->moveFlag - 2 > 0)
            this->moveFlag -= 2;
    }


}
