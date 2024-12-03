#include <stdlib.h>

#include "structs.h"
#include "init.h"
#include "main.h"

bool initSDL(App* app)
{
	int windowFlags = SDL_WINDOW_RESIZABLE;
	
	// Initialize SDL in Video & Audio mode
	if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
	{
		printf("Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	if (!(app->window = SDL_CreateWindow("My Game", SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags)))
	{
		printf("Failed to create window of width: %i, height: %i. Error: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	if (!(app->renderer = SDL_CreateRenderer(app->window, NULL)))
	{
		printf("Failed to create SDL Renderer. Error: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	// Set audio spec
	SDL_AudioSpec audioSpec;
	audioSpec.format = SDL_AUDIO_F32;
	audioSpec.channels = 2;
	audioSpec.freq = 44100;

	// Open audio device
	app->audioDeviceID = SDL_OpenAudioDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &audioSpec);
	if (app->audioDeviceID == 0)
	{
		SDL_Log("Unable to open audio device. Error: %s\n", SDL_GetError());
		return false;
	}
	else
	{
		// Initialize the SDL Mixer
		if (!Mix_OpenAudio(app->audioDeviceID, NULL))
		{
			printf("SDL Mixer failed to initialize. Error: %s\n", SDL_GetError());
			return false;
		}
	}

	return true;
}