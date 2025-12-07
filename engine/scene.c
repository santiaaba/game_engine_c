#include "scene.h"

void scene_init(scene_t *s, SDL_Window *window){
    s->renderer = SDL_CreateRenderer(window, NULL);
    /* La cámara inicialmente posee el tamaño del window y se ubica en (x.y) = (0.0) */
    (s->camera).x = 0;
    (s->camera).y = 0;
    int w_h;
    int w_w;
    SDL_GetWindowSize(window, &w_w, &w_h);
    (s->camera).w = (float)w_w;
    (s->camera).h = (float)w_h;

}

void scene_draw(scene_t *s){
    lista_first(s->layers);
    while(!lista_eol(s->layers)){
        layer_draw(lista_get(s->layers),s->renderer,s->camera);
        lista_next(s->layers);
    }
}

void scene_set_camera(scene_t *s, camera_data c_data){
    (s->camera).x = c_data.x;
    (s->camera).y = c_data.y;
    (s->camera).h = c_data.h;
    (s->camera).w = c_data.w;
}

void scene_destroy(scene_t **s){
    lista_destroy(&((*s)->layers),(void*)(void**)layer_destroy);
    free(*s);
}