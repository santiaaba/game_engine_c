#include "entity.h"

void entity_init(entity_t *e, int32_t x, int32_t y, SDL_Renderer *r, char *path_image){
    e = (entity_t *)malloc(sizeof(entity_t));
    lista_init(e->animations,sizeof(animation_t));
    e->texture = IMG_LoadTexture(r, path_image);
    e->pos_x = x;
    e->pos_y = y;
}

void entity_add_animation(entity_t *e, animation_t *a){
    lista_add(e->animations,a);
}

void entity_draw(entity_t *e, SDL_Renderer *renderer, SDL_FRect camera){
    /* Dibujamos la entidad solo si el rectángulo que la define está total
       o parcialmente dentro del rectángulo de la cámara */
    SDL_FRect dest;
    SDL_FRect *cutter;
    frame_t *frame;
    frame = animation_next_frame(lista_get(e->animations));
    cutter = frame_get_cutter(frame);

    dest.x = e->pos_x - frame->pos_relative_x;
    dest.y = e->pos_y - frame->pos_relative_y;
    dest.w = cutter->w;
    dest.h = cutter->h;
    
    dest = rect_inside_rect(&camera, &dest);
    SDL_RenderTexture(renderer, e->texture, cutter, &dest);
}

void entity_set_animation(entity_t *e, int index){
    lista_set_index(e->animations,index);
    animation_start(lista_get(e->animations));
}

void entity_set_position(entity_t *e, int32_t x, int32_t y){
    e->pos_x = x;
    e->pos_y = y;
}
void entity_add_position(entity_t *e, int32_t add_x, int32_t add_y){
    e->pos_x =+ add_x;
    e->pos_y =+ add_y;

}
void entity_destroy(entity_t **e){
    lista_destroy(&((*e)->animations),(void*)(void**)animation_destroy);
    free(*e);
}