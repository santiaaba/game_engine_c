#ifndef FRAME_H
#define FRAME_H

#include <SDL3/SDL.h>
#include "stdint.h"
#include <stdlib.h>

typedef struct {
    SDL_FRect cutter;
    /* Las siguientes posiciones son relativas a las
       coordenadas que situan la entidad en el plano */
    int16_t pos_relative_x;
    int16_t pos_relative_y;
} frame_t;

void frame_init(frame_t *frame, float x, float y, float h, float w, float addx, float addy);
SDL_FRect *frame_get_cutter(frame_t *frame);
void frame_destroy(frame_t **frame);

#endif