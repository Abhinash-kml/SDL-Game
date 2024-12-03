#pragma once

#include "common.h"

typedef struct Resources
{
	SDL_Surface* images[MAX_IMAGES];
	Mix_Chunk* sounds[MAX_SOUNDS];
} Resources;

typedef struct App
{
	SDL_Renderer* renderer;
	SDL_Window* window;
	Resources* resources;
	SDL_AudioDeviceID audioDeviceID;
	int audioChannelCount;
} App;
