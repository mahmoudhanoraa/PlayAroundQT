#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <vector>
#include <QLabel>

class Snake;
class Food;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void clear();
    void addFood();
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
    Snake *s;
    std::vector<Food*> food;
    unsigned int gameTimerMilles = 20;
    unsigned int moveCounter = 0;
    unsigned int foodDropCounter = 0;
    unsigned int score = 0;
    unsigned int level = 1;
    unsigned int foodDropFlag = 100;
    unsigned int moveFlag = 10;
    unsigned int moveFlagJoyStick = 0;



public slots:
    void refreshTheGame();
    void draw();
};

#endif // MAINWINDOW_H
