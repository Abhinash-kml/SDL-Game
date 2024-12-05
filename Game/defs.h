#pragma once

#define SCREEN_WIDTH	1280
#define SCREEN_HEIGHT	720

enum images
{
	IMAGE_PLAYER = 0,
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

enum songs
{
	SONG_BACKGROUND = 0,
	SONG_MENU,
	MAX_SONGS
};

extern const char* images[MAX_IMAGES];
extern const char* sounds[MAX_SOUNDS];
extern const char* songs[MAX_SONGS];

