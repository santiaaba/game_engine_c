#include "layer.h"

void layer_init(layer_t *l){
    l = (layer_t *)malloc(sizeof(layer_t));
    lista_init(l->entities, sizeof(entity_t));
}
void layer_draw(layer_t *l, SDL_Renderer *renderer, SDL_FRect camera){
    lista_first(l->entities);
    while(!lista_eol(l->entities)){
        entity_draw(lista_get(l->entities), renderer, camera);
        lista_next(l->entities);
    }
}
void layer_add_entity(layer_t *l, entity_t *e){
    lista_add(l->entities,e);
}
void layer_destroy(layer_t **l){
    lista_destroy(&((*l)->entities),(void*)(void**)entity_destroy);
    free(*l);
}