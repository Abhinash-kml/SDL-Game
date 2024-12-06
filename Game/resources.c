#include "resources.h"
#include "common.h"

const char* images[MAX_IMAGES] = {
	"textures/background.png",
	"textures/ship.png"
};

const char* sounds[MAX_SOUNDS] = {
	"sounds/sound1.wav",
	"sounds/sound2.wav",
	"sounds/sound3.wav"
};

const char* songs[MAX_SONGS] = {
	"songs/round1.mp3",
	"songs/round2.mp3"
};

void destroy_texture(texture_t* texture)
{	
	if (texture && texture->m_Texture)
	{
		SDL_DestroyTexture(texture);
		texture->m_height = 0;
		texture->m_width = 0;
		texture = NULL;
	}
}

bool load_texture(app_t* app, const char* name, texture_t* new_texture) 
{
	// Ensure app, resources, and renderer are valid
	if (!app || !app->resources || !app->resources->textures || !app->renderer) 
	{
		printf("Invalid application state.\n");
		return false;
	}

	texture_t* textures = app->resources->textures;

	// Destroy texture if it already exists
	for (size_t i = 0; i < MAX_IMAGES; ++i) 
	{
		if (strcmp(textures[i].m_path, name) == 0) 
		{
			destroy_texture(&textures[i]);
			break; // Destroy only the first matching texture
		}
	}

	// Copy the name to texture path (ensure buffer size matches)
	strcpy_s(new_texture->m_path, sizeof(new_texture->m_path), name);

	// Load surface
	SDL_Surface* loaded_surface = IMG_Load(name);
	if (!loaded_surface) {
		printf("Unable to load image %s | Error: %s\n", name, SDL_GetError());
		return false;
	}

	// Create texture from surface
	new_texture->m_Texture = SDL_CreateTextureFromSurface(app->renderer, loaded_surface);
	if (!new_texture->m_Texture) 
	{
		printf("Unable to create texture from loaded pixels for %s | Error: %s\n", name, SDL_GetError());
		SDL_DestroySurface(loaded_surface);
		return false;
	}

	// Set texture dimensions
	new_texture->m_height = loaded_surface->h;
	new_texture->m_width = loaded_surface->w;

	// Free surface
	SDL_DestroySurface(loaded_surface);

	return true;
}


int load_resources(app_t* app)
{
	for (size_t i = 0; i < MAX_IMAGES; ++i)
	{
		//app->resources->textures[0] = malloc(sizeof(texture_t));
		load_texture(app, images[i], &app->resources->textures[i]);

		if (!(&app->resources->textures[i]))
		{
			printf("SDL Images: Couldn't load image %s, error %s", images[i], SDL_GetError());
			return 0;
		}
	}

	for (size_t i = 0; i < MAX_SOUNDS; ++i)
	{
		printf("loading sound %s", sounds[i]);
		if (!(app->resources->sounds[i] = Mix_LoadWAV(sounds[i])))
		{
			printf("SDL Mixer: couldn't load sound %s, error %s", sounds[i], SDL_GetError());
			return 0;
		}
	}

	if ((app->audio_channel_count = Mix_AllocateChannels(MAX_AUDIO_CHANNELS)) != MAX_AUDIO_CHANNELS)
	{
		SDL_Log("Unable to allocate channels. SDL Mixer error: %s", SDL_GetError());
		return 0;
	}

	return 1;
}
