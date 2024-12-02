#pragma once

#include <SDL3/SDL.h>

typedef struct App
{
	SDL_Renderer* renderer;
	SDL_Window* window;
} App;