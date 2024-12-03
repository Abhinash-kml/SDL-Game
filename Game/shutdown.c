#pragma once

#include "common.h"
#include "shutdown.h"

void shutdown(App* app)
{
	for (size_t i = 0; i < MAX_SOUNDS; ++i)
		Mix_FreeChunk(app->resources->sounds[i]);

	/*for (size_t i = 0; i < MAX_MUSIC; ++i)
		Mix_FreeMusic(musics[i]);*/

	Mix_CloseAudio();
	SDL_CloseAudioDevice(app->audioDeviceID);

	SDL_DestroyWindow(app->window);
	SDL_DestroyRenderer(app->renderer);
	Mix_Quit();
	SDL_Quit();
}