#pragma once

#include "common.h"

typedef struct Texture
{
	SDL_Texture* m_Texture;
	int m_height;
	int m_width;
	char m_path[128];
} Texture;

typedef struct Resources
{
	Texture* images[MAX_IMAGES];
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
