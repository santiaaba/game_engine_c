#include "help.h"

SDL_FRect rect_inside_rect(SDL_FRect *a, SDL_FRect *b){
    /* Retorna un rectángulo del área que se encuentre
       el rectángulo A dentro del rectángulo B. Si no
       se tocan, los valores W y H del rectángulo retornado
       serán 0 y 0 respectivamente */

    SDL_FRect aux;
    if(a->x > b->x + b->w || a->y > b->y + b->h ||
       a->x + a->w < b->x || a->y + a->h < b->y ||
       b->x + b->w < a->x || b->y + b->h < a->y){
        /* Rectángulos ni se tocan */
        aux.w = 0;
        aux.h = 0;
    } else {
        /* Se tocan en algún punto */
        if(a->x < b->x)
            aux.x = b->x;
        else
            aux.x = a->x;
    
        if(a->y < b->y)
            aux.y = b->y;
        else
            aux.y = a->y;

        if(a->x + a->w < b->x + b->w)
            aux.w = a->x + a->w - b->x;
        else
            aux.w = b->x + b->w - a->x;

        if(a->y + a->h < b->y + b-> h)
            aux.h = a->y + a->h - b->y;
        else
            aux.h = b->y + b->h - a->y;
    }
    return aux;
}