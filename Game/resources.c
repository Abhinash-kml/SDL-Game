#include "resources.h"
#include "common.h"

const char* images[MAX_IMAGES] = {
	"example.bmp",
	"example2.bmp",
	"example3.bmp"
};

const char* sounds[MAX_SOUNDS] = {
	"sounds/sound1.wav",
	"sounds/sound2.wav",
	"sounds/sound3.wav"
};

int loadResources(App* app)
{
	/*for (size_t i = 0; i < MAX_IMAGES; ++i)
	{
		if (!(app->resources->images[i] = SDL_LoadBMP(images[i])))
		{
			printf("SDL Images: Couldn't load image %s, error %s", images[i], SDL_GetError());
			return 0;
		}
	}*/

	for (size_t i = 0; i < MAX_SOUNDS; ++i)
	{
		printf("loading sound %s", sounds[i]);
		if (!(app->resources->sounds[i] = Mix_LoadWAV(sounds[i])))
		{
			printf("SDL Mixer: couldn't load sound %s, error %s", sounds[i], SDL_GetError());
			return 0;
		}
	}

	if ((app->audioChannelCount = Mix_AllocateChannels(MAX_AUDIO_CHANNELS)) != MAX_AUDIO_CHANNELS)
	{
		SDL_Log("Unable to allocate channels. SDL Mixer error: %s", SDL_GetError());
		return 0;
	}

	return 1;
}
