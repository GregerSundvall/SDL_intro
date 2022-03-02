#pragma once
#include "../../../../Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.29.30133/include/stdbool.h"


struct Projectile
{
    bool alive = false;
    float x;
    float y;

    void update();
    void draw();
    
};
