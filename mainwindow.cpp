#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTimer>
#include <QDebug>
#include <QKeyEvent>


char flag = 0;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   Snake* s = new Snake();
   my_joy= new Joystick();
   direction =1;
   this->generate();
    QTimer *timer = new QTimer(this);
    for(int i=0;i<4;i++){
        snake.push_back(new Square(200-i*10,200));
    }
   // qDebug() <<s->snake[0]->x;
    flag=1;
    timer = new QTimer();
    this->interval=200;
    timer->setInterval(200);
    timer->start();

    //connect(timer,SIGNAL(timeout()),this,SLOT(joystick_update()));
    connect(my_joy,SIGNAL(direction(int, int)),this,SLOT(set_direction(int, int)));
    connect(timer, SIGNAL(timeout()), this, SLOT(init_game()));



}


MainWindow::~MainWindow()
{
    delete ui;
}





/* Implementation of Square Class*/

void MainWindow::paintEvent(QPaintEvent *e)
{
    if(flag==0)
        return;

    for(int i=0;i<snake.size();i++){
        QPainter obj(this);
        obj.drawRect(QRect(snake[i]->x,snake[i]->y,WIDTH,HEIGHT));
    }
    QPainter obj0(this);
    obj0.drawEllipse(QRect(fx,fy,FRUIT_RADIUS,FRUIT_RADIUS));

}

void MainWindow::setCord(int x, int y)
{
        x_Cord = x;
        y_Cord = y;
}

Square::Square(int a_x, int a_y){
    this->x= a_x;
    this->y = a_y;

}

Snake::Snake()
{
    this->direction=1;

}
void MainWindow::update_Length(){
    int x=snake[0]->x;
    int y=snake[0]->y;
    switch (this->direction) {
        case 0:
            y-=10;
            if(y<0)
                y=500;
            break;
        case 1:
            x=(x+10)%500;
            break;
        case 2:
            y=(y+10)%500;
            break;
        case 3:
            x-=10;
            if(x<0)
                x=500;
            break;
    }
    this->snake.insert(snake.begin(),new Square(x,y));
}
void MainWindow::move(){
    this->snake.pop_back();
    this->update_Length();
}

void MainWindow::gameloop()
{
    move();
    fruit_eaten();
    repaint();

}

void MainWindow::fruit_eaten()
{
    if(this->snake[0]->x==fx&&this->snake[0]->y==fy){
        this->generate();
        //this->update_Length();
    }
}

//void MainWindow::keyPressEvent(QKeyEvent *event){
//    if (event->key() == Qt::Key_Up){
//        this->direction=0;
//    }
//    else if (event->key() == Qt::Key_Right){
//        this->direction=1;
//    }
//    else if (event->key() == Qt::Key_Down){
//        this->direction=2;
//    }
//    else if (event->key() == Qt::Key_Left){
//        this->direction=3;
//    }

//}

void MainWindow::generate(){
    this->fx=(rand()%51)*10;
    this->fy=(rand()%51)*10;
}

void MainWindow::init_game()
{
    this->gameloop();
}

void MainWindow::set_direction(int dir, int inter)
{
    this->direction=dir;
   //timer->setInterval(200);
    qDebug()<<"interval:"<<inter;
}


