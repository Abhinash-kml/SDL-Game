#include "common.h"
#include "draw.h"
#include "resources.h"

void prepareScene(App* app)
{
	SDL_SetRenderDrawColor(app->renderer, 96, 128, 255, 255);
	SDL_RenderClear(app->renderer);
}

void presentScene(App* app)
{
	//SDL_BlitSurface()
	SDL_RenderPresent(app->renderer);
}