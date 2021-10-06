//
// Created by kfarrell on 6/10/21.
//

#include "Starfield.h"

Starfield::Starfield() {
    for(auto &i : star)
    {
        RandomizeStar(i);
        i.coords.y = GetRandomValue(0, screenHeight);
    }
}

void Starfield::RandomizeStar(Starfield::Star &i) {
    i.speed = GetRandomValue(1.f, 4.f);
    i.radius = i.speed;
    i.coords.x = GetRandomValue(1, screenWidth);
    i.coords.y = 0;

}

void Starfield::Draw() {
    for(auto &i : star)
    {
        if(i.coords.y < screenHeight) {
            DrawCircleV(i.coords, i.radius, DARKGRAY);
            i.coords.y += i.speed;
        }
        else
        {
            i.active = false;
            RandomizeStar(i);

        }
    }
}
