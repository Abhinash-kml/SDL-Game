#pragma once

#include "common.h"
#include "shutdown.h"

void destroyTexture(Texture* texture);

void shutdown(App* app)
{
	for (size_t i = 0; i < MAX_IMAGES; ++i)
		destroyTexture(app->resources->images[i]);
		
	for (size_t i = 0; i < MAX_SOUNDS; ++i)
		Mix_FreeChunk(app->resources->sounds[i]);

	/*for (size_t i = 0; i < MAX_MUSIC; ++i)
		Mix_FreeMusic(musics[i]);*/

	Mix_CloseAudio();
	SDL_CloseAudioDevice(app->audioDeviceID);

	SDL_DestroyWindow(app->window);
	SDL_DestroyRenderer(app->renderer);
	IMG_Quit();
	Mix_Quit();
	SDL_Quit();
}