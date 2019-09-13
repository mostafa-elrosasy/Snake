#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QPainter>
#include <QtGlobal>
#include <qtimer.h>
#include <joystick.h>

/* Preprocessors #defines */
#define FRUIT_RADIUS 10
#define WIDTH 10
#define HEIGHT 10

extern char flag;

class Square{
private:
     /* Saving the direction in the current object data member if there is  */
    //char direction;

public:
    int x,y;
    Square(int x,int y);

    /* Fucntion prototypes*/

    /* Removing a square*/
    void remove();

};


class Snake{
private:

public:
    QVector <Square*> snake;
    /* 0- UP , 1- Right , 2-Down , 3- Left */
    char direction;

    /* Constructor */
    Snake();

    /* Fucntion prototypes*/

    /* Updating the length of the snake by adding new square at the end*/
   // void update_Length(QVector <Square*> snake);

    /* Loosing the snake when it hits itself */
    void snake_Lost();

    /* Moving the snake to new dimensions*/
    void snake_Move();

};


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Snake* s;
    int direction;
    int interval = 200;
    int fx,fy;
    QTimer *timer;
    QVector <Square*> snake;
     void paintEvent(QPaintEvent *);

    int x_Cord, y_Cord;

    /* Setters & Getters */
    void setCord(int x, int y);
    void update_Length();
    //void keyPressEvent(QKeyEvent * event);
    void move();
    void gameloop();
    void fruit_eaten();

    void generate();
private slots:
    void init_game();

public slots:
    void set_direction(int dir, int inter);



private:
    Ui::MainWindow *ui;
    Joystick* my_joy;
protected:
    QPainter obj;



};










#endif // MAINWINDOW_H
