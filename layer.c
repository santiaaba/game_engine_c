#include "layer.h"

void layer_init(layer_t *l){
    l = (layer_t *)malloc(sizeof(layer_t));
    lista_init(t->entities, sizeof(entity_t));
}
void layer_draw(layer_t *l){
    printf("Dibujamos layer\n");
}
void layer_add_entity(layer_t *l, entity_t *e){
    lista_add(l->entities,e);
}
void layer_destroy(layer_t **l){
    lista_destroy(*l->entities,entity_destroy);
    free(*l);
}