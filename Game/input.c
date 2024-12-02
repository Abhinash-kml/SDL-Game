#pragma once

#include "common.h"
#include "input.h"

void doInput(bool* bRunning)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_EVENT_QUIT:
			*bRunning = false;
			break;
		default:
			break;
		}
	}
}