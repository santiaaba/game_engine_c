#ifndef ENGINE_H
#define ENGINE_H

#include <SDL3/SDL.h>
#include "scene.h"

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_PropertiesID window_props;
    scene_t *scene;
} engine_t;

bool engine_init(engine_t *e);
void engine_loop_start(engine_t *e);
void engine_create_scene(engine_t *e);
entity_t *engine_create_entity(engine_t *e, int32_t x, int32_t y, char *file_path_texture);
void engine_destroy(engine_t *e);

#endif