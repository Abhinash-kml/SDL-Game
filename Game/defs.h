#pragma once

#define SCREEN_WIDTH	1280
#define SCREEN_HEIGHT	720

enum images
{
	IMAGE_PLAYER = 0,
	IMAGE_ENEMY,
	IMAGE_ASTEROID,
	IMAGE_BOMB,
	IMAGE_BULLET,
	MAX_IMAGES
};

enum sound_effects
{
	SOUND_BULLET_FIRE = 0,
	SOUND_RELOAD,
	SOUND_DASH,
	MAX_SOUNDS
};
enum sound_channels
{
	CHANNEL_LOW = 0,
	CHANNEL_MEDIUM,
	CHANNEL_HIGH,
	MAX_AUDIO_CHANNELS
};

extern const char* images[MAX_IMAGES];

extern const char* sounds[MAX_SOUNDS];

