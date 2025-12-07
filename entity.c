#include "entity.h"

void entity_init(entity_t *e, int32_t x, int32_t y){
    entity = (entity_t *)malloc(sizeof(entity_t));
    lista_init(entity->animations,sizeof(animation_t));
    entity->pos_x = x;
    entity->pos_y = y;
}

void entity_add_animation(entity_t *e, animation_t *a){
    lista_add(e->animations,a)
}

void entity_draw(entity_t *e, SDL_renderer *renderer, SDL_rect camera){
    /* Dibujamos la entidad solo si el rectángulo que la define está total
       o parcialmente dentro del rectángulo de la cámara */
    SDL_rect dest;
    SDL_rect *cutter;
    frame_t *frame;
    frame = animation_next_frame(list_get(e->animations));
    cutter = frame_get_cutter(frame);

    dest.x = e->pos_x - frame->pos_relative_x;
    dest.y = e->pos_y - frame->pos_relative_y;
    dest.w = cutter->w;
    dest.h = cutter->h;
    
    dest = rect_inside_rect(camera, &dest);
    SDL_RenderCopy(renderer, e->texture, cutter, &dest);
}

void entity_set_animation(entity_t *e, int index){
    lista_set_index(e,index);
    animation_start(lista_get(e));
}

void entity_set_position(entity_t *e, int32_t x, int32_t y){
    entity->pos_x = x;
    entity->pos_y = y;
}
void entity_add_position(entity_t *e, int32_t add_x, int32_t add_y){
    entity->pos_x =+ add_x;
    entity->pos_y =+ add_y;

}
void entity_destroy(entity_t **e){
    lista_destroy((*e)->animations,animation_destroy);
    free(*e);
}