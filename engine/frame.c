#include "frame.h"


void frame_init(frame_t *frame, float x, float y, float h, float w, float addx, float addy){
    frame = (frame_t *)malloc(sizeof(frame_t));
    frame->cutter.x = x;
    frame->cutter.y = y;
    frame->cutter.h = h;
    frame->cutter.w = w;

    frame->pos_relative_x = addx;
    frame->pos_relative_y = addy;
}
void frame_destroy(frame_t **frame){
    free(*frame);
}

SDL_FRect *frame_get_cutter(frame_t *frame){
    return &(frame->cutter);
}