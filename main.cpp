#include <raylib.h>
#include "PlayerShip.h"
#include "MissileDB.h"
#include "constants.h"
#include "Starfield.h"




int main()
{
    InitWindow(screenWidth, screenHeight, "SpaceGame");
    InitAudioDevice();

    PlayerShip playerShip;
    MissileDB missileDB;
    Starfield starField;
    EvilShip evilShip;

    SetTargetFPS(60);

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        playerShip.processPlayerInput();

        BeginDrawing();
            ClearBackground(BLACK);
            starField.Draw();
            playerShip.Draw();
            if (IsKeyPressed(KEY_SPACE))
                missileDB.SpawnMissile(playerShip.getShipPosition());
            else {
                missileDB.UpdateMissile(evilShip);
            }

            if(!evilShip.collisionDetected)
                evilShip.Draw();




        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();        // Close window and OpenGL context

    return 0;
}

// Check walls collision for bouncing
//if ((ballPosition.x >= (GetScreenWidth() - ballRadius)) || (ballPosition.x <= ballRadius)) ballSpeed.x *= -1.0f;
//if ((ballPosition.y >= (GetScreenHeight() - ballRadius)) || (ballPosition.y <= ballRadius)) ballSpeed.y *= -1.0f;
//}