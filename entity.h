#ifndef ENTITY_H
#define ENTITY_H

#include <stdint.h>
#include "lista.h"
#include "animation.h"

typedef struct {
    int32_t pos_x;
    int32_t pos_y;
    lista_t animations;
} entity_t;

void entity_init(entity_t *e);
void entity_draw(entity_t *e);
void entity_add_animation(entity_t *e, animation_t *a);
void entity_set_animation(entity_t *e, int index);
void entity_set_position(entity_t *e, int32_t x, int32_t y);
void entity_add_position(entity_t *e, int32_t add_x, int32_t add_y);
void entity_destroy(entity_t **e);

#endif