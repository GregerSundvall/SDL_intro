#pragma once

struct Player
{
    float x = 100.0f;
    float y = 100.0f;

    float shoot_timer = 0.0f;
    int next_projectile_index = 0;

    void update();
    void draw();
};