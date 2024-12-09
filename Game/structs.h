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

typedef struct EnemyPool
{
	SDL_Texture* enemies;
} enemy_pool_t;

typedef struct WaveManager
{
	enemy_pool_t enemy_pool;
	int enemy_per_wave[10];
	int current_wave;
	int current_wave_ended;
	int current_enemy_num;
	SDL_Texture* current_enemies[3];
} wave_manager_t;

typedef struct Vector2
{
	float x;
	float y;
} vector2_t;

typedef struct Player
{
	SDL_Texture* texture;
	vector2_t position;
} player_t;

typedef struct App
{
	SDL_Renderer* renderer;
	SDL_Window* window;
	resources_t* resources;
	SDL_AudioDeviceID audio_device_id;
	int audio_channel_count;
	mouse_data_t* mouse_data;
	TTF_Font* font;
	char buffer[200];
} app_t;
