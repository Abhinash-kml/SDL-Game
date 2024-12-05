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
	SDL_SetRenderDrawColor(app->renderer, 96, 128, 255, 255);
	SDL_RenderClear(app->renderer);
}

void present_scene(app_t* app)
{
	static float angle = 0;
	angle += 0.05;
	//if (angle > 2 * 3.14) angle -= 2 * 3.14;
	//SDL_BlitSurface()
	render_texture(app, &app->resources->textures[0], app->mouse_data->x /*- app->mouse_data->deltaX*/, app->mouse_data->y /*- app->mouse_data->deltaY*/, angle);
	SDL_RenderPresent(app->renderer);
}