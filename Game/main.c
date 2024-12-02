// Example program:
// Using SDL3 to create an application window

#include "common.h"
#include "init.h"
#include "draw.h"
#include "input.h"

int main(int argc, char* argv[]) {

    App game;
    initSDL(&game);

    while (1)
    {
        prepareScene(&game);
        doInput();
        presentScene(&game);
        SDL_Delay(16);
    }

    return 0;
}