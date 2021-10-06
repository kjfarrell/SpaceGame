//
// Created by kfarrell on 6/10/21.
//

#ifndef MY_PROJECT_STARFIELD_H
#define MY_PROJECT_STARFIELD_H
#include <raylib.h>
#include "constants.h"

const int numStars = 100;

class Starfield
{
private:
    struct Star
    {
        Vector2 coords{};
        int speed = 1;
        int radius{};
        bool active{};
    };

    Star star[numStars];
public:
    Starfield();
    void RandomizeStar(Star &i);
    void Draw();
};

#endif //MY_PROJECT_STARFIELD_H
