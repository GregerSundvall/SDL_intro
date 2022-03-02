#include "Projectile.h"

#include <cstdlib>

#include "engine.h"


void Projectile::update()
{
    if (!alive)
    {
        return;
    }
    x += 400 * delta_time;
}
void Projectile::draw()
{
    if (!alive)
    {
        return;
    }
    SDL_SetRenderDrawColor(renderer, rand() & 0xFF, rand() & 0xFF, rand() & 0xFF, 255);
    SDL_Rect rect = { (int)x, (int)y, 8, 8};
    SDL_RenderFillRect(renderer, &rect);
}
