//
// Created by kfarrell on 6/10/21.
//

#ifndef MY_PROJECT_PLAYERSHIP_H
#define MY_PROJECT_PLAYERSHIP_H
#include <raylib.h>
#include "constants.h"

class PlayerShip
{
private:
    Vector2 shipPosition;
    Texture2D playerSprite;
    int shipMoveSpeed = 8.f;
public:
    PlayerShip();
    void processPlayerInput();
    const Vector2 &getShipPosition() const;
    void Draw();
};


#endif //MY_PROJECT_PLAYERSHIP_H
