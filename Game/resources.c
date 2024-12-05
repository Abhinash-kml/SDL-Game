#include "resources.h"
#include "common.h"

const char* images[MAX_IMAGES] = {
	"textures/example.png"
};

const char* sounds[MAX_SOUNDS] = {
	"sounds/sound1.wav",
	"sounds/sound2.wav",
	"sounds/sound3.wav"
};

void destroyTexture(Texture* texture)
{	
	if (texture && texture->m_Texture)
	{
		SDL_DestroyTexture(texture);
		texture->m_height = 0;
		texture->m_width = 0;
		texture = NULL;
	}
}

bool loadTexture(App* app, const char* name, Texture* newTexture) 
{
	// Ensure app, resources, and renderer are valid
	if (!app || !app->resources || !app->resources->images || !app->renderer) 
	{
		printf("Invalid application state.\n");
		return false;
	}

	Texture* textures = app->resources->images;

	// Destroy texture if it already exists
	for (size_t i = 0; i < MAX_IMAGES; ++i) 
	{
		if (strcmp(textures[i].m_path, name) == 0) 
		{
			destroyTexture(&textures[i]);
			break; // Destroy only the first matching texture
		}
	}

	// Copy the name to texture path (ensure buffer size matches)
	strcpy_s(textures[0].m_path, sizeof(textures[0].m_path), name);

	// Load surface
	SDL_Surface* loadedSurface = IMG_Load(name);
	if (!loadedSurface) {
		printf("Unable to load image %s | Error: %s\n", name, SDL_GetError());
		return false;
	}

	// Create texture from surface
	newTexture->m_Texture = SDL_CreateTextureFromSurface(app->renderer, loadedSurface);
	if (!newTexture->m_Texture) 
	{
		printf("Unable to create texture from loaded pixels for %s | Error: %s\n", name, SDL_GetError());
		SDL_DestroySurface(loadedSurface);
		return false;
	}

	// Set texture dimensions
	(*newTexture).m_height = loadedSurface->h;
	(*newTexture).m_width = loadedSurface->w;

	// Free surface
	SDL_DestroySurface(loadedSurface);

	return true;
}


int loadResources(App* app)
{
	/*for (size_t i = 0; i < MAX_IMAGES; ++i)
	{*/
	app->resources->images[0] = malloc(sizeof(Texture));
		loadTexture(app, images[0], &app->resources->images[0]);

		if (!(&app->resources->images[0]))
		{
			printf("SDL Images: Couldn't load image %s, error %s", images[0], SDL_GetError());
			return 0;
		}
	//}

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
