#include "common.h"
#include "draw.h"

void render_texture(app_t* app, texture_t* texture, float x, float y, double degree)
{
	// Set texture position
	SDL_FRect destination_rectangle = { x, y, texture->m_Texture->w, texture->m_Texture->h };

	// Render the texture
	//SDL_RenderTexture(app->renderer, texture->m_Texture, NULL, &destinationRectable);
	SDL_RenderTextureRotated(app->renderer, texture->m_Texture, NULL, &destination_rectangle, degree, NULL, SDL_FLIP_NONE);
}

void prepare_scene(app_t* app)
{
	SDL_SetRenderDrawColor(app->renderer, 0, 0, 0, 255);
	SDL_RenderClear(app->renderer);
}

void present_scene(app_t* app)
{
	SDL_RenderTexture(app->renderer, &app->resources->textures[IMAGE_BACKGROUND]->m_Texture, NULL, NULL);
	render_texture(app, &app->resources->textures[IMAGE_PLAYER], app->mouse_data->x - 64.f, app->mouse_data->y - 64.f, 0.0);
	render_font(app, "HELLO WORLD");
	SDL_RenderPresent(app->renderer);
}

void render_font(app_t* app, const char* message)
{
	SDL_Color color = { 155, 130, 255, 255 };
	SDL_Surface* surface = TTF_RenderText_Blended(app->font, message, 0, color);
	if (!surface)
	{
		printf("Couldn't create surface from TTF font\n");
		return;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(app->renderer, surface);
	if (!texture)
	{
		printf("Couldn't create texture from surface created by font\n");
		return;
	}

	SDL_Rect dest_rect = { 0, 0, surface->w, surface->h };
	SDL_DestroySurface(surface);

	printf("%i | %i\n", dest_rect.w, dest_rect.h);	// Text rendering doesn't work with destination rectangle
	SDL_RenderTexture(app->renderer, texture, NULL, NULL);	// FIXME: Fix me
}