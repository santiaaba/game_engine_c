/* Define una secuencia de Frames que darán como resultado
   una animación */

#include "animation.h"

void animation_init(animation_t *a, bool isLooping){
    a = (animation_t *)malloc(sizeof(animation_t));
    lista_init(a->frames,sizeof(frame_t));
    a->loop = isLooping;
}

void animation_add_frame(animation_t *a, float x, float y, float h, float w, float addx, float addy){
    frame_t *frame;
    frame_init(frame,x,y,h,w,addx,addy);
    printf("AAACA estamos\n");
    lista_add(a->frames,frame);
    printf("AAACA estamos 2\n");
}

void animation_start(animation_t *a){
    lista_first(a->frames);
}

frame_t *animation_next_frame(animation_t *a){
    /* Devuelve el frame actual y avanza al siguiente */
    frame_t *f;
    f = lista_get(a->frames);
    if(lista_eol(a->frames))
        if(a->loop)
            lista_first(a->frames);
    else
        lista_next(a->frames);
    return f;
}

void animation_destroy(animation_t **a){
    lista_destroy(&((*a)->frames),(void*)(void**)&frame_destroy);
    free(*a);
}