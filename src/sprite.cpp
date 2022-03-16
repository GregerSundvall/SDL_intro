#include "sprite.h"
#include "engine.h"



void Sprite::load(const char* path)
{
	texture = IMG_LoadTexture(render, path);
	SDL_QueryTexture(texture, NULL, NULL, &width, &height);
}

void Sprite::draw(int x, int y)
{
	SDL_Rect destination = {x, y, width, height};
	SDL_RenderCopy(render, texture, NULL, &destination);
}