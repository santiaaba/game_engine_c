/* Representa el mundo para un juego en 2D */

#ifndef SCENE_H
#define SCENE_H

typedef struct
{
    lista_t layers;
} world_t;

void scene_init(world_t *w);

#endif