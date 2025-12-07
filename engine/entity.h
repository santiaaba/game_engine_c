#ifndef ENTITY_H
#define ENTITY_H

#include <stdint.h>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "lista.h"
#include <stdlib.h>
#include "animation.h"
#include "frame.h"
#include "help.h"

typedef struct {
    int32_t pos_x;
    int32_t pos_y;
    lista_t *animations;
    SDL_Texture *texture;
} entity_t;

void entity_init(entity_t *e, int32_t x, int32_t y, SDL_Renderer *r, char *path_image);
void entity_draw(entity_t *e, SDL_Renderer *renderer, SDL_FRect camera);
void entity_add_animation(entity_t *e, animation_t *a);
void entity_set_animation(entity_t *e, int index);
void entity_set_position(entity_t *e, int32_t x, int32_t y);
void entity_add_position(entity_t *e, int32_t add_x, int32_t add_y);
void entity_destroy(entity_t **e);

#endif