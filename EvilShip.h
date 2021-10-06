//
// Created by kfarrell on 6/10/21.
//

#ifndef MY_PROJECT_EVILSHIP_H
#define MY_PROJECT_EVILSHIP_H

#include <raylib.h>
#include "constants.h"



class EvilShip
{
private:
    Vector2 shipPosition;
    Texture2D evilSprite;
    int speed = 2;

public:
    bool collisionDetected = false;

public:
    EvilShip();
    const Vector2 &getShipPosition() const;
    void Move();
    void Draw();
};

#endif //MY_PROJECT_EVILSHIP_H
