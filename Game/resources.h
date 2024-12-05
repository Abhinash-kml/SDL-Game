#pragma once

#include "common.h"

void destroy_texture(texture_t* texture);

bool load_texture(app_t* app, const char* name, texture_t* newTexture);

int load_resources(app_t* app);
