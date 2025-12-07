#ifndef ANIMATION_H
#define ANIMATION_H

#include "lista.h"
#include "frame.h"
#include <stdlib.h>

typedef struct
{
    bool loop;
    lista_t *frames;
} animation_t;

void animation_init(animation_t *a, bool isLooping);
void animation_add_frame(animation_t *a, float x, float y, float h, float w, float addx, float addy);
frame_t *animation_next_frame(animation_t *a);
void animation_start(animation_t *a);
void animation_destroy(animation_t **a);

#endif