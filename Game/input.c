#pragma once

#include "common.h"
#include "input.h"

void doInput()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_EVENT_QUIT:
			exit(EXIT_SUCCESS);
			break;
		default:
			break;
		}
	}
}