#include <crtdbg.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "engine.h"
#include "player.h"
#include "game.h"

#include "../../../../Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.29.30133/include/cstdlib"

int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 1200, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	bool running = true;
	
	Uint64 previous_ticks = SDL_GetPerformanceCounter();
	
	while (running)
	{
		Uint64 ticks = SDL_GetPerformanceCounter();
		Uint64 delta_ticks = ticks - previous_ticks;
		previous_ticks = ticks;
		delta_time = (float)delta_ticks / SDL_GetPerformanceFrequency();
		// printf("FPS %f\n", 1.0f/delta_time);
		
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				running = false;
				break;
			case SDL_KEYDOWN:
			{
				int scancode = event.key.keysym.scancode;
				if (scancode == SDL_SCANCODE_ESCAPE) {running = false;}
				keys[scancode] = true;
				break;
			}
			case SDL_KEYUP:
				{
					int scancode = event.key.keysym.scancode;
					keys[scancode] = false;
					break;
				}
			}
		};
		
		// SDL_SetRenderDrawColor(renderer, 100, 0, 100, 255); 
		SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255); 
		SDL_RenderClear(renderer);

		player.update();
		player.draw();
		for (int i = 0; i < PROJECTILES_MAX; ++i)
		{
			projectiles[i].update();
			projectiles[i].draw();
		}
		
		// SDL_SetRenderDrawColor(renderer, 100, 0, 100, 255);
		// SDL_SetRenderDrawColor(renderer, rand() & 0xFF, rand() & 0xFF, rand() & 0xFF, 255);
		// SDL_Rect rect = {(int)x, (int)y, 32, 32};
		// SDL_Rect rect = {0, 0, 1600, 1200};
		// SDL_RenderDrawRect(renderer, &rect);
		// SDL_RenderFillRect(renderer, &rect);
		SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}
}
