#include "common.h"
#include "draw.h"

void render_texture(app_t* app, texture_t* texture, float x, float y, double degree)
{
	// Set texture position
	float w, h;
	SDL_GetTextureSize(app->resources->textures[IMAGE_PLAYER], &w, &h);


	SDL_FRect destination_rectangle = { x, y, w, h };
	SDL_RenderTextureRotated(app->renderer, texture->m_Texture, NULL, &destination_rectangle, degree, NULL, SDL_FLIP_NONE);
}

void prepare_scene(app_t* app)
{
	SDL_SetRenderDrawColor(app->renderer, 0, 0, 0, 255);
	SDL_RenderClear(app->renderer);
}

void present_scene(app_t* app)
{										
	SDL_RenderTexture(app->renderer, &app->resources->textures[IMAGE_BACKGROUND]->m_Texture, NULL, NULL);	// EXPLAIN: Why working with addressof operator and not without it ?
	render_texture(app, &app->resources->textures[IMAGE_PLAYER], app->mouse_data->x - 64.f, app->mouse_data->y - 64.f, 0.0);	// FIXME: Why working when passed with addressof operator, which it shouldn't

	for (size_t i = 0; i < 3; ++i)
	{
		float width = 100.f;
		float height = 100.f;
		SDL_FRect dst_rect = { 20.f + i * 400.f, 0.f, width, height };
		SDL_RenderTexture(app->renderer, app->resources->textures[IMAGE_PLAYER], NULL, &dst_rect);
	}

	//sprintf_s(app->buffer, sizeof(app->buffer), "Mouse Position: %f - %f", app->mouse_data->x, app->mouse_data->y);
	//render_font(app, app->buffer);
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

	SDL_FRect dest_rect = { 0.f, 0.f, 400.f, 60.f };
	SDL_DestroySurface(surface);

	SDL_RenderTexture(app->renderer, texture, NULL, &dest_rect);	// FIX: (Always use SDL_FRect with RenderTexture)
}