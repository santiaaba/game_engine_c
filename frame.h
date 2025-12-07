#ifndef FRAME_H
#define FRAME_H

#include <SDL3/SDL.h>
#include "stdint.h"

typedef struct {
    SDL_rect;
    /* Las siguientes posiciones son relativas a las
       coordenadas que situan la entidad en el plano */
    int16_t pos_relative_x;
    int16_t pos_relative_y;
} frame_t;

typedef struct {
    int sprite_x;
    int sprite_y;
    int sprite_width;
    int sprite_height;
    int entity_relative_x;
    int entity_relative_y;
} frame_data

void frame_init(frame_t *frame, frame_data data);
void frame_destroy(frame_t **frame);
void frame_draw(frame_t *fame);

#endif