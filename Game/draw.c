#include "common.h"
#include "draw.h"

void renderTexture(App* app, Texture* texture, float x, float y)
{
	// Set texture position
	SDL_FRect destinationRectable = { x, y, 360.f, 360.f };

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
	renderTexture(app, &app->resources->images[0], 0.f, 0.f);
	SDL_RenderPresent(app->renderer);
}