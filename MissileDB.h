//
// Created by kfarrell on 6/10/21.
//
#ifndef MISSILEDB_H
#define MISSILEDB_H

#include <raylib.h>
#include "constants.h"
#include "EvilShip.h"


class MissileDB
{
private:
    struct Missile
    {
        Vector2 coords{};
        bool active = false;
    };
public:
    Missile missile[numMissile];
    Texture2D textureMissile;
    Sound sndMissile;

    MissileDB();
    void SpawnMissile(Vector2 shipPosition);
    void UpdateMissile(EvilShip &evilShip); // Also checks for collision.
};


#endif //MISSILEDB_H
