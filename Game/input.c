#pragma once

#include "common.h"
#include "input.h"

void doInput(bool* bRunning, App* app)
{
	SDL_Event event; 

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_EVENT_QUIT:
			*bRunning = false;
			break;
		case SDL_EVENT_KEY_DOWN:
			switch (event.key.key)
			{
			case SDLK_1:
				Mix_PlayChannel(CHANNEL_LOW, app->resources->sounds[0], 0);
				break;
			case SDLK_2:
				Mix_PlayChannel(CHANNEL_MEDIUM, app->resources->sounds[1], 0);
				break;
			case SDLK_3:
				Mix_PlayChannel(CHANNEL_HIGH, app->resources->sounds[2], 0);
				break;
			}
		default:
			break;
		}
	}
}