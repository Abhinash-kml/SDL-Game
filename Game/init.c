#include <stdlib.h>

#include "structs.h"
#include "init.h"
#include "main.h"

void initSDL(App* app)
{
	int windowFlags = 0;
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	app->window = SDL_CreateWindow("My Game", SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

	if (!app->window)
	{
		printf("Fialed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
		exit(EXIT_FAILURE);
	}

	//SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	
	app->renderer = SDL_CreateRenderer(app->window, NULL);

	if (!app->renderer)
	{
		printf("Failed to create renderer: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
}