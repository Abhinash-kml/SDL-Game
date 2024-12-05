// Example program:
// Using SDL3 to create an application window

#include "common.h"
#include "init.h"
#include "draw.h"
#include "input.h"
#include "resources.h"
#include "shutdown.h"

int main(int argc, char* argv[]) {

    App game;
    game.resources = (Resources*)malloc(sizeof(game.resources));
    if (!game.resources) {
        printf("Failed to allocate memory for resources\n");
        return -1;
    }
    game.mouse_data = (MouseData*)malloc(sizeof(game.mouse_data));
    if (!game.mouse_data) {
        printf("Failed to allocate memory for mouse data\n");
        return -1;
    }
    game.mouse_data->deltaX = 180.f;
    game.mouse_data->deltaY = 180.f;
    for (size_t i = 0; i < MAX_IMAGES; ++i) {
        game.resources->images[i] = (Texture*)malloc(sizeof(Texture));
        if (game.resources->images[i]) {
            game.resources->images[i]->m_Texture = NULL; // Initialize the SDL_Texture pointer
            game.resources->images[i]->m_height = 0.0f;  // Default height
            game.resources->images[i]->m_width = 0.0f;   // Default width
            game.resources->images[i]->m_path[0] = '\0'; // Initialize path to empty string
        }
    }

    bool bInitialized = false;
    bool bRunning = true;

    if (bInitialized = initSDL(&game))
    {
        if (!loadResources(&game))
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
        prepareScene(&game);
        doInput(&bRunning, &game);
        presentScene(&game);
    }

    shutdown(&game);

    return 0;
}