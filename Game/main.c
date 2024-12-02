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
    bool bRunning = true;

    initSDL(&game);
    if (!loadResources())
    {
        printf("Loading resources failed!");
        bRunning = false;
    }

    while (bRunning)
    {
        prepareScene(&game);
        doInput(&bRunning);
        presentScene(&game);
    }

    shutdown(&game);

    return 0;
}