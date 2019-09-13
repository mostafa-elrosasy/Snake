#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <QObject>
#include "SDL2/SDL.h"
#include "SDL2/SDL_joystick.h"
#include "QThread"
#include <QTimer>

class Joystick : public QObject
{
    Q_OBJECT
public:
    explicit Joystick(QObject *parent = nullptr);

private:
    SDL_Joystick* joy;
    QTimer* timer;
    SDL_Event* event;

signals:
    void direction(int dir, int inter);

public slots:
    void joystick_update();

};

#endif // JOYSTICK_H
