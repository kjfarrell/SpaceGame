//
// Created by kfarrell on 6/10/21.
//

#include "EvilShip.h"

EvilShip::EvilShip() {
    evilSprite = LoadTexture(
            "/home/kfarrell/Documents/Programming/raylib/SpaceGame/cmake-build-debug/10B.png");

    evilSprite.height = 100;
    evilSprite.width = 100;

    shipPosition = {static_cast<float>(screenWidth / 2.f - (float) evilSprite.width / 2.f),
                    100};
}

const Vector2 &EvilShip::getShipPosition() const {
    return shipPosition;
}

void EvilShip::Move() {
    if (shipPosition.x >= GetScreenWidth() - 200 || shipPosition.x <= 200)
        speed *= -1;

    shipPosition.x += speed;
}

void EvilShip::Draw() {
    if(collisionDetected)
    {

    }
    else {
        DrawTextureV(evilSprite, shipPosition, WHITE);
        Move();
    }
}
