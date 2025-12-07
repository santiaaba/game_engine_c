/* Define una secuencia de Frames que darán como resultado
   una animación */

#include "animation.h"

void animation_init(a *animation_t, bool isLooping){
    a = (animation_t *)malloc(sizeof(animation_t));
    lista_init(a->frames,sizeof(frame_t));
    a->loop = isLooping
}

void animation_add_frame(a *animation_t, frame_data df){
    frame_t *frame;
    frame_init(frame,df);
    lista_add(a->frames,frame);
}

void animation_start(animation_t *a){
    lista_first(a->frames);
}

frame_t *animation_next_frame(a *animation_t){
    /* Devuelve el frame actual y avanza al siguiente */
    frame_t *f;
    f = lista_get(a->frames);
    if(lista_eol(a->frames))
        if(a->loop)
            lista_first(a->lista)
    else
        lista_next(a->frames)
    return f;
}

void animation_destroy(a **animation_t){
    free(*a)
}