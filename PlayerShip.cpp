//
// Created by kfarrell on 6/10/21.
//

#include "PlayerShip.h"

PlayerShip::PlayerShip() {

    playerSprite = LoadTexture(
            "/home/kfarrell/Documents/Programming/raylib/SpaceGame/cmake-build-debug/1.png");

    playerSprite.height = 60;
    playerSprite.width = 60;

    shipPosition = {static_cast<float>(screenWidth / 2.f - (float) playerSprite.width / 2.f),
                    static_cast<float>(screenHeight - playerSprite.height)};

}

void PlayerShip::processPlayerInput() {
    if (IsKeyDown(KEY_RIGHT) && shipPosition.x < static_cast<float>(screenWidth - playerSprite.width))
        shipPosition.x += static_cast<float>(shipMoveSpeed);
    if (IsKeyDown(KEY_LEFT) && shipPosition.x > 0)
        shipPosition.x -= static_cast<float>(shipMoveSpeed);
    if (IsKeyDown(KEY_UP) && shipPosition.y > screenHeight - 200)
        shipPosition.y -= static_cast<float>(shipMoveSpeed);
    if (IsKeyDown(KEY_DOWN) && shipPosition.y < static_cast<float>(screenHeight - playerSprite.width))
        shipPosition.y += static_cast<float>(shipMoveSpeed);

}

const Vector2 &PlayerShip::getShipPosition() const {
    return shipPosition;
}

void PlayerShip::Draw() {
    DrawTextureV(playerSprite, shipPosition, WHITE);
}
