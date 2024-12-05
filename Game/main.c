// Example program:
// Using SDL3 to create an application window

#include "common.h"
#include "init.h"
#include "draw.h"
#include "input.h"
#include "resources.h"
#include "shutdown.h"

int main(int argc, char* argv[]) 
{
    app_t game;
    game.resources = (resources_t*)malloc(sizeof(game.resources));
    if (!game.resources) 
    {
        printf("Failed to allocate memory for resources\n");
        return -1;
    }
    game.mouse_data = (mouse_data_t*)malloc(sizeof(game.mouse_data));
    if (!game.mouse_data) 
    {
        printf("Failed to allocate memory for mouse data\n");
        return -1;
    }
    game.mouse_data->deltaX = 180.f;
    game.mouse_data->deltaY = 180.f;
    for (size_t i = 0; i < MAX_IMAGES; ++i) 
    {
        game.resources->textures[i] = (texture_t*)malloc(sizeof(texture_t));
        if (game.resources->textures[i]) 
        {
            game.resources->textures[i]->m_Texture = NULL; // Initialize the SDL_Texture pointer
            game.resources->textures[i]->m_height = 0.0f;  // Default height
            game.resources->textures[i]->m_width = 0.0f;   // Default width
            game.resources->textures[i]->m_path[0] = '\0'; // Initialize path to empty string
        }
    }

    bool bInitialized = false;
    bool bRunning = true;

    if (bInitialized = init_SDL(&game))
    {
        if (!load_resources(&game))
        {
            printf("Loading resources failed!");
            bRunning = false;
        }
    }
    else
    {
        bRunning = false;
    }


    while (bRunning)
    {
        prepare_scene(&game);
        process_input(&bRunning, &game);
        present_scene(&game);
    }

    shutdown(&game);

    return 0;
}