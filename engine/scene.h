/* Representa el mundo para un juego en 2D. Una escena posee layers con entidades
   a ser dibujadas. La escena puede ser mucho más grande de lo que se puede llegar
   a ver en pantalla. El atributo "camera" determina que parte de la escena debe
   dibujarse en pantalla. */

#ifndef SCENE_H
#define SCENE_H

#include "lista.h"
#include "layer.h"
#include <SDL3/SDL.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
    int w;
    int h;
} camera_data;

typedef struct {
    lista_t *layers;
    SDL_FRect camera;
    SDL_Renderer *renderer;
} scene_t;

void scene_init(scene_t *s, SDL_Window *window);
void scene_set_camera(scene_t *s, camera_data c_data);
void scene_draw(scene_t *s);
void scene_destroy(scene_t **s);
#endif