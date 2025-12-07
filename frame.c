#include "frame.h"


void frame_init(frame_t *frame, frame_data data){
    frame = (frame_t *)malloc(sizeof(frame_t));
    frame->cutter.x = data.sprite_x;
    frame->cutter.y = data.sprite_y;
    frame->cutter.h = data.sprite_height;
    frame->cutter.w = data.sprite_width;

    frame->pos_relative_x = data.entity_relative_x;
    frame->pos_relative_y = data.entity_relative_y;
}
void frame_destroy(frame_t **frame){
    free(*frame);
}

SDL_rect *frame_get_cutter(frame_t *frame){
    return &(frame->cutter);
}