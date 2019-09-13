#include "joystick.h"
#include <qdebug.h>

Joystick::Joystick(QObject *parent) : QObject(parent)
{
    SDL_Init(SDL_INIT_JOYSTICK);
    joy = SDL_JoystickOpen(0);
    if(joy==nullptr){
        qDebug()<<"joystick not connected";
        exit(1);
    }

    //qDebug()<<SDL_JoystickNumAxes(joy);
    //qDebug()<<SDL_JoystickNumButtons(joy);

    timer = new QTimer();
    timer ->setInterval(100);
    timer->start();
    connect(timer,SIGNAL(timeout()),this,SLOT(joystick_update()));

    event= new SDL_Event();
}

void Joystick::joystick_update()
{
//    SDL_JoystickUpdate();
//    qDebug()<<"X= "<<SDL_JoystickGetAxis(joy,0);
    int dir =-1;
    int inter=200;
    while(SDL_PollEvent(event)){
        if(event->type == SDL_JOYAXISMOTION){
            if(event->jaxis.axis==1){
                if(event->jaxis.value<-1000){
                    dir=0;

                }else if(event->jaxis.value>1000){
                    dir=2;
                }
            }else{
                if(event->jaxis.value>1000){
                    dir=1;

                }else if(event->jaxis.value<-1000){
                    dir=3;
                }
            }
            inter = 200- (event->jaxis.value/200);
           qDebug()<<"Axis "<<event->jaxis.axis<<"value = "<<event->jaxis.value;
        }
        //qDebug()<<"sent signal";
        emit direction(dir, inter);

//        else if(event->type== SDL_JOYBUTTONDOWN){
//            qDebug()<<"Axis "<<event->jbutton.button<<"pressed";
//        }
    }
}
