#pragma once

#include "input.h"

void process_input(bool* bRunning, app_t* app)
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
			case SDLK_LEFT:
				app->mouse_data->deltaX -= 10.f;
				break;
			case SDLK_RIGHT:
				app->mouse_data->deltaX += 10.f;
				break;
			case SDLK_UP:
				app->mouse_data->deltaY += 10.f;
				break;
			case SDLK_DOWN:
				app->mouse_data->deltaY -= 10.f;
				break;
			}
		case SDL_EVENT_MOUSE_MOTION:
			SDL_GetMouseState(&app->mouse_data->x, &app->mouse_data->y);
			printf("X = %f | Y = %f\n", app->mouse_data->x, app->mouse_data->y);
			break;
		default:
			break;
		}
	}
}