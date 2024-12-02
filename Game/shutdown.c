#pragma once

#include "common.h"
#include "shutdown.h"

void shutdown(App* app)
{
	SDL_DestroyWindow(app->window);
	SDL_DestroyRenderer(app->renderer);
	SDL_Quit();
}