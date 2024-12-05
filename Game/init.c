#include <stdlib.h>

#include "structs.h"
#include "init.h"
#include "main.h"

bool init_SDL(app_t* app)
{
	int window_flags = SDL_WINDOW_RESIZABLE;
	
	// Initialize SDL in Video & Audio mode
	if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
	{
		printf("Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	if (!(app->window = SDL_CreateWindow("My Game", SCREEN_WIDTH, SCREEN_HEIGHT, window_flags)))
	{
		printf("Failed to create window of width: %i, height: %i. Error: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	if (!(app->renderer = SDL_CreateRenderer(app->window, NULL)))
	{
		printf("Failed to create SDL Renderer. Error: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	// Initialize Image loading
	int image_flags = IMG_INIT_PNG;
	if (!(IMG_Init(image_flags) & image_flags))
	{
		SDL_Log("Unable to initialize SDL_Image | Error: %s", SDL_GetError());
		return false;
	}

	// Set audio spec
	SDL_AudioSpec audio_spec;
	audio_spec.format = SDL_AUDIO_F32;
	audio_spec.channels = 2;
	audio_spec.freq = 44100;

	// Open audio device
	app->audio_device_id = SDL_OpenAudioDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &audio_spec);
	if (app->audio_device_id == 0)
	{
		SDL_Log("Unable to open audio device. Error: %s\n", SDL_GetError());
		return false;
	}
	else
	{
		// Initialize the SDL Mixer
		if (!Mix_OpenAudio(app->audio_device_id, NULL))
		{
			printf("SDL Mixer failed to initialize. Error: %s\n", SDL_GetError());
			return false;
		}
	}

	return true;
}