#include <stdlib.h>

#include "structs.h"
#include "init.h"
#include "main.h"

bool init_SDL(app_t* app)
{
	int window_flags = 0;
	
	// Initialize SDL in Video & Audio mode
	if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
	{
		printf("Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	if (!SDL_CreateWindowAndRenderer("Space Wars", SCREEN_WIDTH, SCREEN_HEIGHT, window_flags, &app->window, &app->renderer))
	{
		printf("Fialed to create SDL Window / Renderer | Error: %s", SDL_GetError());
		return false;
	}

	// Initialize Image loading
	int image_flags = IMG_INIT_PNG;
	if (!(IMG_Init(image_flags) & image_flags))
	{
		SDL_Log("Unable to initialize SDL_Image | Error: %s", SDL_GetError());
		return false;
	}

	// Initialize TTF Fonts loading
	if (!TTF_Init())
	{
		SDL_Log("Unable to initialize SDL_TTF | Error: %s", SDL_GetError());
		return false;
	}

	// Try to load a font
	TTF_Font* font = TTF_OpenFont("fonts/Roboto/Roboto-Bold.ttf", 300);
	if (!font)
	{
		printf("Unable to load custom fonts: Error: %s", SDL_GetError());
		return false;
	}

	// Assign loaded font if successfully loaded
	app->font = font;

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