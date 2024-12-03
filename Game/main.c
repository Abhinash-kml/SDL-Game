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
    game.resources = malloc(sizeof(game.resources));
    if (!game.resources) {
        printf("Failed to allocate memory for resources\n");
        return -1;
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