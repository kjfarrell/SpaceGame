//
// Created by kfarrell on 6/10/21.
//
#include "MissileDB.h"


MissileDB::MissileDB() {
    for(auto & i : missile)
    {
        i.coords.x = 0;
        i.coords.y = 0;
        i.active = false;
    }
    textureMissile = LoadTexture(
            "/home/kfarrell/Documents/Programming/raylib/SpaceGame/cmake-build-debug/misile.png"
    );
    textureMissile.height = 10;
    textureMissile.width = 10;

    sndMissile =
            LoadSound("/home/kfarrell/Documents/Programming/raylib/SpaceGame/cmake-build-debug/drip.wav");
}

bool hasCollided(Vector2 inMissile, Vector2 inEvilShip)
{
    Rectangle missile;
    Rectangle evilShip;

    missile.x = inMissile.x;
    missile.y = inMissile.y;
    missile.width = 5;
    missile.height = 5;

    evilShip.x = inEvilShip.x;
    evilShip.y = inEvilShip.y;
    evilShip.width = 100;
    evilShip.height = 100;

    return CheckCollisionRecs(evilShip, missile);

}

void MissileDB::UpdateMissile(EvilShip &evilShip) {
    for (auto & i : missile) {
        if (i.active && i.coords.y > 0) {
            i.coords.y -= 20;
            if(hasCollided(i.coords, evilShip.getShipPosition()))
            {
                TraceLog(LOG_INFO, "Collision detected...");
                i.active = false;
                evilShip.collisionDetected = true;
            }
            else {
                DrawTexture(textureMissile,
                            (int) i.coords.x,
                            (int) i.coords.y,
                            WHITE);
            }
        }
        else
        {
            i.active = false;
        }
    }
}

void MissileDB::SpawnMissile(Vector2 shipPosition) {
    for(auto & i : missile)
    {
        if(!i.active)
        {
            i.coords.x = shipPosition.x + 25;
            i.coords.y = shipPosition.y - 20;
            i.active = true;
            PlaySound(sndMissile);
            DrawTexture(textureMissile,
                        (int) i.coords.x,
                        (int) i.coords.y,
                        WHITE);
            return;
        }
    }

    return;
}
