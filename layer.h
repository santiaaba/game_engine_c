#ifndef LAYER_H
#define LAYER_H

#include "lista.h"
#include "entity.h"

typedef struct{
    lista_t *entities;
} layer_t;

void layer_init(layer_t *l);
void layer_draw(layer_t *l);
void layer_add_entity(layer_t *l, entity_t *e);
void layer_destroy(layer_t **l);

#endif