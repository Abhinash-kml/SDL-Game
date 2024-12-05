#include "common.h"
#include "draw.h"

void renderTexture(App* app, Texture* texture, float x, float y)
{
	// Set texture position
	SDL_FRect destinationRectable = { x, y, texture->m_Texture->w,  texture->m_Texture->h };

	// Render the texture
	SDL_RenderTexture(app->renderer, texture->m_Texture, NULL, &destinationRectable);
}

void prepareScene(App* app)
{
	SDL_SetRenderDrawColor(app->renderer, 96, 128, 255, 255);
	SDL_RenderClear(app->renderer);
}

void presentScene(App* app)
{
	//SDL_BlitSurface()
	renderTexture(app, &app->resources->images[0], app->mouse_data->x - app->mouse_data->deltaX, app->mouse_data->y - app->mouse_data->deltaY);
	SDL_RenderPresent(app->renderer);
}