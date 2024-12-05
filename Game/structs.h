#pragma once

#include "common.h"

typedef struct Texture
{
	SDL_Texture* m_Texture;
	float m_height;
	float m_width;
	char m_path[128];
} Texture;

typedef struct Resources
{
	Texture* images[MAX_IMAGES];
	Mix_Chunk* sounds[MAX_SOUNDS];
} Resources;

typedef struct MouseData
{
	float x;
	float y;
	float deltaX;
	float deltaY;
} MouseData;

typedef struct App
{
	SDL_Renderer* renderer;
	SDL_Window* window;
	Resources* resources;
	SDL_AudioDeviceID audioDeviceID;
	int audioChannelCount;
	MouseData *mouse_data;
} App;
