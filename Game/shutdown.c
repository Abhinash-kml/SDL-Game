#pragma once

#include "common.h"
#include "shutdown.h"

void destroy_texture(texture_t* texture);

void shutdown(app_t* app)
{
	for (size_t i = 0; i < MAX_IMAGES; ++i)
		destroy_texture(app->resources->textures[i]);
		
	for (size_t i = 0; i < MAX_SOUNDS; ++i)
		Mix_FreeChunk(app->resources->sounds[i]);

	/*for (size_t i = 0; i < MAX_MUSIC; ++i)
		Mix_FreeMusic(musics[i]);*/

	Mix_CloseAudio();
	SDL_CloseAudioDevice(app->audio_device_id);

	SDL_DestroyWindow(app->window);
	SDL_DestroyRenderer(app->renderer);
	IMG_Quit();
	Mix_Quit();
	SDL_Quit();

	free(app->resources);
	free(app->mouse_data);
}