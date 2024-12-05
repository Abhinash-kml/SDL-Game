#pragma once

#include "common.h"

typedef struct Texture
{
	SDL_Texture* m_Texture;
	float m_height;
	float m_width;
	char m_path[128];
} texture_t;

typedef struct Resources
{
	texture_t* textures[MAX_IMAGES];
	Mix_Chunk* sounds[MAX_SOUNDS];
	Mix_Music* songs[MAX_SONGS];
} resources_t;

typedef struct MouseData
{
	float x;
	float y;
	float deltaX;
	float deltaY;
} mouse_data_t;

typedef struct App
{
	SDL_Renderer* renderer;
	SDL_Window* window;
	resources_t* resources;
	SDL_AudioDeviceID audio_device_id;
	int audio_channel_count;
	mouse_data_t* mouse_data;
} app_t;
