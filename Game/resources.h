#pragma once

#include "common.h"

void destroyTexture(Texture* texture);

bool loadTexture(App* app, const char* name, Texture* newTexture);

int loadResources(App* app);
